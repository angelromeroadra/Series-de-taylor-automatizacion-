cmake_minimum_required(VERSION 3.10)
project(Matematicas)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(FUENTES
    main.cpp
    src/matematicas.cpp
)

add_executable(matematicas ${FUENTES})
