//		vWriteCapture.cpp
//Programm for write a image_t into a .ppm file
//JvdK 07-04-2015

#include "visionoperator.h"

int vWriteCapture(image_t *capture)
{
	uint32_t p, x, y;
	cv::Mat capt(cv::Size(800, 600), CV_8UC1); //create matrix for capturing
	uint8_t *p_capture = (uint8_t *)capture->data; //pointer to the first pixel of the destination
												   //uchar *p_capt = (uchar *)capt.data; //pointer to the first pixel of the destination

	uchar *p_capt = capt.data;

	p = capture->pixels;
	while (p) {
		*p_capt = (uchar)((*p_capture));// *255);
		p--; p_capture++; p_capt++;
	}

	imwrite("LoadCapture.ppm", capt);

	return 0;
}