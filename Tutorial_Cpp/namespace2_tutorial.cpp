/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* Cpp Tutorial: namespace2
* Created: 2022-Spring
------------------------------------------------------*/

#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	Mat src, gray, dst;
	src = imread("testImage.jpg");

	if (src.empty())
		cout << "src is empty!!" << endl;

	namedWindow("src");
	imshow("src", src);

	waitKey(0);
}