cmake_minimum_required(VERSION 3.30)
project(ghostscript_api_test)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/)
include_directories(/usr/local/include/ghostscript)


add_executable(ghostscript_api_test main.cpp)
target_link_libraries(ghostscript_api_test libgs.so)