#include "List.h"

List::List()
{
    count = 0;
    head = NULL;
    tail = NULL;

}

List::~List()
{
    while (!IsEmpty())
    {
        deleteLocationBased(0);
    }

}

Nptr List::findNode(int item)
{
    Nptr temp = head;
    while ((temp != NULL) && (temp->data) != item)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return NULL;
    }
    else
    {
        return temp;
    }
}

Nptr List::getNodeAt(int index)
{
    if (index <0 || index > count-1)
    {
        return NULL;
    }
    else
    {
        Nptr temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

}

void List::add(int index, int item)
{
    if (index<0 || index >count)
    {
        std::cout << "Out of Range" << std::endl;
    }
    else
    {
        Nptr temp = NULL;
        Nptr p = new node;
        p->data = item;

        if (index == 0)
        {
            p->prev = NULL;
            temp = getNodeAt(index);
            head = p;
            p->next = temp;

            if (temp != NULL)
            {
                temp->prev = p;
            }

        }
        else if (index == count)
        {
            p->next = NULL;
            p->prev = tail;
            tail->next = p;
        }
        else
        {
            temp = getNodeAt(index);
            temp->prev->next = p;
            p->prev = temp->prev;
            p->next = temp;
            temp->prev = p;
        }

        if (p->next == NULL)
        {
            tail = p;
        }

        count++;
    }
}

void List::deleteLocationBased(int index)
{
    if (IsEmpty())
    {
        std::cout << "There is nothing to delete!" << std::endl;
    }
    else if (index < 0 || index >count-1)
    {
        std::cout << "Out of range" << std::endl;
    }
    else
    {
        Nptr temp = getNodeAt(index);

        if (index == 0)
        {
            head = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = NULL;
            }
        }
        else
        {
            temp->prev->next = temp->next;

            if (temp != tail)
            {
                temp->next->prev = temp->prev;
            }
        }

        if (temp == tail)
        {
            tail = temp->prev;
        }
        count--;
        delete temp;
    }
}

void List::deleteValueBased(int item)
{
    Nptr temp = findNode(item);
    if (temp == NULL)
    {
        std::cout << "Item not found!" << std::endl;
    }
    else
    {
        if (temp->prev == NULL)
        {
            head = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = NULL;
            }
        }
        else
        {
            temp->prev->next = temp->next;

            if (temp != tail)
            {
                temp->next->prev = temp->prev;
            }
        }

        if (temp == tail)
        {
            tail = temp->prev;
        }
        count--;
        delete temp;
    }
}



void List::print()
{
    Nptr temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout<<std::endl;

}

bool List::IsEmpty()
{
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}