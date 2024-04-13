cmake_minimum_required(VERSION 3.28.0)

set(PROJECT_NAME NOJ)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES C CXX)
message(STATUS "Project: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

set(MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/module)

# module name
set(INI_PARSER_NAME iniParser)

add_subdirectory(src)
add_subdirectory(module)