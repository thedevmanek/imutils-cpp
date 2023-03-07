//
// Created by dev on 3/7/23.
//

#ifndef IMUTILS_CPP_HELPER_H
#define IMUTILS_CPP_HELPER_H

#include "bits/stdc++.h"
#include "opencv2/imgproc.hpp"
#include "dlib/geometry.h"
#include "dlib/pixel.h"
#include <dlib/image_processing.h>
#include <valarray>


const std::map<std::string, std::pair<int, int>> facial_landmarks_68_idxs = {
        {"mouth",         std::pair(48, 68)},
        {"inner_mouth",   std::pair(60, 68)},
        {"right_eyebrow", std::pair(17, 22)},
        {"left_eyebrow",  std::pair(22, 27)},
        {"right_eye",     std::pair(36, 42)},
        {"left_eye",      std::pair(42, 48)},
        {"nose",          std::pair(27, 36)},
        {"jaw",           std::pair(0, 17)},
};

const std::map<std::string, std::any> facial_landmarks_5_idxs = {
        {"right_eye", std::pair(2, 3)},
        {"left_eye",  std::pair(0, 1)},
        {"nose",      4},
};

const auto facial_landmarks = facial_landmarks_68_idxs;

long *rect_to_bb(dlib::rectangle rect);

std::vector<std::pair<int, int>> shape_to_np(dlib::full_object_detection shape);

auto visualize_facial_landmarks(const cv::Mat &image, dlib::full_object_detection shape,
                                std::vector<cv::Scalar_<double>> colors,
                                double alpha);


#endif //IMUTILS_CPP_HELPER_H
