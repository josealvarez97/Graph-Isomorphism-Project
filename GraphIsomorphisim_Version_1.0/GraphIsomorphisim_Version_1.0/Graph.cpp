#include "Graph.h"



CGraph::CGraph(int vertexCardinality)
{
	this->vertexArray = new CSinglyLinkedList[vertexCardinality];
	this->vertQuantity = vertexCardinality;
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
	int* distancesValues = new int[G.VertexQuantity()];
	CSinglyLinkedList visitedNodesSet;
	CSinglyLinkedList unvisitedNodesSet;

	int current;
	int lengthTraversed = 0;



	// Assign To Every Node A Tentative Distance Value. Initialization
	distancesValues[sourceVertex] = 0;
	for (int i = 0; G.VertexQuantity(); i++)
		if (i != sourceVertex)
			distancesValues[i] = INT_MAX; //Infity

	// Mark the one with the least distance value as current. Initialization & any other Iteration
	current = LeastDistanceVertex(distancesValues);


	lengthTraversed += distancesValues[current];
	// Alternative checking algorithm
	//if(distancesValues[current] < distancesValues[current] + )

	return CSinglyLinkedList();
}

int CGraph::LeastDistanceVertex(int * distanceValues)
{
	return 0;
}

bool CGraph::CompareVerticesQuantity(CGraph* G1, CGraph* G2)
{
	return G1->VertexQuantity() == G2->VertexQuantity();
}

int * CGraph::GetVertexDegreeTable(CGraph * G)
{

	int* classificationArray = new int[G->VertexQuantity()];

	for (int i = 0; i < G->VertexQuantity(); i++)
		classificationArray[i] = G->Degree(i);


	return classificationArray;
}

int CGraph::GetSumOfVerticesDegrees(CGraph * G)
{

	int* degreeTable = GetVertexDegreeTable(G);
	//int* classificationArray = new int[G->VertexQuantity()];

	//for (int i = 0; i < G->VertexQuantity(); i++)
	//	classificationArray[i] = G->Degree(i);
	int degreeSum = 0;
	for (int i = 0; i < G->VertexQuantity(); i++)
		degreeSum += degreeTable[i];

	return degreeSum;
}

int * CGraph::GetVerticesQuantityPerDegreeTableClassification(CGraph * G)
{
	int* degreeTable = GetVertexDegreeTable(G);
	int* verticesQuantityPerDegreeTable = new int[G->VertexQuantity() /*- 1*/];


	// Inicializar valores en array
	for (int i = 0; i < G->VertexQuantity(); i++)
	{
		verticesQuantityPerDegreeTable[i] = 0;
	}

	// Asignar valores a tabla
	for (int i = 0; i < G->VertexQuantity(); i++)
	{
		verticesQuantityPerDegreeTable[degreeTable[i]]++; // Vertice i, tiene grado tanto, entonces vaya a position tanto de verticesQuantityPerDegreeTable y aumente uno.
	}



	return verticesQuantityPerDegreeTable;
}
