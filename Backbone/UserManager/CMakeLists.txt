cmake_minimum_required(VERSION 3.9)
project(UserManager)

set(CMAKE_CXX_STANDARD 11)

include_directories(${/XMLManager})
include_directories(${/HashFunct})
include_directories(${/DataManager})
include_directories(${/AlphabeticTree})
include_directories(${/nlohmann})
include_directories(${/DataStructs})
include_directories(${/GenericServer})
include_directories(${../AVLTree})




add_executable(UserManager main.cpp DataBaseManager.cpp DataBaseManager.h XMLManager/pugixml.cpp XMLManager/pugixml.hpp XMLManager/pugiconfig.hpp
        GenericServer/mainServer.cpp GenericServer/mainServer.h HashFunct/HashClass.cpp HashFunct/HashClass.h DataManager/JSONManager.cpp XMLManager/XMLParts.cpp DataStructs/DataStructures.cpp DataStructs/DataStructures.tpp DataStructs/DataStructures.h
                ../AVLTree/AVLTree.h XMLManager/XMLParts.h XMLManager/XMLManager.cpp XMLManager/XMLManager.h DataManager/JSONManager.h
                AlphabeticTree/AlphaTree.cpp AlphabeticTree/AlphaTree.h nlohmann/json.hpp BTree/BTree.cpp BTree/BTree.h)