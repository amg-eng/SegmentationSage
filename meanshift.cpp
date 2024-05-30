#include "meanshift.h"
#include "opencv2/imgproc.hpp"

const int dxdy[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; // Region Growing

void setPoint(Pixel* p, float px, float py, float pl, float pa, float pb) {
    p->x = px;
    p->y = py;
    p->l = pl;
    p->a = pa;
    p->b = pb;
}

void convertLab(Pixel* pt) {
    pt->l = pt->l * 100 / 255;
    pt->a -= 128;
    pt->b -= 128;
}

void copyPoint(Pixel* p1, Pixel* p2) {
    // Function to copy colors of the second point to the first point
    // p2 --> p1
    p1->x = p2->x;
    p1->y = p2->y;
    p1->l = p2->l;
    p1->a = p2->a;
    p1->b = p2->b;
}

float colorDistance(Pixel Pt1, Pixel Pt2) {
    return sqrt((Pt1.l - Pt2.l) * (Pt1.l - Pt2.l) + (Pt1.a - Pt2.a) * (Pt1.a - Pt2.a) + (Pt1.b - Pt2.b) * (Pt1.b - Pt2.b));
}

float spatialDistance(Pixel Pt1, Pixel Pt2) {
    return sqrt((Pt1.x - Pt2.x) * (Pt1.x - Pt2.x) + (Pt1.y - Pt2.y) * (Pt1.y - Pt2.y));
}

void scalePoint(Pixel* p, float scale) {
    p->x *= scale;
    p->y *= scale;
    p->l *= scale;
    p->a *= scale;
    p->b *= scale;
}

void accumulatePoint(Pixel* mainPt, Pixel Pt) {
    mainPt->x += Pt.x;
    mainPt->y += Pt.y;
    mainPt->l += Pt.l;
    mainPt->a += Pt.a;
    mainPt->b += Pt.b;
}

void convertRGB(Pixel* p) {
    p->l = p->l * 255 / 100;
    p->a += 128;
    p->b += 128;
}

cv::Mat segment(cv::Mat Img, float distanceBandwidth, float colorBandwidth) {
    // Image clone to an output image
    cv::Mat ImgOut = Img.clone();
    cv::cvtColor(ImgOut, ImgOut, cv::COLOR_BGR2Lab);

    int ROWS = Img.rows;
    int COLS = Img.cols;
    std::vector<cv::Mat> IMGChannels(3);
    cv::split(ImgOut, IMGChannels);

    Pixel PtCur;
    Pixel PtPrev;
    Pixel PtSum;
    Pixel Pt;

    int Left;
    int Right;
    int Top;
    int Bottom;
    int NumPts; // number of points in a hypersphere
    int step;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Left = (j - distanceBandwidth) > 0 ? (j - distanceBandwidth) : 0;
            Right = (j + distanceBandwidth) < COLS ? (j + distanceBandwidth) : COLS;
            Top = (i - distanceBandwidth) > 0 ? (i - distanceBandwidth) : 0;
            Bottom = (i + distanceBandwidth) < ROWS ? (i + distanceBandwidth) : ROWS;
            setPoint(&PtCur, i, j, (float)IMGChannels[0].at<uchar>(i, j), (float)IMGChannels[1].at<uchar>(i, j), (float)IMGChannels[2].at<uchar>(i, j));
            convertLab(&PtCur);
            step = 0;
            do {
                copyPoint(&PtPrev, &PtCur);
                setPoint(&PtSum, 0, 0, 0, 0, 0);
                NumPts = 0;
                for (int hx = Top; hx < Bottom; hx++) {
                    for (int hy = Left; hy < Right; hy++) {
                        setPoint(&Pt, hx, hy, (float)IMGChannels[0].at<uchar>(hx, hy), (float)IMGChannels[1].at<uchar>(hx, hy), (float)IMGChannels[2].at<uchar>(hx, hy));
                        convertLab(&Pt);
                        if (colorDistance(Pt, PtCur) < colorBandwidth) {
                            accumulatePoint(&PtSum, Pt);
                            NumPts++;
                        }
                    }
                }
                scalePoint(&PtSum, 1.0 / NumPts);
                copyPoint(&PtCur, &PtSum);
                step++;
            } while ((colorDistance(PtCur, PtPrev) > MS_MEAN_SHIFT_TOL_COLOR) && (spatialDistance(PtCur, PtPrev) > MS_MEAN_SHIFT_TOL_SPATIAL) && (step < MS_MAX_NUM_CONVERGENCE_STEPS));

            convertRGB(&PtCur);
            ImgOut.at<cv::Vec3b>(i, j) = cv::Vec3b(PtCur.l, PtCur.a, PtCur.b);
        }
    }
    //--------------------------------------------------------------------

    //----------------------- Segmentation ------------------------------
    int label = -1; // Label number
    std::vector<float> Mode(ROWS * COLS * 3); // Store the Lab color of each region
    std::vector<int> MemberModeCount(ROWS * COLS, 0); // Store the number of each region
    cv::split(ImgOut, IMGChannels);
    // Label for each point
    std::vector<std::vector<int>> Labels(ROWS);;

    // Initialization
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Labels[i].push_back(-1);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If the point is not being labeled
            if (Labels[i][j] < 0) {
                Labels[i][j] = ++label; // Give it a new label number
                // Get the point
                setPoint(&PtCur, i, j, (float)IMGChannels[0].at<uchar>(i, j), (float)IMGChannels[1].at<uchar>(i, j), (float)IMGChannels[2].at<uchar>(i, j));
                convertLab(&PtCur);

                // Store each value of Lab
                Mode[label * 3 + 0] = PtCur.l;
                Mode[label * 3 + 1] = PtCur.a;
                Mode[label * 3 + 2] = PtCur.b;

                // Region Growing 8 Neighbours
                std::vector<Pixel> NeighbourPoints;
                NeighbourPoints.push_back(PtCur);
                while (!NeighbourPoints.empty()) {
                    Pt = NeighbourPoints.back();
                    NeighbourPoints.pop_back();

                    // Get 8 neighbours
                    for (int k = 0; k < 8; k++) {
                        int hx = Pt.x + dxdy[k][0];
                        int hy = Pt.y + dxdy[k][1];
                        if ((hx >= 0) && (hy >= 0) && (hx < ROWS) && (hy < COLS) && (Labels[hx][hy] < 0)) {
                            Pixel P;
                            setPoint(&P, hx, hy, (float)IMGChannels[0].at<uchar>(hx, hy), (float)IMGChannels[1].at<uchar>(hx, hy), (float)IMGChannels[2].at<uchar>(hx, hy));
                            convertLab(&P);

                            // Check the color
                            if (colorDistance(PtCur, P) < colorBandwidth) {
                                // Satisfied the color bandwidth
                                Labels[hx][hy] = label; // Give the same label
                                NeighbourPoints.push_back(P); // Push it into stack
                                MemberModeCount[label]++; // This region number plus one
                                // Sum all color in same region
                                Mode[label * 3 + 0] += P.l;
                                Mode[label * 3 + 1] += P.a;
                                Mode[label * 3 + 2] += P.b;
                            }
                        }
                    }
                }
                MemberModeCount[label]++; // Count the point itself
                Mode[label * 3 + 0] /= MemberModeCount[label]; // Get average color
                Mode[label * 3 + 1] /= MemberModeCount[label];
                Mode[label * 3 + 2] /= MemberModeCount[label];
            }
        }
    }
    // Get result image from Mode array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            label = Labels[i][j];
            float l = Mode[label * 3 + 0];
            float a = Mode[label * 3 + 1];
            float b = Mode[label * 3 + 2];
            Pixel Pixel;
            setPoint(&Pixel, i, j, l, a, b);
            convertRGB(&Pixel);
            ImgOut.at<cv::Vec3b>(i, j) = cv::Vec3b(Pixel.l, Pixel.a, Pixel.b);
        }
    }
    cv::cvtColor(ImgOut, ImgOut, cv::COLOR_Lab2BGR);
    return ImgOut;
}
