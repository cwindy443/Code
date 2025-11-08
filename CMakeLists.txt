cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This line is crucial for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(helloworld helloworld.cpp)
