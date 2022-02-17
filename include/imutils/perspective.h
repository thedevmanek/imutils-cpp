//
// Created by jonsnow on 09/02/22.
//

#pragma once

#include <opencv2/core/mat.hpp>
#include "vector"

typedef std::vector<cv::Point2f> vectorpair;

/** @file perspective.h **/
/***************************************************************************//**
 *@class Perspective
 *@brief
 * The class helps to implement four point transformation on a given image
 * @fn orderPoints
 * @fn fourPointTransformation
 ******************************************************************************/

class Perspective {
private:
        /**
    * @param points a vector of coordinates
    * @return Consistent order of points
    * @brief Converting vector of points to a vector with consistent order.
    **/
        static vectorpair orderPoints(vectorpair points);

public:

    /**
    * @param img Image
    * @param points a vector of coordinates
    * @return cropped Image with FPT applied.
    * @brief Applying four point transformation to the image
    **/
    static cv::Mat fourPointTransformation(cv::Mat &img, vectorpair points);

};