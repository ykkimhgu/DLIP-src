/*------------------------------------------------------------------------------------------
@ DLIP by Young-Keun Kim - Handong Global University

Author           : Jaeeun Park
Created          : 2017/09/01
Modified         : 2022/02/28
Language/ver     : C++ in MSVS2017

Description     : basic_webcam_program_example.cpp
------------------------------------------------------------------------------------------*/
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {

	VideoCapture cap(0); // check your webcam device number

	if (!cap.isOpened()) { // if not success, exit program
		cout << "Cannot open the video cam" << endl;
		system("pause");
		return -1;
	}

	int inKey = -1;
	int flip_H = 1;
	int flip_V = 2;
	int flipIn = 4;
	bool bPause = false;
	bool bGrayScale = false;
	bool bSave = false;
	bool bReset = false;
	bool bExit = false;

	time_t t;
	Mat src, dst;

	while (1) {

		inKey = waitKey(30);
		if (inKey == 'h' || inKey == 'H') flip_H *= -1;
		else if (inKey == 'v' || inKey == 'V') flip_V *= -1;
		else if (inKey == 'g' || inKey == 'G') bGrayScale = !bGrayScale;
		else if (inKey == 'r' || inKey == 'R') bReset = !bReset;
		else if (inKey == 's' || inKey == 'S') bSave = !bSave;
		else if (inKey == 32) bPause = !bPause;  // space bar
		else if (inKey == 27) bExit = !bExit;    // ESC key
		flipIn = flip_H + flip_V + 1;

		if (!bPause) {
			bool bSuccess = cap.read(src);
			if (!bSuccess) {
				cout << "Cannot read a frame from video stream" << endl;
				break;
			}
		}

		if (flipIn != 4)
			flip(src, dst, flipIn);
		else
			src.copyTo(dst);

		if (bGrayScale)
			cvtColor(dst, dst, CV_BGR2GRAY);

		if (bReset) {
			flip_V = 2;
			flip_H = 1;
			bGrayScale = false;
			bPause = false;
			bReset = false;
		}

		if (bSave) {
			imwrite(to_string(time(&t)) + ".jpg", dst);
			bSave = false;
		}

		if (bExit) {
			cout << "esc key is pressed by user" << endl;
			break;
		}

		imshow("MyVideo", dst);
	}
	return 0;
}