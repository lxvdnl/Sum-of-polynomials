cmake_minimum_required(VERSION 3.10)
project(GrehamAlgorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_DIR src)

set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/TList.cpp
    ${SOURCE_DIR}/TPolynomial.cpp
    
)

set(HEADERS
    headers/TList.h
    headers/TPolynomial.h
)

include_directories(
    ${SOURCE_DIR}/../headers
)

add_executable(GrehamAlgorithm ${SOURCES} ${HEADERS})