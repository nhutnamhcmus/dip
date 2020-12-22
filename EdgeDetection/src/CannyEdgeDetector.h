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

	int getLowThreshold();
	int getHighThreshold();


	void setLowThreshold(int lowThreshold);
	void setHighThreshold(int highThreshold);

	std::pair<int, int> getThreshold();
	CannyEdgeDetector();
	~CannyEdgeDetector();
};

#endif  // CANNY_EDGE_DETECTOR_H


/*
Canny Edge Detection
1. Smooth with gaussian filter.
2. Compute h/v gradients.
3. Compute magnitude of gradient.
4. Perform Non-Maximal Suppression.
5. Perform Hysteresis Threshold.
*/