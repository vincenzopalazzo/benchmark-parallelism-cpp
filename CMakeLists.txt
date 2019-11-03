cmake_minimum_required(VERSION 3.9)
project(Benchmark-parallel-algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP)

add_executable( ${PROJECT_NAME}
        src/main.cpp

        src/stl.cpp
        src/openmp.cpp
        src/seq.cpp
        )

target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX stdc++fs)
