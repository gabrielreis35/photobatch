cmake_minimum_required(VERSION 3.26)
project(Cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(PhotoBatch "main.cpp"
        ArgumentParser.h
        ArgumentParser.cpp)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY, "${build}/..")