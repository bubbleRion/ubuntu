cmake_minimum_required(VERSION 3.10)

project(part3)

file(GLOB EXCUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")
foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()

add_subdirectory(carSerial)
add_subdirectory(date)
add_subdirectory(myRandom)
add_subdirectory(string)