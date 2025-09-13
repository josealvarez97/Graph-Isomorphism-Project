// tests/GraphCasesTest.cpp
#include <gtest/gtest.h>
#include <string>
#include "../GraphIsomorphisim_Version_1.0/ReadInput.h"

#ifndef TEST_GRAPH_CASES_DIR
// Define TEST_GRAPH_CASES_DIR to the path of Cases directory (should be set via CMake).
#define TEST_GRAPH_CASES_DIR ""
#endif

static std::string caseFile(const std::string& name) {
    return std::string(TEST_GRAPH_CASES_DIR) + "/" + name;
}

TEST(GraphCasesTest, SampleGraphsAreIsomorphic) {
    std::string file1 = caseFile("Grafo1.txt");
    std::string file2 = caseFile("Grafo2.txt");
    // These files represent two graphs of 6 vertices that should be isomorphic (per project documentation).
    int n1 = CReadInput::GetVertexQuantity(file1);
    int n2 = CReadInput::GetVertexQuantity(file2);
    ASSERT_EQ(n1, n2);
    CGraph g1(n1);
    CGraph g2(n2);
    CReadInput::ReadInput(file1, &g1);
    CReadInput::ReadInput(file2, &g2);
    // According to the example output, these graphs are isomorphic and an isomorphism mapping exists:contentReference[oaicite:56]{index=56}:contentReference[oaicite:57]{index=57}.
    EXPECT_TRUE(CGraph::Isomorphism(&g1, &g2));
}

TEST(GraphCasesTest, AnotherPairIsomorphic) {
    // Example: Grafo9A.txt vs Grafo9B.txt (7 vertices each) are expected to be isomorphic.
    std::string fileA = caseFile("Grafo9A.txt");
    std::string fileB = caseFile("Grafo9B.txt");
    int nA = CReadInput::GetVertexQuantity(fileA);
    int nB = CReadInput::GetVertexQuantity(fileB);
    ASSERT_EQ(nA, nB);
    CGraph gA(nA);
    CGraph gB(nB);
    CReadInput::ReadInput(fileA, &gA);
    CReadInput::ReadInput(fileB, &gB);
    EXPECT_TRUE(CGraph::Isomorphism(&gA, &gB));
}

// (Additional tests can be added for non-isomorphic pairs if identified among provided Cases.)
