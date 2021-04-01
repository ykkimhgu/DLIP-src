//#include "opencv2/video/tracking.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include <ctype.h>
#include <iostream>
#include <opencv.hpp>

using namespace cv;
using namespace std;

Mat image;
Point origin;
Rect selection;
bool selectObject = false;
bool trackObject = false;
int hmin = 1, hmax = 179, smin = 30, smax = 255, vmin = 0, vmax = 255;

/// On mouse event 
static void onMouse(int event, int x, int y, int, void*);

int main()
{
	Mat image_disp, hsv, hue, mask, dst;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	image = imread("color_ball.jpg");
	image.copyTo(image_disp);

	Mat dst_track = Mat::zeros(image.size(), CV_8UC3);

	// TrackBar 설정
	namedWindow("Source", 0);
	setMouseCallback("Source", onMouse, 0);
	createTrackbar("Hmin", "Source", &hmin, 179, 0);
	createTrackbar("Hmax", "Source", &hmax, 179, 0);
	createTrackbar("Smin", "Source", &smin, 255, 0);
	createTrackbar("Smax", "Source", &smax, 255, 0);
	createTrackbar("Vmin", "Source", &vmin, 255, 0);
	createTrackbar("Vmax", "Source", &vmax, 255, 0);

	
	for (;;)
	{
		imshow("Source", image);
		cvtColor(image, hsv, COLOR_BGR2HSV);

		/******** You can use RGB instead of HSV ********/
		// YOUR CODE GOES HERE
		// YOUR CODE GOES HERE
		// YOUR CODE GOES HERE
		

		/******** Add Pre-Processing such as filtering etc  ********/
		// YOUR CODE GOES HERE
		// YOUR CODE GOES HERE
		// YOUR CODE GOES HERE


		/// set dst as the output of InRange
		inRange(hsv, Scalar(MIN(hmin, hmax), MIN(smin, smax), MIN(vmin, vmax)),
			Scalar(MAX(hmin, hmax), MAX(smin, smax), MAX(vmin, vmax)), dst);


		/******** Add Post-Processing such as morphology etc  ********/
		// YOUR CODE GOES HERE
		// YOUR CODE GOES HERE
		// YOUR CODE GOES HERE


		namedWindow("InRange", 0);
		imshow("InRange", dst);

		/// once mouse has selected an area bigger than 0
		if (trackObject)
		{
			trackObject = false;					// Terminate the next Analysis loop
			Mat roi_RGB(image, selection); 			// Set ROI by the selection box		
			Mat roi_HSV;
			cvtColor(roi_RGB, roi_HSV, CV_BGR2HSV);
			Scalar means, stddev;
			meanStdDev(roi_HSV, means, stddev);
			cout << "\n Selected ROI Means= " << means << " \n stddev= " << stddev;

			// Change the value in the trackbar according to Mean and STD //
			hmin = MAX((means[0] - stddev[0]), 0);
			hmax = MIN((means[0] + stddev[0]), 179);
			setTrackbarPos("Hmin", "Source", hmin);
			setTrackbarPos("Hmax", "Source", hmax);

			/******** Repeat for S and V trackbar ********/
			// YOUR CODE GOES HERE
			// YOUR CODE GOES HERE
			// YOUR CODE GOES HERE
			
		}


		if (selectObject && selection.area() > 0)  // Left Mouse is being clicked and dragged
		{
			// Mouse Drag을 화면에 보여주기 위함
			Mat roi_RGB(image_disp, selection);
			bitwise_not(roi_RGB, roi_RGB);
			imshow("Source", image_disp);
		}
		image.copyTo(image_disp);

		
		
		///  Find All Contour   ///
		findContours(dst, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);


		/// Find the Contour with the largest area ///
		int idx = 0, largestComp = 0;
		double maxArea = 0;
		for (; idx >= 0; idx = hierarchy[idx][0])
		{
			const vector<Point>& c = contours[idx];
			double area = fabs(contourArea(Mat(c)));		
			if (area > maxArea)
			{
				maxArea = area;
				largestComp = idx;
			}
		}

		///  Draw the max Contour on Black-background  Image ///
		Mat dst_out = Mat::zeros(dst.size(), CV_8UC3);
		drawContours(dst_out, contours, largestComp, Scalar(0, 0, 255), 2, 8, hierarchy);		
		namedWindow("Contour", 0);
		imshow("Contour", dst_out);


		/// Draw the Contour Box on Original Image ///
		Rect boxPoint = boundingRect(contours[largestComp]);
		rectangle(image_disp, boxPoint, Scalar(255, 0, 255), 3);
		namedWindow("Contour_Box", 0);
		imshow("Contour_Box", image_disp);


		/// Continue Drawing the Contour Box  ///
		rectangle(dst_track, boxPoint, Scalar(255, 0, 255), 3);
		namedWindow("Contour_Track", 0);
		imshow("Contour_Track", dst_track);

		char c = (char)waitKey(10);
		if (c == 27)
			break;
	} // end of for(;;)

	return 0;
}



/// On mouse event 
static void onMouse(int event, int x, int y, int, void*)
{
	if (selectObject)  // for any mouse motion
	{
		selection.x = MIN(x, origin.x);
		selection.y = MIN(y, origin.y);
		selection.width = abs(x - origin.x) + 1;
		selection.height = abs(y - origin.y) + 1;
		selection &= Rect(0, 0, image.cols, image.rows);  /// Bitwise AND  check selectin is within the image coordinate
	}

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		selectObject = true;
		origin = Point(x, y);
		break;
	case CV_EVENT_LBUTTONUP:
		selectObject = false;
		if (selection.area())
			trackObject = true;
		break;
	}
}
