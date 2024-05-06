cmake_minimum_required(VERSION 3.16.3)

project(test_tcurses DESCRIPTION "Test para la librería TCurses" LANGUAGES CXX)

set(EXECUTABLE test)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(INC_DIR ${PROJECT_SOURCE_DIR}/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncurses)

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(${EXECUTABLE} PUBLIC ${INC_DIR})

include_directories(${NCURSES_INCLUDE_DIRS})

target_link_libraries(${EXECUTABLE} TrucoCurses ${NCURSES_LIBRARIES})
