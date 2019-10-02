cmake_minimum_required(VERSION 3.15)
project(solver_FJ98)

set(CMAKE_CXX_STANDARD 14)

add_executable(solver_FJ98
        main.cpp funciones.h ExpressionSolver.cpp ExpressionSolver.h)
