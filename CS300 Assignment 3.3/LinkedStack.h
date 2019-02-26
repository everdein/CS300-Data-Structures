// Matthew Clark
// CS300 - Data Structures
// Assignment 3.3 - Large Addition

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    node<T>* next;
};

template <class T>
class LinkedStack
{
    node<T> *top;
	public:
		LinkedStack();
		void push(T&);
		T pop();
		bool isEmpty();
		void destroyList();
		~LinkedStack();
};

template <class T>
LinkedStack<T>::LinkedStack()
{
    top = NULL;
}

template <class T>
void LinkedStack<T>::push(T& item)
{
    node<T> *p = new node<T>;
    p->data = item;
    p->next = top;
    top = p;
}

template <class T>
T LinkedStack<T>::pop()
{
    node<T> *p = top;
    top = top->next;
    T data = p->data;
    delete p;
    return data;
}

template <class T>
bool LinkedStack<T>::isEmpty()
{
    return top == NULL;
}

template <class T>
void LinkedStack<T>::destroyList()
{
    node<T> *p;
    while(top != NULL){
        p = top;
        top = top->next;
        delete p;
    }
}

template <class T>
LinkedStack<T>::~LinkedStack()
{
    destroyList();
}

#endif /* LINKEDSTACK_H_ */

