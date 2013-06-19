#include <stdio.h>
#include <cv.h>
#include "src/preprocessing/preprocessing.h"
#include "src/identification/identification.h"

/*
** Main entry point
*/

int main (int argc, char **argv)
{

	if (argc == 1)
	{
		fprintf(stderr,"\nNo arugments found.\n\tUsage: ./fractal.o <path-to-image>\n\n");
	}	

	return 0;
}
