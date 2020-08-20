#include "stddef.h"
#include <iostream>
#pragma once


typedef struct nodeRecord
{
    int data;
    struct nodeRecord* prev, * next;
}node;

typedef node* Nptr;

class List
{
private:
    int count;
    node* head;
    node* tail;
public:
    List();
    ~List();
    Nptr findNode(int item);
    Nptr getNodeAt(int index);
    void add(int index, int item); 
    void deleteLocationBased(int index); 
    void deleteValueBased(int item);
    void print();
    bool IsEmpty();
};

