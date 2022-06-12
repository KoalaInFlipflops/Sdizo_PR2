cmake_minimum_required(VERSION 3.21)
project(sdizo2_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdizo2_1 main.cpp BellmanFord.cpp BellmanFord.h Dijkstra.cpp Dijkstra.h Graph.cpp Graph.h Kruskal.cpp Kruskal.h Prim.cpp Prim.h Timer.cpp Timer.h)
