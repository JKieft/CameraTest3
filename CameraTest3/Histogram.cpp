//		vHistogram.cpp
//Programm for make a histogram of the pixel values in the image
	//*hist must be array of uint32_t with 256 (0-255) elements
//JvdK 07-04-2015

#include "visionoperator.h"

void vHistogram(image_t  *src,
	uint32_t *hist,
	uint32_t *sum) {

	uint8_t *p_src = (uint8_t *)src->data; //pointer to the source data
	uint32_t *p_hist = (uint32_t *)hist; //pointer to the histogram who is declared in the programm who called up this program
	uint32_t *p_sum = (uint32_t *)sum; //pointer to the sum of all pixels
	uint32_t p;

	//set al elements of the hist to zero
	p = 256;
	while (p) {
		*(p_hist + p - 1) = 0;
		p--;
	}
	//calculate the som of al the pixel in the image
	p = src->pixels;
	while (p) {
		*p_sum = *p_sum + *p_src;
		p_src++, p--;
	}
	//fill the hist
	p = src->pixels;
	p_src = (uint8_t *)src->data;
	while (p) {
		*(p_hist + *p_src) = (*(p_hist + *p_src) + 1);
		p_src++, p--;
	}
	return;
}