// tests/GraphTest.cpp
#include <gtest/gtest.h>
#include "../GraphIsomorphisim_Version_1.0/Graph.h"
#include "../GraphIsomorphisim_Version_1.0/ReadInput.h"  // (Include if ReadInput needed for some tests)

TEST(CGraphTest, ConstructorInitializesVertices) {
    const int N = 5;
    CGraph graph(N);
    EXPECT_EQ(graph.VertexQuantity(), N);
    // Each vertex's adjacency list should be allocated and empty:
    for (int v = 0; v < N; ++v) {
        // The adjacency list exists and its Value is set to the vertex index:contentReference[oaicite:30]{index=30}.
        ASSERT_NE(graph.vertexArray[v], nullptr);
        EXPECT_EQ(graph.vertexArray[v]->Value(), v);
        EXPECT_EQ(graph.vertexArray[v]->Size(), 0);
    }
}

TEST(CGraphTest, AddEdgeUndirectedAdjacency) {
    CGraph graph(3);
    // No edges initially:
    EXPECT_FALSE(graph.Adjacent(0,1));
    EXPECT_EQ(graph.Degree(0), 0);
    EXPECT_EQ(graph.Degree(1), 0);

    graph.AddEdge(0, 1);  // add an edge between 0 and 1:contentReference[oaicite:31]{index=31}

    // Edge should be reflected in both directions:
    EXPECT_TRUE(graph.Adjacent(0, 1));  // 1 is neighbor of 0
    EXPECT_TRUE(graph.Adjacent(1, 0));  // 0 is neighbor of 1
    // Degrees should update:
    EXPECT_EQ(graph.Degree(0), 1);
    EXPECT_EQ(graph.Degree(1), 1);
    EXPECT_EQ(graph.Degree(2), 0);  // Vertex 2 remains isolated
    // Neighbors list should contain the connected vertex:
    CVertexAdjacencyList neighbors0 = graph.Neighbors(0);
    EXPECT_EQ(neighbors0.Size(), 1);
    EXPECT_TRUE(neighbors0.IsAnElement(1));  // 1 should appear in 0's neighbor list

    // Add another edge and verify:
    graph.AddEdge(0, 2);
    EXPECT_TRUE(graph.Adjacent(0, 2));
    EXPECT_TRUE(graph.Adjacent(2, 0));
    EXPECT_EQ(graph.Degree(0), 2);
    EXPECT_EQ(graph.Degree(2), 1);
    // Now 0's neighbors should be {1,2}:
    neighbors0 = graph.Neighbors(0);
    EXPECT_EQ(neighbors0.Size(), 2);
    EXPECT_TRUE(neighbors0.IsAnElement(1));
    EXPECT_TRUE(neighbors0.IsAnElement(2));
    EXPECT_FALSE(neighbors0.IsAnElement(0));  // 0 should not list itself
}

TEST(CGraphTest, AddEdgeDuplicateAllowsDuplicates) {
    CGraph graph(2);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 1);  // add the same edge again (duplicate)
    // Degrees increase twice because duplicates are not prevented:
    EXPECT_EQ(graph.Degree(0), 2);
    EXPECT_EQ(graph.Degree(1), 2);
    // Adjacent remains true (edge exists):
    EXPECT_TRUE(graph.Adjacent(0, 1));
    EXPECT_TRUE(graph.Adjacent(1, 0));
    // The neighbors list for 0 will contain two entries of 1 (duplicate edge) due to lack of duplicate check:contentReference[oaicite:32]{index=32}.
    CVertexAdjacencyList neighbors0 = graph.Neighbors(0);
    EXPECT_EQ(neighbors0.Size(), 2);
    EXPECT_EQ(neighbors0.ElementAtIndex(0), 1);
    EXPECT_EQ(neighbors0.ElementAtIndex(1), 1);
}

TEST(CGraphTest, RemoveEdgeNoEffect) {
    CGraph graph(2);
    graph.AddEdge(0, 1);
    EXPECT_TRUE(graph.Adjacent(0, 1));
    graph.RemoveEdge(0, 1);  // This function is not implemented:contentReference[oaicite:33]{index=33}.
    // The edge should still exist (no removal happened):
    EXPECT_TRUE(graph.Adjacent(0, 1));
    EXPECT_TRUE(graph.Adjacent(1, 0));
    EXPECT_EQ(graph.Degree(0), 1);
    EXPECT_EQ(graph.Degree(1), 1);
}

TEST(CGraphTest, AdjacentAndDegreeWithNoEdges) {
    CGraph graph(4);
    // In a new graph with no edges, Adjacent should return false for any pair:
    EXPECT_FALSE(graph.Adjacent(0, 3));
    EXPECT_FALSE(graph.Adjacent(2, 1));
    // Degrees should all be zero:
    for (int v = 0; v < 4; ++v) {
        EXPECT_EQ(graph.Degree(v), 0);
    }
}

