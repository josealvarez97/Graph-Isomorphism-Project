#pragma once
#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class CReadInput
{
public:
	CReadInput();
	~CReadInput();

	static int FileSize(string Entrada);
	static void ReadInput(string Entrada, CGraph* Graph);
	static int GetVertexQuantity(string Entrada);


};

