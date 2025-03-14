cmake_minimum_required(VERSION 3.10)

project(myString)

# include_directories((${CMAKE_CURRENT_LIST_DIR}))
set(SOURCES main.c myString.c)

add_executable(myString ${SOURCES})
