cmake_minimum_required(VERSION 3.10)
project(GraphIsomorphisim_Version_1.0 LANGUAGES CXX)

# Use C++11 standard (or higher) for compilation
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable target and list all source files
add_executable(GraphIsomorphisim_Version_1.0 
    GraphIsomorphisim_Version_1.0/Main.cpp 
    GraphIsomorphisim_Version_1.0/Graph.cpp 
    GraphIsomorphisim_Version_1.0/ReadInput.cpp 
    GraphIsomorphisim_Version_1.0/VertexAdjacencyList.cpp
)
