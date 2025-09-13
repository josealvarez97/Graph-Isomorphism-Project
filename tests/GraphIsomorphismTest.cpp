// tests/GraphIsomorphismTest.cpp
#include <gtest/gtest.h>
#include "../GraphIsomorphisim_Version_1.0/Graph.h"

// Algorithm doesn't always handle well disconnected graphs yet. It probably could with recursion. Anyways, be careful.
TEST(GraphIsomorphismTest, GraphIsomorphicToItselfDisconnected) {
    // A graph is always isomorphic to itself (identity mapping).
    CGraph g1(5);
    // Add some edges to g1:
    g1.AddEdge(0,1);
    g1.AddEdge(0,2);
    g1.AddEdge(3,4);
    // Create a second graph g2 with the same edges:
    CGraph g2(5);
    g2.AddEdge(0,1);
    g2.AddEdge(0,2);
    g2.AddEdge(3,4);
    EXPECT_TRUE(CGraph::Isomorphism(&g1, &g2));
    EXPECT_TRUE(CGraph::Isomorphism(&g1, &g1));  // sanity check: a graph vs itself.
}

TEST(GraphIsomorphismTest, GraphIsomorphicToItself) {
    // A graph is always isomorphic to itself (identity mapping).
    CGraph g1(5);
    // Add some edges to g1:
    g1.AddEdge(0,1);
    g1.AddEdge(0,2);
    g1.AddEdge(3,4);
    g1.AddEdge(2,3);  // NEW EDGE to connect the two components, now fully connected

    // Create a second graph g2 with the same edges:
    CGraph g2(5);
    g2.AddEdge(0,1);
    g2.AddEdge(0,2);
    g2.AddEdge(3,4);
    g2.AddEdge(2,3);  // also add this edge

    EXPECT_TRUE(CGraph::Isomorphism(&g1, &g2));
    EXPECT_TRUE(CGraph::Isomorphism(&g1, &g1));  // sanity check: a graph vs itself.
}


TEST(GraphIsomorphismTest, DifferentVertexCountNotIsomorphic) {
    CGraph g1(3);
    CGraph g2(4);
    // Even without edges, vertex count differs, so should return false immediately:contentReference[oaicite:45]{index=45}.
    EXPECT_FALSE(CGraph::Isomorphism(&g1, &g2));
}

TEST(GraphIsomorphismTest, DifferentEdgeCountNotIsomorphic) {
    CGraph g1(4);
    CGraph g2(4);
    // g1: one edge, g2: two edges (different edge counts)
    g1.AddEdge(0,1);
    g2.AddEdge(0,1);
    g2.AddEdge(2,3);
    // Same number of vertices but edge counts differ (1 vs 2), expect false:contentReference[oaicite:46]{index=46}.
    EXPECT_FALSE(CGraph::Isomorphism(&g1, &g2));
}

TEST(GraphIsomorphismTest, DifferentDegreeSequenceNotIsomorphic) {
    CGraph g1(4);
    CGraph g2(4);
    // g1: star structure (0 connected to 1,2,3 -> degree sequence [3,1,1,1])
    g1.AddEdge(0,1);
    g1.AddEdge(0,2);
    g1.AddEdge(0,3);
    // g2: chain structure (0-1-2-3 -> degree sequence [1,2,2,1])
    g2.AddEdge(0,1);
    g2.AddEdge(1,2);
    g2.AddEdge(2,3);
    // They have same vertex and edge count (4 vertices, 3 edges each) but different degree distributions.
    EXPECT_FALSE(CGraph::Isomorphism(&g1, &g2));  // Should fail on degree table comparison:contentReference[oaicite:47]{index=47}.
}

TEST(GraphIsomorphismTest, NonIsomorphicSameDegreeSequence) {
    // Construct two graphs with identical degree sequences and edge counts, but non-isomorphic.
    // Example: G1 = two disjoint triangles, G2 = one cycle of length 6. Both have 6 vertices and 6 edges, all vertices degree 2.
    CGraph g1(6);
    CGraph g2(6);
    // g1: two triangles (components: {0,1,2} and {3,4,5})
    g1.AddEdge(0,1); g1.AddEdge(1,2); g1.AddEdge(2,0);
    g1.AddEdge(3,4); g1.AddEdge(4,5); g1.AddEdge(5,3);
    // g2: one cycle of 6 (0-1-2-3-4-5-0)
    g2.AddEdge(0,1); g2.AddEdge(1,2); g2.AddEdge(2,3);
    g2.AddEdge(3,4); g2.AddEdge(4,5); g2.AddEdge(5,0);
    // Quick checks pass (both have 6 vertices, 6 edges, each vertex deg 2), but graphs are not isomorphic (g1 is disconnected, g2 is connected).
    EXPECT_FALSE(CGraph::Isomorphism(&g1, &g2));  // The backtracking search should eventually fail to find a mapping.
}

TEST(GraphIsomorphismTest, IsomorphicGraphsDifferentLabeling) {
    // Graphs with the same structure but different vertex labels should be isomorphic.
    // Example: star vs chain for 3 vertices (both have one vertex of deg2 and two of deg1).
    CGraph star(3);
    star.AddEdge(0,1);
    star.AddEdge(0,2);
    // star: vertex0 deg2, vertex1 deg1, vertex2 deg1.
    CGraph chain(3);
    chain.AddEdge(1,2);
    chain.AddEdge(0,1);
    // chain: vertex1 deg2, vertex0 deg1, vertex2 deg1.
    // These two graphs are isomorphic (mapping star's center (0) -> chain's center (1), etc.).
    EXPECT_TRUE(CGraph::Isomorphism(&star, &chain));

    // Another test: a square cycle vs the same cycle with relabeled vertices.
    CGraph cycle1(4);
    cycle1.AddEdge(0,1); cycle1.AddEdge(1,2);
    cycle1.AddEdge(2,3); cycle1.AddEdge(3,0);  // Edges: 0-1-2-3-0 (a 4-cycle)
    CGraph cycle2(4);
    // Relabel cycle1: map {0->2, 1->3, 2->0, 3->1} (just an example permutation)
    cycle2.AddEdge(2,3);
    cycle2.AddEdge(3,0);
    cycle2.AddEdge(0,1);
    cycle2.AddEdge(1,2);
    // Both are 4-cycles, so should be isomorphic.
    EXPECT_TRUE(CGraph::Isomorphism(&cycle1, &cycle2));
}
