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

    else if (srcImage.channels() == 3) {
        Utils::log("[LOG] Enable mode for color image.");
        mode = 3;
        Utils::log("[LOG] Convert source image to gray.");
        Converter converter;
        cv::Mat src = srcImage.clone();
        converter.Convert(src, srcImgClone, 0);
    }


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

    else if (srcImage.channels() == 3) {
        Utils::log("[LOG] Enable mode for color image.");
        mode = 3;
        Utils::log("[LOG] Convert source image to gray.");
        Converter converter;
        cv::Mat src = srcImage.clone();
        converter.Convert(src, srcImgClone, 0);
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

    Utils::log("[LOG] Starting static threshold ....");

    for (int y = 0; y < dstHeigth; y++,  ptrDstData += dstWidthStep) {
        uchar* ptrDstRow = ptrDstData;

        for (int x = 0; x < dstWidth; x++, ptrDstRow += dstChannels) {
            for (int i = this->getLowThreshold() + 1; i < this->getHighThreshold(); i++) {
                objectArray[i] = 255;
            }
            ptrDstRow[0] = objectArray[ptrDstRow[0]];
        }
    }

    Utils::log("[LOG] Finished static threshold ....");

    if (!dstImage.data) {
        Utils::log("[ERROR] Error has occured.");
        return 0;
    }
    Utils::log("[LOG] Success static threshold.");
    return 1;
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

    else if (srcImage.channels() == 3) {
        Utils::log("[LOG] Enable mode for color image.");
        mode = 3;
        Utils::log("[LOG] Convert source image to gray.");
        Converter converter;
        cv::Mat src = srcImage.clone();
        converter.Convert(src, srcImgClone, 0);
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

    // Width kernel
    int widthKernel = winSize.width;
    int heightKernel = winSize.height;

    std::vector<int> offsets;
    std::cout << "[LOG] Calculating kernel center...\n";
    for (int y = -heightKernel; y <= heightKernel; y=-~y)
    {
        for (int x = -widthKernel; x <= widthKernel; x=-~x)
        {
            offsets.push_back(y * dstWidthStep + x);
        }
    }

    // Con trỏ quản lý vùng nhớ data ảnh source
    uchar* ptrSourceData = srcImgClone.data;

    // Con trỏ quản lý vùng nhớ data ảnh destination
    uchar* ptrDestinationData = dstImage.data;

    Utils::log("[LOG] Starting median threshold ....");

    for (int y = 0; y < dstHeigth; y++, ptrSourceData += srcImgClone.step[0], ptrDestinationData += dstWidthStep) {
        uchar* ptrSourceRow = ptrSourceData;
        uchar* ptrDestinationRow = ptrDestinationData;

        for (int x = 0; x < dstWidth; x++, ptrSourceRow += srcImgClone.channels(), ptrDestinationRow += dstChannels) {
            int x_source = x + (widthKernel >> 1), y_source = y + (heightKernel >> 1);

            uchar* pSource = ptrDstData + ((long long)x_source * dstWidthStep + (long long)y_source * dstChannels);

            std::vector<uchar> value;
            for (int k = 0; k < offsets.size(); k++) {
                value.push_back(pSource[offsets[k]]);
            }

            sort(value.begin(), value.begin() + value.size());
            ptrDestinationRow[0] = ptrSourceRow[0] > ((int)value[value.size() / 2 + 1] - getFactorC()) ? 255 : 0;
        }
    }
    Utils::log("[LOG] Finished median threshold ....");

    if (!dstImage.data) {
        Utils::log("[ERROR] Error has occured.");
        return 0;
    }
    Utils::log("[LOG] Success median threshold.");
    return 1;
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

    else if (srcImage.channels() == 3) {
        Utils::log("[LOG] Enable mode for color image.");
        mode = 3;
        Utils::log("[LOG] Convert source image to gray.");
        Converter converter;
        cv::Mat src = srcImage.clone();
        converter.Convert(src, srcImgClone, 0);
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


    return 0;
}

SauvolaLocalThreshold::SauvolaLocalThreshold()
{
    this->_k = 0;
    this->_r = 0;
}

SauvolaLocalThreshold::~SauvolaLocalThreshold() = default;