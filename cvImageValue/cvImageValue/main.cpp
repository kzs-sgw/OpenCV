///////////////////////////////////////////////////////////////////////////////////////
/// *�����p����*
// jpg�̏ꍇ�Aphotoshop��"web�p�ɕۑ�"�ł͒l���򉻂��Ă����B
// png�̏ꍇ�A������Ɛݒ肵���l��\�������B
// --2013/8/14
// 
// 
///////////////////////////////////////////////////////////////////////////////////////


#include <opencv2\opencv.hpp>
#include "OpenCVheader.h"

void showValue(IplImage* img);
void jikkou();
void jikkou2();

// �摜�\��
int main(int argc, char* argv[]){
	
	jikkou();
	
	return 0;
}

//------------------------------------------------------------------------------------------------------------------
// �ȉ��֐���`
//------------------------------------------------------------------------------------------------------------------
void showValue(IplImage* img){
	for (int y = 0; y < img->height; y++){
		for (int x = 0; x < img->width; x++){
			// �����炭�|�C���^�ɃA�N�Z�X���Ă���B
			std::cout<< (int) *(uchar *)(img->imageData + y * img->widthStep + x * img->nChannels + 0) <<", ";
			std::cout<< (int) *(uchar *)(img->imageData + y * img->widthStep + x * img->nChannels + 1) <<", ";
			std::cout<< (int) *(uchar *)(img->imageData + y * img->widthStep + x * img->nChannels + 2) <<std::endl;
			
			/*
			std::cout<< (int) img->imageData[img->widthStep * y + x * 3    ] <<std::endl; // B
			std::cout<< (int) img->imageData[img->widthStep * y + x * 3 + 1] <<std::endl; // G
			std::cout<< (int) img->imageData[img->widthStep * y + x * 3 + 2] <<std::endl; // R
			*/
		}
	}
}

void jikkou(){
	IplImage* img;
	char imgfile[] = "lena.jpg";

	img = cvLoadImage(imgfile, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);

	// �摜�\���p�E�B���h�E����
	cvNamedWindow("lena", CV_WINDOW_AUTOSIZE);
	
	cvShowImage("lena", img);

	showValue(img);

	cvWaitKey(0);
	cvDestroyWindow("lena");
	cvReleaseImage(&img);
}

void jikkou2(){
	cv::Mat srcImg = cv::imread("red.jpg");

	for (int y = 0; y < srcImg.rows; y++){
		// �|�C���^�̎擾
		cv::Vec3b* ptr = srcImg.ptr<cv::Vec3b>(y);
		for (int x = 0; x < srcImg.cols; x++){

			ptr[x] = cv::Vec3b(255, 0, 0);
			cv::Vec3b bgr = ptr[x];
			printf("%d,%d,%d \n", bgr[0], bgr[1], bgr[2]);
		}
	}

	getchar();
	cvWaitKey(0);
}

















