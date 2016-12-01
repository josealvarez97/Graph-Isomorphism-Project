#include "ReadInput.h"


static ifstream file;

CReadInput::CReadInput()
{
}


CReadInput::~CReadInput()
{
}

int CReadInput::FileSize(string Entrada)
{
	file.open(Entrada);
	string line = "";
	int line_counter = 0;
	while (!file.eof())
	{
		getline(file, line);
		line_counter++;
	}
	file.close();

	return line_counter;
}

void CReadInput::ReadInput(string Entrada, CGraph* Graph)
{

	string line = "";
	int line_counter = 1;
	int sizeFile = FileSize(Entrada);

	file.open(Entrada);

	while (!file.eof())
	{

		(getline(file, line));
		(getline(file, line));
		while (line_counter > 0 && line_counter < sizeFile)
		{
			Graph->AddEdge(atoi(line.substr(0, 1).c_str()), atoi(line.substr(2, 1).c_str()));
			(getline(file, line));
			line_counter++;
		}
	}
	file.close();
}

int CReadInput::GetVertexQuantity(string Entrada)
{
	string line = "";
	file.open(Entrada);

	getline(file, line);
	int vertexQuantity = atoi(line.c_str());
	file.close();

	return vertexQuantity;
}
