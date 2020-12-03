#pragma once
#ifndef CANNY_EDGE_DETECTOR_H
#define CANNY_EDGE_DETECTOR_H
#include "cv_include.h"

class CannyEdgeDetector
{
	//ngưỡng dưới
	int _lowThreshold;
	//ngưỡng trên
	int _highThreshold;

public:
	/*
		Hàm áp dụng thuật toán Canny để phát hiện biên cạnh
		- srcImage: ảnh input
		- dstImage: ảnh kết quả
		Hàm trả về
			1: nếu detect thành công
			0: nếu detect không thành công
	*/
	int Apply(const cv::Mat& srcImage, cv::Mat& dstImage);

	CannyEdgeDetector();
	~CannyEdgeDetector();
};

#endif  // CANNY_EDGE_DETECTOR_H