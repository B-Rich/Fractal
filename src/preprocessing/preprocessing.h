/*
** All the activity related to preprocessing is defined in this file
*/
#include <cv.h>
#include <highgui.h>
using namespace cv;

/* All the Macros */


/* All the pre processing related function definitions */
Mat deskew (Mat skewed_image, double angle);
double get_skew_angle(Mat skewed_image);
