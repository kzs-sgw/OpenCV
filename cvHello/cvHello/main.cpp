#include <opencv2\opencv.hpp>
#include "OpenCVheader.h"

// �摜�\��
int main(int argc, char* argv[]){
	IplImage* img;
	char imgfile[] = "lena.jpg";

	img = cvLoadImage(imgfile, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);

	// �摜�\���p�E�B���h�E����
	cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);
	
	cvShowImage("lena", img);

	cvWaitKey(0);
	cvDestroyWindow("lena");
	cvReleaseImage(&img);

	return 0;
}