#include "Convolution.h"

//trả về kernel
std::vector<float> Convolution::GetKernel()
{
    return std::vector<float>();
}

//set kernel, chiều rộng, chiều dài kernel phải là số lẻ
void Convolution::SetKernel(std::vector<float> kernel, int kWidth, int kHeight){

}

/*
Hàm tính convolution của 1 ảnh xám với kernel được xác định trước
sourceImage: ảnh input
destinationImage: ảnh output
Hàm trả về
0: nếu tính thành công
1: nếu tính thất bại (không đọc được ảnh input,...)
*/
int Convolution::DoConvolution(const cv::Mat& sourceImage, cv::Mat& destinationImage){
    return 0;
}

Convolution::Convolution(){

}

Convolution::~Convolution(){

}
