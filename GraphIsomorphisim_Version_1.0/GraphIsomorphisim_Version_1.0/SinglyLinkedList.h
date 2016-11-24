#pragma once


struct Node
{
	int value;
	Node* next;
};

class CSinglyLinkedList
{
private:
	int size;

public:
	CSinglyLinkedList();
	~CSinglyLinkedList();

	Node* head;
	int Size() {return size;}

	bool Add(int value);
	bool IsAnElement(int value);
	int ElementAtIndex(int index);



};

