cmake_minimum_required(VERSION 3.15)
project(jnp1_fibo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fido src/main.cc src/Fibo.cc src/Fibo.h)
