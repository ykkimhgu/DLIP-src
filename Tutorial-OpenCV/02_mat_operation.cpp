///*------------------------------------------------------/
//* Image Proccessing with Deep Learning
//* OpenCV Tutorial: Matrix Operation
//* Created: 2021-Spring
//------------------------------------------------------*/
//#include <iostream>
//#include <opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	/*  Create or Construct Mat  */
//	Mat A(10, 10, CV_8UC3, Scalar::all(155));
//	Mat B(A.size(), CV_8UC1);
//	Mat C = Mat::zeros(A.size(), CV_8UC1);
//	Mat D = Mat::ones(A.size(), CV_32FC1);
//	
//	cout << "MAT A: " << A << endl << endl;
//	cout << "MAT B: " << B << endl << endl;
//	cout << "MAT C: " << C << endl << endl;
//	cout << "MAT D: " << D << endl << endl;
//
//
//	/*  Get size of A (rows, cols)  */
//	cout << "Size of A:  " << A.size() << endl;
//	cout << "# of Rows of A:  " << A.rows << endl;
//	cout << "# of Cols of A:  " << A.cols << endl;
//	cout << "# of Channel of A:  " << A.channels() << endl;
//
//
//	/*  Copy/Clone Mat A to E/F  */
//	Mat E, F;
//	A.copyTo(E);
//	F = A.clone();
//
//
//	/*  Convert channel  */
//	Mat img = imread("image.jpg");	// CV8UC3 Image
//	Mat img_gray;
//	cvtColor(img, img_gray, CV_BGR2GRAY);
//	
//	/*  Chnage image type (8UC1 ¡æ 32FC1)  */
//	Mat img_32F;
//	img_gray.convertTo(img_32F, CV_32FC1);
//	imshow("img_32F", img_32F);
//
//	//cout << "img_32F: " << img_32F.channels() << endl << endl;
//
//
//	waitKey(0);
//}