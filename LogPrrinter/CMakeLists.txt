cmake_minimum_required(VERSION 2.6)

project(output)

add_subdirectory(Logs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(output main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Logs)