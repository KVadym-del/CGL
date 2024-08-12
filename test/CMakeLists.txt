set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)

file(GLOB SRC "./*.c")

add_executable(CGL_Test ${SRC})
target_include_directories(CGL_Test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../src/headers)
target_link_libraries(CGL_Test CGL)
