// STL include
#include <iostream>

// Exercises class
#include "ColorTransformer.h"

// Utils
#include "Utils.h"


int main(int argc, char* argv[]) {

	ColorTransformer color_transfer;
	Converter converter;

	if (Utils::__str_cmp__(argv[1], "--rgb2gray")) {
		// --rgb2gray
		// code 
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

		// Khởi tạo ảnh đầu ra
		cv::Mat output_image = cv::Mat(input_image.rows, input_image.cols, CV_8UC1);

		// Chuyển đổi
		converter.Convert(input_image, output_image, 0);

		// Dispay ảnh ra màn hình
		cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Input image", input_image);

		cv::namedWindow("Show result image RGB to GrayScale", cv::WINDOW_AUTOSIZE);
		cv::imshow("Show result image RGB to GrayScale", output_image);
		cv::waitKey(0);
	}
	else if (Utils::__str_cmp__(argv[1], "--gray2rgb")) {
		// --gray2rgb
		// code 
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

		// Khởi tạo ảnh đầu ra
		cv::Mat output_image = cv::Mat(input_image.rows, input_image.cols, CV_8UC3);

		// Chuyển đổi
		converter.Convert(input_image, output_image, 1);

		// Dispay ảnh ra màn hình
		cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Input image", input_image);

		cv::namedWindow("Show result image GrayScale to RGB", cv::WINDOW_AUTOSIZE);
		cv::imshow("Show result image GrayScale to RGB", output_image);
		cv::waitKey(0);
	}
	else if (Utils::__str_cmp__(argv[1], "--rgb2hsv")) {
		// --rgb2hsv
		// code 
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

		// Khởi tạo ảnh đầu ra
		cv::Mat output_image = cv::Mat(input_image.rows, input_image.cols, CV_8UC3);

		// Chuyển đổi
		converter.Convert(input_image, output_image, 2);

		// Dispay ảnh ra màn hình
		cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Input image", input_image);

		cv::namedWindow("Show result image RGB to HSV", cv::WINDOW_AUTOSIZE);
		cv::imshow("Show result image RGB to HSV", output_image);
		cv::waitKey(0);
	}
	else if (Utils::__str_cmp__(argv[1], "--hsv2rgb")) {
		// --hsv2rgb
		// code 
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

		// Khởi tạo ảnh đầu ra
		cv::Mat output_image = cv::Mat(input_image.rows, input_image.cols, CV_8UC3);

		// Chuyển đổi
		converter.Convert(input_image, output_image, 3);

		// Dispay ảnh ra màn hình
		cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Input image", input_image);

		cv::namedWindow("Show result image HSV to RGB", cv::WINDOW_AUTOSIZE);
		cv::imshow("Show result image HSV to RGB", output_image);
		cv::waitKey(0);
	}
	else if (Utils::__str_cmp__(argv[1], "--bright")) {
		// --bright
		// code 
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

		// Khởi tạo ảnh đầu ra
		cv::Mat output_image = input_image.clone();

		// Thay đổi độ sáng
		if (argv[3] == nullptr) {
			std::cout << "Exception: No brightness input.\n";
			return 0;
		}

		else {
			color_transfer.ChangeBrighness(input_image, output_image, atoi(argv[3]));

			// Dispay ảnh ra màn hình
			cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
			cv::imshow("Input image", input_image);

			cv::namedWindow("Show result after change birghtness", cv::WINDOW_AUTOSIZE);
			cv::imshow("Show result after change birghtness", output_image);
			cv::waitKey(0);
		}
	
	}
	else if (Utils::__str_cmp__(argv[1], "--contrast")) {
		// --contrast
		// code
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

		// Khởi tạo ảnh đầu ra
		cv::Mat output_image = input_image.clone();

		// Thay đổi độ sáng
		if (argv[3] == nullptr) {
			std::cout << "Exception: No contrast input.\n";
			return 0;
		}

		else {
			color_transfer.ChangeContrast(input_image, output_image, atoi(argv[3]));

			// Dispay ảnh ra màn hình
			cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
			cv::imshow("Input image", input_image);

			cv::namedWindow("Show result after change contrast", cv::WINDOW_AUTOSIZE);
			cv::imshow("Show result after change contrast", output_image);
			cv::waitKey(0);
		}
	}
	else if (Utils::__str_cmp__(argv[1], "--hist")) {
		// --hist
		// code
		

	}
	else if (Utils::__str_cmp__(argv[1], "--equalhist")) {
		// --equalhist
		// code
		// Đọc ảnh (image) đầu vào)
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);
		// Khởi tạo ảnh đầu ra
		cv::Mat output_image;

		color_transfer.HistogramEqualization(input_image, output_image);

		// Dispay ảnh ra màn hình
		cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Input image", input_image);

		cv::namedWindow("Show result", cv::WINDOW_AUTOSIZE);
		cv::imshow("Show result", output_image);
		cv::waitKey(0);
	}
	else if (Utils::__str_cmp__(argv[1], "--drawhist")) {
		// --drawhist
		// code
		// Đọc ảnh (image) đầu vào)
		cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

		// Tính histogram của ảnh
		cv::Mat histogram_matrix_input_image;
		color_transfer.CalcHistogram(input_image, histogram_matrix_input_image);

		cv::Mat histogram_input_image;
		color_transfer.DrawHistogram(histogram_matrix_input_image, histogram_input_image);

		// Dispay ảnh ra màn hình
		cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Input image", input_image);

		cv::namedWindow("Show histogram", cv::WINDOW_AUTOSIZE);
		cv::imshow("Show histogram", histogram_input_image);
		cv::waitKey(0);
	}
	else if (Utils::__str_cmp__(argv[1], "--compare")) {
		// --compare
		// code 
	}
	else if (Utils::__str_cmp__(argv[1], "--help") || Utils::__str_cmp__(argv[1], "--h")) {
		std::cout << "Usage:  [Program name].exe [command] [input path] [command arguments]\n\n"
			<< "Options command & command arguments:\n"
			"--rgb2gray\t[no command arguments]\t\t Convert the image's color space from RGB to GrayScale.\n"
			"--gray2rgb\t[no command arguments]\t\t Convert the image's color space from GrayScale to RGB.\n"
			"--rgb2hsv\t[no command arguments]\t\t Convert the image's color space from RGB to HSV.\n"
			"--hsv2rgb\t[no command arguments]\t\t Convert the image's color space from HSV to RGB.\n"
			"--bright\t[b]\t\t\t\t Change image's brightness with intensity equal to [b] argument.\n"
			"--contrast\t[c]\t\t\t\t Change image's contrast with intensity equal to [c] argument.\n"
			"--hist\t\t[no command arguments]\t\t Calculate the histogram of RGB image, GrayScale image.\n"
			"--equalhist\t[no command arguments]\t\t Equilibrate the histogram of RGB image, GrayScale image.\n"
			"--drawhist\t[no command arguments]\t\t Draw the histogram of RGB image, GrayScale image.\n"
			"--compare\t[no command arguments]\t\t Compare two image based on the histogram of them.\n"
			"\n\nDepartment of Computer Science, University of Science\nAuthor: Nhut-Nam Le"
			;
	}
	else if (Utils::__str_cmp__(argv[1], "--testhsv")) {
	// Đọc ảnh (image) đầu vào)
	cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_ANYCOLOR);

	cv::Mat temp;
	// Tính histogram của ảnh
	cv::Mat output_image;
	converter.Convert(input_image, temp, 2);
	converter.Convert(temp, output_image, 3);
	// Dispay ảnh ra màn hình
	cv::namedWindow("Input image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Input image", input_image);

	cv::namedWindow("RGB -> HSV -> RGB", cv::WINDOW_AUTOSIZE);
	cv::imshow("RGB -> HSV -> RGB", output_image);
	cv::waitKey(0);
	}
	//std::cin.get();
	return 0;
}