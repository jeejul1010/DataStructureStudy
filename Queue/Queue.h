#include "stddef.h"
#include <iostream>
#pragma once

typedef struct node
{
	int data;
	struct node* next;
}node;

typedef node* Nptr;

class Queue
{
private:
	Nptr rear;
public:
	Queue();
	Queue(const Queue& q);
	~Queue();
	void add(int item);
	void remove();
	bool isEmpty();
	void print();
};

