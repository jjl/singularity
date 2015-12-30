cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("SINGULARITY")

# include_directories(${CYBERLOCKER_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-Wall -std=c89 -O0")
add_library(singularity singularity.c)

add_test(test_singularity singularity)