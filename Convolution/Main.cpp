#include <iostream>
#include "Convolution1D.h"
#include "Convolution2D.h"

int main() {

	int x[3] = { 3, 4, 5 };
	int h[2] = { 2, 1 };
	int y[4] = { 0, 0, 0, 0};

	convolve1D(x, y, 3, h, 2);

	for (int i = 0; i < 3; i++) {
		std::cout << y[i] << " ";
	}
	std::cout << "\n";

	int input[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int kernel[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };
	int output[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };


	Convolution2D(input, output, 3, 3, kernel, 3, 3);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << output[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}