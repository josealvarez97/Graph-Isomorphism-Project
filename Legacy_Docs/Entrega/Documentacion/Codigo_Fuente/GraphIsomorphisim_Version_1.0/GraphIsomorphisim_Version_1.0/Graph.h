#pragma once
#include <iostream>
#include <array>
#include "VertexAdjacencyList.h"

class CGraph
{

private:

	int vertQuantity;
public:

	CVertexAdjacencyList** vertexArray;

	CGraph(int vertexCardinality);
	~CGraph();

	bool Adjacent(int x, int y); // tests whether there is and edge from vertices x to y
	CVertexAdjacencyList Neighbors(int x); // lists all vertices y such that there is an edge from the vertices x to y
	int Degree(int x); // returns the degree of vertex x
	
	void AddEdge(int x, int y); // adds the edge from the vertices x to y, if it is not there
	void RemoveEdge(int x, int y); // removes the edge from the vertices x to y, if it is there
	

	static CVertexAdjacencyList Dijkstra(CGraph G, int sourceVertex, int destinyVertex);
	static int LeastDistanceVertex(int* distanceValues);



	// Gets 
	int VertexQuantity() { return vertQuantity; }

	


	static bool Isomorphism(CGraph* G1, CGraph* G2);
	static bool CompareVerticesQuantity(CGraph* G1, CGraph* G2); //
	static bool CompareEdgesQuantity(CGraph* G1, CGraph* G2);
	static bool CompareVerticesPerDegreeTables(CGraph* G1, CGraph* G2);
	static void PrintGraphsInfo(CGraph* G1, CGraph* G2);
	static void PrintVertexDegreeTable(CGraph* G);
	static int GetEdgesQuantity(CGraph* G);
	static int* GetVertexDegreeTable(CGraph* G);// for an specific vertex, gives its degree...
	static int GetSumOfVerticesDegrees(CGraph* G); // sum of vertices degree...
	static int* GetVerticesQuantityPerDegreeTableClassification(CGraph* G);// para un determinado grado, cuantos vertices poseen ese grado en el grafo.



	static bool JJO(CVertexAdjacencyList* vertexArray_A[], CVertexAdjacencyList* vertexArray_B[], CVertexAdjacencyList* A /*vertex A*/, CVertexAdjacencyList* B /*vertex B*/);

	
	static bool JJO(CGraph * G1, CGraph* G2);


	static int AvailableAdjacents(CVertexAdjacencyList* A, int table);
	static bool Assigned(int vertex, int table);
	static void UncoverInTable(int VertexA, int VertexB);
	static void CrossOutInTable(int vertexA, int vertexB);

	

	static bool CheckIsomorphismTable(CGraph* G1, CGraph* G2);
	static bool CheckIsomorphismTableAdjacentVertices(CVertexAdjacencyList* A, CVertexAdjacencyList* B);


	static bool CheckRedPairs(CVertexAdjacencyList * A, CVertexAdjacencyList * B);
};

