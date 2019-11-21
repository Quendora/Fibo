cmake_minimum_required(VERSION 3.13)
project(jnp1_fibo)

set(CMAKE_CXX_STANDARD 17)

add_executable(fibo src/main.cc src/fibo.cc src/fibo.h)
