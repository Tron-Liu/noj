message(STATUS "IniParser module dir: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
  ${INI_PARSER_NAME}
  SHARED
  section.h section.cpp
  iniParser.h iniParser.cpp
)