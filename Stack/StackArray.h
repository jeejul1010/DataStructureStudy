#include <iostream>
#pragma once

const int MAX = 100;

class StackArray
{
private:
	int stack[MAX];
	int top;
public:
	StackArray();
	StackArray(const StackArray& s);
	~StackArray();
	void push(int item);
	int pop();
	bool isEmpty();
	bool isFull();
	void print();

};

