cmake_minimum_required(VERSION 3.15)
project(codingInterviews)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES
        src/*/*/*.h
        src/*/*/*.cpp
        )

file(GLOB SORT
        src/sort/*.cpp
        src/sort/*.h
        )

#
add_executable(codingInterviews main.cpp ${SOURCE_FILES} ${SOURCES})

#add_executable(codingInterviews main.cpp src/codingInterviews/01_AssignmentOperator/AssignmentOperator.h src/codingInterviews/01_AssignmentOperator/AssignmentOperator.cpp)
add_executable(05_replaceSpace src/codingInterviews/05_replaceSpace/replaceSpace.cpp src/codingEveryday/20201013_swapPairs/swapPairs.cpp)
add_executable(09_CQueue src/codingInterviews/09_CQueue/CQueue.cpp)
add_executable(10_1_fib src/codingInterviews/10_1_fib/fib.cpp)
add_executable(20201014_swapPairs src/codingEveryday/20201013_swapPairs/swapPairs.cpp)
add_executable(10_2_numWays src/codingInterviews/10_2_numWays/numWays.cpp)
#add_executable(17_printNumber src/codingInterviews/17_printNumbers/printNumbers.cpp)

add_executable(20201106_sortByBits src/codingEveryday/20201106_sortByBits/sortByBits.cpp)

add_executable(TEST_SORT src/sort/test.cpp ${SORT})
