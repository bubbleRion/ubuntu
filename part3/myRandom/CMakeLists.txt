cmake_minimum_required(VERSION 3.10)

project(myRandom)

# include_directories((${CMAKE_CURRENT_LIST_DIR}))
set(SOURCES main.c myRandom.c)

add_executable(myRandom ${SOURCES})
