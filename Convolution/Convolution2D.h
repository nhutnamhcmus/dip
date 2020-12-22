#pragma once

int Convolution2D(unsigned char** input, unsigned char* output, int width, int height, float** kernel, int widthKernel, int heightKernel);
int Convolution2D(int** input, int* output, int width, int height, float** kernel, int widthKernel, int heightKernel);

