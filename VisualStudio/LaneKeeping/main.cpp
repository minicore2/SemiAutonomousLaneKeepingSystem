#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

#include "LaneDetection.h"
#include "Timer.h"

int main() {

   std::string source = "C://Users//adamc//Desktop//pulpit//output.mp4";

    cv::VideoCapture cap(source);
    if (!cap.isOpened()) return -1;

    //Set up lane detection parameters
    cv::Size frameSize = cv::Size(cap.get(cv::CAP_PROP_FRAME_WIDTH), cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double frameFormat = cap.get(cv::CAP_PROP_FORMAT);
    LaneDetection::prepare(frameSize, frameFormat);

    cv::Mat frame;

    auto globalTimer = new Timer("Loop", cap.get(cv::CAP_PROP_FRAME_COUNT));

    while (cap.read(frame)) {

        auto t = new Timer("Loop");

        LaneDetection::process(frame);

        delete t;
    }

    delete globalTimer;
}