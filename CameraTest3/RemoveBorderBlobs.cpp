//		vRemoveBorderBlobs.cpp
//Remove the border blobs
//
//JvdK 14-04-2015

#include "visionoperator.h"

void vRemoveBorderBlobs(image_t *dst) {

	uint32_t 	value, changes, k, p,
				y, ys, ye, 
				x, xs, xss, xe, xee;
	uint8_t *p_dst = (uint8_t *)dst->data;

	//changes is the amount of changes (set to 1 to start the loop)
	changes = 1;
	//k is the amount of loops
	for (k = 0; changes > 0; k++) {
		y = 0;
		//first loop will run from left top to right bottom
		for (y = k; y < (dst->rows - k); y++) {
			for (x = k; x < (dst->cols - k); x++) {
				//this loop will start with the border pixels
				//each iteration the loop will check a rectangle who is one pixel smaller (k)
				if (y == k || y == (dst->rows - 1 - k) || x == k || x == (dst->cols - 1 - k)) {
					value = 0;
					//check if it is a pixel from the first itteration (border pixels)
					if (k == 0) {
						if ((*(p_dst + (y*IMG_COLS + x))) == 1) { *(p_dst + (y*IMG_COLS + x)) = 2; changes++; }
					}
					//all the pixels of the inner side
					else {
						//if the pixel value is 1 check the pixels around for find a border pixel (2)
						if ((*(p_dst + (y*IMG_COLS + x))) == 1) {
							value = 1;
							ye = y + 2;
							ys = y - 1;
							xee = x + 2;
							xss = x - 1;
							while (ys < ye) {
								xe = xee;
								xs = xss;
								while (xs < xe) {
									if ((*(p_dst + (ys*IMG_COLS + xs))) == 2) { value = 2; changes++; }
									xs++;
								}
								ys++;
							}
							*(p_dst + (y*IMG_COLS + x)) = value;
						}
					}
				}
			}
		}
		//second loop will run from right bottom to left top
		if (k != 0) {
			for (y = (dst->rows - 1 - k); y >= k; y--) {
				for (x = (dst->cols - 1 - k); x >= k; x--) {
					if (y == k || y == (dst->rows - 1 - k) || x == k || x == (dst->cols - 1 - k)) {
						if ((*(p_dst + (y*IMG_COLS + x))) == 1) {
							value = 1;
							ye = y + 2;
							ys = y - 1;
							xee = x + 2;
							xss = x - 1;
							while (ys < ye) {
								xe = xee;
								xs = xss;
								while (xs < xe) {
									if ((*(p_dst + (ys*IMG_COLS + xs))) == 2) { value = 2; changes++; }
									xs++;
								}
								ys++;
							}
							*(p_dst + (y*IMG_COLS + x)) = value;
						}
					}
				}
			}
		}
	}

	p = dst->pixels;
	while (p){
		if (*(p_dst) == 2) {
			*(p_dst) = 0;
		}
		p_dst++;
	}
	return;
}
