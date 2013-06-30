#include <iostream>
#include <cv.h>
#include "globals.h"
#include "src/preprocessing/preprocessing.h"
#include "src/identification/identification.h"
using namespace cv;
using namespace std;
/* Global variables */
extern Mat input_image;
extern Mat input_image_thresholded;

/*
** Main entry point
*/

int main (int argc, char **argv)
{

	/* Primary check for passed image */
	if (argc == 1)
	{
		cout << "\nNo arguments found.\n\tUsage: ./fractal.o <path-to-image>\n\n" << endl;
	}	

	/* Local Variables */
	Mat compute_skew_image;
	Mat deskew_image;
	Mat cropped_image;

	/*Initialize Variables */
	input_image = imread(argv[1],0);
	compute_skew_image = input_image.clone();
	deskew_image = input_image.clone();

	/* Pre-process given image */
	double angle = get_skew_angle(compute_skew_image);

	cropped_image = deskew(deskew_image,angle);

	return 0;
}
