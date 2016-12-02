#include "Graph.h"
#include <iomanip> //for table format

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

bool CGraph::Isomorphism(CGraph* G1, CGraph* G2)
{
	bool VertexMatch = CompareVerticesQuantity(G1, G2);
	bool EdgesMath = CompareEdgesQuantity(G1, G2);
	bool VertexPerDegreeTableMatch = CompareVerticesPerDegreeTables(G1, G2);

	if (!VertexMatch)
		cout << "Number of vertices doesn't match" << endl;

	if (!EdgesMath)
		cout << "Number of edges doesn't match" << endl;

	if (!VertexPerDegreeTableMatch)
		cout << "Vertex Per Degree tables don't match" << endl;

	if (!VertexMatch || !EdgesMath || !VertexPerDegreeTableMatch)
	{
		cout << "THEREFORE, GRAPHS ARE NOT ISOMORPHIC" << endl;
		return false;
	}


	if (!JJO(G1, G2))
	{
		cout << "ISOMORPHISM FUNCTION NOT FOUND, GRAPHS ARE NOT ISOMORPHIC" << endl;
		return false;
	}
	else
	{
		//std::cout << "ISOMORPHISM FUNCTION" << std::endl;
		//std::cout << "G1" << " -> " << "G2" << std::endl;

		//for (int i = 0; i < G1->VertexQuantity(); i++)
		//{
		//	std::cout << i << " -> " << IsomorphismTable[i] << std::endl;
		//}
		//return true;
	}

}

bool CGraph::CompareVerticesQuantity(CGraph* G1, CGraph* G2)
{
	return G1->VertexQuantity() == G2->VertexQuantity();
}

int CGraph::GetEdgesQuantity(CGraph* G)
{
	int EdgesG = 0;

	EdgesG = (GetSumOfVerticesDegrees(G) / 2);

	return EdgesG;
}

bool CGraph::CompareEdgesQuantity(CGraph* G1, CGraph* G2)
{
	return GetEdgesQuantity(G1) == GetEdgesQuantity(G2);
}

bool CGraph::CompareVerticesPerDegreeTables(CGraph * G1, CGraph * G2)
{
	int * G1table = GetVerticesQuantityPerDegreeTableClassification(G1);
	int * G2table = GetVerticesQuantityPerDegreeTableClassification(G2);

	for (int i = 0; i < G1->VertexQuantity(); i++)
	{
		if (G1table[i] != G2table[i])
			return false;
	}
	return true;
}

void CGraph::PrintVertexDegreeTable(CGraph* G)
{
	cout << "|  | Degree | # of Vertex " << endl;
	for (int i = 0; i < G->VertexQuantity() - 1; i++)
	{
		cout << "|  |   " << i << "    |    ";
		int count = 0;
		for (int j = 0; j < G->VertexQuantity(); j++)
		{
			if (G->vertexArray[j]->Size() == i)
			{
				count++;
			}
		}
		cout << " " << count << endl;
	}
}

