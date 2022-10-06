//
// Created by mark on 10/5/22.
//

#ifndef HELLO_REALSENSE_CVT_UTILS_HPP
#define HELLO_REALSENSE_CVT_UTILS_HPP

#include <vector>
#include <string>
#include <opencv2/core.hpp>
namespace cvt {
static const std::vector<std::string> CLASS_LABELS{
            "person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat",
            "trafficlight", "firehydrant", "stopsign", "parkingmeter", "bench", "bird", "cat",
            "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack",
            "umbrella", "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sportsball",
            "kite", "baseballbat", "baseballglove", "skateboard", "surfboard", "tennisracket",
            "bottle", "wineglass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple",
            "sandwich", "orange", "broccoli", "carrot", "hotdog", "pizza", "donut", "cake", "chair",
            "sofa", "pottedplant", "bed", "diningtable", "toilet", "tvmonitor", "laptop", "mouse",
            "remote", "keyboard", "cellphone", "microwave", "oven", "toaster", "sink", "refrigerator",
            "book", "clock", "vase", "scissors", "teddybear", "hairdrier", "toothbrush"};

static const std::vector<cv::Scalar> COLORS{
            cv::Scalar(255,0,0),
            cv::Scalar(0,255,0),
            cv::Scalar(0,0,255),
            cv::Scalar(255,255,0),
            cv::Scalar(255,200,20),
            cv::Scalar(255,0,255),
            cv::Scalar(0,255,255),
            cv::Scalar(127,0,255),
            cv::Scalar(0,127,255),
            cv::Scalar(20,20,20),
            cv::Scalar(127,255,0),
            cv::Scalar(255,0,127)
    };

static cv::Scalar getColor(int index) {
        return COLORS[index % COLORS.size()];
    }
}
#endif//HELLO_REALSENSE_CVT_UTILS_HPP
