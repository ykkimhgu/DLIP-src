///*------------------------------------------------------/
//* Image Proccessing with Deep Learning
//* OpenCV Tutorial: Flip exercise (Video based)
//* Created: 2021-Spring
//------------------------------------------------------*/
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <time.h>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//
//	/*  Open the video  */
//	//VideoCapture cap(0);
//	VideoCapture cap("video.mp4");
//	
//	if (!cap.isOpened())	// if not success, exit the programm
//	{
//		cout << "Cannot open the video cam\n";
//		return -1;
//	}
//	
//	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);
//	
//	time_t t;
//
//	int key = 0;
//	bool horizontal_flip = 0;
//	bool vertical_flip = 0;
//	int flip_code = 0;
//	while (1)
//	{
//		key = waitKey(15);
//		if (key == 'h' || key == 'H')
//			horizontal_flip = !horizontal_flip;
//		else if (key == 'v' || key == 'V')
//			vertical_flip = !vertical_flip;
//		else if (key == 27)
//		{
//			cout << "ESC key is pressed by user\n";
//			break;
//		}
//
//		Mat src, dst;
//
//
//		/*  read a new frame from video  */
//		bool bSuccess = cap.read(src);
//	
//		if (!bSuccess)	// if not success, break loop
//		{
//			cout << "Cannot find a frame from  video stream\n";
//			break;
//		}
//
//		if (!horizontal_flip && !vertical_flip)
//			src.copyTo(dst);
//		else if (horizontal_flip && !vertical_flip)
//			flip(src, dst, 1);
//		else if (!horizontal_flip && vertical_flip)
//			flip(src, dst, 0);
//		else if (horizontal_flip && vertical_flip)
//			flip(src, dst, -1);
//
//		if (key == 's' || key == 'S')
//		{
//			string output_data_name = "flipedImg_" + to_string(time(&t)) + ".jpg";
//			imwrite(output_data_name, dst);
//		}
//			
//		
//		imshow("MyVideo", dst);
//		
//	}
//}