cmake_minimum_required(VERSION 3.16)
project(bebish LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS lib/*.c src/*.c)

add_executable(bebish ${SOURCES})

target_compile_options(bebish PRIVATE
        -Wall -Wextra -pedantic -Wconversion -Wnull-dereference
        -pipe -fno-common -fstack-protector-strong
)
target_include_directories(bebish PRIVATE inc lib /usr/local/include)
