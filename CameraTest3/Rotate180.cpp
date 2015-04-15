//		vBlobanalyse.cpp
//Rotates the image 180 degrees
//
//JvdK 14-04-2015

#include "visionoperator.h"

void vRotate180(image_t *dst) {

	uint8_t *p_dst = (uint8_t *)dst->data;
	uint8_t a;
	uint16_t p, i, c;

	p = (dst->pixels/2);
	c = ((p * 2) - 1);
	p_dst = (uint8_t *)dst->data;
	for (i = 0; i < p; i++) {
		a = *(p_dst + i);
		*(p_dst + i) = *(p_dst + c - i);
		*(p_dst + c - i) = a;
	}
	return;
}
