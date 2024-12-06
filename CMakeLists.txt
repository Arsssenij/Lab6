cmake_minimum_required(VERSION 3.10)
project(VectorEditor)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorEditor main.cpp Controller.h Document.h GraphicPrimitive.h)
