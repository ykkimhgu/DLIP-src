/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* Cpp Tutorial: Class
* Created: 2021-Spring
------------------------------------------------------*/

#include <opencv2/opencv.hpp>
#include <iostream>

int main() 
{
	cv::Mat src, gray, dst;
	src = cv::imread("image.jpg");

	if (src.empty())
		std::cout << "src is empty!!" << std::endl;

	std::cout << "is empty?  : " << src.empty() << std::endl;
	std::cout << "channels   : " << src.channels() << std::endl;
	std::cout << "row of src :" << src.rows << std::endl;
	std::cout << "col of src :" << src.cols << std::endl;
	std::cout << "type of src:" << src.type() << std::endl;

}