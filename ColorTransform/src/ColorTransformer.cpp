#include "ColorTransformer.h"

/*
Hàm nhận vào một ảnh, thay đổi độ sáng của ảnh này và lưu kết quả vào ảnh mới
Tham số:
	sourceImage	: ảnh ban đầu
	destinationImage: ảnh kết quả
	b	: giá trị số nguyên dùng để thay đổi độ sáng của ảnh
Hàm trả về:
	1: Nếu thành công thì trả về ảnh kết quả (ảnh gốc vẫn giữ nguyên giá trị)
	0: Nếu không tạo được ảnh kết quả hoặc ảnh input không tồn tại
*/
int ColorTransformer::ChangeBrighness(const cv::Mat& sourceImage, cv::Mat& destinationImage, short b)
{
	// Thay đổi độ sáng (Brightness): g(x, y) = f(x, y) + b

	// Kiểm trả ảnh đầu vào
	if (!sourceImage.data) {
		// Chuyển đổi ảnh thất bại: in ra màn hình console tin nhắn
		std::cout << "[EXCEPTION] Error with input image.\n";
		return 0; // Trả về 0
	}

	if (b < 0) {
		// Chuyển đổi ảnh thất bại: in ra màn hình console tin nhắn
		std::cout << "[EXCEPTION] Input brightness must be positive.\n";
		return 0;
	}

	if (b == 0) {
		// Chuyển đổi ảnh thành công: in ra màn hình console tin nhắn
		std::cout << "[LOG]: Nothing has change.\n";
		return 1;
	}

	// Chiều rộng của ảnh source
	int width = sourceImage.cols;

	// Chiều cao của ảnh source
	int heigth = sourceImage.rows;

	// Số channels của ảnh source
	int sourceChannels = sourceImage.channels();

	// Source Image là ảnh RGB
	if (sourceChannels == 3) {
		// Khởi tạo ảnh destination với thông số height, width
		destinationImage = cv::Mat(heigth, width, CV_8UC3, cv::Scalar(0));

		// Số channels của ảnh destination
		int destinationChannels = destinationImage.channels();

		// Widthstep của ảnh source
		size_t sourceWidthStep = sourceImage.step[0];

		// Widthstep của ảnh destination
		size_t destinationWidthStep = destinationImage.step[0];

		// Con trỏ quản lý vùng nhớ data ảnh source
		uchar* ptrSourceData = sourceImage.data;

		// Con trỏ quản lý vùng nhớ data ảnh destination
		uchar* ptrDestinationData = destinationImage.data;

		for (int y = 0; y < heigth; y++, ptrSourceData += sourceWidthStep, ptrDestinationData += destinationWidthStep) {
			uchar* ptrSourceRow = ptrSourceData;
			uchar* ptrDestinationRow = ptrDestinationData;

			for (int x = 0; x < width; x++, ptrSourceRow += sourceChannels, ptrDestinationRow += destinationChannels) {
				// Lấy giá trị kênh màu Blue của ảnh source
				uchar blue = ptrSourceRow[0];

				// Lấy giá trị kênh màu Green của ảnh source
				uchar green = ptrSourceRow[1];

				// Lấy giá trị kênh màu Red của ảnh source
				uchar red = ptrSourceRow[2];

				ptrDestinationRow[0] = cv::saturate_cast<uchar>(blue + b);

				ptrDestinationRow[1] = cv::saturate_cast<uchar>(green + b);

				ptrDestinationRow[2] = cv::saturate_cast<uchar>(red + b);
			}
		}
	}

	// Source Image là ảnh GrayScale
	else if (sourceChannels == 1) {

		// Khởi tạo ảnh destination với thông số height, width
		destinationImage = cv::Mat(heigth, width, CV_8UC1, cv::Scalar(0));

		// Số channels của ảnh destination
		int destinationChannels = destinationImage.channels();

		// Widthstep của ảnh source
		size_t sourceWidthStep = sourceImage.step[0];

		// Widthstep của ảnh destination
		size_t destinationWidthStep = destinationImage.step[0];

		// Con trỏ quản lý vùng nhớ data ảnh source
		uchar* ptrSourceData = sourceImage.data;

		// Con trỏ quản lý vùng nhớ data ảnh destination
		uchar* ptrDestinationData = destinationImage.data;

		// For each line
		for (int y = 0; y < heigth; y++, ptrSourceData += sourceWidthStep, ptrDestinationData += destinationWidthStep) {
			uchar* ptrSourceRow = ptrSourceData;
			uchar* ptrDestinationRow = ptrDestinationData;

			for (int x = 0; x < width; x++, ptrSourceRow += sourceChannels, ptrDestinationRow += destinationChannels) {

				uchar gray = ptrSourceRow[0] + b;
				ptrDestinationRow[0] = gray;
			}
		}
	}

	// Lưu ảnh lại
	Utils::saving_image(destinationImage, "result_after_change_bightness.jpg");

	// Trả về 1: Chuyển đổi ảnh thành công
	return 1;
}

