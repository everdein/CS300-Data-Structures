// Matthew Clark
// CS300 - Data Structures
// Assignment 4 - Phonebook & Performance Comparison

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	node<T>* left;
	node<T>* right;
};

template <class T>
class BinarySearchTree
{
private:
	node<T>* root;
	void inOrderT(node<T>*);
	void preOrderT(node<T>*);
	void postOrderT(node<T>*);
	void destroy(node<T>*);
	int treeHeight(node<T>*);
	int max(int, int);
	int treeNodeCount(node<T>*);
	int treeLeaveCount(node<T>*);
	void treeInsert(node<T>*&, T&);
	bool treeSearch(node<T>*, T&);
	void treeDataSearch(node<T>*, T&);
	void treeDataFilter(node<T>*, T&);
	node<T>* findMax(node<T>*);
	void deletenode(node<T>*&, T&);
	int count;

public:
	BinarySearchTree();
	void inOrder()
	{
		inOrderT(root);
	}
	void preOrder()
	{
		preOrderT(root);
	}
	void postOrder()
	{
		postOrderT(root);
	}
	int height()
	{
		return treeHeight(root);
	}
	int nodeCount()
	{
		return treeNodeCount(root);
	}
	int leaveCount()
	{
		return treeLeaveCount(root);
	}
	void insert(T& item)
	{
		treeInsert(root, item);
	}
	bool search(T& item)
	{
		return treeSearch(root,item);
	}
	void treeDataSearch(T& item)
	{
		treeDataSearch(root, item);
	}
	void treeDataFilter(T& item)
	{
		treeDataFilter(root, item);
	}
	node<T>* findMax()
	{
		return findMax(root);
	}
	void deletenode(T& item)
	{
		deletenode(root, item);
	}
	~BinarySearchTree()
	{
		destroy(root);
	}

};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}


template <class T>
void BinarySearchTree<T>::inOrderT(node<T>* p)
{
	if(p!=NULL)
	{
		inOrderT(p->left);
		cout<<p->data;
		inOrderT(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::preOrderT(node<T>* p)
{
	if(p!=NULL)
	{
		cout<<p->data;
		preOrderT(p->left);
		preOrderT(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::postOrderT(node<T>* p)
{
	if(p!=NULL)
	{
		postOrderT(p->left);
		postOrderT(p->right);
		cout<<p->data;
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y)
{
	if (x>y)
	{
		return x;
	}
	return y;
}

template <class T>
int BinarySearchTree<T>::treeHeight(node<T>* p)
{
	if(p!=NULL)
	{
		return 1 + max(height(p->left, p->right));
	}
	return 0;
}

template <class T>
int BinarySearchTree<T>::treeNodeCount(node<T>* p)
{
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		return 1 + treeNodeCount(p->left) + treeNodeCount(p->right);
	}
}

template <class T>
int BinarySearchTree<T>::treeLeaveCount(node<T>* p)
{
	if(p==NULL)
	{
		return 0;
	}
	else if(p->left==NULL && p->right==NULL)
	{
		return 1;
	}
	else
	{
		return treeLeaveCount(p->left) + treeLeaveCount(p->right);

	}
}

template <class T>
void BinarySearchTree<T>::destroy(node<T>* p)
{
	if(p!= NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p= NULL;
	}
}

template <class T>
void BinarySearchTree<T>::treeInsert(node<T>*& p, T& item)
{
	if(p == NULL)
	{
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if(item<p->data)
	{
		treeInsert(p->left, item);
	}
	else
	{
		treeInsert(p->right, item);
	}

}

template <class T>
bool BinarySearchTree<T>::treeSearch(node<T>* p, T& item)
{
	if(p == NULL)
		return false;
	else if(item<p->data)
		return treeSearch(p->left, item);
	else if(item>p->data)
		return treeSearch(p->right, item);
	return true;
}

template <class T>
void BinarySearchTree<T>::treeDataSearch(node<T>* p, T& item)
{
	if(p == NULL)
	{
		cout << "Unable to find contact. Make sure the phone book is loaded." << endl;
	}
	else if(item==p->data)
	{
		cout << "Contact Found: ";
		cout << p->data;
	}
	else if(item<p->data)
	{
		treeDataSearch(p->left, item);
	}
	else if(item > p->data)
	{
		treeDataSearch(p->right, item);
	}
	else
	{
		cout << "error";
	}
}

template <class T>
void BinarySearchTree<T>::treeDataFilter(node<T>*p, T& item)
{
	if(p!=NULL){
		treeDataFilter(p->left, item);
		if(p->data <=item)
		{
			cout<<p->data;
			count++;
		}
		if(p->data == item)
		{
			// Prints contact count.			
			cout << "Phone book has " << count << " contacts." << endl;
		}
		treeDataFilter(p->right, item);
	}
}

template <class T>
node<T>* BinarySearchTree<T>::findMax(node<T>* p)
{
	if (p==NULL)
		return NULL;
	else if(p->right == NULL)
		return p;
	else
		return findMax(p->right);
}

template <class T>
void BinarySearchTree<T>::deletenode(node<T>*& p, T& item)
{
	//item not found, do nothing
	if(p == NULL)
		return;
	else if (item<p->data)	//item is on the left subtree
		deletenode(p->left, item);
	else if (item>p->data)	//item is on the right subtree
		deletenode(p->right, item);
    else{//item is equal to data,  it is found
		if(p->left!= NULL && p->right != NULL)
		{	//if it is with two children
			p->data = findMax(p->left)->data;
			deletenode(p->left, p->data);
		}
		else
		{
			node<T>* old = p;
			if(p->left != NULL)
				p = p->left;
			else
				p = p->right;
			delete old;
		}
	}
}



#endif /* BINARYSEARCHTREE_H_ */
