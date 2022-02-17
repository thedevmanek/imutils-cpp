//
// Created by jonsnow on 09/02/22.
//
#include "../include/imutils/perspective.h"
#include <utility>
#include "opencv2/imgproc.hpp"
#include "iostream"
#include "../include/imutils/convenience.h"

typedef std::vector<cv::Point2f> vectorpair;


vectorpair Perspective::orderPoints(
        vectorpair points) {
    vectorpair rect(4);
    std::vector<float> sum;
    for (auto &point: points) {
        sum.push_back(point.x + point.y);
    }

    rect[1] = points[std::min_element(sum.begin(), sum.end()) - sum.begin()];
    rect[3] = points[std::max_element(sum.begin(), sum.end()) - sum.begin()];
    std::vector<float> diff;
    for (auto &point: points) {
        diff.push_back(point.x - point.y);
    }
    rect[0] = points[std::min_element(diff.begin(), diff.end()) - diff.begin()];
    rect[2] = points[std::max_element(diff.begin(), diff.end()) - diff.begin()];
    return rect;
}

cv::Mat Perspective::fourPointTransformation(cv::Mat &img, vectorpair pts) {

    vectorpair rect = orderPoints(std::move(pts));
    cv::Point2f tl = rect[0];
    cv::Point2f tr = rect[1];
    cv::Point2f br = rect[2];
    cv::Point2f bl = rect[3];
    double widthA = sqrt(pow((br.x - bl.x), 2) + pow((br.y - bl.y), 2));
    double widthB = sqrt(pow((tr.x - tl.x), 2) + pow((tr.y - tl.y), 2));
    auto maxWidth = (float) std::max(widthA, widthB);


    double heightA = sqrt(pow((tr.x - br.x), 2) + pow((tr.y - br.y), 2));
    double heightB = sqrt(pow((tl.x - bl.x), 2) + pow((tl.y - bl.y), 2));
    auto maxHeight = (float) std::max(heightA, heightB);

    vectorpair data = {
            {0,            0},
            {maxWidth - 1, 0},
            {maxWidth - 1, maxHeight - 1},
            {0,            maxHeight - 1}
    };
    cv::Mat dst(data, CV_32FC1);
    cv::Mat M = cv::getPerspectiveTransform(rect, data);
    cv::Mat output;
    cv::warpPerspective(img, output, M, {static_cast<int>(maxWidth), static_cast<int>(maxHeight)});
    output = Convenience::rotateBounds(output,-90);
    return output;
}

