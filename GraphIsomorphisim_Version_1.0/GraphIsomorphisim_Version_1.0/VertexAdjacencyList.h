#pragma once


struct Node
{
	int value;
	Node* next;
};

class CVertexAdjacencyList
{
private:
	int size;
	int value;
public:
	void SetVertexValue(int value);

	CVertexAdjacencyList();
	~CVertexAdjacencyList();

	Node* head;
	int Value();
	int Size() {return size;}

	bool Add(int value);

	bool IsAnElement(int value);
	int ElementAtIndex(int index);



};

