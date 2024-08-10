cmake_minimum_required(VERSION 3.26)
project(CGL C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)

include_directories(/opt/developer/libs/ArrayFire-3.9.0-Linux/include)
link_directories(/opt/developer/libs/ArrayFire-3.9.0-Linux/lib64)

file(GLOB SRC "src/*.c")

add_executable(CGL ${SRC})
