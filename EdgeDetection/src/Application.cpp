#include <iostream>
#include <functional>
#include "Convolution.h"
#include "Kernel.h"


int main() {
	// std::cout << "Hello world" << std::endl;
	// [out = std::ref(std::cout << "Hello ")] (){out.get() << "C++"; }();

	Convolution convolution;
	Kernel kernel;
	convolution.SetKernel(kernel.getGaussianKernel(5, 5, 1, 2), 5, 5);
	// kernel.displayKernel(convolution.GetKernel());
	std::cout << convolution.GetKernel().size();
	cv::Mat inputImage = cv::imread("E:/lena.jpg", cv::IMREAD_ANYCOLOR);
	//cv::Mat inputImage2gray;
	//cv::cvtColor(inputImage, inputImage2gray, cv::COLOR_BGR2GRAY);
	cv::Mat  outputImage;
	// convolution.DoConvolutionColor(inputImage, outputImage);
	// blur.BlurImage(inputImage, outputImage, 17, 17, 0);
	convolution.Convole(inputImage, outputImage);
	cv::namedWindow("Origin image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Origin image", inputImage);
	//cv::namedWindow("Gray image", cv::WINDOW_AUTOSIZE);
	//cv::imshow("Gray image", inputImage2gray);
	cv::namedWindow("Output image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Output image", outputImage);
	cv::waitKey(0);

	cv::destroyAllWindows();
	return 0;
}