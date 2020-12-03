#include "ComplexImage.h"

ComplexImage::ComplexImage()
{
}

ComplexImage::~ComplexImage()
{
}

ComplexImage ComplexImage::FromOpenCVMat(cv::Mat image)
{
	return ComplexImage();
}

cv::Mat ComplexImage::ToOpenCVMat()
{
	return cv::Mat();
}

void ComplexImage::ForwardFourierTransform()
{
}

void ComplexImage::BackwardFourierTransform()
{
}
