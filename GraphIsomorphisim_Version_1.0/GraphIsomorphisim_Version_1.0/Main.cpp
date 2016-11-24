#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	CGraph* G = new CGraph(5);
	cout << "hola" << endl;

	G->Add_edge(0, 1);
	G->Add_edge(0, 3); // devolvio -1....
	G->Add_edge(1, 4);
	G->Add_edge(4, 3);
	G->Add_edge(2, 3);


	// Print neighbors of 3
	cout << "Vertices adyacentes a 3" << endl;
	for (int i = 0; i < G->Degree(3); i++)
	{
		cout << G->Neighbors(3).ElementAtIndex(i) << endl;
	}

	return 0;
}