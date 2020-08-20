#include "stddef.h"
#include "DequeLL.h"

DequeLL::DequeLL()
{
	count = 0;
	head = NULL;
	tail = NULL;
}

DequeLL::~DequeLL()
{
	while (count != 0)
	{
		removeLast();
	}

}

void DequeLL::addLast(int _data)
{
	Nptr p = new Node;
	p->data = _data;
	p->next = NULL;
	p->prev = tail;
	if (count == 0)
	{
		head = p;
	}
	else {

		tail->next = p;

	}
	tail = p;
	
	count++;
}

void DequeLL::addFirst(int _data)
{
	Nptr p = new Node;
	p->data = _data;
	p->next = head;
	p->prev = NULL;
	if (count != 0)
	{
		head->prev = p;
	}
	else
	{
		tail = p;
	}
	head = p;
	count++;
}

void DequeLL::removeLast()
{
	if (count == 0)
	{
		std::cout << "There is nothing to remove" << std::endl;
	}
	else
	{
		Nptr temp = tail;
		tail = tail->prev;
		delete temp;
		if (count == 1)
		{
			head = NULL;
		}
		else
		{
			tail->next = NULL;
		}
		count--;
	}
	
}

void DequeLL::removeFirst()
{
	if (count == 0)
	{
		std::cout << "There is nothing to remove" << std::endl;
	}
	else
	{
		Nptr temp = head;
		head = head->next;
		delete temp;
		if (count == 1)
		{
			tail = NULL;
		}
		else
		{
			head->prev = NULL;
		}
		count--;
	}
	
}

void DequeLL::print()
{
	Nptr temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
	
}