//
// Created by dev on 3/8/23.
//

#include "imutils/facealigner.h"
#include "opencv2/imgproc.hpp"
#include "dlib/geometry.h"
#include <dlib/image_processing.h>
Facealigner::Facealigner(const dlib::shape_predictor& predictor, const dlib::point& desiredLeftEye, int desiredFaceWidth,
                         int desiredFaceHeight) {
    _predictor=predictor;
    _desiredLeftEye=desiredLeftEye;
    _desiredFaceWidth=desiredFaceWidth;

    if (desiredFaceHeight == -1) {
        desiredFaceHeight = desiredFaceWidth;
    }
    _desiredFaceHeight=desiredFaceHeight;
}

//TODO
//Fix implicit dec error and complete the function
cv::Mat Facealigner::align(const cv::Mat& image, cv::Mat gray, dlib::rectangle &rect) {
    auto shape=Facealigner::_predictor(gray,rect);

    return cv::Mat();
}
