//		vLoadCapture.cpp
//Programm for load a new capture from the camera with opencv
//capture will be returned with a selfmade image_t format
//JvdK 06-04-2015

//set
//0		Width * Height 1080 x 720
//1		Width * Height 600  x 400

#include "visionoperator.h"

int vLoadCaptureGray(image_t *capture)
{
	uint32_t p,x,y;
	cv::Mat capt(cv::Size(capture->cols, capture->rows), CV_8UC3); //create matrix for capturing
	uint8_t *p_capture = (uint8_t *)capture->data; //pointer to the first pixel of the destination
	//uchar *p_capt = (uchar *)capt.data; //pointer to the first pixel of the destination

	cv::VideoCapture cap = cv::VideoCapture(0); //open the device for make a photo

    //set the size of the capture
	cap.set(CV_CAP_PROP_FRAME_WIDTH, (int)(capture->cols));// (dst->cols));
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, (int)(capture->rows));// (dst->rows));

	//printf("width: %f\n",(cap.get(CV_CAP_PROP_FRAME_WIDTH)));
	//printf("height: %f\n",(cap.get(CV_CAP_PROP_FRAME_HEIGHT)));
	//start the grab of the image with a sleep for initialize the camera
	if (!cap.grab());
	usleep(200);
	if (cap.grab());

	//retrieve the image to the matrix
	cap.retrieve(capt);

	//set the image to grayscale
	cv::cvtColor(capt, capt, CV_RGB2GRAY);

	//pointer to the first pixel of the Mat
	uchar *p_capt = capt.data;

	//copy to image_t
	p = capture->pixels;
	while (p) {
		*p_capture = (uint8_t)(*p_capt);
		p--; p_capture++; p_capt++;
	}

	return 0;
}