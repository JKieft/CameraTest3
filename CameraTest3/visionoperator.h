#include <stdint.h>			//uint32_t, uint8_t
//#include <string>			//string
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <unistd.h>
#include <inttypes.h>

//gebruik altijd cv:: of std:: voor een operator
//using namespace cv;
using namespace std;

//height and width for the normal image
#define IMG_ROWS		(600)
#define IMG_COLS		(800)
/*
//height and width for the ROI of the number
#define NUM_ROWS		(111)
#define NUM_COLS		(81)
*/
//typedefenition of a image
typedef struct{
	uint16_t rows;
	uint16_t cols;
	uint32_t pixels;
	uint32_t lut[15];
	uint16_t dummy;
	uint8_t data[IMG_ROWS][IMG_COLS];
}image_t;

/*//typedefenition of a ROI of a number
typedef struct {
	uint32_t rows;
	uint32_t cols;
	uint8_t data[NUM_ROWS][NUM_COLS];
}number_t;

//typedefenition of a point in a image
typedef struct{
	float x;
	float y;
}point;

typedef struct{
	float x;
	float y;
}fpoint;

//typedefenition of a line between two points in a image
typedef struct{
	fpoint start;
	fpoint end;
	float gradient;
	float intercept;
	float length;
}ffline;

typedef struct{
	point start;
	fpoint end;
	float gradient;
	float intercept;
	float length;
}fline;

typedef struct{
	point start;
	point end;
	float gradient;
	float intercept;
	float length;
}uline;

//FUNCTIONS

//Load image
void vLoadImage(	image_t *dst,
					string imagename);*/

void vRotate180(image_t *dst);

int vLoadCaptureGray(image_t *capture);//	image_t *dst);

int vWriteCapture(image_t *capture);//	image_t *dst);

void vRotate180(image_t *dst);

/*//Capture image
void vCaptureImage(	image_t dst);

//Threshold fixed value
void vThreshold(	image_t *src,
					image_t *dst,
					uint8_t value);*/

//Histogram pixelvalues between 0 and 255
void vHistogram	(	image_t  *src,
					uint32_t *hist,
					uint32_t *sum);

//Threshold Iso Data
int vThresholdIsoData(	image_t *src,
						image_t *dst);

/*//Dilation
void vDilate(	image_t *src,
				image_t *dst,
				uint8_t mask);

//Dilation of the number
void vNumDilate( number_t *src,
	             number_t *dst);


//Erosion
void vErode(	image_t *src,
				image_t *dst);

//Perspective warp of a image with 4 coordinates with some more funtions
void vPerspectiveWarp(	image_t *src,
						image_t *dst,
						uint16_t ax, uint16_t ay,
						uint16_t bx, uint16_t by,
						uint16_t cx, uint16_t cy,
						uint16_t dx, uint16_t dy);

fpoint INTERSECT(fpoint *startA, fpoint *endA, fpoint *startB, fpoint *endB);
void EDGEPOINTS(fpoint *eA, fpoint *eB, fpoint *eC, fpoint *eD, fpoint *eM, fpoint *VH, fpoint *VV, fpoint *eH, fpoint *eV, uint32_t *fy, uint32_t *fx);*/

//Remove the blobs at the border
void vRemoveBorderBlobs(image_t *dst);

/*//Label the blobs in the image;
void vLabelBlobs(image_t *dst);

void vSetSelectedToValue(image_t *src, image_t *dst, uint32_t vsrc, uint8_t vdst);*/

void vBlobAnalysis(image_t *dst);

/*float dNCM(image_t *src, uint8_t p, uint8_t q, uint8_t blobnr);

float IntPower(float x, uint8_t power);

void vFillNumLut();

void vROINumber(image_t *capture2, number_t *number);

uint32_t vSearchBlobPuzzle(image_t *src);

void vScaleSource(image_t *src, image_t *blob, image_t *dst2, uint32_t blobnr);

uint32_t vSearchNumber(number_t *number);

uint32_t vCheckTangram(image_t *src, image_t *dst, uint32_t blobnr);

void vDrawTriangle(image_t *dst, uint32_t siz, uint32_t angle, uint32_t xcent, uint32_t ycent, uint32_t pix);*/