/*
Hàm nhận vào một ảnh, thay đổi độ tương phản của ảnh này và lưu kết quả vào ảnh mới
Tham số:
	sourceImage : ảnh ban đầu
	destinationImage : ảnh kết quả
	c: giá trị số thực dùng để thay đổi độ tương phản của ảnh
Hàm trả về:
	1: Nếu thành công thì trả về ảnh kết quả (ảnh gốc vẫn giữ nguyên giá trị)
	0: Nếu không tạo được ảnh kết quả hoặc ảnh input không tồn tại
*/
int ColorTransformer::ChangeContrast(const cv::Mat& sourceImage, cv::Mat& destinationImage, float c)
{
	// Thay đổi độ tương phản (Contrast): g(x, y) = c.f(x, y)

	// Kiểm trả ảnh đầu vào
	if (!sourceImage.data) {
		// Chuyển đổi ảnh thất bại: in ra màn hình console tin nhắn
		std::cout << "[EXCEPTION] Error with input image.\n";
		return 0; // Trả về 0
	}

	if (c < 0) {
		// Chuyển đổi ảnh thất bại: in ra màn hình console tin nhắn
		std::cout << "[EXCEPTION] Input contrast value must be positive.\n";
		return 0;
	}

	if (c == 0) {
		// Chuyển đổi ảnh thành công: in ra màn hình console tin nhắn
		std::cout << "[LOG]: Nothing has change.\n";
		return 1;
	}

	// Chiều rộng của ảnh source
	int width = sourceImage.cols;

	// Chiều cao của ảnh source
	int heigth = sourceImage.rows;

	// Số channels của ảnh source
	int sourceChannels = sourceImage.channels();

	// Source Image là ảnh RGB
	if (sourceChannels == 3) {
		// Khởi tạo ảnh destination với thông số height, width
		destinationImage = cv::Mat(heigth, width, CV_8UC3, cv::Scalar(0));

		// Số channels của ảnh destination
		int destinationChannels = destinationImage.channels();

		// Widthstep của ảnh source
		size_t sourceWidthStep = sourceImage.step[0];

		// Widthstep của ảnh destination
		size_t destinationWidthStep = destinationImage.step[0];

		// Con trỏ quản lý vùng nhớ data ảnh source
		uchar* ptrSourceData = sourceImage.data;

		// Con trỏ quản lý vùng nhớ data ảnh destination
		uchar* ptrDestinationData = destinationImage.data;

		for (int y = 0; y < heigth; y++, ptrSourceData += sourceWidthStep, ptrDestinationData += destinationWidthStep) {
			uchar* ptrSourceRow = ptrSourceData;
			uchar* ptrDestinationRow = ptrDestinationData;

			for (int x = 0; x < width; x++, ptrSourceRow += sourceChannels, ptrDestinationRow += destinationChannels) {
				// Lấy giá trị kênh màu Blue của ảnh source
				uchar blue = ptrSourceRow[0];

				// Lấy giá trị kênh màu Green của ảnh source
				uchar green = ptrSourceRow[1];

				// Lấy giá trị kênh màu Red của ảnh source
				uchar red = ptrSourceRow[2];

				ptrDestinationRow[0] = cv::saturate_cast<uchar>(blue * c);

				ptrDestinationRow[1] = cv::saturate_cast<uchar>(green * c);

				ptrDestinationRow[2] = cv::saturate_cast<uchar>(red * c);
			}
		}
	}

	// Source Image là ảnh GrayScale
	else if (sourceChannels == 1) {
		// Khởi tạo ảnh destination với thông số height, width
		destinationImage = cv::Mat(heigth, width, CV_8UC1, cv::Scalar(0));

		// Số channels của ảnh destination
		int destinationChannels = destinationImage.channels();

		// Widthstep của ảnh source
		size_t sourceWidthStep = sourceImage.step[0];

		// Widthstep của ảnh destination
		size_t destinationWidthStep = destinationImage.step[0];

		// Con trỏ quản lý vùng nhớ data ảnh source
		uchar* ptrSourceData = sourceImage.data;

		// Con trỏ quản lý vùng nhớ data ảnh destination
		uchar* ptrDestinationData = destinationImage.data;

		// For each line
		for (int y = 0; y < heigth; y++, ptrSourceData += sourceWidthStep, ptrDestinationData += destinationWidthStep) {
			uchar* ptrSourceRow = ptrSourceData;
			uchar* ptrDestinationRow = ptrDestinationData;

			for (int x = 0; x < width; x++, ptrSourceRow += sourceChannels, ptrDestinationRow += destinationChannels) {

				ptrDestinationRow[0] = cv::saturate_cast<uchar>(ptrSourceRow[0] * c);
			}
		}
	}

	// Lưu ảnh lại
	Utils::saving_image(destinationImage, "result_after_change_contrast.jpg");

	// Trả về 1: Chuyển đổi ảnh thành công
	return 1;
}

