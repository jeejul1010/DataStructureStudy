#include "StackLL.h"

StackLL::StackLL()
{
	top = NULL;

}

StackLL::StackLL(const StackLL& s)
{
	Nptr temp = s.top;
	if (temp != NULL)
	{
		Nptr p = new node;
		p->data = temp->data;
		top = p;
		Nptr temp2 = top;
		temp = temp->next;
		while (temp != NULL)
		{
			Nptr p = new node;
			p->data = temp->data;
			temp2->next = p;
			temp2 = temp2->next;
			temp = temp->next;

		}
		temp2->next = NULL;
	}
	else
	{
		top = s.top;
	}

}

StackLL::~StackLL()
{
	while (!isEmpty())
	{
		pop();
	}
}

void StackLL::push(int item)
{
	Nptr p = new node;
	p->data = item;
	p->next = top;
	top = p;

}

int StackLL::pop()
{
	if (isEmpty())
	{
		std::cout << "There is nothing to pop" << std::endl;
		return -1;
	}
	else
	{
		int topValue;
		Nptr temp = top;
		top = temp->next;
		topValue = temp->data;
		delete temp;
		return topValue;
	}
}

bool StackLL::isEmpty()
{
	if (top == NULL)
	{
		std::cout << "Stack is Empty!!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}

}



void StackLL::print()
{
	Nptr temp = top;
	while (temp != NULL)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;

}
