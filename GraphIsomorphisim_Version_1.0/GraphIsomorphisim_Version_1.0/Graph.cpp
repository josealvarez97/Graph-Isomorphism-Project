#include "Graph.h"

static bool* G1_CrossedOutTable;
static bool* G2_CrossedOutTable;
static int* IsomorphismTable;


CGraph::CGraph(int vertexCardinality)
{
	vertexArray = new CVertexAdjacencyList*[vertexCardinality];


	for (int i = 0; i < vertexCardinality; i++)
	{
		vertexArray[i] = new CVertexAdjacencyList();
		vertexArray[i]->SetVertexValue(i);
	}


	this->vertQuantity = vertexCardinality;
}



CGraph::~CGraph()
{
}


bool CGraph::Adjacent(int x, int y)
{

	if (vertexArray[x]->IsAnElement(y))
		return true;

	return false;
}

CVertexAdjacencyList CGraph::Neighbors(int x)
{
	return *vertexArray[x];
}

int CGraph::Degree(int x)
{
	return vertexArray[x]->Size();
}

void CGraph::AddEdge(int x, int y)
{
	vertexArray[x]->Add(y);
	vertexArray[y]->Add(x);
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
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "Analizando vertice/lista: " << A->Value() << " & " << B->Value() << std::endl;
	std::cout << "A: "; A->PrintList(); std::cout << endl;
	std::cout << "B: "; B->PrintList(); std::cout << endl;


	if (Available(A, 1) == Available(B, 2)
		&& Available(A, 1) != 0)// Checkear disponibilidad
	{
		std::cout << "CrossOut: " << A->Value() << " & " << B->Value() << std::endl;
		CrossOutInTable(A->Value(), B->Value()); // Marcar En Tabla

		int A_1 = 0; // SERA QUE ESTOS CONTADORES SON GLOBALES O LOCAes?????
		int B_1 = 0;


		while (A_1 /*+ 1*/ < A->Size() /*&& Assigned(A_1 + 1, 1)*/
			&& Available(A, 1) == Available(B, 2)
			&& Available(A, 1) != 0)
		{
			while (Assigned(A->ElementAtIndex(A_1), 1) && A_1 + 1 < A->Size())
			{
				A_1++;
			}
			std::cout << "A_1 se sumo hasta " << A_1 << std::endl;

			while (Assigned(B->ElementAtIndex(B_1), 2) || (A->Size()/*degree*/ != B->Size()/*degree*/))
			{
				if (B_1 + 1 < B->Size())
				{
					B_1++;
				}
				else
					return false;
			}
			std::cout << "B_1 se sumo hasta " << B_1 << std::endl;

			while (JJO(vertexArray_A, vertexArray_B, vertexArray_A[A->ElementAtIndex(A_1)], vertexArray_B[B->ElementAtIndex(B_1)]) == false)
			{
				std::cout << "JJO de A: " << A->Value() << "y B: " << B->Value() << " dio false" << std::endl;
				// Queremos que sume
				if (B_1 + 1 < B->Size())
				{
					B_1++;
					std::cout << "Sumamos uno a B_1 = " << B->Value() << std::endl;
				}
				else
				{

					UncoverInTable(A->Value(), B->Value());
					std::cout << "UncoverInTable = " << A->Value() << ", " << B->Value() << std::endl;
					for (int i = 0; i < 6; i++)
					{

						std::cout << i << " -> " << G1_CrossedOutTable[i] << std::endl;
						std::cout << i << " -> " << G2_CrossedOutTable[i] << std::endl;

					}

					return false;
				}
				// Pero nos aseguramos que sume lo necesario
				while (Assigned(B->ElementAtIndex(B_1), 2) || (A->Size()/*degree*/ != B->Size()/*degree*/))
				{
					if (B_1 + 1 < B->Size())
					{
						B_1++;
					}
					else
					{
						UncoverInTable(A->Value(), B->Value());
						std::cout << "UncoverInTable = " << A->Value() << ", " << B->Value() << std::endl;
						std::cout << "G1_CrossedOutTable: " << std::endl;
						for (int i = 0; i < 6; i++)
						{
							if (G1_CrossedOutTable[i])
								std::cout << i << " -> " << "True" << std::endl;
							else
								std::cout << i << " -> " << "false" << std::endl;

						}
						std::cout << "G2_CrossedOutTable: " << std::endl;
						for (int i = 0; i < 6; i++)
						{
							if (G2_CrossedOutTable[i])
								std::cout << i << " -> " << "True" << std::endl;
							else
								std::cout << i << " -> " << "false" << std::endl;

						}
						return false;
					}
				}
			}
			//while (Assigned(A->ElementAtIndex(A_1/* + 1*/), 1) == false) // if its not assigned. // esta validacion va en el while
			//{
			//	A_1++;
			//}
		}
		return true;
	}

	else if (Available(A, 1) == Available(B, 2) && Available(A, 1) == 0)
	{
		CrossOutInTable(A->Value(), B->Value()); // Marcar En Tabla
		std::cout << "FUNCION ISOMORFISMO SIN SWAP" << std::endl;
		std::cout << "G1" << " -> " << "G2" << std::endl;

		for (int i = 0; i < 8; i++)
		{
			std::cout << i << " -> " << IsomorphismTable[i] << std::endl;
		}
		return true;
	}
	else
	{
		//UncoverInTable(A->Value(), B->Value());
		return false;
	}
}

