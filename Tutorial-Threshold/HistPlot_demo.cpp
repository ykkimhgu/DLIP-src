// Image Proccessing with Deep Learning
// Tutorial - Calculate and Plot Histogram
// 2021-Spring 

#include <iostream>
#include "opencv.hpp"

using namespace std;
using namespace cv;

void plotHist(Mat &hist);

int main()
{
	Mat src, dst;

	/// Load image in Gray scale image  '0'
	src = imread("testImage.jpg", 0);
	if (!src.data)
	{
		cout << " File Not Found";
		return -1;
	}

	/// Compute the histograms 
	Mat hist;

	/// Establish the number of bins (for uchar Mat type)
	int histSize = 256;
	/// Set the ranges (for uchar Mat type)
	float range[] = { 0, 256 };
	const float* histRange = { range };
	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false);

	/// Plot the histograms
	plotHist(hist);
	

	/// Calculate the mean intensity 
	double t = (double)cv::getTickCount();
	float mean = 0;
	for (int v = 0; v < src.rows; v++) {
		for (int u = 0; u < src.cols; u++) {
			mean += src.at<uchar>(v, u); // Read pixel value from src image		  
		}
	}
	mean = mean / (src.rows*src.cols);
	cout << "The mean intensity\t= " << mean << endl;
		
	namedWindow("Image", CV_WINDOW_AUTOSIZE);
	imshow("Image", src);

	waitKey(0);
	return 0;
}

void plotHist(Mat &hist)
{
	// Draw the histogram
	int histSize = 256;
	int hist_w = 2 * 256; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize); // bin_w=1

	/// Normalize the result to [ 0, histImage.rows ], histImage.rows=hist_h
	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0));
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	/// Draw for each channel - Line (pt1(x,y), pt2(x,y))
	//  x,y는 Top Left corner에서 0,0 으로 시작됨- 즉 histlevel=0은 hist_h [pixel] 로 표현됨

	for (int v = 0; v < histSize; v++)
	{
		line(histImage, Point(bin_w*(v), hist_h),
			Point(bin_w*(v), hist_h - cvRound(hist.at<float>(v))),
			Scalar(255), 2, 8, 0);
	}

	namedWindow("Histogram", CV_WINDOW_AUTOSIZE);
	imshow("Histogram", histImage);
}
