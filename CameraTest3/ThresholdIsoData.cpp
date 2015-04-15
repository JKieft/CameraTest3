//		vThresholdIsoData.cpp
//Programm for thresholding with iso data (automatic threshold)
//JvdK 07-04-2015

#include "visionoperator.h"

int vThresholdIsoData(image_t *src, image_t *dst)
{
	uint8_t *p_src = (uint8_t *)src->data;
	uint8_t *p_dst = (uint8_t *)dst->data;
	uint32_t hist[256] = { 0 };
	uint32_t sum = 0;
	uint32_t T, mT, p, min, max, sleft, sright, pleft, pright, mleft, mright;
	uint8_t lut[256];

	//set the min and the max
	min = 0;
	max = 255;
	//ask for histogram
	vHistogram(src, hist, &sum);
	//search the lowest pixel value in the histogram, and write into min
	p_src = (uint8_t *)src->data;
	p = 0;
	while (p == 0) {
		p = hist[min];
		min++;
	}
	//search the highest pixel value in the histogram, and write into max
	p = 0;
	while (p == 0) {
		p = hist[max];
		max--;
	}
	//because the min and max value are shifted min - 1, max + 1
	min = min - 1;
	max = max + 1;
	//T is the treshold value. pix value and location in histogram
	//T is a remember, mT is for calculation
	//check if the image isn't uniform
	if (max != min) {
		//mT is the midpoint between min and max
		mT = (uint32_t)(((max - min) / 2) + min);
		T = 0;
		while (T != mT) {
			//make threshold points equal for measure differences
			T = mT;
			sleft = 0;
			pleft = 0;
			//som of pixels above T
			p = (T - min + 1);
			while (p) {
				sleft = sleft + ((hist[(T + 1) - p])*((T + 1) - p));
				p--;
			}
			//amount of pixels above T
			p = (T - min + 1);
			while (p) {
				pleft = pleft + (hist[(T + 1) - p]);
				p--;
			}
			//mean of pixels above T
			mleft = ((uint32_t)(((float)sleft / pleft) + (float)0.5));
			//som of pixels under T
			sright = (sum - sleft);
			//amount of pixels under T
			pright = ((IMG_ROWS * IMG_COLS) - pleft);
			//mean of pixels above T
			mright = (uint32_t)(((float)sright / pright) + (float)0.5);
			//point between the two meanpoints
			mT = (uint32_t)(((float)(((mleft + mright) / 2)) + (float)0.5));
		}
	//Thresholding
		//fill the lut for thresholding the image
		p = 256;
		while (p) {
			if ((p - 1) > mT) { lut[p - (1)] = 1; }
			else { lut[p - 1] = 0; }
			p--;
		}
		//threshold the image
		p = src->pixels;
		while (p) {
			*p_dst = (lut[*p_src++]);
			p_dst++, p--;
		}
	}
	else {
		p = src->pixels;
		min = *p_src++;
		while (p) {
			*p_dst++ = min;
			p--;
		}
	}
	return 0;
}