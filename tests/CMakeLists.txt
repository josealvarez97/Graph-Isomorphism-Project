file(GLOB TEST_SRC_FILES *.cpp)

add_executable(graph_iso_tests ${TEST_SRC_FILES})
target_link_libraries(graph_iso_tests
  PRIVATE
    graph_iso_lib       # <--- link to the library, not the executable
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(graph_iso_tests)
