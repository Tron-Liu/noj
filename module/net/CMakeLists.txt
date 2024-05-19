message(STATUS "Net module dir: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
  ${NET_NAME}
  SHARED
  socket.h socket.cpp
  epoll.h epoll.cpp
)

target_include_directories(
  ${NET_NAME}
  PUBLIC
  ${CORE_PATH}
  ${MODULE_PATH}/${LOG_NAME}
)

target_link_libraries(
  ${NET_NAME}
  ${CORE}
  ${LOG_NAME}
)