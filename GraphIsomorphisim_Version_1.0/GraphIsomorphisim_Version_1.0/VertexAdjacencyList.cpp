#include "VertexAdjacencyList.h"



void CVertexAdjacencyList::SetVertexValue(int value)
{
	this->value = value;
}

CVertexAdjacencyList::CVertexAdjacencyList()
{
	this->head = nullptr;
	this->size = 0;
}


CVertexAdjacencyList::~CVertexAdjacencyList()
{
}

int CVertexAdjacencyList::Value()
{
	return this->value;
}

bool CVertexAdjacencyList::Add(int value)
{
	Node* newNode = new Node();
	newNode->value = value;

	if (head == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = newNode;
	}
	size++;
	return true;
}



bool CVertexAdjacencyList::IsAnElement(int value)
{
	Node* temp = head;
	while (temp->next != nullptr)
	{
		if (temp->value == value)
			return true;
		else
			temp = temp->next;

	}
	return false;
}

int CVertexAdjacencyList::ElementAtIndex(int index)
{
	Node* temp = head;

	for (int i = 0; i < index; i++)
	{
		if (temp->next != nullptr)
			temp = temp->next;
		else
			return -1; // It's not in the list
	}
	return temp->value; // It's in the list

}

void CVertexAdjacencyList::PrintList()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << ElementAtIndex(i) << "->";
	}
}
