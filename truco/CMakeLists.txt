cmake_minimum_required(VERSION 3.22.1)

project(TrucoYMate DESCRIPTION "Truco argentino para terminal GNU Linux" LANGUAGES CXX)

set(EXECUTABLE truco)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(INC_DIR ${PROJECT_SOURCE_DIR}/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncurses)

file(GLOB SOURCES ${SRC_DIR}/*.cpp)

add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(${EXECUTABLE} PUBLIC ${INC_DIR})

include_directories(${NCURSES_INCLUDE_DIRS})

target_link_libraries(${EXECUTABLE} ${NCURSES_LIBRARIES})
