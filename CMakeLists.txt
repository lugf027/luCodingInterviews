cmake_minimum_required(VERSION 3.15)
project(codingInterviews)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES
        src/*/*.h
        src/*/*.cpp
        )

add_executable(codingInterviews main.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(05_replaceSpace src/05_replaceSpace_leetcode/replaceSpace.cpp)
add_executable(09_CQueue src/09_CQueue_leetcode/CQueue.cpp)
