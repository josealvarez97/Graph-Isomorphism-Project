#include "Graph.h"

static bool* G1_CrossedOutTable;
static bool* G2_CrossedOutTable;
static int* IsomorphismTable;


CGraph::CGraph(int vertexCardinality)
{
	this->vertexArray = new CVertexAdjacencyList[vertexCardinality];
	for (int i = 0; i < vertexCardinality; i++)
	{
		vertexArray->SetVertexValue(i);
	}


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

CVertexAdjacencyList CGraph::Neighbors(int x)
{
	return vertexArray[x];
}

int CGraph::Degree(int x)
{
	return vertexArray[x].Size();
}

void CGraph::AddEdge(int x, int y)
{
	vertexArray[x].Add(y);
	vertexArray[y].Add(x);
}

void CGraph::RemoveEdge(int x, int y)
{
}

CVertexAdjacencyList CGraph::Dijkstra(CGraph G, int sourceVertex, int destinyVertex)
{
	int* distancesValues = new int[G.VertexQuantity()];
	CVertexAdjacencyList visitedNodesSet;
	CVertexAdjacencyList unvisitedNodesSet;

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

	return CVertexAdjacencyList();
}

int CGraph::LeastDistanceVertex(int * distanceValues)
{
	return 0;
}

bool CGraph::Isomorphism(CGraph G1, CGraph G2)
{
	return false;
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

bool CGraph::JJO(CVertexAdjacencyList* vertexArray_A[], CVertexAdjacencyList* vertexArray_B[], CVertexAdjacencyList * A, CVertexAdjacencyList * B/*, bool* G1_availabilityTable, bool* G2_availabilityTable, int* IsomorphismTable*/)
{
	if (Available(A, 1) == Available(B, 2)
		&& Available(A, 1) != 0)
	{
		CrossOutInTable(A->Value(), B->Value());

		int A_1 = 0;
		int B_1 = 0;

		while (A_1 + 1 < A->Size())
		{
			while (Assigned(A->ElementAtIndex(A_1), 1) && A_1 + 1 < A->Size())
			{
				A_1++;
			}
			while (Assigned(B->ElementAtIndex(B_1), 2) && (A->Size()/*degree*/ == B->Size()/*degree*/))
			{
				if (B_1 + 1 < B->Size())
				{
					B_1++;
				}
				else
					return false;
			}

			while (JJO(vertexArray_A, vertexArray_B, vertexArray_A[A_1], vertexArray_B[B_1]) == false)
			{
				while (Assigned(B->ElementAtIndex(B_1), 2) && (A->Size()/*degree*/ == B->Size()/*degree*/))
				{
					if (B_1 + 1 < B->Size())
					{
						B_1++;
					}
					else
						return false;
				}
			}
			A_1++;
		}
		return true;
	}

	else if (Available(A, 1) == Available(B, 2) && Available(A, 1) == 0)
	{
		return true;
	}
	else
	{
		UncoverInTable(A->Value(), B->Value());
		return false;
	}
}

bool CGraph::JJO(CVertexAdjacencyList* vertexArray_G1[], CVertexAdjacencyList* vertexArray_G2[], CGraph * G1, CGraph * G2)
{
	//Esta es una trampa bien cocha
	//CVertexAdjacencyList* vertexArray = G1->vertexArray;

	// Asumiendo solo llamaremos a JJO para grafos con igual numero n de vertices
	G1_CrossedOutTable = new bool[G1->VertexQuantity()];
	G2_CrossedOutTable = new bool[G2->VertexQuantity()];

	// set all default values in false
	for (int i = 0; i < G1->VertexQuantity(); i++)
	{
		G1_CrossedOutTable[i] = false;
		G2_CrossedOutTable[i] = false;
	}

	//int IsomorphismTable[2][G1->VertexQuantity()];
	IsomorphismTable = new int[G1->VertexQuantity()]; // position is a G1 vertex, and the value the assigned vertex of G2
	for (int i = 0; i < G1->VertexQuantity(); i++)
	{
		IsomorphismTable[i] = -1;
	}

	JJO(vertexArray_G1, vertexArray_G2, vertexArray_G1[0], vertexArray_G2[0]);

	//G1vertexArray[0];
	//vertexArray_G1[0];
	//while()
	//for (int i = 0; i < G1->VertexQuantity(); i++)
	//{
	//	for (int j = 0; i < G2->VertexQuantity(); j++)
	//	{
	//		while (JJO(vertexArray, vertexArray[i], vertexArray[j]));

	//	}
	//}

	//JJO(vertexArray)

	/*JJO(vertexArray, vertexArray[1], vertexArray[1]);*/

	// Llamar a JJO especifico
	return false;
}

// Returns how many vertices are not "red"
int CGraph::Available(CVertexAdjacencyList * A, int table)
{
	int count = 0;
	for (int i = 0; i < A->Size(); i++)
	{
		if (Assigned(A->ElementAtIndex(i), table) == false) // not crossed out or ("not red") means its available. 
			count++;
	}
	return count;
}

bool CGraph::Assigned(int vertex, int table)
{
	switch (table)
	{
	case 1:
		if (G1_CrossedOutTable[vertex]) // if true means its crossed out or assigned. Assigned means red
			return true;
	case 2:
		if (G2_CrossedOutTable[vertex])
			return true;
	default:
		//return false;
	}
	return false;


}

//change the boolean asignation value of vertices A and B; removes B in the A position at the isomorphismTable. 
void CGraph::UncoverInTable(int vertexA, int vertexB)
{
	G1_CrossedOutTable[vertexA] = false;
	G2_CrossedOutTable[vertexB] = false;

	IsomorphismTable[vertexA] = -1;
}


//change the boolean asignation value of vertices A and B; assigns B in the A position at the isomorphismTable.
void CGraph::CrossOutInTable(int vertexA, int vertexB)
{
	//G1_CrossedOutTable
	//G2_CrossedOutTable
	//IsomorphismTable;

	G1_CrossedOutTable[vertexA] = true;
	G2_CrossedOutTable[vertexB] = true;

	IsomorphismTable[vertexA] = vertexB;
}
