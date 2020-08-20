#include <iostream>
#pragma once


typedef struct node {
	struct node* prev;
	struct node* next;
	int data;
}Node;

typedef Node* Nptr;

class DequeLL
{
private:
	int count;
	Nptr head;
	Nptr tail;
public:
	DequeLL();
	~DequeLL();
	void addLast(int _data);
	void addFirst(int _data);
	void removeLast();
	void removeFirst();
	void print();
};

