/*******************************************************************************
 
 Title:                 LinkedList.hpp
 Author:                Danny Wu
 Created on:            April 28th 2014
 Description:           Templates, Inheritance, and List Data Structures
 Purpose:               Assignment 4

 Build:					g++ driver.cpp ListTester.cpp

 *******************************************************************************/

#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include "List.hpp"
#include "Error.h"


template <class T>
struct Node
{
	Node<T> * next;
	T data;
};


	//LinkedList is a 1-based list
template <class T>
class LinkedList : public List <T>
{

public:

		//Intializes size to zero
	LinkedList();

		//Deletes every item of the list
	~LinkedList();

		// Returns true if List has no items
	bool isEmpty();

		// Returns the number of items on the List
	int getLength();

		// Inserts item to position (pos) on the list
		// position is 1-based (NOT like array)
		// Throws Error if pos is invalid
	void insert(int pos, T item) throw (Error::Insert::OutOfBounds);

		// Removes and returns item from position (pos) on list
		// position is 1-based (NOT like array)
		// Throws Error if pos is invalid
	T remove(int pos) throw (Error::Remove::OutOfBounds);

		// Returns (returns but leaves on list) item at pos
		// position is 1-based (NOT like array)
		// Throws Error if pos is invalid
	T retrieve(int pos) throw (Error::Retrieve::OutOfBounds);
	
private:
	int size;
	Node<T> * head;

};


template  <class T>
LinkedList<T>::LinkedList()
{
	size = 0;
	head = NULL;
}


template <class T>
LinkedList<T>::~LinkedList()
{
	while (size !=0)
	{
		this -> remove(size);
		this -> size--;
	}
}


template <class T>
bool LinkedList<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}


template <class T>
int LinkedList<T>::getLength()
{
	return size;
}


template <class T>
void LinkedList<T>::insert(int pos, T item) throw (Error::Insert::OutOfBounds)
{
	int endOfList = size + 1;

	if (pos < 1 || pos > 10)
	{
		throw Error::Insert::OutOfBounds();
	}

	Node <T> * addNode = new Node <T>;
	addNode -> data = item;
	addNode -> next = NULL;

		//Inserting into an empty list
		//or inserting into first position
	if (pos == 1)
	{
		if (this->isEmpty())
		{
			head = addNode;
		}
		else 
		{
			addNode -> next = head;
			head = addNode;
		}

		size ++;	
	}

		//Inserting to the end of the list
	else if (pos == endOfList && !(this->isEmpty()))
	{	
		Node<T> *currentNode = head;
		for (int i = 0; i < size - 1; ++i)
		{
			currentNode = currentNode -> next;
		}

		currentNode -> next = addNode;

		size ++;
	}

		//Inserting anywhere else (into the middle)
	else
	{
		Node<T> * currentNode = head;
		Node<T> * previousNode = head;

		for (int i = 0; i < pos - 1; ++i)
		{
			previousNode = currentNode;
			currentNode = currentNode -> next;
		}

		addNode -> next = currentNode;
		previousNode -> next = addNode;

		size ++;
	}
}


template <class T>
T LinkedList<T>::remove(int pos) throw (Error::Remove::OutOfBounds)//throw
{
	T removedItem;
	Node<T> * currentNode = head;

		//Throws Error if pos is out of bounds
	if (pos < 1 || pos > 10)
	{
		throw Error::Remove::OutOfBounds();
	}

		//Throws Error if pos is not on list
	if (pos > size)
	{
		throw Error::Remove::OutOfBounds();
	}

		//Removing final item of list
	if (pos == 1 && size == 1)
	{
		removedItem = head -> data;

		delete head;

		head = NULL;

		size --;
	}

		//Removing first item of non-empty list
	else if (pos == 1)
	{
		removedItem = head -> data;

		head = head -> next;

		delete currentNode;

		size --;
	}

		//Removing end item of a non-empty list
	else if (pos == size)
	{
		for (int i = 0; i < pos - 2; ++i)
		{
			currentNode = currentNode -> next;
		}

		removedItem = currentNode -> next -> data;

		delete currentNode -> next;

		currentNode -> next = NULL;

		size --;
	}

		//Removing anywhere else (middle)
	else
	{
		Node<T> * previousNode = NULL;
		for (int i = 0; i < pos - 1; ++i)
		{
			previousNode = currentNode;
			currentNode = currentNode -> next;
		}

		removedItem = currentNode -> data;
		previousNode -> next = currentNode -> next;

		delete currentNode;

		size --;
	}

	return removedItem;
}


template <class T>
T LinkedList<T>::retrieve(int pos) throw (Error::Retrieve::OutOfBounds)
{
	T retrievedItem;

	Node<T> * currentNode = head;

		//Throws Error if pos is out of bounds
	if (pos < 1 || pos > 10)
	{
		throw Error::Retrieve::OutOfBounds();
	}

		//Throws Error if pos is out of bounds
	if (pos > size)
	{
		throw Error::Retrieve::OutOfBounds();
	}

		//Throws Error if retrieving from an empty list
	if (size == 0)
	{
		throw Error::Retrieve::OutOfBounds();
	}

		//Retrieving the first item of list
	if (pos == 1)
	{
		return head -> data;
	}

		//Retrieving the last item of list
	else if (pos == size)
	{
		for (int i = 0; i < pos - 1; ++i)
		{
			currentNode = currentNode -> next;
		}
		retrievedItem = currentNode -> data;
	}

		//Retrieving anywhere else (middle);
	else
	{
		for (int i = 0; i < pos - 1; ++i)
		{
			currentNode = currentNode -> next;
		}
		retrievedItem = currentNode -> data;
	}

    return retrievedItem;
}

#endif