void CGraph::PrintGraphsInfo(CGraph* G1, CGraph* G2)
{
	cout << "|--------------------------------" << endl;
	cout << "| GRAPH A: " << endl;
	cout << "| - Vertices Quantity: " << G1->VertexQuantity() << endl;
	cout << "| - Edges Quantity: " << GetEdgesQuantity(G1) << endl;
	cout << "| - Vertex per Degree: " << endl;
	PrintVertexDegreeTable(G1);
	cout << "|--------------------------------" << endl;
	cout << "| GRAPH B: " << endl;
	cout << "| - Vertices Quantity: " << G2->VertexQuantity() << endl;
	cout << "| - Edges Quantity: " << GetEdgesQuantity(G2) << endl;
	cout << "| - Vertex per Degree: " << endl;
	PrintVertexDegreeTable(G2);
	cout << "|--------------------------------" << endl;
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
		&& Available(A, 1) != 0)// CHECKEAR LA DISPONIBILIDAD. (NIGGAS)
	{

		// <<< VER PAREJAS DE ROJOS >>>
		if (CheckRedPairs(A, B))
		{
			// <<< TODO ESTO VA DENTRO DEL IF QUE TIENE EL METODO QUE REVISE LOR ROJOS. Si true entra

			CrossOutInTable(A->Value(), B->Value()); // Marcar en tabla

			int A_1 = 0;
			int B_1 = 0;


			
			while (A_1 /*+ 1*/ < A->Size() /*&& Assigned(A_1 + 1, 1)*/
				&& Available(A, 1) == Available(B, 2)
				&& Available(A, 1) != 0) // BUSCA EL PRIMER A NEGRO (DISPONIBLE)
			{

				// LLEGAR AL PRIMER NEGRO DISPONIBLE
				while (Assigned(A->ElementAtIndex(A_1), 1) && A_1 + 1 < A->Size()) 
				{
					A_1++;
				}

				// CORRALO MIENTRAS NO SEA NEGRO (DISPONIBLE) NI ULTIMO
				while (Assigned(B->ElementAtIndex(B_1), 2) || (A->Size()/*degree*/ != B->Size()/*degree*/))
				{
					if (B_1 + 1 < B->Size())
					{
						B_1++;
					}
					else
						return false;
				}

				// INTENTE APLICAR JJO CON LOS ADYACENTES ACTUALES
				while (JJO(vertexArray_A, vertexArray_B, vertexArray_A[A->ElementAtIndex(A_1)], vertexArray_B[B->ElementAtIndex(B_1)]) == false)
				{
					// Queremos que sume si no le cuadro el B_1
					if (B_1 + 1 < B->Size())
					{
						B_1++;
					}
					else
					{
						// Si se le acaban los B_1 es porque no cuadraban A y B
						UncoverInTable(A->Value(), B->Value());
						return false;
					}

					// Pero nos aseguramos que sume lo necesario, porque el primer ++ es para probar el siguiente
					// Este es para verificar que ese siguiente sea un negro.
					while (Assigned(B->ElementAtIndex(B_1), 2) || (A->Size()/*degree*/ != B->Size()/*degree*/))
					{
						if (B_1 + 1 < B->Size()) // misma historia que arriba en validacion de suma para B_1
						{
							B_1++;
						}
						else
						{
							UncoverInTable(A->Value(), B->Value());
							return false;
						}
					}
				}

			}

			//// Anadicion creo que debe ser solo en caso trivial
			//if (CheckIsomorphismTableAdjacentVertices(A, B))
			//	return true;
			//else
			//{
			//	UncoverInTable(A->Value(), B->Value());
			//	return false;
			//}

			// Este true significa que se rompio el while de arriba, porque JOO dio true, lo que 
			// significa que A y B cuadran.
			return true;
		}
		else
		{

			// RETORNE FALSO SI LOS ROJOS NO CUADRAN. METODO DEL COLOCHASO.
			// ACA NO DESMARCO PORQUE NUNCA LOS MARQUE
			return false;
		}
		
	}
	// CASO TRIVIAL: CUANDO LOS ADYACENTES YA ESTAN TODOS MARCADOS DE A Y B.
	else if (Available(A, 1) == Available(B, 2) && Available(A, 1) == 0)
	{
		if (CheckRedPairs(A, B))
		{
			CrossOutInTable(A->Value(), B->Value()); // Marcar En Tabla
			/*std::cout << "FUNCION ISOMORFISMO PATITO" << std::endl;
			std::cout << "G1" << " -> " << "G2" << std::endl;

			for (int i = 0; i < 8; i++)
			{
				std::cout << i << " -> " << IsomorphismTable[i] << std::endl;
			}*/


			////Añadicion de chequear adyacentes
			//if (CheckIsomorphismTableAdjacentVertices(A, B))
			//	return true;
			//else
			//	return false; // No cuadraron adjacentes de A  y B consultando funcion de isomorfismo.

			return true;
		}
		else
			return false; // No cuadraron red pairs
	}
	else
	{
		// No cuadraron disponibilidades
		return false;
		// no se da uncover porque no se marca en este nivel de recursion ya que no entro al if donde se hace
	}
}

