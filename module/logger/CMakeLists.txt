message(STATUS "Logger module dir: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
  ${LOG_NAME}
  SHARED
  logger.h logger.cpp
)

target_include_directories(
  ${LOG_NAME}
  PUBLIC
  ${MODULE_PATH}/${UTILS_NAME}
  ${THIRD_PARTY_PATH}/${SPDLOG_NAME}
)

target_link_libraries(
  ${LOG_NAME}
  ${SPDLOG_NAME}
)
