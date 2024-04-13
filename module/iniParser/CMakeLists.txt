message("sub_dir: ${CMAKE_SOURCE_DIR}")

add_library(${INI_PARSER_NAME}
            SHARED
            section.h section.cpp
            iniParser.h iniParser.cpp
)