#include <iostream>
#pragma once
const int MAX = 5;



class DequeCArray
{
private:
	int head;
	int tail;
	int deque[MAX];
public:
	DequeCArray();
	~DequeCArray();
	void addFirst(int data);
	void addLast(int data);
	void removeFirst();
	void removeLast();
	bool isFull();
	bool isEmpty();
	void print();
};

