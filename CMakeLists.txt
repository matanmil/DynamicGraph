cmake_minimum_required(VERSION 3.13)
project(dynamic_202)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(dynamic_202
        Dynamic_Graph.cpp
        Dynamic_Graph.h
        Graph_Edge.cpp
        Graph_Edge.h
        Graph_Node.cpp
        Graph_Node.h
        main.cpp
        Queue.cpp
        Queue.h
        Rooted_Tree.cpp
        Rooted_Tree.h
        T_Node.cpp
        T_Node.h Stack.cpp Stack.h)
