#include <iostream>
#pragma once
const int MAX = 5;

class QueueArray
{
private:
	int front;
	int rear;
	int queue[MAX];
public:
	QueueArray();
	QueueArray(const QueueArray& q);
	~QueueArray();
	void add(int item);
	void remove();
	bool isEmpty();
	bool isFull();
	void print();

};

