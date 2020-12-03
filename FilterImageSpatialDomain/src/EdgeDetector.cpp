#include "EdgeDetector.h"

/*
Hàm phát hiện biên cạnh của ảnh xám
sourceImage: ảnh input
destinationImage: ảnh output
method: phương pháp detect
kWidth, kHeight: kích thước kernel
	1: Sobel
	2: Prewitt
	3: Laplace
Hàm trả về
	0: nếu detect thành công
	1: nếu detect thất bại (không đọc được ảnh input,...)
*/
int EdgeDetector::DetectEdge(const cv::Mat& sourceImage, cv::Mat& destinationImage, int kWidth, int kHeight, int method)
{
    return 0;
}

EdgeDetector::EdgeDetector()
{
}

EdgeDetector::~EdgeDetector()
{
}
