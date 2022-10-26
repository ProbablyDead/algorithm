cmake_minimum_required(VERSION 3.21)
project(algo)

set(CMAKE_CXX_STANDARD 20)

add_executable(algo array/arrOpt.cpp array/arrOpt.hpp algorithm/binary/binary.cpp algorithm/binary/binary.hpp research.cpp algorithm/ladder/ladder.cpp algorithm/ladder/ladder.h algorithm/exponentional/exp.cpp algorithm/exponentional/exp.h)