/*
Hàm tính lược đồ màu tổng quát cho ảnh bất kỳ
Tham số:
	sourceImage : ảnh ban đầu
	histMatrix : ma trận histogram (nChannels x 256), mỗi dòng là 1 mảng 256 phần tử histogram của từng kênh màu
Hàm trả về:
	1: Nếu thành công thì trả về matrix kết quả (ảnh gốc vẫn giữ nguyên giá trị)
	0: Nếu không tính được histogram hoặc ảnh input không tồn tại
*/
int ColorTransformer::CalcHistogram(const cv::Mat& sourceImage, cv::Mat& histMatrix)
{
	// Kiểm tra ảnh đầu vào
	if (!sourceImage.data) {
		std::cout << "Exception: Can not calculate the histogram of image.\n";
		return 0;
	}

	// Chiều rộng của ảnh source
	int width = sourceImage.cols;

	// Chiều cao của ảnh source
	int heigth = sourceImage.rows;

	// Số channels của ảnh source
	int sourceChannels = sourceImage.channels();

	// Nếu ảnh đầu vào là ảnh GrayScale
	if (sourceImage.channels() == 1) {
		// Khởi tạo ảnh histogram matrix với thông số height = 1, width = 256
		histMatrix = cv::Mat(1, 256, CV_32S, cv::Scalar(0));

		// Số channels của ảnh destination
		int histMatrixChannels = histMatrix.channels();

		// Widthstep của ảnh source
		size_t sourceWidthStep = sourceImage.step[0];

		// Widthstep của ảnh destination
		size_t histMatrixWidthStep = histMatrix.step[0];

		// Con trỏ quản lý vùng nhớ data ảnh source
		uchar* ptrSourceData = sourceImage.data;

		// Con trỏ quản lý vùng nhớ data ảnh destination
		int* ptrHistMatrixData = histMatrix.ptr<int>(0);

		for (int y = 0; y < heigth; y++, ptrSourceData += sourceWidthStep) {
			uchar* ptrSourceRow = ptrSourceData;
			for (int x = 0; x < width; x++, ptrSourceRow += sourceChannels) {
				
				uchar gray = ptrSourceRow[0];
				ptrHistMatrixData[gray] += 1;
			}
		}

		int sum = 0;
		for (int i = 0; i < 256; i++) {
			sum += ptrHistMatrixData[i];
		}

		std::cout << sum << std::endl;

		Utils::saving_image(histMatrix, "result_histogram_matrix_gray_scale.jpg");

		std::cout << "Success: Calculated the histogram of image.\n";
		return 1;
	}

	// Nếu ảnh đầu vào là ảnh RGB
	else if (sourceImage.channels() == 3) {

		
		// Khởi tạo ảnh histogram matrix với thông số height = 3, width = 256
		histMatrix = cv::Mat(3, 256, CV_32S, cv::Scalar(0));
		// std::vector<std::vector<int>> histVector(3, std::vector<int>(256, 0));

		// Số channels của ảnh destination
		int histMatrixChannels = histMatrix.channels();

		// Widthstep của ảnh source
		size_t sourceWidthStep = sourceImage.step[0];

		// Widthstep của ảnh destination
		size_t histMatrixWidthStep = histMatrix.step[0];

		// Con trỏ quản lý vùng nhớ data ảnh source
		uchar* ptrSourceData = sourceImage.data;

		// Con trỏ quản lý vùng nhớ data ảnh destination
		int* blueHistMatrixData = histMatrix.ptr<int>(0);
		int* greenHistMatrixData = histMatrix.ptr<int>(1);
		int* redHistMatrixData = histMatrix.ptr<int>(2);

		for (int y = 0; y < heigth; y++, ptrSourceData += sourceWidthStep) {
			uchar* ptrSourceRow = ptrSourceData;
			for (int x = 0; x < width; x++, ptrSourceRow += sourceChannels) {

				// Lấy giá trị kênh màu Blue của ảnh source
				uchar blue = ptrSourceRow[0];

				// Lấy giá trị kênh màu Green của ảnh source
				uchar green = ptrSourceRow[1];

				// Lấy giá trị kênh màu Red của ảnh source
				uchar red = ptrSourceRow[2];

				// Blue
				blueHistMatrixData[blue] += 1;
				// Green
				greenHistMatrixData[green] += 1;
				// Red
				redHistMatrixData[red] += 1;
			}
		}

		int sum_blue = 0;
		for (int i = 0; i < 256; i++) {
			sum_blue += blueHistMatrixData[i];
		}

		std::cout << sum_blue << std::endl;
		int sum_green = 0;
		for (int i = 0; i < 256; i++) {
			sum_green += greenHistMatrixData[i];
		}

		std::cout << sum_green << std::endl;
		int sum_red = 0;
		for (int i = 0; i < 256; i++) {
			sum_red += redHistMatrixData[i];
		}

		std::cout << sum_red << std::endl;


		Utils::saving_image(histMatrix, "result_histogram_matrix_rgb.jpg");
		std::cout << "Success: Calculated the histogram of image.\n";
		return 1;
	}
	std::cout << "Exception: Can not calculate the histogram of image.\n";
	return 0;
}

