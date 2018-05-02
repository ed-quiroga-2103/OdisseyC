cmake_minimum_required(VERSION 3.9)
project(XMLManager)

set(CMAKE_CXX_STANDARD 11)

add_executable(XMLManager main.cpp pugiconfig.hpp pugixml.cpp pugixml.hpp XMLParts.cpp XMLParts.h XMLManager.cpp XMLManager.h)