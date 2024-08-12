set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)

file(GLOB SRC "./*.c")

add_library(CGL STATIC ${SRC})
target_include_directories(CGL PUBLIC ${CMAKE_CURRENT_LIST_DIR}/headers)
