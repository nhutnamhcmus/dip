#pragma once
#ifndef KERNEL_H
#define KERNEL_H

#include "cv_include.h"

const int DEFAULT_SIGMA_X = 1;
const int DEFAULT_SIGMA_Y = 2;


class Kernel {
public:
	void displayKernel(const std::vector<float>& v);
	std::vector<float> getGaussianKernel(int rows, int cols, double sigmax, double sigmay);
	std::vector<float> getSobelKernelX();
	std::vector<float> getSobelKernelY();

	std::vector<float> getPrewittKernelX();
	std::vector<float> getPrewittKernelY();

	std::vector<float> getLaplaceKernel();
	Kernel();
	~Kernel();
};

#endif // KERNEL_H