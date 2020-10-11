cmake_minimum_required(VERSION 3.15)
project(codingInterviews)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES
        src/*/*.h
        src/*/*.cpp
        )

add_executable(codingInterviews main.cpp ${SOURCE_FILES} ${SOURCES})
add_executable(03_1_findRepeatNumber src/03_1_findRepeatNumber/findRepeatNumber.cpp)
add_executable(03_2_findRepeatNumber_noEdit src/03_2_findRepeatNumber_noEdit/findRepeatNumberNoEdit.cpp)
