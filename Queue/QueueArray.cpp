#include "QueueArray.h"

QueueArray::QueueArray()
{
	front = 0;
	rear = 0;
}

QueueArray::QueueArray(const QueueArray& q)
{
	front = q.front;
	rear = q.rear;

	if (front < rear)
	{
		for (int i = front; i < rear; i++)
		{
			queue[i] = q.queue[i];
		}
	}
	else if (front > rear)
	{
		for (int i = front; i < MAX; i++)
		{
			queue[i] = q.queue[i];
		}
		for (int i = 0; i < rear; i++)
		{
			queue[i] = q.queue[i];
		}
	}

}

QueueArray::~QueueArray()
{

}

void QueueArray::add(int item)
{
	if (!isFull())
	{
		queue[rear] = item;
		rear = (rear + 1) % MAX;
	}

}

void QueueArray::remove()
{
	if (!isEmpty())
	{
		front=(front+1)%MAX;
	}

}

bool QueueArray::isEmpty()
{
	if (front == rear)
	{
		std::cout << "Queue is empty" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool QueueArray::isFull()
{
	if (front == (rear + 1) % MAX)
	{
		std::cout << "Queue is full" << std::endl;
		return true;
	}
	else
	{
		return false;
	}

}

void QueueArray::print()
{
	if (front < rear)
	{
		for (int i = front; i < rear; i++)
		{
			std::cout << queue[i] << ' ';
		}
		std::cout << std::endl;
	}
	else if (front > rear)
	{
		for (int i = front; i < MAX; i++)
		{
			std::cout << queue[i] << ' ';
		}
		for (int i = 0; i < rear; i++)
		{
			std::cout << queue[i] << ' ';
		}
		std::cout << std::endl;
	}

}