/*
Hàm cân bằng lược đồ màu tổng quát cho ảnh bất kỳ
Tham số:
	image: ảnh dùng để tính histogram
	histImage : ảnh histogram
Hàm trả về:
	1: Nếu thành công vẽ được histogram
	0: Nếu không vẽ được histogram
*/
int ColorTransformer::HistogramEqualization(const cv::Mat& sourceImage, cv::Mat& destinationImage)
{
	// Kiểm trả ảnh đầu vào
	if (!sourceImage.data) {
		// Cân bằng lược đồ màu thất bại: in ra màn hình console tin nhắn
		std::cout << "[EXCEPTION] Error with input image.\n";
		return 0; // Trả về 0
	}

	Converter converter;
	cv::Mat sourceImgClone = sourceImage.clone();

	// Chiều rộng của ảnh source
	int width = sourceImgClone.cols;

	// Chiều cao của ảnh source
	int heigth = sourceImgClone.rows;

	// Số channels của ảnh source
	int sourceChannels = sourceImgClone.channels();

	// Widthstep của ảnh source
	size_t sourceWidthStep = sourceImage.step[0];

	// Con trỏ quản lý vùng nhớ data ảnh source
	uchar* ptrSourceData = sourceImage.data;

	if (sourceImage.channels() == 1) {
		// Khởi tạo ảnh destination với thông số height, width
		destinationImage = cv::Mat(heigth, width, CV_8UC1, cv::Scalar(0));
		// Số channels của ảnh destination
		int destinationChannels = destinationImage.channels();
		// Widthstep của ảnh destination
		size_t destinationWidthStep = destinationImage.step[0];
		// Con trỏ quản lý vùng nhớ data ảnh destination
		uchar* ptrDestinationData = destinationImage.data;
		//Khởi tạo ảnh kết quả des
		cv::Mat destinationHistogram = cv::Mat(sourceImage.rows, sourceImage.cols, CV_8UC1, cv::Scalar(0));

		destinationImage = cv::Mat(sourceImage.rows, sourceImage.cols, CV_8UC1, cv::Scalar(0));
		this->CalcHistogram(sourceImage, destinationHistogram);

		int temp[256];
		for (int i = 0; i < 256; i++) {
			temp[i] = 0;
		}
		uchar* ptrdestinationHistogramData = destinationHistogram.data;

		//Tính lược đồ xám tích lũy
		temp[0] = *(ptrdestinationHistogramData);
		for (int i = 1; i < 256; i++)
		{
			temp[i] = temp[i - 1] + *(ptrdestinationHistogramData + i);
		}

		//Chuẩn hóa về đoạn [0, 255]
		for (int i = 0; i < 256; i++)
		{
			float tmp = (256 - 1) / (float)(sourceImage.cols * sourceImage.rows);
			temp[i] = (int)round(tmp * temp[i]);
		}

		//Biến đổi ảnh
		for (int y = 0; y < heigth; y++, ptrSourceData += sourceWidthStep, ptrDestinationData += destinationWidthStep) {
			uchar* ptrSourceRow = ptrSourceData;
			uchar* ptrDestinationRow = ptrDestinationData;

			for (int x = 0; x < width; x++, ptrSourceRow += sourceChannels, ptrDestinationRow += destinationChannels) {
				ptrDestinationRow[0] = temp[ptrSourceRow[0]];
			}
		}
	}

	else if (sourceImage.channels() == 3) {
		cv::Mat destinationHistogram = cv::Mat(sourceImage.rows, sourceImage.cols, CV_8UC3, cv::Scalar(0));
		destinationImage = cv::Mat(sourceImage.rows, sourceImage.cols, CV_8UC3, cv::Scalar(0));
		cv::Mat sourceImageHSV = cv::Mat(sourceImage.rows, sourceImage.cols, CV_8UC3, cv::Scalar(0));
		cv::Mat destinationImageHSV = cv::Mat(sourceImage.rows, sourceImage.cols, CV_8UC3, cv::Scalar(0));
		this->CalcHistogram(sourceImage, destinationHistogram);

		int temp_hsv[256];
		for (int i = 0; i < 256; i++) {
			temp_hsv[i] = 0;
		}

		int temp[256];
		for (int i = 0; i < 256; i++) {
			temp[i] = 0;
		}

		// RGB2HSV(sourceImage, sourceImageHSV);
		converter.Convert(sourceImgClone, sourceImageHSV, 2);

		for (int i = 0; i < sourceImageHSV.rows; i++)
		{
			for (int j = 0; j < sourceImageHSV.cols; j++)
			{
				temp_hsv[sourceImageHSV.at<cv::Vec3b>(i, j)[2]] += 1;
			}
		}

		temp[0] = temp_hsv[0];
		for (int i = 1; i < 256; i++)
		{
			temp[i] = temp[i - 1] + temp_hsv[i];
		}

		//Chuẩn hóa t về đoạn [0, 255]
		for (int i = 0; i < 256; i++)
		{
			float tmp = (256 - 1) / (float)(sourceImage.cols * sourceImage.rows);
			temp[i] = (int)round(tmp * temp[i]);
		}

		// Biến đổi ảnh
		destinationImageHSV = sourceImageHSV.clone();
		for (int i = 0; i < destinationImageHSV.rows; i++)
		{
			for (int j = 0; j < destinationImageHSV.cols; j++)
			{
				destinationImageHSV.at<cv::Vec3b>(i, j)[2] = temp[sourceImageHSV.at<cv::Vec3b>(i, j)[2]];
			}
		}
		// HSV2RGB(destinationImageHSV, destinationImage);
		converter.Convert(destinationImageHSV, destinationImage, 3);
		return 1;
	}

	return 0;
}


