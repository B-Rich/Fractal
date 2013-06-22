/*
** Actual pre processing functions are included in this file
*/
#include "preprocessing.h"

/* Extern declaration for global variables */


/* Pre procssing functions */

/*
** get_skew_angle()
**
** Calculate and return the angle at which the image is skewed
**
*/

double get_skew_angle(Mat img)
{
  // Binarize
  threshold(img, img, 225, 255, THRESH_BINARY);
 
  // Invert colors
  bitwise_not(img, img);
 Mat element = getStructuringElement(MORPH_RECT, Size(5, 3));
  erode(img, img, element);

vector<Point> points;
  Mat_<uchar>::iterator it = img.begin<uchar>();
  Mat_<uchar>::iterator end = img.end<uchar>();
  for (; it != end; ++it)
    if (*it)
      points.push_back(it.pos());

RotatedRect box = minAreaRect(Mat(points));
double angle = box.angle;
  if (angle < -45.)
    angle += 90.;

Point2f vertices[4];
  box.points(vertices);
  for(int i = 0; i < 4; ++i)
    line(img, vertices[i], vertices[(i + 1) % 4], Scalar(255, 0, 0), 1, CV_AA);
 
return angle;
}

/*
** deskew()
** 
** Incorrectly scanned images can be skewed.
** This function will correct the image so as to enhance it
** 
*/

Mat deskew(Mat skewed_image, double angle)
{
	
}
