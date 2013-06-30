/*
** All the activity related to preprocessing is defined in this file
*/
#include <cv.h>
#include <highgui.h>
#include<iostream>
using namespace cv;
using namespace std;

/* All the Macros */


/* All the pre processing related function definitions */
Mat deskew (Mat img, double angle);
double get_skew_angle(Mat skewed_image);
