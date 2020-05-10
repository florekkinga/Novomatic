cmake_minimum_required(VERSION 3.13)
project(Novomatic)

set(CMAKE_CXX_STANDARD 14)

add_executable(Novomatic main.cpp "Task 1/List.h" "Task 2/pickMorphs.cpp" "Task 2/pickMorphs.h" "Task 1/List_tests.cpp" "Task 1/List_tests.h" "Task 2/pickMorphs_tests.cpp" "Task 2/pickMorphs_tests.h")