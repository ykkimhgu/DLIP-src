/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV Tutorial: Shallow copy & Deep copy
* Created: 2021-Spring
------------------------------------------------------*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

	Mat src, dst_shallow, dst_deep;
	// read image  
	src = imread("image.jpg", 0);   //graysacle

	/* Shallow Copy */
	dst_shallow = src;
	flip(dst_shallow, dst_shallow, 1);
	imshow("src after shallow copy", src);

	/* Deep Copy */
	src.copyTo(dst_deep);
	flip(dst_deep, dst_deep, 1);
	imshow("src after deep copy", src);

	waitKey(0);
	return 0;
}
