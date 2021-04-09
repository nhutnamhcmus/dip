#pragma once
#include <cmath>

template<size_t N>
int Convolution2D(int input[][N], int output[][N], int width, int height, int kernel[][N], int widthKernel, int heightKernel)
{
	if (!input || !kernel || !output) {
		return 1;
	}

	if (width <= 0 || widthKernel <= 0) {
		return 1;
	}

	if (height <= 0 || heightKernel <= 0) {
		return 1;
	}

	int kernelCenterX = widthKernel >> 1;
	int kernelCenterY = heightKernel >> 1;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			float sum = 0;

			for (int m = 0; m < heightKernel; m++) {
				int mm = heightKernel - 1 - m;
				for (int n = 0; n < widthKernel; n++) {
					int nn = widthKernel - 1 - n;
					int rowIndex = y + m - kernelCenterY;
					int colIndex = x + n - kernelCenterX;

					if (rowIndex >= 0 && rowIndex < height && colIndex >= 0 && colIndex < width)
						sum += input[rowIndex][colIndex] * kernel[mm][nn];
				}
			}

			output[y][x] = (unsigned char)((float)fabs(sum) + 0.5f);
		}
	}

	return 0;
}


