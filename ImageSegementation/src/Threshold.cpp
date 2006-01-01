#include "Threshold.h"
#include "Converter.h"
#include "Ultils.h"

int AverageLocalThreshold::getFactorC()
{
    return this->_C;
}

void AverageLocalThreshold::setFactorC(const int&iC)
{
    this->_C = iC;
}

int AverageLocalThreshold::Apply(const cv::Mat& srcImage, cv::Mat& dstImage, cv::Size winSize)
{

    return 0;
}

AverageLocalThreshold::AverageLocalThreshold()
{
    this->_C = 0;
}

AverageLocalThreshold::~AverageLocalThreshold() = default;

int StaticThreshold::getLowThreshold()
{
    return this->_lowThreshold;
}

void StaticThreshold::setLowThreshold(const int& ilowThreshold)
{
    this->_lowThreshold = ilowThreshold;
}

int StaticThreshold::getHighThreshold()
{
    return this->_highThreshold;
}

void StaticThreshold::setHighThreshold(const int& iHighThreshold)
{
    this->_highThreshold = iHighThreshold;
}

int StaticThreshold::Apply(const cv::Mat& srcImage, cv::Mat& dstImage)
{
    // Kiểm trả ảnh đầu vào
    if (!srcImage.data) {
        Utils::log("[EXCEPTION] Error with input image.");
        return 0;
    }

    int mode = 0;
    cv::Mat srcImgClone;

    if (srcImage.channels() == 1) {
        Utils::log("[LOG] Enable mode for gray image.");
        mode = 1;
        srcImgClone = srcImage.clone();
    }

    if (srcImage.channels() == 3) {
        Utils::log("[LOG] Enable mode for color image.");
        mode = 3;
        Utils::log("[LOG] Convert source image to gray.");
        Converter converter;
        cv::Mat src = srcImage.clone();
        converter.Convert(src, srcImgClone, 0);
        src.release();
        converter.~Converter();
    }

    // Khởi tạo ảnh destination
    dstImage = srcImgClone.clone();

    // Chiều rộng của ảnh destination
    int dstWidth = dstImage.cols;

    // Chiều cao của ảnh destination
    int dstHeigth = dstImage.rows;

    // Số channels của ảnh destination
    int dstChannels = dstImage.channels();

    // Widthstep của ảnh source
    size_t dstWidthStep = dstImage.step[0];

    // Con trỏ quản lý vùng nhớ data ảnh destination
    uchar* ptrDstData = dstImage.data;

    uchar objectArray[256] = { 0 };

    for (int y = 0; y < dstHeigth; y++,  ptrDstData += dstWidthStep) {
        uchar* ptrDstRow = ptrDstData;

        for (int x = 0; x < dstWidth; x++, ptrDstRow += dstChannels) {
            for (int i = this->getLowThreshold(); i <= this->getHighThreshold(); i++) {
                objectArray[i] = 255;
            }
            ptrDstRow[0] = objectArray[ptrDstRow[0]];
        }
    }

    return 0;
}

StaticThreshold::StaticThreshold()
{
    this->_highThreshold = 0;
    this->_lowThreshold = 0;
}

StaticThreshold::~StaticThreshold() = default;

int MedianLocalThreshold::getFactorC()
{
    return this->_C;
}

void MedianLocalThreshold::setFactorC(const int&iC)
{
    this->_C = iC;
}

int MedianLocalThreshold::Apply(const cv::Mat& srcImage, cv::Mat& dstImage, cv::Size winSize)
{
    return 0;
}

MedianLocalThreshold::MedianLocalThreshold()
{
    this->_C = 0;
}

MedianLocalThreshold::~MedianLocalThreshold() = default;

int SauvolaLocalThreshold::getFactorR()
{
    return this->_r;
}

void SauvolaLocalThreshold::setFactorR(const int&ir)
{
    this->_r = ir;
}

float SauvolaLocalThreshold::getFactorK()
{
    return this->_k;
}

void SauvolaLocalThreshold::setFactorK(const float&ik)
{
    this->_k = ik;
}

int SauvolaLocalThreshold::Apply(const cv::Mat& srcImage, cv::Mat& dstImage, cv::Size winSize)
{
    return 0;
}

SauvolaLocalThreshold::SauvolaLocalThreshold()
{
    this->_k = 0;
    this->_r = 0;
}

SauvolaLocalThreshold::~SauvolaLocalThreshold() = default;