cmake_minimum_required(VERSION 3.20)
project(3500_E_3_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(3500_E_3_2 pthread-data-sharing-mutex-os-call.cpp pthread-data-sharing-mutex-peterson.cpp)
