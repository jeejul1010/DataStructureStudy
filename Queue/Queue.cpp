#include "Queue.h"

Queue::Queue()
{
	rear = NULL;
}
Queue::Queue(const Queue& q)
{
	if (q.rear == NULL)
	{
		rear = NULL;
	}
	else
	{
		Nptr temp = q.rear;
		Nptr p = new node;
		p->data = temp->data;
		rear = p;
		Nptr temp2 = rear;
		temp = temp->next;
		while (temp != q.rear)
		{
			Nptr p = new node;
			p->data = temp->data;
			temp2->next = p;
			temp2 = temp2->next;
			temp = temp->next;
		}
		temp2->next = rear;
	}
}
Queue::~Queue()
{
	while (!isEmpty())
	{
		remove();
	}

}
void Queue::add(int item)
{
	Nptr p = new node;
	p->data = item;
	if (rear == NULL)
	{
		p->next = p;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;

	}
	rear = p;

}
void Queue::remove()
{
	if (isEmpty())
	{
		std::cout << "There is nothing to delete" << std::endl;
	}
	else
	{
		Nptr temp = rear->next;
		if (temp == rear)
		{
			rear = NULL;
		}
		else
		{
			rear->next = temp->next;
		}
		delete temp;
	}
	
}
bool Queue::isEmpty()
{
	if (rear == NULL)
	{
		std::cout << "Queue is empty" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
void Queue::print()
{
	Nptr temp = rear->next;
	while (temp != rear)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << temp->data;
	std::cout << std::endl;
}
