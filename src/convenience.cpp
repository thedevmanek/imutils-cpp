//
// Created by jonsnow on 16/02/22.
//

#include <utility>
#include "opencv2/imgproc.hpp"
#include "iostream"
#include "../include/imutils/convenience.h"
#include <curl/curl.h>
#include <opencv2/imgcodecs.hpp>

cv::Mat Convenience::translate(const cv::Mat &img, float x, float y) {
    cv::Mat imgAffine;
    float warp_values[] = {1.0, 0.0, x, 0.0, 1.0, y};
    cv::Mat M = cv::Mat(2, 3, CV_32F, warp_values);
    cv::warpAffine(img, imgAffine, M, img.size());
    return imgAffine;
}

cv::Mat Convenience::rotate(cv::Mat &img, double angle, cv::Point2f center, float scale) {
    cv::Mat imgRotated;
    float height = img.cols;
    float width = img.rows;
    if (center.x == -1)
        center = {height / 2, width / 2};
    cv::Mat M = cv::getRotationMatrix2D(center, angle, scale);
    cv::warpAffine(img, imgRotated, M, img.size());
    return imgRotated;
}

cv::Mat Convenience::rotateBounds(cv::Mat &img, double angle) {
    int h = img.rows, w = img.cols;

    cv::Point center = cv::Point(w / 2, h / 2);

    cv::Mat M = getRotationMatrix2D(center, -angle, 1.0);
    double cos = abs(M.at<double>(0, 0));
    double sin = abs(M.at<double>(0, 1));

    int nW = int((h * sin) + (w * cos));
    int nH = int((h * cos) + (w * sin));

    M.at<double>(0, 2) += (nW / 2) - center.x;
    M.at<double>(1, 2) += (nH / 2) - center.y;
    cv::Mat rotated;

    warpAffine(img, rotated, M, cv::Size(nW, nH));
    return rotated;

}

cv::Mat Convenience::resize(cv::Mat &img, int height, int width, int inter) {
    cv::Size dim;
    cv::Size size = img.size();
    if (height == 0 and width == 0)
        return img;
    if (width == 0) {
        float r = (float) height / (float) size.height;
        dim = cv::Size(size.width * r, height);
    } else {
        float r = (float) width / (float) size.width;
        dim = cv::Size(width, size.height * r);
    }
    cv::Mat resized;
    cv::resize(img, resized, dim, 0, 0, inter);
    return resized;
}

cv::Mat Convenience::skeletonize(cv::Mat &img, cv::Size size, int structuring) {
    int area = img.rows * img.cols;
    cv::Mat skeleton = cv::Mat::zeros(img.size(), img.type());
    cv::Mat elem = cv::getStructuringElement(structuring, size);

    while (true) {
        cv::Mat eroded;
        cv::erode(img, eroded, elem);
        cv::Mat temp;
        cv::dilate(eroded, temp, elem);

        cv::subtract(img, temp, temp);
        cv::bitwise_or(skeleton, temp, skeleton);
        img = eroded.clone();

        if (area == area - cv::countNonZero(img))
            break;
    }
    return skeleton;
}

cv::Mat Convenience::urlToImager(std::string url, int readFlag) {
    CURL *curl;
    CURLcode res;
    std::ostringstream stream;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream);
    res = curl_easy_perform(curl);
    std::string output = stream.str();
    curl_easy_cleanup(curl);
    std::vector<char> data = std::vector<char>(output.begin(), output.end());
    cv::Mat data_mat = cv::Mat(data);
    cv::Mat image = cv::imdecode(data_mat, 1);
    return image;
}

size_t Convenience::write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    auto *stream = (std::ostringstream *) userdata;
    size_t count = size * nmemb;
    stream->write(ptr, count);
    return count;
}

cv::Mat Convenience::autoCanny(cv::Mat img, double sigma) {
    double v = medianMat(img);
    int lower = (int) fmax(0, (1.0 - sigma) * v);
    int upper = (int) fmin(255, (1.0 + sigma) * v);
    cv::Mat edged;
    cv::Canny(img, edged, lower, upper);
    return edged;

}

double Convenience::medianMat(cv::Mat Input) {
    Input = Input.reshape(0, 1); // spread Input Mat to single row
    std::vector<double> vecFromMat;
    Input.copyTo(vecFromMat); // Copy Input Mat to vector vecFromMat
    std::nth_element(vecFromMat.begin(), vecFromMat.begin() + vecFromMat.size() / 2, vecFromMat.end());
    return vecFromMat[vecFromMat.size() / 2];
}

cv::Mat Convenience::adjustBrightnessContrast(cv::Mat img, int brightness, double contrast) {
    int beta = 0;
    cv::Mat adjusted;
    cv::addWeighted(img, 1 + contrast / 100.0, img, beta, brightness, adjusted);
    return adjusted;
}
