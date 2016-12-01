#include <iostream>
#include "Graph.h"
#include "ReadInput.h"
using namespace std;

int main()
{
	CGraph* G1 = new CGraph(4);
	CGraph* G2 = new CGraph(4);


	// PRUEBA GRAFO PENTAGONO Y GRAFO ESTRELLA

	string grafo1 = "";
	string grafo2 = "";

	/*cout << "Ingrese direccion de la entrada para el primero grafo" << endl;
	getline(cin, grafo1);
	CGraph* G1 = new CGraph(CReadInput::GetVertexQuantity(grafo1));
	cout << "Ingrese direccion de la entrada para el segundo grafo" << endl;
	getline(cin, grafo2);
	CGraph* G2 = new CGraph(CReadInput::GetVertexQuantity(grafo2));

	CReadInput::ReadInput(grafo1, G1);
	CReadInput::ReadInput(grafo2, G2);*/




	// SI SALIERON WUUUUUUUUUUUUUUU
	////Pentagono
	//G1->AddEdge(4, 0);
	//G1->AddEdge(4, 3);
	//G1->AddEdge(3, 2);
	//G1->AddEdge(2, 1);
	//G1->AddEdge(1, 0);

	////Estrella
	//G2->AddEdge(0, 4);
	//G2->AddEdge(0, 3);
	//G2->AddEdge(1, 4);
	//G2->AddEdge(1, 2);
	//G2->AddEdge(3, 2);

	// OTRO INTENTO Si salio y no todos tienen el mismo grado
	G1->AddEdge(0, 1);
	G1->AddEdge(0, 2);
	G1->AddEdge(0, 3);
	G1->AddEdge(1, 3);
	G1->AddEdge(2, 3);

	G2->AddEdge(0, 1);
	G2->AddEdge(0, 2);
	G2->AddEdge(1, 2);
	G2->AddEdge(1, 3);
	G2->AddEdge(2, 3);

	// OTRO INTENTO (FALLIDO NO CUADRO UNO)

	//G1->AddEdge(0, 1);
	//G1->AddEdge(0, 2);
	//G1->AddEdge(0, 4);
	//G1->AddEdge(0, 5);
	//G1->AddEdge(1, 2);
	//G1->AddEdge(1, 3);
	//G1->AddEdge(1, 4);
	//G1->AddEdge(2, 3);
	//G1->AddEdge(2, 5);
	//G1->AddEdge(3, 4);
	//G1->AddEdge(3, 5);
	//G1->AddEdge(4, 5);

	//G2->AddEdge(0, 1);
	//G2->AddEdge(0, 2);
	//G2->AddEdge(0, 3);
	//G2->AddEdge(0, 4);
	//G2->AddEdge(1, 2);
	//G2->AddEdge(1, 3);
	//G2->AddEdge(1, 5);
	//G2->AddEdge(2, 4);
	//G2->AddEdge(2, 5);
	//G2->AddEdge(3, 4);
	//G2->AddEdge(3, 5);
	//G2->AddEdge(4, 5);


	//OTRO INTENTO

	//G1->AddEdge(0, 1);
	//G1->AddEdge(0, 3);
	//G1->AddEdge(0, 5);
	//G1->AddEdge(1, 2);
	//G1->AddEdge(1, 6);
	//G1->AddEdge(2, 3);
	//G1->AddEdge(2, 7);
	//G1->AddEdge(3, 4);
	//G1->AddEdge(4, 5);
	//G1->AddEdge(4, 7);
	//G1->AddEdge(5, 6);
	//G1->AddEdge(6, 7);

	//G2->AddEdge(0, 3);
	//G2->AddEdge(0, 5);
	//G2->AddEdge(0, 7);
	//G2->AddEdge(1, 3);
	//G2->AddEdge(1, 4);
	//G2->AddEdge(1, 7);
	//G2->AddEdge(2, 3);
	//G2->AddEdge(2, 4);
	//G2->AddEdge(2, 5);
	//G2->AddEdge(4, 6);
	//G2->AddEdge(5, 6);
	//G2->AddEdge(6, 7);




	//G1
	// 0 : e-d-c
	// 0 : 4-3-2
	
	//G2
	// 0: b-y-x
	// 0: 1-4-3

	//vertexArray[x]->Add(y);
	//vertexArray[y]->Add(x);

	//LA QUE FUNCIONA:
	/*G1->AddEdge(0, 4);
	G1->AddEdge(0, 3);
	G1->AddEdge(0, 2);

	G1->AddEdge(1, 3);
	G1->AddEdge(1, 4);
	G1->AddEdge(1, 5);
	G1->AddEdge(2, 4);
	G1->AddEdge(2, 5);
	G1->AddEdge(3, 5);*/

	//LA QUE NO FUNCIONA
	//G1->AddEdge(0, 2);
	//G1->AddEdge(0, 3);
	//G1->AddEdge(0, 4);
	//G1->AddEdge(1, 3);
	//G1->AddEdge(1, 4);
	//G1->AddEdge(1, 5);
	//G1->AddEdge(2, 4);
	//G1->AddEdge(2, 5);
	//G1->AddEdge(3, 5);


	//LA QUE FUNCIONA:
	/*G2->AddEdge(0, 1);
	G2->AddEdge(0, 4);
	G2->AddEdge(0, 3);

	G2->AddEdge(1, 2);
	G2->AddEdge(1, 3);
	G2->AddEdge(2, 4);
	G2->AddEdge(2, 5);
	G2->AddEdge(3, 5);
	G2->AddEdge(4, 5);*/

	//LA QUE NO FUNCIONA:
	//G2->AddEdge(0, 1);
	//G2->AddEdge(0, 3);
	//G2->AddEdge(0, 4);
	//G2->AddEdge(1, 2);
	//G2->AddEdge(1, 3);
	//G2->AddEdge(2, 4);
	//G2->AddEdge(2, 5);
	//G2->AddEdge(3, 5);
	//G2->AddEdge(4, 5);


	//bool hola = CGraph::JJO(G1, G2);

	bool hola1 = CGraph::JJO(G1, G2);

	cout << "hola" << endl;

	//G1->AddEdge(0, 1);
	//G1->AddEdge(0, 3); // devolvio -1....
	//G1->AddEdge(1, 4);
	//G1->AddEdge(4, 3);
	//G1->AddEdge(2, 3);


	//// Print neighbors of 3
	//cout << "Vertices adyacentes a 3" << endl;
	//for (int i = 0; i < G1->Degree(3); i++)
	//{
	//	cout << G1->Neighbors(3).ElementAtIndex(i) << endl;
	//}


	//CGraph::JJO(G, G);
	return 0;
}