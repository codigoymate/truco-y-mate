cmake_minimum_required(VERSION 3.16.3)

project(TrucoArgentino LANGUAGES CXX)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_subdirectory(tcurses)
add_subdirectory(truco)
add_subdirectory(testing_tcurses)
