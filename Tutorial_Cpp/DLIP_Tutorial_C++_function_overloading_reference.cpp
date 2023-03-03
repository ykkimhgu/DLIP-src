
#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat cvtGray(const cv::Mat color);
void cvtGray(cv::Mat color, cv::Mat & gray);

void main() {
	cv::Mat src, gray, dst;
	src = cv::imread("image.jpg");

	if (src.empty())
		std::cout << "src is empty!!" << std::endl;

	cvtGray(src, gray);

	cv::namedWindow("src");
	cv::imshow("src", src);

	cv::namedWindow("gray");
	cv::imshow("gray", gray);

	cv::waitKey(0);
}

cv::Mat cvtGray(cv::Mat color)
{
	cv::Mat gray;
	color = cv::Mat::zeros(color.size(), CV_8UC3);
	cv::cvtColor(color, gray, CV_RGB2GRAY);
	return gray;
}

void cvtGray(cv::Mat color, cv::Mat gray)
{
	cv::cvtColor(color, gray, CV_RGB2GRAY);
	cv::namedWindow("inside_function");
	cv::imshow("inside_function", gray);
}
