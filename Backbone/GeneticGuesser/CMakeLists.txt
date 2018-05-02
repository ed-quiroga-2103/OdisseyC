cmake_minimum_required(VERSION 3.9)
project(GeneticGuesser)

set(CMAKE_CXX_STANDARD 11)

add_executable(GeneticGuesser main.cpp Random.cpp Random.h GenG.cpp GenG.h)