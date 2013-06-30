#include<cv.h>
#include<highgui.h>
#include<iostream>

using namespace cv;
using namespace std;

int off_pixels_in_row(Mat img,int row_number)
{
int off_pixels_count = 0;

    // Check if there are any while pixels in the y'th row.
    for (int i = 0; i < img.cols; ++i)
    {
	Scalar intensity = img.at<uchar>(row_number,i); 
	if(intensity[0] > 200) 
	{
		// Found a white pixel in this line
		off_pixels_count++;
	}
	else
	{
		// No white pixels in this line
		continue;
	}
    }

return off_pixels_count;
}

int off_pixels_in_column(Mat img,int col_number)
{
int off_pixels_count = 0;

    // Check if there are any while pixels in the y'th row.
    for (int i = 0; i < img.rows; ++i)
    {
	Scalar intensity = img.at<uchar>(i,col_number); 
	if(intensity[0] > 200) 
	{
		// Found a white pixel in this line
		off_pixels_count++;
	}
	else
	{
		// No white pixels in this line
		continue;
	}
    }

return off_pixels_count;
}

