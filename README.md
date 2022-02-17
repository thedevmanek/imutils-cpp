# imutils-cpp

<!-- Version and License Badges -->
![Version](https://img.shields.io/badge/version-1.0.1-green.svg?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-yellow.svg?style=flat-square)
![Language](https://img.shields.io/badge/language-C++-blue.svg?style=flat-square)
![example workflow](https://github.com/github/docs/actions/workflows/main.yml/badge.svg)

<br/>
This is a cpp implementation of popular python library [imutils](https://github.com/PyImageSearch/imutils)

## Installation

This library is dependent on [opencv](https://github.com/opencv/opencv) and [curl](https://github.com/curl/curl)
libraries

### Dynamic Library for local use

<pre> 
$ cp /home/usr/Download/libimutils_cpp.so /home/usr/lib
</pre>
or
<pre> 
$ cp /usr/Download/libimutils_cpp.so.1.0.1 /usr/lib
$ ldconfig -n -v /usr/lib
</pre>

### Static Library

Just install the .a file in the lib dir or the root dir of the project

## Usage

### Dynamic Library

<pre>
g++ -Wall -L/opt/lib main.cpp -limutils_cpp
</pre>

### Static Library

<pre>
$ g++ main.cpp libfoo.a
</pre>
or
<pre>
$ g++ -L. -lfoo prog.cpp libfoo.a
</pre>

## CMAKE

### Dynamic

<pre>
target_link_libraries(imutils_cpp ${OpenCV_LIBS} curl)
</pre>

### Static

<pre>
target_link_libraries(main ${CMAKE_SOURCE_DIR}/libimutils_cpp.a)
</pre>

