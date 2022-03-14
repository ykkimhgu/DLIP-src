#include "opencv.hpp"
#include <iostream>
#include <time.h>

using namespace cv;
using namespace std;

void plotHist(Mat, string, int, int);

int main(int argc, char* argv[]) {

	int fps = 60;
	int delay_waitKey = 1000 / fps;
	int keyIn = 0;
	Mat src, dst;

	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	while (1) {

		bool bSuccess = cap.read(src);
		if (!bSuccess) {
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		cvtColor(src, src, CV_BGR2GRAY);
		equalizeHist(src, dst);

		keyIn = waitKey(delay_waitKey);
		if (keyIn == 27) { // ESC key
			cout << "esc key is pressed by user" << endl;
			break;
		}
		
		imshow("src", src);
		imshow("dst", dst);	
		plotHist(src, "histplot_src", src.cols, src.rows);
		plotHist(dst, "histplot_dst", dst.cols, dst.rows);
	}

	return 0;
}

void plotHist(Mat src, string plotname, int width, int height) {

	/// Compute the histograms 
	Mat hist;
	/// Establish the number of bins (for uchar Mat type)
	int histSize = 256;
	/// Set the ranges (for uchar Mat type)
	float range[] = { 0, 256 };

	const float* histRange = { range };
	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

	double min_val, max_val;
	cv::minMaxLoc(hist, &min_val, &max_val);
	Mat hist_normed = hist * height / max_val; // max_val�� plot �̹����� �ְ� ���̿� ���������� ��
	float bin_w = (float)width / histSize;	// plot�̹��� ����ũ�⿡ ���߾� ���ι��� �� ���ݰ� ����
	Mat histImage(height, width, CV_8UC1, Scalar(0));	// plot�뵵�� ���� width, height ũ���� 8��Ʈ ��� �̹��� ����
	for (int i = 0; i < histSize - 1; i++) {	// �׷����� �� ���� �մ� �������� ����ǹǷ� 256 - 1����ŭ ����
		line(histImage,	// histImage�� ������ �׸��� �Լ�
			Point((int)(bin_w * i), height - cvRound(hist_normed.at<float>(i, 0))),			// ������ : bin_w * k , normalized_val * n[k]
			Point((int)(bin_w * (i + 1)), height - cvRound(hist_normed.at<float>(i + 1, 0))),	// ������ : bin_w * (k+1) , normalized_val * n[k+1]
			Scalar(255), 2, 8, 0);													// ���� ������ ����(0), ���β��� linewidth�� ����
	}

	imshow(plotname, histImage);
}