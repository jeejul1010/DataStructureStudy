#include "DequeCArray.h"

DequeCArray::DequeCArray()
{
	head = 0;
	tail = 0;
}

DequeCArray::~DequeCArray()
{

}

void DequeCArray::addFirst(int data)
{
	if (isFull())
	{
		std::cout << "Deque is full! You can't add more!" << std::endl;
	}
	else if (isEmpty())
	{
		deque[tail] = data;
		tail = (tail + 1) % MAX;
	}
	else 
	{
		if (head == 0)
		{
			head = MAX - 1;
			deque[head] = data;
		}
		else 
		{
			deque[--head] = data;
		}
		
	}

}

void DequeCArray::addLast(int data)
{
	if (isFull())
	{
		std::cout<< "Deque is full! You can't add more!" << std::endl;

	}
	else
	{
		deque[tail] = data;
		tail = (tail + 1) % MAX;
	}

}

void DequeCArray::removeFirst()
{
	if (isEmpty())
	{
		std::cout << "There is nothing to remove!" << std::endl;
	}
	else
	{
		head = (head + 1) % MAX;
	}
	
}

void DequeCArray::removeLast()
{
	if (isEmpty())
	{
		std::cout << "There is nothing to remove!" << std::endl;
	}
	else
	{
		if (tail == 0)
		{
			tail = MAX - 1;
		}
		else {
			tail--;
		}
	}
}

bool DequeCArray::isFull()
{
	if ((tail + 1) % MAX == head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DequeCArray::isEmpty()
{
	if (head == tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DequeCArray::print()
{
	if (head < tail)
	{
		for (int i = head; i < tail; i++)
		{
			std::cout << deque[i] << ' ';
		}
		std::cout << std::endl;
	}
	else if (head > tail)
	{
		for (int i = head; i < MAX; i++)
		{
			std::cout << deque[i] << ' ';
		}
		for (int i = 0; i < tail; i++)
		{
			std::cout << deque[i] << ' ';
		}
		std::cout << std::endl;
	}
}