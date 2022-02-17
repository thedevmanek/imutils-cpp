#include "string"
#include "bits/stdc++.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"


void putText(cv::Mat &img, const std::string &text, cv::Point origin, int fontFace,

             double fontScale, cv::Scalar color, int thickness = 1, int lineType = 8, bool bottomLeftOrigin = false) {
    // Break out drawing coords
    int x = origin.x;
    int y = origin.y;
    int lineY;
    int lineGap;
    int lineHeight;
    int baseline = 0;
    std::map<int, std::string> Mp;
    std::stringstream textStream(text);
    std::string segment;
    std::vector<std::string> textLines;
    // Break text into list of text lines
    while (std::getline(textStream, segment, '\n')) {
        //Split newline into vector of lines
        textLines.push_back(segment);
    }
    // Get height of text lines in pixels (height of all lines is the same)
    lineHeight = cv::getTextSize("", fontFace,
                                 fontScale, thickness, &baseline).height;
    // Set distance between lines in pixels
    lineGap = lineHeight / 3;

    for (auto &line: Mp) {
        // Find total size of text block before this line
        int lineYAdjustment = line.first * (lineGap + lineHeight);
        // Move text down from original line based on line number
        if (!bottomLeftOrigin) {
            lineY = y + lineYAdjustment;
        } else {
            lineY = y - lineYAdjustment;
        }
        // Draw text
        cv::putText(img, line.second, cv::Point(x, lineY), fontFace = fontFace, fontScale = fontScale, color = color,
                    thickness = thickness, lineType, bottomLeftOrigin = bottomLeftOrigin);
    }

}

void putCenteredText(cv::Mat &img, const std::string &text, int fontFace,

                     double fontScale, cv::Scalar color, int thickness = 1, int lineType = 8) {
    //Save img dimensions
    int x;
    int y;
    int imgHeight = img.rows;
    int imgWidth = img.cols;
    int lineGap;
    int lineHeight;
    int lineWidth;
    int lineAdjustment;
    std::stringstream textStream(text);
    std::string segment;
    int baseline = 0;
    std::map<int, std::string> Mp;
    unsigned long textBlockHeight;
    std::vector<std::string> textLines;
    // Break text into list of text lines
    while (std::getline(textStream, segment, '\n')) {
        //Split newline into vector of lines
        textLines.push_back(segment);
    }
    // Get height of text lines in pixels (height of all lines is the same)
    lineHeight = cv::getTextSize("", fontFace,
                                 fontScale, thickness, &baseline).height;
    // Set distance between lines in pixels
    lineGap = lineHeight / 3;
    textBlockHeight = textLines.size() * (lineHeight * lineGap);
    for (auto &line: Mp) {
        //Get width of text line in pixels (height of all lines is the same)
        lineWidth = cv::getTextSize("", fontFace,
                                     fontScale, thickness, &baseline).width;
        x = (imgWidth - lineWidth) / 2;
        y = (imgHeight+ lineHeight) / 2;
        // Find total size of text block before this line
        lineAdjustment = line.first * (lineGap + lineHeight);
        // Adjust line y and re-center relative to total text block height
        y = y + lineAdjustment - textBlockHeight / 2 + lineGap;
        // Draw text
        cv::putText(img, line.second, cv::Point(x,y), fontFace = fontFace, fontScale = fontScale, color = color,
                    thickness = thickness, lineType);
    }

}
