#include <iostream>
#include <cv.h>
#include <highgui.h>
#include "src/preprocessing/preprocessing.h"
#include "src/identification/identification.h"
using namespace cv;
using namespace std;
/* Global variables */


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
	Mat img = imread (argv[1],0);

	/*Initialize Variables */


	/* Pre-process given image */
	cout << "Skew angle: " << get_skew_angle(img) << endl;

	return 0;
}
