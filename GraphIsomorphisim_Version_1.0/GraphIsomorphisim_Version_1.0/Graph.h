#pragma once
#include <iostream>
#include <array>
#include "SinglyLinkedList.h"

class CGraph
{

private:
	CSinglyLinkedList* vertexArray;
	int vertQuantity;
public:
	CGraph(int vertexCardinality);
	~CGraph();

	bool Adjacent(int x, int y); // tests whether there is and edge from vertices x to y
	CSinglyLinkedList Neighbors(int x); // lists all vertices y such that there is an edge from the vertices x to y
	int Degree(int x); // returns the degree of vertex x
	//static void Add_vertex(CGraph G, int x); // adds the vertex x, if it is not there;
	//static void Remove_vertex(Cgraph G, int x, y); // adds theedge from the vertices x to y, if it is not there
	void Add_edge(int x, int y); // adds the edge from the vertices x to y, if it is not there
	void Remove_edge(int x, int y); // removes the edge from the vertices x to y, if it is there
	//static void Get_vertex_value(CGraph G, int x, int y); // returns the value associated with the vertex x
	//static void Set_vertex_value(CGraph G, int x, int v); // sets the value associated with the vertex x to v
	//Structures that associate values to the edges usually also provide
	//static void Get_edge_value(CGraph G, int x, int y); // returns the value associated with the edge (x,y)
	//static void Set_edge_value(CGraph G, int x, int y, int v); // sets the value associated with the edge (x,y) to v

	static CSinglyLinkedList Dijkstra(CGraph G, int sourceVertex, int destinyVertex);
	static int LeastDistanceVertex(int* distanceValues);



	// Gets 
	int VertexQuantity() { return vertQuantity; }

	//DoubleLinkedList variable[4];

	//int n = 0;
	//int* arrayDinamico = (int*)malloc(n * sizeof(int));


	static bool Isomorphism(CGraph G1, CGraph G2);

	static bool CompareVerticesQuantity(CGraph* G1, CGraph* G2);
	static int* GetVertexDegreeTable(CGraph* G);
	static int GetSumOfVerticesDegrees(CGraph* G);
	static int* GetVerticesQuantityPerDegreeTableClassification(CGraph* G);


	


};

