#pragma once
#include <opencv2/opencv.hpp>
#include "Timer.h"

class Blur {
public:
	static void blur(cv::Mat& frame);
};