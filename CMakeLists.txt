cmake_minimum_required(VERSION 3.14)
project(GraphIso LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Separate main.cpp from the rest
file(GLOB PROJECT_SOURCES GraphIsomorphisim_Version_1.0/*.cpp)
list(REMOVE_ITEM PROJECT_SOURCES
     ${CMAKE_SOURCE_DIR}/GraphIsomorphisim_Version_1.0/main.cpp)

# Library of core code
add_library(graph_iso_lib ${PROJECT_SOURCES})
target_include_directories(graph_iso_lib PUBLIC GraphIsomorphisim_Version_1.0)

# Main executable
add_executable(graph_iso GraphIsomorphisim_Version_1.0/main.cpp)
target_link_libraries(graph_iso PRIVATE graph_iso_lib)

# GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)

# Define the path to Cases directory for integration tests
target_compile_definitions(graph_iso_tests PRIVATE 
    TEST_GRAPH_CASES_DIR=\"${CMAKE_SOURCE_DIR}/GraphIsomorphisim_Version_1.0/Cases\")