TEST(CGraphTest, StaticCompareVerticesQuantity) {
    CGraph g1(3);
    CGraph g2(3);
    CGraph g3(4);
    EXPECT_TRUE(CGraph::CompareVerticesQuantity(&g1, &g2));   // both have 3 vertices:contentReference[oaicite:34]{index=34}.
    EXPECT_FALSE(CGraph::CompareVerticesQuantity(&g1, &g3));  // 3 vs 4 vertices.
}

TEST(CGraphTest, StaticEdgesCountAndCompare) {
    CGraph g1(4);
    CGraph g2(4);
    // Build g1 with 2 edges and g2 with 3 edges:
    // g1: edges between (0-1) and (2-3)
    g1.AddEdge(0, 1);
    g1.AddEdge(2, 3);
    // g2: edges between (0-1), (0-2), (0-3)
    g2.AddEdge(0, 1);
    g2.AddEdge(0, 2);
    g2.AddEdge(0, 3);
    // Edge counts:
    EXPECT_EQ(CGraph::GetEdgesQuantity(&g1), 2);  // 2 edges expected:contentReference[oaicite:35]{index=35}.
    EXPECT_EQ(CGraph::GetEdgesQuantity(&g2), 3);
    // CompareEdgesQuantity should reflect the difference:contentReference[oaicite:36]{index=36}:
    EXPECT_FALSE(CGraph::CompareEdgesQuantity(&g1, &g2));
    // If we add one more edge to g1 to also have 3 edges:
    g1.AddEdge(1, 2);
    EXPECT_EQ(CGraph::GetEdgesQuantity(&g1), 3);
    EXPECT_TRUE(CGraph::CompareEdgesQuantity(&g1, &g2));  // now both have 3 edges.
}

TEST(CGraphTest, StaticDegreeTableFunctions) {
    // Graph with 4 vertices where:
    // Vertex 0 connected to 1,2,3 (deg 3), vertices 1,2,3 each connected only to 0 (deg 1).
    CGraph starGraph(4);
    starGraph.AddEdge(0, 1);
    starGraph.AddEdge(0, 2);
    starGraph.AddEdge(0, 3);
    // Degrees should be [3,1,1,1].
    int* degreeTable = CGraph::GetVertexDegreeTable(&starGraph);
    // Sort the degree table for easier comparison (optional, but here we check each index directly):
    EXPECT_EQ(degreeTable[0], 3);
    EXPECT_EQ(degreeTable[1], 1);
    EXPECT_EQ(degreeTable[2], 1);
    EXPECT_EQ(degreeTable[3], 1);
    // Sum of degrees should be 3+1+1+1 = 6:
    EXPECT_EQ(CGraph::GetSumOfVerticesDegrees(&starGraph), 6);  // Should equal 2 * (#edges=3):contentReference[oaicite:37]{index=37}.
    delete [] degreeTable;  // Clean up allocated array from GetVertexDegreeTable.

    // Degree distribution table:
    int* degDist = CGraph::GetVerticesQuantityPerDegreeTableClassification(&starGraph);
    // For 4 vertices, indices 0..3 represent degree counts:
    // Expect: one vertex of deg3, three vertices of deg1, zero of deg0 and deg2.
    EXPECT_EQ(degDist[0], 0);  // 0 vertices of degree 0
    EXPECT_EQ(degDist[1], 3);  // 3 vertices of degree 1
    EXPECT_EQ(degDist[2], 0);  // 0 vertices of degree 2
    EXPECT_EQ(degDist[3], 1);  // 1 vertex  of degree 3
    delete [] degDist;

    // CompareVerticesPerDegreeTables should detect if two graphs have the same degree sequence:contentReference[oaicite:38]{index=38}.
    CGraph chainGraph(4);
    // Create a "chain" graph: 0-1-2-3 (which yields degrees [1,2,2,1], sorted [2,2,1,1]).
    chainGraph.AddEdge(0, 1);
    chainGraph.AddEdge(1, 2);
    chainGraph.AddEdge(2, 3);
    // The starGraph had degree multiset [3,1,1,1] (sorted [3,1,1,1]).
    EXPECT_FALSE(CGraph::CompareVerticesPerDegreeTables(&starGraph, &chainGraph));
    // Now create another star-like graph to compare:
    CGraph starGraph2(4);
    starGraph2.AddEdge(1, 0);
    starGraph2.AddEdge(2, 0);
    starGraph2.AddEdge(3, 0);
    // starGraph2 has the same degree distribution [3,1,1,1] as starGraph.
    EXPECT_TRUE(CGraph::CompareVerticesPerDegreeTables(&starGraph, &starGraph2));
}
