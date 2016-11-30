#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	CGraph* G1 = new CGraph(6);
	CGraph* G2 = new CGraph(6);


	//G1
	// 0 : e-d-c
	// 0 : 4-3-2
	
	//G2
	// 0: b-y-x
	// 0: 1-4-3

	//vertexArray[x]->Add(y);
	//vertexArray[y]->Add(x);

	G1->AddEdge(0, 4);
	G1->AddEdge(0, 3);
	G1->AddEdge(0, 2);

	G1->AddEdge(1, 3);
	G1->AddEdge(1, 4);
	G1->AddEdge(1, 5);
	G1->AddEdge(2, 4);
	G1->AddEdge(2, 5);
	G1->AddEdge(3, 5);


	G2->AddEdge(0, 1);
	G2->AddEdge(0, 4);
	G2->AddEdge(0, 3);

	G2->AddEdge(1, 2);
	G2->AddEdge(1, 3);
	G2->AddEdge(2, 4);
	G2->AddEdge(2, 5);
	G2->AddEdge(3, 5);
	G2->AddEdge(4, 5);


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