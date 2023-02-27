/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* Cpp Tutorial: namespace1
* Created: 2022-Spring
------------------------------------------------------*/

#include <opencv.hpp>
#include <iostream>

void main() {
	cv::Mat src, gray, dst;
	src = cv::imread("testImage.jpg");

	if (src.empty())
		std::cout << "src is empty!!" << std::endl;

	cv::namedWindow("src");
	cv::imshow("src", src);

	cv::waitKey(0);
}