/*
Hàm cân bằng lược đồ màu tổng quát cho ảnh bất kỳ
Tham số:
	histMatrix : ma trận histogram đã tính được
	histImage : ảnh histogram được vẽ
Hàm trả về:
	1: Nếu thành công vẽ được histogram
	0: Nếu không vẽ được histogram
*/
int ColorTransformer::DrawHistogram(const cv::Mat& histMatrix, cv::Mat& histImage)
{
	// Kiểm tra ma trận hist đầu vào
	if (histMatrix.empty())
	{
		std::cout << "[EXCEPTION] Error with input histogram matrix.\n";
		return 0;
	}

	cv::Mat hist = histMatrix.clone();

	// Vẽ histogram cho ảnh grayscale
	if (hist.rows == 1)
	{
		std::cout << "Gray";
		uchar* ptrHistMatrixData = hist.data;
		uchar max = *ptrHistMatrixData;

		for (int i = 0; i < hist.cols; i++)
		{
			max = max < *(ptrHistMatrixData + i) ? *(ptrHistMatrixData + i) : max;
		}

		for (int i = 0; i < hist.cols; i++)
		{
			*(ptrHistMatrixData + i) = *(ptrHistMatrixData + i) * 300 / max;
		}

		histImage = cv::Mat(300, 256, CV_8UC1, cv::Scalar(0));
		
		for (int j = 0; j < histImage.cols; j++)
		{
			line(histImage, cv::Point(j, histImage.rows - 1 - *(ptrHistMatrixData + j)),
				cv::Point(j, histImage.rows - 1), Utils::white, 2);
		}

		cv::imwrite("result_histogram_gray.jpg", histImage);
		return 1;
	}
	// Vẽ histogram cho ảnh màu
	else if (hist.rows == 3)
	{
		uchar* ptrHistMatrixData = hist.data;

		uchar max = *ptrHistMatrixData;
		uchar* ptrSourceData = ptrHistMatrixData;
		for (int i = 0; i < hist.rows; i++, ptrSourceData += hist.step[0])
		{
			uchar* ptrSourceRow = ptrSourceData;
			for (int j = 0; j < hist.cols; j++)
			{
				max = max < *(ptrSourceRow + j) ? *(ptrSourceRow + j) : max;
			}
		}

		for (int i = 0; i < hist.rows; i++, ptrSourceData += hist.step[0])
		{
			uchar* ptrSourceRow = ptrSourceData;
			for (int j = 0; j < hist.cols; j++)
			{
				*(ptrHistMatrixData + i) = *(ptrHistMatrixData + i) * 300 / max;
			}
		}

		histImage = cv::Mat(300, 256 * 3, CV_8UC3, cv::Scalar(0));
		
		size_t histMatrixWidthStep = hist.step[0];
		uchar* blueHistMatrixData = ptrHistMatrixData;
		uchar* greenHistMatrixData = ptrHistMatrixData + histMatrixWidthStep;
		uchar* redHistMatrixData = ptrHistMatrixData + histMatrixWidthStep + histMatrixWidthStep;
		for (int j = 0; j < hist.cols; j++)
		{
			// cv::Scalar(255, 0, 0) đường màu xanh
			line(histImage, cv::Point(j, histImage.rows - 1 - *(blueHistMatrixData + j)),
				cv::Point(j, histImage.rows - 1), Utils::blue, 2);
			line(histImage, cv::Point(256 + j, histImage.rows - 1 - *(greenHistMatrixData + j)),
				cv::Point(256 + j, histImage.rows - 1), Utils::green, 2);
			line(histImage, cv::Point(512 + j, histImage.rows - 1 - *(redHistMatrixData + j)),
				cv::Point(512 + j, histImage.rows - 1), Utils::red, 2);
		}

		cv::imwrite("result_histogram_rgb.jpg", histImage);
		return 1;
	}
	return 0;
}

