#include "SinglyLinkedList.h"



CSinglyLinkedList::CSinglyLinkedList()
{
	this->head = nullptr;
	this->size = 0;
}


CSinglyLinkedList::~CSinglyLinkedList()
{
}

bool CSinglyLinkedList::Add(int value)
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

bool CSinglyLinkedList::IsAnElement(int value)
{
	Node* temp = head;
	while (temp->next != nullptr)
	{
		if (temp->value == value)
			return true;
	}
	return false;
}

int CSinglyLinkedList::ElementAtIndex(int index)
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
