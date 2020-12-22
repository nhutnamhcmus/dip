#include "GaussianBlur.h"
#include "Kernel.h"
#include "Convolution.h"

int GaussianBlur::Blur(const cv::Mat& sourceImage, cv::Mat& destinationImage, int kWidth, int kHeight)
{
	// Kiểm trả ảnh đầu vào
	if (!sourceImage.data) {
		std::cout << "[EXCEPTION] Error with input image.\n";
		return 1;
	}

	if (kWidth < 0) {
		std::cout << "[EXCEPTION] kWidth negative.\n";
		return 1;
	}

	if (kHeight < 0) {
		std::cout << "[EXCEPTION] kHeigh negative.\n";
		return 1;
	}

	// Chiều rộng của ảnh source
	int widthSourceImage = sourceImage.cols;

	// Chiều cao của ảnh source
	int heigthSourceImage = sourceImage.rows;

	// Số channels của ảnh source
	int sourceImageChannels = sourceImage.channels();

	// Widthstep của ảnh source
	size_t sourceWidthStep = sourceImage.step[0];

	int mode = 0;


	// Ảnh 1 kênh màu
	if (sourceImageChannels == 1) {
		// std::cout << "[EXCEPTION] Error occurs with source image channels.\n"
		destinationImage = cv::Mat(heigthSourceImage, widthSourceImage, CV_8UC1, cv::Scalar(0));
		std::cout << "Gray\n";
		mode = 1;
	}

	// Ảnh 3 kênh màu
	else if (sourceImageChannels == 3) {
		destinationImage = cv::Mat(heigthSourceImage, widthSourceImage, CV_8UC3, cv::Scalar(0));
		std::cout << "Color\n";
		mode = 3;
	}

	else {
		std::cout << "[EXCEPTION] Error occurs with source image channels.\n";
		return 1;
	}

	std::cout << "Blur method starting: Gaussian\n";
	Convolution convolution;
	std::vector<float> gaussian_kernel;
	Kernel kernel;
	std::cout << "Calculating kernel...\n";
	gaussian_kernel = kernel.getGaussianKernel(kHeight, kWidth, DEFAULT_SIGMA_X, DEFAULT_SIGMA_Y);
	std::cout << "Set kernel...\n";
	convolution.SetKernel(gaussian_kernel, kWidth, kHeight);
	if (mode == 1) {
		convolution.DoConvolution(sourceImage, destinationImage);
		std::cout << "End convolution...\n";
	}

	if (mode == 3) {
		convolution.DoConvolutionColor(sourceImage, destinationImage);
		std::cout << "End convolution...\n";
	}
}

GaussianBlur::GaussianBlur() = default;

GaussianBlur::~GaussianBlur() = default;