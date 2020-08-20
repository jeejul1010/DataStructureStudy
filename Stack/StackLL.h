#include "stddef.h"
#include <iostream>
#pragma once

typedef struct node
{
	int data;
	struct node* next;

}node;

typedef node* Nptr;

class StackLL
{
private:
	Nptr top;
public:
	StackLL();
	StackLL(const StackLL& s);
	~StackLL();
	void push(int item);
	int pop();
	bool isEmpty();
	void print();


};

