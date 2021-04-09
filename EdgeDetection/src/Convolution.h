#pragma once
#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "cv_include.h"

class Convolution
{
	std::vector<float> _kernel;// lưu giá trị của ma trận kernel dùng để tích chập
	int _kernelWidth;//chiều rộng kernel
	int _kernelHeight;//chiều dài kernel
public:
	// Hàm cắt image thành mảng màu đơn
	// 	 	sourceImage: ảnh input
	//		destinationImage : ảnh output
	//		channel: là channel được chọn để cắt
	//		0: blue
	//		1: green
	//		2: red
	int separateColorImg(const cv::Mat& sourceImage, cv::Mat& destinationImage, int channel);


	// Hàm gộp image từ các ma trận màu đơn blue, green red
	// 	 	sourceImage: ảnh input
	//		blueLayer : ma trận màu blue
	//		greenLayer: ma trận màu green
	//		redLayer: ma trận màu rd
	int mergeColorImg(cv::Mat& sourceImage, cv::Mat& blueLayer, cv::Mat& greenLayer, cv::Mat& redLayer);

public:
	//trả về kernel 
	std::vector<float> GetKernel();
	//set kernel, chiều rộng, chiều dài kernel phải là số lẻ
	void SetKernel(std::vector<float> kernel, int kWidth, int kHeight);

	/*
	Hàm tính convolution của 1 ảnh xám với kernel được xác định trước
	sourceImage: ảnh input
	destinationImage: ảnh output
	Hàm trả về
	0: nếu tính thành công
	1: nếu tính thất bại (không đọc được ảnh input,...)
	*/
	int DoConvolution(const cv::Mat& sourceImage, cv::Mat& destinationImage);

	/*
	Hàm tính convolution của 1 ảnh màu với kernel được xác định trước
	sourceImage: ảnh input
	destinationImage: ảnh output
	Hàm trả về
	0: nếu tính thành công
	1: nếu tính thất bại (không đọc được ảnh input,...)
	*/
	int DoConvolutionColor(const cv::Mat& sourceImage, cv::Mat& destinationImage);


	int Convole(const cv::Mat& sourceImage, cv::Mat& destinationImage);
	Convolution();
	~Convolution();
};

#endif // CONVOLUTION_H