/*
Hàm so sánh hai ảnh
Tham số:
	image1 : ảnh thứ nhất
	image2 : ảnh thứ hai
Hàm trả về:
	độ đo sự tương đồng giữa hai ảnh
*/
float ColorTransformer::CompareImage(const cv::Mat& image1, cv::Mat& image2)
{
	// Kiểm tra ảnh đầu vào
	if (!image1.data || !image2.data) {
		std::cout << "Exception: Can not compare two images.\n";
		return -1;
	}

	// TH1: cả hai ảnh đều là ảnh màu
	// TH2: cả hai ảnh đều là ảnh xám
	// TH3: ảnh thứ nhất là ảnh xám, ảnh thứ 2 là ảnh màu
	// TH4: ảnh thứ nhất là ảnh màu, ảnh thứ 2 là ảnh xám

	float delta = 0.0f;

	cv::Mat histogram_matrix_image_1;
	cv::Mat histogram_matrix_image_2;
	this->CalcHistogram(image1, histogram_matrix_image_1);
	this->CalcHistogram(image2, histogram_matrix_image_2);

	for (auto i = 0; i < histogram_matrix_image_1.cols; i++) {
		delta = delta + (histogram_matrix_image_1.at<uchar>(0, i) + histogram_matrix_image_2.at<uchar>(0, i)
			- histogram_matrix_image_1.at<uchar>(0, i) * histogram_matrix_image_2.at<uchar>(0, i)
			);
	}

	return delta;
}

ColorTransformer::ColorTransformer() = default;

ColorTransformer::~ColorTransformer() = default;