bool CGraph::JJO(/*CVertexAdjacencyList* vertexArray_G1[], CVertexAdjacencyList* vertexArray_G2[],*/ CGraph* G1, CGraph * G2)
{
	//Esta es una trampa bien cocha
	//CVertexAdjacencyList* vertexArray = G1->vertexArray;

	// Asumiendo solo llamaremos a JJO para grafos con igual numero n de vertices
	G1_CrossedOutTable = new bool[G1->VertexQuantity()];
	G2_CrossedOutTable = new bool[G2->VertexQuantity()];
	IsomorphismTable = new int[G1->VertexQuantity()]; // position is a G1 vertex, and the value the assigned vertex of G2


	//bool * prueba = new bool[G1->VertexQuantity()];
	//int * prubaint = new int[G1->VertexQuantity()];
	//int * pruebaint2 = new int[4];

	// set all default values in false
	for (int i = 0; i < G1->VertexQuantity(); i++)
	{
		G1_CrossedOutTable[i] = false;
		G2_CrossedOutTable[i] = false;
		IsomorphismTable[i] = -1;

	}


	//JJO(G1->vertexArray, G2->vertexArray, G1->vertexArray[1], G2->vertexArray[1]);


	// vertexArray lo interpreta como puntero a lista y no como arreglo. Listo, arreglado

	//JOO COPIA
	//if (Available(A, 1) == Available(B, 2)
	//	&& Available(A, 1) != 0)
	//{
		//CrossOutInTable(A->Value(), B->Value());

	int G1_i = 0;
	int G2_i = 0;


	if (JJO(G1->vertexArray, G2->vertexArray, G1->vertexArray[G1_i], G2->vertexArray[G2_i]))
	{

		CheckIsomorphismTable(G1, G2);
		return true;
	}
	else
	{
		cout << "FUNCION NO ENCONTRADA, GRAFOS NO SON ISOMORFOS" << endl;
		return false;
	}




	//	while (G1_i + 1 < G1->VertexQuantity())
	//	{
	//		while (Assigned(G1->vertexArray[G1_i]->Value(), 1) && G1_i + 1 < G1->VertexQuantity())
	//		{
	//			G1_i++;
	//		}
	//		while (Assigned(G2->vertexArray[G2_i]->Value(), 2) || (G1->Neighbors(G1_i).Size()/*degree*/ != G2->Neighbors(G2_i).Size()/*degree*/))
	//		{
	//			if (G2_i + 1 < G2->VertexQuantity())
	//			{
	//				G2_i++;
	//			}
	//			else
	//				return false;
	//		}
	//
	//		while (JJO(G1->vertexArray, G2->vertexArray, G1->vertexArray[G1_i], G2->vertexArray[G2_i]) == false)
	//		{
	//			while (Assigned(G2->vertexArray[G2_i]->Value(), 2) || (G1->Neighbors(G1_i).Size()/*degree*/ != G2->Neighbors(G2_i).Size()/*degree*/))
	//			{
	//				if (G2_i + 1 < G2->VertexQuantity())
	//				{
	//					G2_i++;
	//				}
	//				else
	//					return false;
	//			}
	//		}
	//		G1_i++;
	//	}
	//	return true;
	//}

	//else if (Available(A, 1) == Available(B, 2) && Available(A, 1) == 0)
	//{
	//	return true;
	//}
	//else
	//{
	//	UncoverInTable(A->Value(), B->Value());
	//	return false;
	// FIN JOO COPIA


	//return false;
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
		break;
	case 2:
		if (G2_CrossedOutTable[vertex])
			return true;
		break;
	default:
		//return false;
		break;
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

void CGraph::CheckIsomorphismTable(CGraph* G1, CGraph* G2)
{
	int i = 0;
	CVertexAdjacencyList * G1_vertex = new CVertexAdjacencyList();
	CVertexAdjacencyList* G2_vertex = new CVertexAdjacencyList();
	// VERTICES TO COMPARE
	// Compare vertices acording to isomorphism table.
	G1_vertex = G1->vertexArray[i];
	G2_vertex = G2->vertexArray[IsomorphismTable[i]];
	// DATA TO OBTAIN
	int G1_NoBijectionVertex = 0;
	int G2_NoBijectionVertex = 0;
	int G1_Index_NoBijectionVertex = 0;
	int G2_Index_NoBijectionVertex = 0;
	bool executeSwap = false;


	// FIND G1_NO_BIJECTION VERTEX

	// Check adjacents bijection
	int* miniCorrectIsomorphismTable = new int[G1->VertexQuantity()];
	for (int z = 0; z < G1->VertexQuantity(); z++)
		miniCorrectIsomorphismTable[z] = -1;

	for (int j = 0; j < G1->Degree(i); j++)
	{
		//CHECK IF THE VERTEX THE FUNCTION RETURNS IS IN G2_VERTEX ADJACENTS
		if (G2_vertex->IsAnElement(IsomorphismTable[G1_vertex->ElementAtIndex(j)]) == true) // Adjacent of G1_vertex has a corresponding adjacent to G2_vertex?
		{
			miniCorrectIsomorphismTable[G1_vertex->ElementAtIndex(j)] = IsomorphismTable[G1_vertex->ElementAtIndex(j)];
		}
		else
		{
			G1_NoBijectionVertex = G1_vertex->ElementAtIndex(j); // It's the element that doesn't have a correct bijection.
			executeSwap = true;
		}
	}
	if (executeSwap == false)
	{
		delete G1_vertex;
		delete G2_vertex;
		return;
	}

	// FIND G1_NoBijectionVertex INDEX
	G1_Index_NoBijectionVertex = G1_NoBijectionVertex;  // ITS JUST THE SAME THING, SINCE THE DOMAIN OF FUNCTION IS THE POSITION OF THE ARRAY



	// FIND G2_NO_BIJECTION_VERTEX
	bool iTsInArray = false;

	for (int a = 0; a < G2_vertex->Size(); a++) // Recorrer List (G2_vertex adjacents)
	{
		iTsInArray = false;

		for (int b = 0; b < G2->VertexQuantity(); b++) // Recorrer Array (miniIso Table)
		{
			if (G2_vertex->ElementAtIndex(a) == miniCorrectIsomorphismTable[b])
				iTsInArray = true;
		}

		if (iTsInArray == false)
		{
			G2_NoBijectionVertex = G2_vertex->ElementAtIndex(a);
			break;
		}
	}


	// FIND G2_NoBijectionVertex_INDEX

	for (int c = 0; c < G1->VertexQuantity(); c++) // Recorrer array (Iso table)
	{
		if (G2_NoBijectionVertex == IsomorphismTable[c])
		{
			G2_Index_NoBijectionVertex = c;
		}
	}



	// MAKE THE SWAP!!!!!!!!!!
	swap(IsomorphismTable[G1_Index_NoBijectionVertex], IsomorphismTable[G2_Index_NoBijectionVertex]);
	delete G1_vertex;
	delete G2_vertex;
	std::cout << "FUNCION ISOMORFISMO CON SWAP" << std::endl;
	std::cout << "G1" << " -> " << "G2" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << i << " -> " << IsomorphismTable[i] << std::endl;
	}
}

