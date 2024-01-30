cmake_minimum_required(VERSION 3.28.0)

project(NOJ VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
    "main.cpp"
)