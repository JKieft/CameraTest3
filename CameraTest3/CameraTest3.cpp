#include "visionoperator.h"

using namespace std;
using namespace cv;

int state;
// , capture2;
//number_t number;
cv::Mat capture; //make a matrix for the capture
time_t startstart, start, stop, stopstop;	//make two timers for timing

int main(int argc, char *argv[])
{
	startstart = clock(); //set the first timer
	image_t capture1; capture1.rows = IMG_ROWS; capture1.cols = IMG_COLS; capture1.pixels = IMG_ROWS*IMG_COLS;
	
		//Loadcapture
	start = clock(); //set the first timer
	state = vLoadCaptureGray(&capture1);// &capture1);
	if (state) {printf("LoadCapture failed!\n"); return 0; }
	stop = clock();	//set the last timer
	printf("Loadcapture:			%.3f\n", ((double)(stop - start) / CLOCKS_PER_SEC)); //calculate the time

	/*	 //Rotate180
	start = clock();
	vRotate180(&capture1);
	if (state) { printf("Rotate180 failed!\n"); return 0; }
	stop = clock();
	printf("Rotate180:				%.3f\n", ((double)(stop - start) / CLOCKS_PER_SEC));*/
																						 
		//ThresholdIsoData
	start = clock();
	state = vThresholdIsoData(&capture1,&capture1);
	if (state) { printf("ThresholdIsoData failed!\n"); return 0; }
	stop = clock();
	printf("ThresholdIsoData:		%.3f\n", ((double)(stop - start) / CLOCKS_PER_SEC));

		//Labelblobs
	start = clock();
	vRemoveBorderBlobs(&capture1);
	if (state) { printf("RemoveBorderBlobs failed!\n"); return 0; }
	stop = clock();
	printf("RemoveBorderBlobs:		%.3f\n", ((double)(stop - start) / CLOCKS_PER_SEC));

		//Writecapture
	start = clock();
	state = vWriteCapture(&capture1);
	if (state) { printf("WriteCapture failed!\n"); return 0; }
	stop = clock();	
	printf("Writecaptrure:			%.3f\n", ((double)(stop - start) / CLOCKS_PER_SEC));
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


	stopstop = clock();
	printf("Total time:				%.3f\n", ((double)(stopstop - startstart) / CLOCKS_PER_SEC));
	return 0;
}

