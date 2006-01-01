#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <functional>
#include <string>
#include <iostream>
#include "cv_include.h"

class Utils {
public:

	static void log(std::string msg) {
		[output = std::ref(std::cout << msg)] (){output.get() << "\n"; }();
	}

	static int __str_cmp__(const char* string_1, const char* string_2)
	{
		while (*string_1)
		{
			// if characters differ or end of second string is reached
			if (*string_1 != *string_2)
				break;

			// move to next pair of characters
			string_1++;
			string_2++;
		}

		// return the ASCII difference after converting char* to unsigned char*
		return *(const unsigned char*)string_1 - *(const unsigned char*)string_2 == 0 ? 1 : 0;
	}

	static int saving_image(cv::Mat input_image, std::string image_name) {
		return cv::imwrite(image_name, input_image);
	}
};

#endif // UTILS_H