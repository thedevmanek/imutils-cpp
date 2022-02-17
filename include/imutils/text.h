//
// Created by thedevmanek on 05/02/22.
//

#pragma once

#include "opencv2/core/mat.hpp"

/** @file text.h **/
/***************************************************************************//**
 *@class Text
 *@brief
 * The helps in writing text on images
 * @fn listImages
 * @fn listFiles
 ******************************************************************************/
class Text {
public:
    /**
* @param img Image
* @param text Text string to be drawn.
* @param origin Bottom-left corner of the first line of the text string in the image.
* @param fontFace Font type. One of FONT_HERSHEY_SIMPLEX, FONT_HERSHEY_PLAIN, FONT_HERSHEY_DUPLEX,
                      FONT_HERSHEY_COMPLEX, FONT_HERSHEY_TRIPLEX, FONT_HERSHEY_COMPLEX_SMALL,
                      FONT_HERSHEY_SCRIPT_SIMPLEX, or FONT_HERSHEY_SCRIPT_COMPLEX, where each of the font ID’s
                      can be combined with FONT_ITALIC to get the slanted letters.
* @param fontScale Font scale factor that is multiplied by the font-specific base size.
* @param color  Text color.
* @param thickness Thickness of the lines used to draw a text.
* @param lineType Line type. See the line for details.
* @param bottomLeftOrigin When true, the image data origin is in the bottom-left corner.
                           Otherwise, it is in the top-left corner.
* @return None; image is modified in place
* @brief Utility for drawing text with line breaks
**/
    static void putText(cv::Mat &img, const std::string &text, cv::Point origin, int fontFace,

                 double fontScale, cv::Scalar color, int thickness = 1, int lineType = 8,
                 bool bottomLeftOrigin = false);

/**
 * @param img Image
 * @param text Text string to be drawn.
 * @param fontFace Font type. One of FONT_HERSHEY_SIMPLEX, FONT_HERSHEY_PLAIN, FONT_HERSHEY_DUPLEX,
                          FONT_HERSHEY_COMPLEX, FONT_HERSHEY_TRIPLEX, FONT_HERSHEY_COMPLEX_SMALL,
                          FONT_HERSHEY_SCRIPT_SIMPLEX, or FONT_HERSHEY_SCRIPT_COMPLEX, where each of the font ID’s
                          can be combined with FONT_ITALIC to get the slanted letters.
 * @param fontScale Font scale factor that is multiplied by the font-specific base size.
 * @param color  Text color.
 * @param thickness Thickness of the lines used to draw a text.
 * @param lineType Line type. See the line for details.
                               Otherwise, it is in the top-left corner.
 * @return None; image is modified in place
 * @brief Utility for drawing vertically & horizontally centered text with line breaks
 **/
    static void putCenteredText(cv::Mat &img, const std::string &text, int fontFace,

                         double fontScale, cv::Scalar color, int thickness = 1, int lineType = 8);

};