bool CGraph::JJO(/*CVertexAdjacencyList* vertexArray_G1[], CVertexAdjacencyList* vertexArray_G2[],*/ CGraph* G1, CGraph * G2)
{


	// Asumiendo solo llamaremos a JJO para grafos con igual numero n de vertices
	G1_CrossedOutTable = new bool[G1->VertexQuantity()];
	G2_CrossedOutTable = new bool[G2->VertexQuantity()];
	IsomorphismTable = new int[G1->VertexQuantity()]; // position is a G1 vertex, and the value the assigned vertex of G2


	// set all default values in false
	for (int i = 0; i < G1->VertexQuantity(); i++)
	{
		G1_CrossedOutTable[i] = false;
		G2_CrossedOutTable[i] = false;
		IsomorphismTable[i] = -1;

	}


	int G1_i = 0;
	int G2_i = 0;

	while (JJO(G1->vertexArray, G2->vertexArray, G1->vertexArray[G1_i], G2->vertexArray[G2_i]) == false)
	{
		if (G2_i + 1 < G2->VertexQuantity())
		{
			G2_i++;
			// set all default values in false
			for (int i = 0; i < G1->VertexQuantity(); i++)
			{
				G1_CrossedOutTable[i] = false;
				G2_CrossedOutTable[i] = false;
				IsomorphismTable[i] = -1;

			}
		}
		else
		{
			//cout << "FUNCION NO ENCONTRADA, GRAFOS NO SON ISOMORFOS" << endl;
			return false;
		}

	}

	std::cout << "FUNCION ISOMORFISMO" << std::endl;
	std::cout << "G1" << " -> " << "G2" << std::endl;

	for (int i = 0; i < G1->VertexQuantity(); i++)
	{
		std::cout << i << " -> " << IsomorphismTable[i] << std::endl;
	}

	return true;

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

bool CGraph::CheckIsomorphismTable(CGraph* G1, CGraph* G2)
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

		delete miniCorrectIsomorphismTable;
		return true;
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
	if (executeSwap == true)
	{
		//swap(IsomorphismTable[G1_Index_NoBijectionVertex], IsomorphismTable[G2_Index_NoBijectionVertex]);
		return false;
	}
	else
	{
		delete G1_vertex;
		delete G2_vertex;

		delete miniCorrectIsomorphismTable;
		return true;
	}



	delete G1_vertex;
	delete G2_vertex;
	//std::cout << "FUNCION ISOMORFISMO CON SWAP" << std::endl;
	//std::cout << "G1" << " -> " << "G2" << std::endl;

	//for (int i = 0; i < 8; i++)
	//{
	//	std::cout << i << " -> " << IsomorphismTable[i] << std::endl;
	//}
	delete miniCorrectIsomorphismTable;
}

bool CGraph::CheckIsomorphismTableAdjacentVertices(CVertexAdjacencyList * A, CVertexAdjacencyList * B)
{
	// VERTICES TO COMPARE
	// Compare vertices acording to isomorphism table.


	bool EVERYTHINGOK = true;



	for (int j = 0; j < A->Size(); j++)
	{
		//CHECK IF THE VERTEX THE FUNCTION RETURNS IS IN G2_VERTEX ADJACENTS
		if (B->IsAnElement(IsomorphismTable[A->ElementAtIndex(j)]) == false) // Adjacent of G1_vertex has a corresponding adjacent to G2_vertex?
		{
			//A_NoBijectionVertex = A->ElementAtIndex(j); // It's the element that doesn't have a correct bijection.
			EVERYTHINGOK = false;
		}
	}
	return EVERYTHINGOK;
}

bool CGraph::CheckRedPairs(CVertexAdjacencyList * A, CVertexAdjacencyList * B)
{
	for (int i = 0; i < A->Size(); i++) // RECORRER ADYACENTES DE A
	{
		if (Assigned(A->ElementAtIndex(i), 1)) // SI ES ROJO, NOS INTERESA
		{
			// Guardar valor
			int A_RedAdjacentValue = A->ElementAtIndex(i);
			// Ir a tab iso y buscar pareja, SI NO ESTA, RETURN FALSE.
			if (B->IsAnElement(IsomorphismTable[A_RedAdjacentValue]) == false)
				return false;
			// Si SI ESTA, CONTINUE EVALUANDO LOS ADYACENTES RESTANTES DE A

		}
	}

	return true; // No se encontro ningun problema, todo esta en orden.
}

