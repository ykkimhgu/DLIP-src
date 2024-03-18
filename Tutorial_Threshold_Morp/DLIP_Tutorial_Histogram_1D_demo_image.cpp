/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV : Histogram Demo (from OpenCV docs)
* https://docs.opencv.org/3.4/d8/dbc/tutorial_histogram_calculation.html
* Created: 2021-Spring
------------------------------------------------------*/

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    //! [Load image]
    //CommandLineParser parser(argc, argv, "{@input | coin.jpg | input image}");
    //Mat src = imread(samples::findFile(parser.get<String>("@input")), 0);
    Mat src = imread("../../../Image/coin.jpg", 0);
    if (src.empty())
    {
        return EXIT_FAILURE;
    }


    //! [Establish the number of bins]
    int histSize = 256;
    //! [Establish the number of bins]

    //! [Set the ranges ( for B,G,R) )]
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange = { range };
    //! [Set the ranges ( for B,G,R) )]

    //! [Set histogram param]
    bool uniform = true, accumulate = false;
    //! [Set histogram param]

    //! [Compute the histograms]
    Mat hist1D;
    calcHist(&src, 1, 0, Mat(), hist1D, 1, &histSize, &histRange, uniform, accumulate);



    //! [Compute the histograms]

    //! [Draw the histograms for B, G and R]
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);


    Mat histImage1D(hist_h, hist_w, CV_8UC1, Scalar(0));
    normalize(hist1D, hist1D, 0, histImage1D.rows, NORM_MINMAX, -1, Mat());

    //! [Draw for each channel]
    for (int i = 1; i < histSize; i++)
    {
        line(histImage1D, Point(bin_w * (i - 1), hist_h - cvRound(hist1D.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(hist1D.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
    }

    //! [Display]
    imshow("Source image", src);
    imshow("calcHist Demo", histImage1D);
    waitKey();
    //! [Display]

    return EXIT_SUCCESS;
}
