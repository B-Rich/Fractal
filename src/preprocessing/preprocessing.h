/*
** All the activity related to preprocessing is defined in this file
*/
#include <cv.h>

/* All the Macros */


/* All the pre processing related function definitions */
IplImage * deskew (IplImage * skewed_image, float angle);
float get_skew_angle(IplImage *skewed_image);
