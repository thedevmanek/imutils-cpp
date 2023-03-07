//
// Created by dev on 3/7/23.
//

#include "../include/imutils/helper.h"
#include "opencv2/imgproc.hpp"
#include "dlib/geometry.h"
#include <dlib/image_processing.h>
#include <valarray>


long *rect_to_bb(dlib::rectangle rect) {
    long x = rect.left();
    long y = rect.top();
    long w = rect.right() - x;
    long h = rect.bottom() - y;
    static long ret_vals[] = {x, y, w, h};
    return ret_vals;
}

std::vector<std::pair<int, int>> shape_to_np(dlib::full_object_detection shape) {
    std::vector<std::pair<int, int>> coords;
    for (int i = 0; i < shape.num_parts(); ++i) {
        coords.emplace_back(std::pair(shape.part(i).x(), shape.part(i).y()));
    }
    return coords;
}

auto
visualize_facial_landmarks(const cv::Mat& image, dlib::full_object_detection shape, std::vector<cv::Scalar_<double>> colors,
                           double alpha) {

    cv::Mat overlay = image.clone();
    cv::Mat output = image.clone();
    if (colors.empty()) {
        colors = {cv::Scalar_<double>(19, 199, 109),
                  cv::Scalar_<double>(79, 76, 240),
                  cv::Scalar_<double>(230, 159, 23),
                  cv::Scalar_<double>(168, 100, 168),
                  cv::Scalar_<double>(158, 163, 32),
                  cv::Scalar_<double>(163, 38, 32),
                  cv::Scalar_<double>(180, 42, 220),
                  cv::Scalar_<double>(0, 0, 255)};
    }
    int count = 0;
    for (const auto &val: facial_landmarks) {
        std::string name = val.first;
        std::pair<int, int> point = val.second;
        std::vector<cv::Point> pts;
        for (int i = point.first; i < point.second; ++i) {
            pts.emplace_back(shape.part(i).x(), shape.part(i).y());
        }
        if (name == "jaw") {
            for (auto i = 0; i != pts.size(); i++) {
                cv::Point ptaA = cv::Point(pts[i - 1].x, pts[i - 1].y);
                cv::Point ptaB = cv::Point(pts[i].x, pts[i].y);
                cv::line(overlay, ptaA, ptaB, colors[i], 2);
            }
        } else {
            std::vector<std::vector<cv::Point> > hull;
            cv::convexHull(pts, hull);
            cv::drawContours(overlay, hull, -1, colors[count], -1);
        }
        cv::addWeighted(overlay, alpha, output, 1 - alpha, 0, output);
        count++;
    }
    return 0;
}
