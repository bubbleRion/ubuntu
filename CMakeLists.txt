cmake_minimum_required(VERSION 3.10)
project(MainProject)

add_subdirectory(bowling)
add_subdirectory(sqlQuery)
add_subdirectory(part1)
add_subdirectory(part2)
add_subdirectory(part3)

# get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# string(REPLACE " " "_" ProjectId ${ProjectId})
# project(${ProjectId} LANGUAGES C)

# set (CMAKE_CXX_STANDARD 11)

# file(GLOB SOURCES  *.c *.h)
# include(sqlQuery/CMakeLists.txt)
