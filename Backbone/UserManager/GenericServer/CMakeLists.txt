cmake_minimum_required(VERSION 3.9)
project(GenericServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(GenericServer main.cpp mainServer.cpp mainServer.h)