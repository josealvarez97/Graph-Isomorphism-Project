#include <iostream>
#include "Graph.h"
#include "ReadInput.h"
#include <Windows.h>
using namespace std;

int main()
{




	string grafo1 = "";
	string grafo2 = "";
	string decision = "";
	
	string adress = "Batería de pruebas/";
	try
	{
		while (true)
		{
			try {
				system("CLS");
				cout << "  Insert the first graph txt file data adress " << endl;
				cin >> grafo1;
				CGraph* G1 = new CGraph(CReadInput::GetVertexQuantity(/*adress + */grafo1));
				cout << "  Insert the second graph txt file data adress" << endl;
				cin >> grafo2;
				CGraph* G2 = new CGraph(CReadInput::GetVertexQuantity(/*adress + */grafo2));

				CReadInput::ReadInput(/*adress + */grafo1, G1);
				CReadInput::ReadInput(/*adress + */grafo2, G2);


				
				CGraph::PrintGraphsInfo(G1, G2);
				bool Isomorphism = CGraph::Isomorphism(G1, G2);


				

				cout << "\n\n  DESEA CONTINUAR INGRESANDO OTROS GRAFOS? SI: Cualquier tecla  NO: presione 1" << endl;
				cin >> decision;

				delete G1;
				delete G2;
				if (decision == "1")
					break;
				decision = "";
			}
			catch (exception e)
			{
				"Algo malo ocurrio, reinicie el programa y vuelva a intentarlo";
			}
		}
	}
	catch (exception e)
	{
		"Algo malo ocurrio, reinicie el programa y vuelva a intentarlo";
	}
	return 0;
}