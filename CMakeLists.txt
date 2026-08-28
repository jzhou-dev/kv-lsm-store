cmake_minimum_required(VERSION 3.16)

project(kv-lsm-store LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(kv-lsm-store src/main.cpp
  src/Engine/Engine.cpp
  src/Engine/ResponseStatus.cpp
  src/Engine/SkipList.cpp)
