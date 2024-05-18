message(STATUS "core dir: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
  ${CORE_NAME}
  SHARED
  core.h core.cpp
)