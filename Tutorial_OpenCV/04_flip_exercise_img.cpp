/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV Tutorial: Flip exercise (Image based)
* Created: 2021-Spring
------------------------------------------------------*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

	Mat img = imread("image.jpg");
	Mat flipedImg;
	flip(img, flipedImg, 0);


	imshow("image", img);
	imshow("flipedImg", flipedImg);
	waitKey(0);
}