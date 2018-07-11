cmake_minimum_required(VERSION 3.10)
project(calcul_graph C)

set(CMAKE_C_STANDARD 99)

add_executable(calcul_graph main.c graph.c funcstore.c myhead.h)