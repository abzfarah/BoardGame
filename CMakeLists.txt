cmake_minimum_required(VERSION 3.2)
project(BoardGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_custom_target(BoardGame COMMAND make -C ${BoardGame_SOURCE_DIR}
                         CLION_EXE_DIR=${PROJECT_BINARY_DIR})