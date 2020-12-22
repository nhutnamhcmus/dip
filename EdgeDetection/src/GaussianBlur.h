#pragma once

#include "cv_include.h"

class GaussianBlur {
public:
	int Blur(const cv::Mat& sourceImage, cv::Mat& destinationImage, int kWidth, int kHeight);
	GaussianBlur();
	~GaussianBlur();
};