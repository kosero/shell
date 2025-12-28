cmake_minimum_required(VERSION 3.16)
project(shell LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c)

add_executable(shell ${SOURCES})

target_compile_options(shell PRIVATE
        -Wall -Wextra -pedantic -Wconversion -Wnull-dereference
        -pipe -fno-common -fstack-protector-strong
)
target_include_directories(shell PRIVATE inc /usr/local/include)
