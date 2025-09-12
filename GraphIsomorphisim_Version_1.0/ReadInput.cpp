#include "ReadInput.h"
#include <algorithm>  // for std::remove_if
#include <cctype>     // for std::isspace
#include <string>


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
		line.erase(std::remove_if(line.begin(), line.end(),
			static_cast<int(*)(int)>(std::isspace)),
			line.end());
		if (line != "")
			line_counter++;
		else
			break;

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
		line.erase(std::remove_if(line.begin(), line.end(),
			static_cast<int(*)(int)>(std::isspace)),
			line.end());
		while (line_counter > 0 && line_counter < sizeFile && line != "")
		{
			Graph->AddEdge(atoi(line.substr(0, 1).c_str()), atoi(line.substr(2, 1).c_str()));
			(getline(file, line));
			line.erase(std::remove_if(line.begin(), line.end(),
				static_cast<int(*)(int)>(std::isspace)),
				line.end());
			line_counter++;
		}
	}
	file.close();
}

int CReadInput::GetVertexQuantity(string Entrada)
{
	cout << "Reading vertex quantity from file: " << Entrada << endl;
	string line = "";
	file.open(Entrada);

	getline(file, line);
	line.erase(std::remove_if(line.begin(), line.end(),
		static_cast<int(*)(int)>(std::isspace)),
    	line.end());
	int vertexQuantity = atoi(line.c_str());
	file.close();

	cout << "Vertex quantity: " << vertexQuantity << endl;

	return vertexQuantity;
}
