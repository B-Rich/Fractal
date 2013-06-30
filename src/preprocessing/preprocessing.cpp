/*
** Actual pre processing functions are included in this file
*/
#include "preprocessing.h"
#include "../utils.cpp"

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

Mat deskew(Mat img, double angle)
{
  bitwise_not(img, img);

  vector<Point> points;
  Mat_<uchar>::iterator it = img.begin<uchar>();
  Mat_<uchar>::iterator end = img.end<uchar>();
  for (; it != end; ++it)
    if (*it)
      points.push_back(it.pos());
 
  RotatedRect box = minAreaRect(Mat(points));

  Mat rot_mat = getRotationMatrix2D(box.center, angle, 1);

  Mat rotated;
  warpAffine(img, rotated, rot_mat, img.size(), INTER_CUBIC);

  Size box_size = box.size;
  if (box.angle < -45.)
    swap(box_size.width, box_size.height);

  Mat cropped;
  getRectSubPix(rotated, box_size, box.center, cropped);

  return cropped;
}

void line_segmenter(Mat img)
{

 int y = 0;
 int off_pixels = 0;
 int line_begin = 0;
 int line_end = 0;
 int number_of_lines = 0;

  while(y < img.rows)
  {
	off_pixels = off_pixels_in_row(img,y);

	// We're at the beginning of the line
	if (off_pixels && !line_begin)
	{
		line_begin = y;
		number_of_lines++;
	}
	// We're in the line
	else if (off_pixels && line_begin)
	{
		y++;
		continue;	
	}
	// At the end of the line
	if (!off_pixels && line_begin)
	{
		line_end = y;

//		cout << "Line " << number_of_lines << " begins at: " << line_begin << " and ends at: " << line_end << endl;
		imshow("Line",img(Rect(0,line_begin,img.cols,(line_end-line_begin))));
		waitKey(0);
//		cout << "Ends here" << endl;
		line_begin = 0;
		line_end = 0;
	}
   y++;
  }

}

