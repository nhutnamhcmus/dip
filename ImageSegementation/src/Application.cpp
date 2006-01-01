#include <iostream>
#include "Converter.h"

int main() {
	Converter converter;
	// Đọc ảnh (image) đầu vào)
	cv::Mat input_image = cv::imread("E:/lena.jpg", cv::IMREAD_ANYCOLOR);

	// Khởi tạo ảnh đầu ra
	cv::Mat output_image = cv::Mat(input_image.rows, input_image.cols, CV_8UC1);

	// Chuyển đổi
	converter.Convert(input_image, output_image, 0);

	// Dispay ảnh ra màn hình
	cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Input image", input_image);

	cv::namedWindow("Show result image RGB to GrayScale", cv::WINDOW_AUTOSIZE);
	cv::imshow("Show result image RGB to GrayScale", output_image);
	cv::waitKey(0);
	return 0;
}