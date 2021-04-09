#include "Convolution1D.h"

int convolve1D(float* input, float* output, int size, float* kernel, int kernelSize)
{
	if (!input || !kernel || !output) {
		return 1;
	}

	if (size <= 0 || kernelSize <= 0) {
		return 1;
	}

	for (int i = kernelSize - 1; i < size; i++) {
		output[i] = 0;
		for (int j = i, k = 0; k < kernelSize; j--, k++) {
			output[i] += input[j] * kernel[k];
		}
	}

	for (int i = 0; i < kernelSize - 1; i++) {
		output[i] = 0;
		for (int j = i, k = 0; j >= 0; j--, k++) {
			output[i] += input[j] * kernel[k];
		}
	}

	return 0;
}

int convolve1D(double* input, double* output, int size, double* kernel, int kernelSize)
{
	if (!input || !kernel || !output) {
		return 1;
	}

	if (size <= 0 || kernelSize <= 0) {
		return 1;
	}

	for (int i = kernelSize - 1; i < size; i++) {
		output[i] = 0;
		for (int j = i, k = 0; k < kernelSize; j--, k++) {
			output[i] += input[j] * kernel[k];
		}
	}

	for (int i = 0; i < kernelSize - 1; i++) {
		output[i] = 0;
		for (int j = i, k = 0; j >= 0; j--, k++) {
			output[i] += input[j] * kernel[k];
		}
	}

	return 0;
}

int convolve1D(int* input, int* output, int size, int* kernel, int kernelSize)
{
	if (!input || !kernel || !output) {
		return 1;
	}

	if (size <= 0 || kernelSize <= 0) {
		return 1;
	}


	/*
	for (int i = 0; i < size; i++)
		output[i] = 0;
		for (int j = 0; j < kernelSize; j++)
			if (i - j >= 0)
				output[i] += input[i - j] * kernel[j];
				
	*/

	for (int i = kernelSize - 1; i < size; i++) {
		output[i] = 0;
		for (int j = i, k = 0; k < kernelSize; j--, k++) {
			output[i] += input[j] * kernel[k];
		}
	}

	for (int i = 0; i < kernelSize - 1; i++) {
		output[i] = 0;
		for (int j = i, k = 0; j >= 0; j--, k++) {
			output[i] += input[j] * kernel[k];	
		}
	}

	return 0;
}
