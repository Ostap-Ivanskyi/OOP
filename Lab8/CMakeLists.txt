cmake_minimum_required(VERSION 3.30)
project(Lab8)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab8 main.cpp
        Bridge.cpp
        Bridge.h
        Facade.cpp
        Facade.h)
