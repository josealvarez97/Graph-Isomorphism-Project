#include <iostream>
#include "Graph.h"
#include "ReadInput.h"
// #include <Windows.h>
using namespace std;

int main()
{




	string grafo1 = "";
	string grafo2 = "";
	string decision = "";
	
	try
	{
		while (true)
		{
			try {
				// system("CLS");
				cout << "\n***Insert the first graph txt file data adress (must be complete absolute path, not relative path) " << endl;
				cin >> grafo1;
				CGraph* G1 = new CGraph(CReadInput::GetVertexQuantity(grafo1));
				cout << "\n***Insert the second graph txt file data adress (must be complete absolute path, not relative path) " << endl;
				cin >> grafo2;
				CGraph* G2 = new CGraph(CReadInput::GetVertexQuantity(grafo2));

				CReadInput::ReadInput(grafo1, G1);
				CReadInput::ReadInput(grafo2, G2);

				cout << endl;

				CGraph::PrintGraphsInfo(G1, G2);
				bool Isomorphism = CGraph::Isomorphism(G1, G2);


				

				cout << "\n\n  DO YOU WANT TO CONTINUE INSERTING OTHER GRAPHS? YES: Any key  NO: press 1" << endl;
				cin >> decision;

				delete G1;
				delete G2;
				if (decision == "1")
					break;
				decision = "";
			}
			catch (exception e)
			{
				cout << "  An error occurred, please restart the program and try again." << endl;
			}
		}
	}
	catch (exception e)
	{
		cout << "  An error occurred, please restart the program and try again." << endl;
	}
	return 0;
}