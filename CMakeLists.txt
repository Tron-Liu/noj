cmake_minimum_required(VERSION 3.28.0)

set(PROJECT_NAME NOJ)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES C CXX)
message(STATUS "Project: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

add_compile_options(-fPIC)

# path
set(CORE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/core)
set(MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/module)
set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

# core name
set(CORE_NAME core)

# module name
set(INI_PARSER_NAME iniParser)
set(NET_NAME net)
set(LOG_NAME logger)
set(UTILS_NAME utils)
set(THREADPOOL_NAME threadPool)

# third party module name
set(SPDLOG_NAME spdlog)

add_subdirectory(src)
add_subdirectory(core)
add_subdirectory(module)
add_subdirectory(thirdparty)