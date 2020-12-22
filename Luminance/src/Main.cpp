﻿// CV Include
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>


// Luminace = 0.3086 * Red + 0.6094 * Green + 0.0820 * Blue
// Luminace = 0.299 * Red + 0.587 * Green + 0.114 * Blue
int luminance(cv::Mat& sourceImage, cv::Mat& destinationImage) {
	// Kiểm tra ảnh đầu vào
	if (sourceImage.data == NULL) {
		return 1;
	}

	// Chiều rộng của ảnh
	int width = sourceImage.cols;
	// Chiều cao của ảnh
	int heigth = sourceImage.rows;
	// Số channels của ảnh source
	int srcChannels = sourceImage.channels();
	// Tạo ảnh destination
	destinationImage = cv::Mat(heigth, width, CV_8UC1);
	// Số channels của ảnh đích
	int dstChannels = destinationImage.channels();
	// Witdth step của ảnh source
	size_t srcWidthStep = sourceImage.step[0];
	// Witdth step của ảnh destination
	size_t dstWidthStep = destinationImage.step[0];
	// Con trỏ vùng data ảnh source
	uchar* pSrcData = sourceImage.data;
	// Con trỏ vùng data ảnh destination
	uchar* pDstData = destinationImage.data;

	for (int y = 0; y < heigth; y++, pSrcData += srcWidthStep, pDstData += dstWidthStep) {
		uchar* pSrcRow = pSrcData;
		uchar* pDstRow = pDstData;

		for (int x = 0; x < width; x++, pSrcRow += srcChannels, pDstRow += dstChannels) {
			uchar blue = pSrcRow[0];
			uchar green = pSrcRow[1];
			uchar red = pSrcRow[2];
			int value = 0;
			value += blue;
			value += ((green << 2) + green);
			value += (red << 1);

			value >>= 3;

			// pDstRow[0] = (unsigned char)(0.299 * pSrcRow[2] + 0.587 * pSrcRow[1] + 0.114 * pSrcRow[0] + 0.5);

			pDstRow[0] = (uchar)value;
		}
	}

	return 0;
}

int main() {
	cv::Mat inputImage = cv::imread("E:\\lena.jpg", cv::IMREAD_COLOR);
	cv::Mat outputImage;

	luminance(inputImage, outputImage);
	cv::imshow("Show Input Image", inputImage);
	cv::imshow("Show Ouput Image", outputImage);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}