#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	CGraph* G = new CGraph(5);
	cout << "hola" << endl;

	G->AddEdge(0, 1);
	G->AddEdge(0, 3); // devolvio -1....
	G->AddEdge(1, 4);
	G->AddEdge(4, 3);
	G->AddEdge(2, 3);


	// Print neighbors of 3
	cout << "Vertices adyacentes a 3" << endl;
	for (int i = 0; i < G->Degree(3); i++)
	{
		cout << G->Neighbors(3).ElementAtIndex(i) << endl;
	}

	return 0;
}