#include <iostream>
#include "Convolution1D.h"

int main() {

	int x[3] = { 3, 4, 5 };
	int h[2] = { 2, 1 };
	int y[4] = { 0, 0, 0, 0};

	convolve1D(x, y, 3, h, 2);

	for (int i = 0; i < 3; i++) {
		std::cout << y[i] << " ";
	}
	std::cout << "\n";

	return 0;
}