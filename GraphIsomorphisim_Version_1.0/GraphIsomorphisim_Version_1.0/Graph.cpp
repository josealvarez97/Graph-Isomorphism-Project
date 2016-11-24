#include "Graph.h"



CGraph::CGraph(int vertexCardinality)
{
	this->vertexArray = new CSinglyLinkedList[vertexCardinality];
	this->vertexCardinality = vertexCardinality;
}


CGraph::~CGraph()
{
}


bool CGraph::Adjacent(int x, int y)
{

	if (vertexArray[x].IsAnElement(y))
		return true;
	
	return false;
}

CSinglyLinkedList CGraph::Neighbors(int x)
{
	return vertexArray[x];
}

int CGraph::Degree(int x)
{
	return vertexArray[x].Size();
}

void CGraph::Add_edge(int x, int y)
{
	vertexArray[x].Add(y);
	vertexArray[y].Add(x);
}

void CGraph::Remove_edge(int x, int y)
{
}

CSinglyLinkedList CGraph::Dijkstra(CGraph G, int sourceVertex, int destinyVertex)
{
	int* distancesValues = new int[G.VertexCardinality()];
	CSinglyLinkedList visitedNodesSet;
	CSinglyLinkedList unvisitedNodesSet;

	int current;
	int lengthTraversed = 0;



	// Assign To Every Node A Tentative Distance Value. Initialization
	distancesValues[sourceVertex] = 0;
	for (int i = 0; G.VertexCardinality(); i++)
		if (i != sourceVertex)
			distancesValues[i] = INT_MAX; //Infity

	// Mark the one with the least distance value as current. Initialization & any other Iteration
	current = LeastDistanceVertex(distancesValues);


	lengthTraversed += distancesValues[current];
	// Alternative checking algorithm
	if(distancesValues[current] < distancesValues[current] + )

	return CSinglyLinkedList();
}

int CGraph::LeastDistanceVertex(int * distanceValues)
{
	return 0;
}
