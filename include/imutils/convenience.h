//
// Created by jonsnow on 16/02/22.
//

#pragma once

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/core.hpp"

/** @file convenience.h **/
/***************************************************************************//**
 *@class Convenience
 *@brief
 * This class will help you with various problems while dealing with opencv
 * @fn translate
 * @fn rotate
 * @fn rotateBounds
 * @fn resize
 * @fn skeletonize
 * @fn urlToImager
 * @fn autoCanny
 * @fn adjustBrightnessContrast
 ******************************************************************************/
class Convenience {
private:

    static size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata);

    /**
 * @param Input requires input Image
 * @return median Matrix of the image
 **/
    static double medianMat(cv::Mat Input);

public:
/**
* @param img input image
* @param x x-coordinate value for translation
* @param y y-coordinate value for translation
* @return Translated image
* @brief Returns translated image
**/
    static cv::Mat translate(const cv::Mat &img, float x, float y);

/**
* @param img input image
* @param angle angle for rotation
* @param center center of the image
* @param scale scaling value for the image
* @return rotated image
* @brief Returns rotated image
**/
    static cv::Mat rotate(cv::Mat &img, double angle, cv::Point2f center = {-1, -1}, float scale = 1.0);

/**
* @param img input image
* @param angle angle for rotation
* @return rotated image with bounds
* @brief Returns rotated bounded image
**/
    static cv::Mat rotateBounds(cv::Mat &img, double angle);

/**
* @param img input image
* @param height height of the image
* @param width width of the image
* @param inter interpolation
* @return resized image with bounds
* @brief Returns resized bounded image
**/

    static cv::Mat resize(cv::Mat &img, int height = 0, int width = 0, int inter = cv::INTER_AREA);

/**
* @param img input image
* @param size size
* @param structuring the structuring filter you want to apply
* @return skeletonized image
* @brief Returns skeleton  image
**/
    static cv::Mat skeletonize(cv::Mat &img, cv::Size size, int structuring = cv::MORPH_RECT);

/**
* @param url url of the image
* @param readFlag type of reading
* @return image
* @brief Returns image from the specified url with the appropriate read flag applied
**/
    static cv::Mat urlToImager(std::string url, int readFlag = cv::IMREAD_COLOR);

/**
* @param img input image
* @param sigma sigma value while applying canny
* @return autocanny applied image
* @brief Returns image with canny applied
**/
    static cv::Mat autoCanny(cv::Mat img, double sigma = 0.33);

/**
* @param img input image
* @param brightness brightness to be applied
* @param contrast contrast to be applied
* @return image
* @brief Returns image with brightness and contrast  applied
**/
    static cv::Mat adjustBrightnessContrast(cv::Mat img, int brightness = 0, double contrast = 0.0);
};

