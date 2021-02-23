/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV Tutorial: Image read/write/display
* Created: 2021-Spring
------------------------------------------------------*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	/*  read image  */
	String filename1 = "image.jpg";
	Mat img = imread(filename1);
	Mat img_gray = imread("image.jpg", 0);  // read in grayscale

	/*  write image  */
	String filename2 = "writeTest.jpg";
	imwrite(filename2, img);

	/*  display image  */
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", img);

	namedWindow("image_gray", CV_WINDOW_AUTOSIZE);
	imshow("image_gray", img_gray);

	waitKey(0);
  return 0;
}