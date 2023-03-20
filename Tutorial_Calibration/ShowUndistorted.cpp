#include <iostream>
#include <opencv.hpp>



int main()
{
	cv::Mat src, result, cameraMatrix, distCoeffs;
	src = cv::imread("calibTest.jpg");
 
	double fx, fy, cx, cy, k1, k2, p1, p2;
    
	fx	=  812.9470333032964; // Intrinsic Matrix Coefficient
	fy	=  821.4599675610342; // Intrinsic Matrix Coefficient
	cx	=  621.9032174475758; // Intrinsic Matrix Coefficient
	cy	=  345.2169472534054; // Intrinsic Matrix Coefficient
	k1	= -0.386238266682461; // Radial Distortion
	k2	=  0.117700918859102; // Radial Distortion
	p1	=  0.0; // Tangential Distortion
	p2	=  0.0; // Tangential Distortion
	
	// Camera Intrinsic Matrix
	cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
	cameraMatrix.at<double>(0, 0) = fx;
	cameraMatrix.at<double>(0, 2) = cx;
	cameraMatrix.at<double>(1, 1) = fy;
	cameraMatrix.at<double>(1, 2) = cy;


	distCoeffs = cv::Mat::zeros(4, 1, CV_64F);
	distCoeffs.at<double>(0, 0) = k1;
	distCoeffs.at<double>(1, 0) = k2;
	distCoeffs.at<double>(2, 0) = p1;
	distCoeffs.at<double>(3, 0) = p2;


	// result : undistorted image
	cv::undistort(src, result, cameraMatrix, distCoeffs);



	cv::namedWindow("Src", CV_WINDOW_NORMAL);
	cv::namedWindow("Undistorted Image", CV_WINDOW_NORMAL);
	cv::imshow("Src", src);
	cv::imshow("Undistorted Image", result);
	cv::waitKey(0);
	return 0;
}
 