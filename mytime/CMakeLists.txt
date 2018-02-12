project(mytime)

cmake_minimum_required(VERSION 3.2.2)

set(binary-VERSION_MAJOR 1)
set(binary-VERSION_MINOR 0)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../libs)
set(CMAKE_CXX_STANDARD 14)

add_library(mytime SHARED ${PROJECT_SOURCE_DIR}/src/mytime.cpp)
target_include_directories(mytime PRIVATE ${PROJECT_SOURCE_DIR}/../include)
