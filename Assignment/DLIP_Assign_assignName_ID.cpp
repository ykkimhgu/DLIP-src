/*------------------------------------------------------------------------------------------\
@ Deep Learning & Image Processing  by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 01-04-2019
Modified        : 01-04-2023
Language/ver	: C++
Course		: Deep Learning & Image Processing

Description     : "write name of Assignment"
/------------------------------------------------------------------------------------------*/

#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
  /*  read image  */
  String filename1 = "image.jpg";  // class
  Mat img = imread(filename1);  //Mat class
  Mat img_gray = imread("image.jpg", 0);  // read in grayscale
  
  /*  write image  */
  String filename2 = "writeTest.jpg";  // C++ class/syntax (String, cout, cin)
  imwrite(filename2, img);
 
  /*  display image  */
  namedWindow("image", WINDOW_AUTOSIZE);
  imshow("image", img);
  
  namedWindow("image_gray", WINDOW_AUTOSIZE);
  imshow("image_gray", img_gray);
  
  waitKey(0);
}

