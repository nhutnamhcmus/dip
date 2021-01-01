#include "CannyEdgeDetector.h"
#include "Converter.h"
#include "GaussianBlur.h"
#include "Kernel.h"

/*
	Hàm áp dụng thuật toán Canny để phát hiện biên cạnh
	- srcImage: ảnh input
	- dstImage: ảnh kết quả
	Hàm trả về
		1: nếu detect thành công
		0: nếu detect không thành công
*/
int CannyEdgeDetector::Apply(const cv::Mat& srcImage, cv::Mat& dstImage)
{
	// Checking steps
	// Kiểm trả ảnh đầu vào
	if (!srcImage.data) {
		// Chuyển đổi ảnh thất bại: in ra màn hình console tin nhắn
		std::cout << "[EXCEPTION] Error with input image data.\n";
		return 0; // Trả về 0
	}

	cv::Mat srcImageClone;
	if (srcImage.channels() == 3) {
		Converter converter;
		converter.Convert(srcImage, srcImageClone, 0);
	}
	else {
		srcImageClone = srcImage.clone();
	}


	// Chiều rộng của ảnh source
	int sourceWidth = srcImageClone.cols;

	// Chiều cao của ảnh source
	int sourceHeigth = srcImageClone.rows;

	// Số channels của ảnh source
	int sourceChannels = srcImageClone.channels();

	// Widthstep của ảnh source
	size_t sourceWidthStep = srcImageClone.step[0];

	// Khởi tạo ảnh đích
	dstImage = cv::Mat::zeros(srcImageClone.rows, srcImageClone.cols, CV_8UC1);

	// Chiều rộng của ảnh destination
	int destinationWidth = dstImage.cols;

	// Chiều cao của ảnh destination
	int destinationHeigth = dstImage.rows;

	// Số channels của ảnh destination
	int destinationChannels = dstImage.channels();

	// Widthstep của ảnh destination
	size_t destinationWidthStep = dstImage.step[0];

	uchar* ptrSrcData = srcImageClone.data;
	uchar* ptrDesData = dstImage.data;

	Kernel kernel;
	// 1) Smooth with Gaussian Filter
	GaussianBlur gaussianBlur;
	cv::Mat bluredImg;
	gaussianBlur.Blur(srcImageClone, bluredImg, 17, 17);

	// 2) Compute Horizontal/Vertical Gradient
	short* deltaX, * deltaY;             // store horizontal and vertical gradient
	deltaX = new short[sourceWidth * sourceHeigth];
	deltaY = new short[sourceWidth * sourceHeigth];
	// compute delta X
	// deltaX = f(x+1) - f(x-1)
	for (int y = 0; y < sourceHeigth; y++) {
		int t = y * sourceWidth;
		deltaX[t] = ptrSrcData[t + 1] - ptrSrcData[t];
		for (int x = 1; x < sourceWidth; x++) {
			t++;
			deltaX[t] = ptrSrcData[t + 1] - ptrSrcData[t - 1];
		}

		t++;
		deltaX[t] = ptrSrcData[t] - ptrSrcData[t - 1];
	}

	// compute delta Y
	// deltaY = f(y+1) - f(y-1)
	for (int y = 0; y < sourceHeigth; y++) {
		int t = y;
		deltaX[t] = ptrSrcData[t + sourceWidth] - ptrSrcData[t];
		for (int x = 1; x < sourceWidth; x++) {
			t += x;
			deltaY[t] = ptrSrcData[t + sourceWidth] - ptrSrcData[t - sourceWidth];
		}

		t += sourceWidth;
		deltaY[t] = ptrSrcData[t] - ptrSrcData[t - sourceWidth];
	}
	// 3) Compute Magnitude of gradient
	unsigned short* mag;                // store magnitude of gradient
	mag = new unsigned short[sourceWidth * sourceHeigth];
	int tmp = 0;
	for (int i = 0; i < sourceHeigth; ++i)
		for (int j = 0; j < sourceWidth; ++j, ++tmp)
			mag[tmp] = (unsigned short)(abs(deltaX[tmp]) + abs(deltaY[tmp]));
	// 4) Non-Maximal Suppression (NMS)


	// 5) Perform Hysteresis Threshold
    return 0;
}

int CannyEdgeDetector::getLowThreshold()
{
	return this->_lowThreshold;
}

int CannyEdgeDetector::getHighThreshold()
{
	return this->_highThreshold;
}

void CannyEdgeDetector::setLowThreshold(int lowThreshold)
{
	this->_lowThreshold = lowThreshold;
}

void CannyEdgeDetector::setHighThreshold(int highThreshold)
{
	this->_highThreshold = highThreshold;
}

std::pair<int, int> CannyEdgeDetector::getThreshold()
{
	return std::make_pair(this->getLowThreshold(), this->getHighThreshold());
}

CannyEdgeDetector::CannyEdgeDetector()
{
	this->_highThreshold = 0;
	this->_lowThreshold = 0;
}

CannyEdgeDetector::~CannyEdgeDetector()
{
}
