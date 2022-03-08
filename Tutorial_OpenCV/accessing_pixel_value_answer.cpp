/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV Tutorial: Aceessing pixel value answer
* Created: 2021-Spring
------------------------------------------------------*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	// read image  
	Mat img_gray = imread("image.jpg", 0);   //graysacle
	Mat img = imread("image.jpg", 1);

	/* Option1 : Accesing using "at<type>(v,u)" */
	// For single channel img
	printf("%d\n", img_gray.at<uchar>(0, 0));

	// For RGB image
	printf("%d\n", img.at<Vec3b>(0, 0)[0]);
	printf("%d\n", img.at<Vec3b>(0, 0)[1]);
	printf("%d\n", img.at<Vec3b>(0, 0)[2]);

	// solution for exercise (accessing using "at")
	double avgVal = 0;
	for (int v = 0; v < img_gray.rows; v++)
		for (int u = 0; u < img_gray.cols; u++)
			avgVal += img_gray.at<uchar>(v, u);
	avgVal /= (img_gray.rows * img_gray.cols);

	cout << "average intensity = " << avgVal << endl;


	/* Option2 : Accessing Using Pointer */
	// (Gray Image)
	int pixel_temp;
	for (int v = 0; v < img_gray.rows; v++)
	{
		uchar* img_data = img_gray.ptr<uchar>(v);
		for (int u = 0; u < img_gray.cols; u++)
		{
			pixel_temp = img_data[u];
		}
	}

	// (RGB Image)
	int pixel_temp_r, pixel_temp_g, pixel_temp_b;
	int cnt = 0;
	for (int v = 0; v < img.rows; v++)
	{
		uchar* img_data = img.ptr<uchar>(v);
		for (int u = 0; u < img.cols * img.channels(); u = u + 3)
		{
			pixel_temp_r = img_data[u];
			pixel_temp_g = img_data[u + 1];
			pixel_temp_b = img_data[u + 2];
		}
	}

	/* Option3 : Data Approach*/
	uchar* img_data = (uchar*)img_gray.data;
	int length = img_gray.rows * img_gray.cols * img_gray.channels();

	for (int i = 0; i < length; i++)
		pixel_temp = (int)img_data[i];


	waitKey(0);
}
