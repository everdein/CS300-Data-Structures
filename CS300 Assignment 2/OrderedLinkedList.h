// Matthew Clark
// CS300 - Data Structures
// Assignment 2 - Flight Manifest

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
class OrderedLinkedList:public LinkedList<T>
{
	private:
		OrderedLinkedList(const OrderedLinkedList&)=delete; //copy constructor
	protected:
		int count;
		node<T> *head, *last;
	public:
		OrderedLinkedList();
		void insertAlphabetically(T&);
		bool search(T&);
		void deleteNode(T&);
		OrderedLinkedList<T>& operator=(OrderedLinkedList<T>&);
		template <class U>
		friend ostream& operator<<(ostream& os, OrderedLinkedList<U>& list);
		void destroyList();
		~OrderedLinkedList();
};

template <class T>
OrderedLinkedList<T>::OrderedLinkedList()
{
     head = last = NULL;
     count = 0;
}

template <class T>
void OrderedLinkedList<T>::insertAlphabetically(T &item)
{
    node<T> *newNode = new node<T>;
    newNode->data = item;
    if(head==NULL)
    {
        head = last = newNode;
        newNode->next = NULL;
    }
    else if (item < head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else if(last->data < item)
    {
        last->next = newNode;
        last = newNode;
    }
    else if (item > head->data)
    {
        if(head->next == NULL)
        {
            head->next = newNode;
            last = newNode;
        }
        else
        {
            node<T> *p = head;
            while(p->next->data < item && p->next != NULL)
            {
                p = p->next;
            }
            if(p->next == NULL)
            {
                p->next = newNode;
                last = newNode;
            }
            else
            {
                newNode->next = p->next;
                p->next = newNode;
            }
        }
    }
    count++;
}

template <class T>
bool OrderedLinkedList<T>::search(T& item)
{
		node<T>* p = head;
		while(p!= NULL && p->data < item)
		{
			p = p->next;
		}
		if(p!=NULL){
			if(p->data == item){
				cout << p->data;
				return true;
			}
		}
		else
		{
			return false;
		}
}

template <class T>
void OrderedLinkedList<T>::deleteNode(T& item)
{
	if(head == NULL)
	{
		cout << "THE FLIGHT MANIFEST IS EMPTY." << endl;
	}
	else
	{
		if(head->data == item)
		{
			node<T>* p = head;
			head = head->next;
			delete p;
			cout << "THE PASSENGER HAS BEEN DELETED." << endl;
			count--;
			if(head==NULL)
			{
				last = NULL;
			}
		}
		else
		{
			node<T>* p = head;
			node<T>* q = p->next;
			while(q!=NULL && q->data != item)
			{
				p = q;
				q = q->next;
			}
			if(q!=NULL)
			{
				p->next = q->next;
				count--;
				if(last == q) last = p;
				delete q;
				cout << "THE PASSENGER HAS BEEN DELETED." << endl;
			}
			else
			{
				cout << "PASSENGER NOT FOUND, UNABLE TO DELETE." << endl;
			}
		}
	}
}

template <class T>
OrderedLinkedList<T>& OrderedLinkedList<T>::operator=(OrderedLinkedList<T>& list)
{
	if(this!= &list)
	{
		copylist(list);
	}
	return *this;
}

template <class T>
ostream& operator<<(ostream& os, OrderedLinkedList<T>& list)
{
	node<T> *p = list.head;
	while(p!= NULL)
	{
		os<<p->data<<" "<<endl;
		p = p->next;
	}
	return os;
}

template <class T>
void OrderedLinkedList<T>::destroyList()
{
	node<T> *p;
	while(head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

template <class T>
OrderedLinkedList<T>::~OrderedLinkedList()
{
	destroyList();
}

#endif /* ORDEREDLINKEDLIST_H_ */
