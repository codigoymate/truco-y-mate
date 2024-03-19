cmake_minimum_required(VERSION 3.16.3)

project(TrucoCurses DESCRIPTION "NCurses truco TUI" LANGUAGES CXX)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(INC_DIR ${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES ${SRC_DIR}/*.cpp)
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INC_DIR})
