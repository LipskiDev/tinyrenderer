# CMakeLists.txt

# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.20)

# Set the project name
project(tinyrenderer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/includes/config.h @ONLY)

file(GLOB SOURCES "src/*.cpp")

add_executable(tinyrenderer 
    ${SOURCES}
    dependencies/tgaimage.cpp
)

target_include_directories(tinyrenderer PRIVATE $(CMAKE_SOURCE_DIR)/includes $(CMAKE_SOURCE_DIR)/dependencies)

message("Include directory set to: ${CMAKE_SOURCE_DIR}/includes")