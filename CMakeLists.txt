cmake_minimum_required(VERSION 3.23)
project(PerlinNoise)

set(CMAKE_CXX_STANDARD 17)

add_executable(PerlinNoise main.cpp PngSave.cpp PngSave.hpp PerlinNoise.cpp PerlinNoise.hpp)