//		vBlobanalyse.cpp
//Give the blobs a number
//
//JvdK 07-04-2015

#include "visionoperator.h"

void vBlobanalyse(image_t *dst) {

	uint32_t 	pixel, pixvalue, changes, 
				x, xa, xs, xe, 
				y,     ys, ye, yss, yee, 
				k, p;
	uint8_t blobs;
	uint8_t *p_dst = (uint8_t *)dst->data;

	//stap 1 zet alle niet achtergrond pixels naar 255
	//	nu kunnen we beginnen bij blob nr. 1
	//stap 2 herken alle blobs 
	//  van tweede pixel tot 1 pixel voor het einde
	//  als pixel groter is dan 0 en er is 
	//	door van linksboven naar rechtsonder te lopen en andersom
	//  

	//set all the background pixels to 255
	//		this is for that the first blob can set to 1,2,3,4... etc
	p = dst->pixels;
	while (p) {
		if (*(p_dst) == 1) { *(p_dst) = 255; }
		p_dst++; p--;
	}

	//reset the pointer to the destination->data
	p_dst = (uint8_t *)dst->data;
	//changes is for check the changes in the loop for numbering the blobs 
	//		changes is now set to 1 for start the first loop
	changes = 1;
	//blobs is the counter of the blobs
	//		blobs is now set to 1 for the first blob (blobnr. 1)
	blobs = 1;
	//k is the counter of the loops!!!!!!!!!!!! ->misch eruit halen
	printf("k eruit halen in blobanalyse\n");
	for (k = 0; changes > 0; k++) {
		if (blobs < 255) {
			//set the changes to zero
			changes = 0;
			for (x = 1; x < (uint32_t)(dst->rows - 1); x++) {
				for (y = 1; y < (uint32_t)(dst->cols - 1); y++) {
					if ((*(p_dst + (x*dst->cols + y))) > 0) {
						pixvalue = 0;
						xe = x + 2;
						xs = x - 1;
						yee = y + 2;
						yss = y - 1;
						while (xs < xe) {
							ye = yee;
							ys = yss;
							while (ys < ye) {
								xa = xs*dst->cols + ys;
								if ((*(p_dst + xa)) < (*(p_dst + (x*dst->cols + y))) && ((*(p_dst + xa)) > 0)) { pixvalue = (*(p_dst + xa)); }
								ys++;
							}
							xs++;
						}
						if ((pixvalue == 0) && (*(p_dst + (x*dst->cols + y))) == 255) { *(p_dst + (x*dst->cols + y)) = blobs; blobs++;  changes++; }
						else if (pixvalue != 0) { *(p_dst + (x*dst->cols + y)) = pixvalue; changes++; }
					}
				}
			}
		}
		k++;
		if (changes != 0 && blobs < 255) {
			changes = 0;
			for (x = (dst->rows - 2); x > 0; x--) {
				for (y = (dst->cols - 2); y > 0; y--) {
					if ((*(p_dst + (x*dst->cols + y))) > 0) {
						pixvalue = 0;
						xe = x + 2;
						xs = x - 1;
						yee = y + 2;
						yss = y - 1;
						while (xs < xe) {
							ye = yee;
							ys = yss;
							while (ys < ye) {
								xa = xs*dst->cols + ys;
								if ((*(p_dst + xa)) < (*(p_dst + (x*dst->cols + y))) && ((*(p_dst + xa)) > 0)) { pixvalue = (*(p_dst + xa)); }
								ys++;
							}
							xs++;
						}
						if ((pixvalue == 0) && (*(p_dst + (x*dst->cols + y))) == 255) { *(p_dst + (x*dst->cols + y)) = blobs; blobs++;  changes++; }
						else if (pixvalue != 0) { *(p_dst + (x*dst->cols + y)) = pixvalue; changes++; }
					}
				}
			}
		}
	}
	blobs = 0;
	//in dit gedeelte y vervangen door andere naam
	printf("y vervangen door andere naam\n");
	y = 1;
	while (y) {
		y = 0;
		p_dst = (uint8_t *)dst->data;
		pixel = dst->pixels;
		while (pixel) {
			if (*p_dst > blobs) {
				blobs++;
				pixel = *p_dst;
				while (pixel) {
					if (*p_dst == pixel) {
						*p_dst = blobs;	y++;
					}
					p_dst++; pixel--;
				}
			}
			else {
				p_dst++; pixel--;
			}
		}
		if (y < 600) {
			p_dst = (uint8_t *)dst->data;
			pixel = dst->pixels;
			while (pixel) {
				if (*p_dst == pixel) {
					*p_dst = 0;	y++;
				}
				p_dst++; pixel--;
			}
			blobs--;
		}
		else {
			dst->lut[blobs] = y;
		}
	}
	blobs--;
	return;
}