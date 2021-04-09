#pragma once
#ifndef THRESHOLD_H
#define THRESHOLD_H
#include "cv_include.h"

//phân ngưỡng tĩnh
class StaticThreshold
{
	//ngưỡng dưới
	int _lowThreshold;
	//ngưỡng trên
	int _highThreshold;
public:

	int getLowThreshold();
	void setLowThreshold(const int&);

	int getHighThreshold();
	void setHighThreshold(const int&);


	/*
	Hàm áp dụng phân ngưỡng tĩnh
	- srcImage: ảnh input
	- dstImage: ảnh kết quả
	Hàm trả về
	1: nếu phân ngưỡng thành công
	0: nếu phân ngưỡng không thành công
	*/
	int Apply(const cv::Mat& srcImage, cv::Mat& dstImage);


	StaticThreshold();
	~StaticThreshold();
};


//phân ngưỡng cục bộ dựa vào trung bình
class AverageLocalThreshold
{
	//hệ số C
	int _C;

public:
	int getFactorC();
	void setFactorC(const int&);

	/*
	Hàm áp dụng phân ngưỡng cục bộ theo trung bình
	- srcImage: ảnh input
	- dstImage: ảnh kết quả
	- winSize: kích thước lân cận
	Hàm trả về
		1: nếu phân ngưỡng thành công
		0: nếu phân ngưỡng không thành công
	*/
	int Apply(const cv::Mat& srcImage, cv::Mat& dstImage, cv::Size winSize);


	AverageLocalThreshold();
	~AverageLocalThreshold();
};

//phân ngưỡng cục bộ dựa vào trung vị
class MedianLocalThreshold
{
	//hệ số C
	int _C;

public:
	int getFactorC();
	void setFactorC(const int&);
	/*
	Hàm áp dụng phân ngưỡng cục bộ dựa vào trung vị
	- srcImage: ảnh input
	- dstImage: ảnh kết quả
	- winSize: kích thước lân cận
	Hàm trả về
	1: nếu phân ngưỡng thành công
	0: nếu phân ngưỡng không thành công
	*/
	int Apply(const cv::Mat& srcImage, cv::Mat& dstImage, cv::Size winSize);


	MedianLocalThreshold();
	~MedianLocalThreshold();
};

//phân ngưỡng cục bộ dựa vào thuật toán Sauvola
class SauvolaLocalThreshold
{
	//hệ số r
	int _r;
	//hệ số k
	float _k;

public:
	int getFactorR();
	void setFactorR(const int&);
	float getFactorK();
	void setFactorK(const float&);
	/*
	Hàm áp dụng thuật toán Sauvola để phân ngưỡng
	- srcImage: ảnh input
	- dstImage: ảnh kết quả
	- winSize: kích thước lân cận
	Hàm trả về
	1: nếu phân ngưỡng thành công
	0: nếu phân ngưỡng không thành công
	*/
	int Apply(const cv::Mat& srcImage, cv::Mat& dstImage, cv::Size winSize);


	SauvolaLocalThreshold();
	~SauvolaLocalThreshold();
};



#endif // THRESHOLD_H