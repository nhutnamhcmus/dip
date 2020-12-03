#pragma once
#ifndef KMEAN_H
#define KMEAN_H
#include "cv_include.h"

class Kmean
{
	//số cụm K
	int _numClusters;
public:
	/*
	Hàm áp dụng thuật toán Kmeans để phân đoạn ảnh
	- srcImage: ảnh input
	- dstImage: ảnh kết quả
	Hàm trả về
	1: nếu phân đoạn thành công
	0: nếu phân đoạn không thành công
	*/

	int Apply(const cv::Mat& srcImage, cv::Mat& dstImage);

	Kmean();
	~Kmean();
};

#endif // KMEAN_H