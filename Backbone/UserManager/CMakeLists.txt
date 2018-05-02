cmake_minimum_required(VERSION 3.9)
project(UserManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(${/XMLManager})
include_directories(${/HashFunct})
include_directories(${/DataManager})
include_directories(${/AlphabeticTree})
include_directories(${/nlohmann})



add_executable(UserManager main.cpp UserManager.cpp UserManager.h XMLManager/pugixml.cpp XMLManager/pugixml.hpp XMLManager/pugiconfig.hpp
                HashFunct/HashClass.cpp HashFunct/HashClass.h DataManager/JSONManager.cpp XMLManager/XMLParts.cpp
        XMLManager/XMLParts.h XMLManager/XMLManager.cpp XMLManager/XMLManager.h DataManager/JSONManager.h
                AlphabeticTree/AlphaTree.cpp AlphabeticTree/AlphaTree.h nlohmann/json.hpp)