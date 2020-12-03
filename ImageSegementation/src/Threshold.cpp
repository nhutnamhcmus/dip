#include "Threshold.h"

int AverageLocalThreshold::Apply(const cv::Mat& srcImage, cv::Mat& dstImage, cv::Size winSize)
{
    return 0;
}

int StaticThreshold::Apply(const cv::Mat& srcImage, cv::Mat& dstImage)
{
    return 0;
}

StaticThreshold::StaticThreshold()
{
}

StaticThreshold::~StaticThreshold()
{
}
