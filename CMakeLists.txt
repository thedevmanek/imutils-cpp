cmake_minimum_required(VERSION 3.9)
project(imutils_cpp VERSION 1.0.1 DESCRIPTION "imutils_cpp A series of convenience functions to make basic image processing functions such as translation, rotation, resizing and skeletonization easier with OpenCV ")
find_package(OpenCV REQUIRED)
include(GNUInstallDirs)
add_library(imutils_cpp SHARED STATIC src/text.cpp include/imutils/text.h src/paths.cpp include/imutils/paths.h src/perspective.cpp include/imutils/perspective.h src/convenience.cpp include/imutils/convenience.h)
set_target_properties(imutils_cpp PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(imutils_cpp PRIVATE include)
target_include_directories(imutils_cpp PRIVATE src)
include(GNUInstallDirs)
install(TARGETS imutils_cpp
        ${PROJECT_NAME}
        DESTINATION lib/${PROJECT_NAME})
target_link_libraries(imutils_cpp ${OpenCV_LIBS} curl)
