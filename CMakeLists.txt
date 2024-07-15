# cmake最低版本要求
cmake_minimum_required(VERSION 3.7)

# 项目名称
project(dsalcpp)

# 头文件路径
include_directories(
    ${PROJECT_SOURCE_DIR}/data_struct
    ${PROJECT_SOURCE_DIR}/data_struct/array
    ${PROJECT_SOURCE_DIR}/data_struct/list
    ${PROJECT_SOURCE_DIR}/data_struct/stack
)

file(GLOB_RECURSE SRC_FILES
    ${PROJECT_SOURCE_DIR}/algorithm/*.cpp
    ${PROJECT_SOURCE_DIR}/example/*.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})

