//
// Created by jonsnow on 07/02/22.
//
#include "filesystem"
#include "bits/stdc++.h"
#include "../include/imutils/paths.h"

namespace fs = std::filesystem;

std::vector<std::string> Path::listImages(std::string basePath, std::string contains) {

    return listFiles(basePath, imageTypes, contains = contains);
}

std::vector<std::string> Path::listFiles(std::string basePath, std::vector<std::string> validExts, std::string contains
) {
    std::vector<std::string> filesDirs;
    for (const auto &dirEntry: fs::recursive_directory_iterator(basePath)) {
        std::filesystem::path file = dirEntry.path();
        if (contains != "" and ((std::string) file.filename()).find(contains) == std::string::npos) {
            continue;
        }
        if (validExts.empty()) {
            filesDirs.push_back(dirEntry.path());
        } else {
            if (std::find(validExts.begin(), validExts.end(), file.extension()) != validExts.end()){
                filesDirs.push_back(dirEntry.path());

            }

        }
    }
    return filesDirs;
}



