#pragma once
#include <iostream>

template<typename T>
void displayMatrix(T* arr, int size);

template<typename T>
void displayMatrix(T** arr, int width, int height);

template<typename T>
void displayMatrix(T* arr, int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << *(arr + i) << " ";
	}
	std::cout << "\n";
}



