cmake_minimum_required(VERSION 3.2)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(HW-dpcpp-1.1)

add_executable(HW-dpcpp-1.1 main.cpp)

add_library(SqlSelectQueryBuilder SHARED SqlSelectQueryBuilder.cpp SqlSelectQueryBuilder.hpp)

target_link_libraries(HW-dpcpp-1.1 SqlSelectQueryBuilder)
