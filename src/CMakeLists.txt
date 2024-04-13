set(SOURCE_FILE main.cpp)

add_executable(${PROJECT_NAME}
               ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE})

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           ${MODULE_PATH}/iniParser)

target_link_libraries(${PROJECT_NAME}
                      ${INI_PARSER_NAME}
)
