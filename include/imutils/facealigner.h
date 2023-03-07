//
// Created by dev on 3/8/23.
//

#ifndef IMUTILS_CPP_FACEALIGNER_H
#define IMUTILS_CPP_FACEALIGNER_H

#include "bits/stdc++.h"
#include "opencv2/imgproc.hpp"
#include "dlib/geometry.h"
#include "dlib/pixel.h"
#include <dlib/image_processing.h>
#include <valarray>

class Facealigner {
private:
    static dlib::shape_predictor _predictor;
    dlib::point _desiredLeftEye;
    int _desiredFaceWidth{};
    int _desiredFaceHeight{};
public:

     explicit Facealigner(const dlib::shape_predictor &predictor,
                         const dlib::point& desiredLeftEye = dlib::point(static_cast<long>(0.35),
                                                                         static_cast<long>(0.35)),
                         int desiredFaceWidth = 256,
                         int desiredFaceHeight = -1);

    static cv::Mat align(const cv::Mat &image, cv::Mat gray, dlib::rectangle &rect);
};


#endif //IMUTILS_CPP_FACEALIGNER_H
