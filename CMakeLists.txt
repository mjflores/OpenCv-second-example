#==========================================
# Tecnologias I&H
# OpenCv 3.10
#==========================================

cmake_minimum_required(VERSION 2.8)
project( VideoEstereo )
find_package( OpenCV REQUIRED )
add_executable( VideoEstereo capturaEstereo.cpp )
target_link_libraries( VideoEstereo ${OpenCV_LIBS} )
