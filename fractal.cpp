#include <stdio.h>
#include <cv.h>
#include "src/preprocessing/preprocessing.h"
#include "src/identification/identification.h"

/* Global variables */


/*
** Main entry point
*/

int main (int argc, char **argv)
{

	/* Primary check for passed image */
	if (argc == 1)
	{
		fprintf(stderr,"\nNo arugments found.\n\tUsage: ./fractal.o <path-to-image>\n\n");
	}	

	/* Local Variables */
	IplImage *input_image;

	/*Initialize Variables */
	input_image = cvLoadImage(argv[1],1);


	/* Pre-process given image */


	return 0;
}
