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
	Mat hist_normed = hist * height / max_val; // max_val를 plot 이미지의 최고 높이에 맞춰지도록 함
	float bin_w = (float)width / histSize;	// plot이미지 가로크기에 맞추어 가로방향 축 간격값 지정
	Mat histImage(height, width, CV_8UC1, Scalar(0));	// plot용도로 사용될 width, height 크기의 8비트 흰색 이미지 생성
	for (int i = 0; i < histSize - 1; i++) {	// 그래프는 두 점을 잇는 형식으로 진행되므로 256 - 1번만큼 진행
		line(histImage,	// histImage에 라인을 그리는 함수
			Point((int)(bin_w * i), height - cvRound(hist_normed.at<float>(i, 0))),			// 시작점 : bin_w * k , normalized_val * n[k]
			Point((int)(bin_w * (i + 1)), height - cvRound(hist_normed.at<float>(i + 1, 0))),	// 종료점 : bin_w * (k+1) , normalized_val * n[k+1]
			Scalar(255), 2, 8, 0);													// 선의 색깔은 검정(0), 선두께는 linewidth로 지정
	}

	imshow(plotname, histImage);
}