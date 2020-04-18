cmake_minimum_required(VERSION 3.15)
project(Tema)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic -g")

add_executable(Tema main.cpp Vector.cpp Vector.h MatriceAdiacenta.cpp MatriceAdiacenta.h Lista.cpp Lista.h Graf.cpp Graf.h Graf_Neorientat.cpp Graf_Neorientat.h Graf_Orientat.cpp Graf_Orientat.h)