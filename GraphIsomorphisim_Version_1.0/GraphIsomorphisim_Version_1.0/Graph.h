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
	//static void Add_vertex(CGraph G, int x); // adds the vertex x, if it is not there;
	//static void Remove_vertex(Cgraph G, int x, y); // adds theedge from the vertices x to y, if it is not there
	void AddEdge(int x, int y); // adds the edge from the vertices x to y, if it is not there
	void RemoveEdge(int x, int y); // removes the edge from the vertices x to y, if it is there
	//static void Get_vertex_value(CGraph G, int x, int y); // returns the value associated with the vertex x
	//static void Set_vertex_value(CGraph G, int x, int v); // sets the value associated with the vertex x to v
	//Structures that associate values to the edges usually also provide
	//static void Get_edge_value(CGraph G, int x, int y); // returns the value associated with the edge (x,y)
	//static void Set_edge_value(CGraph G, int x, int y, int v); // sets the value associated with the edge (x,y) to v

	static CVertexAdjacencyList Dijkstra(CGraph G, int sourceVertex, int destinyVertex);
	static int LeastDistanceVertex(int* distanceValues);



	// Gets 
	int VertexQuantity() { return vertQuantity; }

	//DoubleLinkedList variable[4];

	//int n = 0;
	//int* arrayDinamico = (int*)malloc(n * sizeof(int));


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

	
	static bool JJO(/*CVertexAdjacencyList* vertexArray_G1[], CVertexAdjacencyList* vertexArray_G2[], */CGraph * G1, CGraph* G2);


	static int Available(CVertexAdjacencyList* A, int table);
	static bool Assigned(int vertex, int table);
	static void UncoverInTable(int VertexA, int VertexB);
	static void CrossOutInTable(int vertexA, int vertexB);

	//static int SerachIndexInGraphArray(int vertexOfInterest);

	static bool CheckIsomorphismTable(CGraph* G1, CGraph* G2);
	static bool CheckIsomorphismTableAdjacentVertices(CVertexAdjacencyList* A, CVertexAdjacencyList* B);


	static bool CheckRedPairs(CVertexAdjacencyList * A, CVertexAdjacencyList * B);
};

