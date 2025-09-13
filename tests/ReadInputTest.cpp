// tests/ReadInputTest.cpp
#include <gtest/gtest.h>
#include <fstream>
#include "../GraphIsomorphisim_Version_1.0/ReadInput.h"

TEST(ReadInputTest, FileSizeCountsLines) {
    // Create a temporary file content for testing.
    const char* tempFileName = "test_graph.txt";
    std::ofstream outfile(tempFileName);
    outfile << "3\n";      // 3 vertices
    outfile << "0,1\n";    // edge 0-1
    outfile << "1,2\n";    // edge 1-2
    outfile << "\n";       // blank line to terminate edges list
    outfile.close();

    int lines = CReadInput::FileSize(tempFileName);
    EXPECT_EQ(lines, 3);  
    // Explanation: 3 non-empty lines (the first line "3" and two edge lines):contentReference[oaicite:52]{index=52}.

    remove(tempFileName); // cleanup
}

TEST(ReadInputTest, GetVertexQuantityParsesFirstLine) {
    const char* tempFileName = "test_vertices.txt";
    std::ofstream outfile(tempFileName);
    outfile << "42\n";  // first line indicating 42 vertices (with newline)
    outfile.close();

    testing::internal::CaptureStdout();
    int vertexCount = CReadInput::GetVertexQuantity(tempFileName);
    std::string ignored = testing::internal::GetCapturedStdout();
    EXPECT_EQ(vertexCount, 42);  // Should parse "42" from the file:contentReference[oaicite:53]{index=53}.

    remove(tempFileName);
}

TEST(ReadInputTest, ReadInputBuildsGraphCorrectly) {
    // Write a small graph to a temp file:
    // 3 vertices, edges: 0-1 and 1-2.
    const char* tempFileName = "test_graph2.txt";
    std::ofstream outfile(tempFileName);
    outfile << "3\n";
    outfile << "0,1\n";
    outfile << "1,2\n";
    outfile << "\n";
    outfile.close();

    int n = CReadInput::GetVertexQuantity(tempFileName);
    ASSERT_EQ(n, 3);
    CGraph graph(n);
    CReadInput::ReadInput(tempFileName, &graph);

    // Now graph should have edges (0-1) and (1-2) added:
    EXPECT_TRUE(graph.Adjacent(0,1));
    EXPECT_TRUE(graph.Adjacent(1,2));
    EXPECT_FALSE(graph.Adjacent(0,2));  // No direct edge between 0 and 2 in the input.
    // Check degrees:
    EXPECT_EQ(graph.Degree(0), 1);
    EXPECT_EQ(graph.Degree(1), 2);
    EXPECT_EQ(graph.Degree(2), 1);
    // The adjacency lists should reflect exactly the input edges:contentReference[oaicite:54]{index=54}:
    CVertexAdjacencyList neighbors1 = graph.Neighbors(1);
    EXPECT_EQ(neighbors1.Size(), 2);
    EXPECT_TRUE(neighbors1.IsAnElement(0));
    EXPECT_TRUE(neighbors1.IsAnElement(2));

    remove(tempFileName);
}
