#include "StackArray.h"

StackArray::StackArray()
{
	top = 0;
	for (int i = 0; i < MAX; i++)
	{
		stack[i] = -1;
	}

}

StackArray::StackArray(const StackArray& s)
{
	top = s.top;
	for (int i = 0; i < top; i++)
	{
		stack[i] = s.stack[i];
	}

}

StackArray::~StackArray()
{
	while (!isEmpty())
	{
		pop();
	}
}

void StackArray::push(int item)
{
	if (isFull())
	{
		std::cout << "No more space!!" << std::endl;
	}
	else
	{
		stack[top++] = item;
	}
	
}

int StackArray::pop()
{
	if (isEmpty())
	{
		std::cout << "There is nothing to pop" << std::endl;
		return -1;
	}
	else
	{
		return stack[--top];
	}
}

bool StackArray::isEmpty()
{
	if (top == 0)
	{
		std::cout << "Stack is empty!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}

}

bool StackArray::isFull()
{
	if (top == MAX)
	{
		std::cout << "Stack is full!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}

}

void StackArray::print()
{
	for (int i = 0; i < top; i++)
	{
		std::cout << stack[i] << ' ';
	}
	std::cout << std::endl;
}