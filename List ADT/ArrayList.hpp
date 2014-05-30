/*******************************************************************************
 
 Title:                 ArrayList.hpp
 Author:                Danny Wu
 Created on:            April 28th 2014
 Description:           Templates, Inheritance, and List Data Structures
 Purpose:               Assignment 4

 Build:					g++ driver.cpp ListTester.cpp

 *******************************************************************************/

#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#define MAX_SIZE 10

#include "List.hpp"
#include "Error.h"


 		// ArrayList is a 1-based list
template <class T>
class ArrayList : public List <T>
{

public:

		// Initializes list with size = 0
	ArrayList();

		// Sets size = 0
	~ArrayList();

		// Returns true if List has no items
	bool isEmpty();

		// Returns the number of items on the List
	int getLength();

		// Inserts item to position (pos) on the list
		// position is 1-based (NOT like array)
		// Throws Error if pos is invalid or list is full
	void insert(int pos, T item) throw (Error::Insert::OutOfBounds, Error::Insert::ListFull);

		// Removes and returns item from position (pos) on list
		// position is 1-based (NOT like array)
		// Throws Error if pos is invalid
	T remove(int pos) throw (Error::Remove::OutOfBounds); //throw

		// Returns (returns but leaves on list) item at pos
		// position is 1-based (NOT like array)
		// Throws Error if pos is invalid
	T retrieve(int pos) throw (Error::Retrieve::OutOfBounds); //throw

private:
	int size;
	T theList[MAX_SIZE];
};


template <class T>
ArrayList<T>::ArrayList()
{
	size = 0;
}


template <class T>
ArrayList<T>::~ArrayList(){};


template <class T>
bool ArrayList<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}


template <class T>
int ArrayList<T>::getLength()
{
	return size;
}


template <class T>
void ArrayList<T>::insert(int pos, T item) throw (Error::Insert::OutOfBounds, Error::Insert::ListFull)
{
		// Instead of needing to +1 
		// I'll just add an int that resembles
		// the position for an 0-indexed array
	int arrayIndex = pos - 1;

		// Same logic here
	int endOfArray = size + 1;

		// Inserting out of bounds
		// Throws an Error
	if (pos < 1 || pos > 10)
	{
		throw Error::Insert::OutOfBounds();
	}

		// Inserting into a full array
		// Throws an Error
	else if (size == 10)
	{
		throw Error::Insert::ListFull();
	}

		// Inserting into an empty list
	else if (pos == 1 && size == 0)
	{
		theList[arrayIndex] = item;
		size++;
	}

		// Inserting into the beginning
	else if (pos == 1)
	{
		for (int i = size; i > 0; --i)
		{
				// Shifting objects to the "right", 
				// then adding item to beginning
			theList[i] = theList[i - 1];
		}

		theList[0] = item;

		size++;
	}

		// Insering into the end of the array
	else if (pos == endOfArray)
	{
		theList[arrayIndex] = item;
		size++;
	}

		// Inserting anywhere else (middle of array)
	else
	{
		for (int i = size; i > arrayIndex; --i)
		{
			theList[i] = theList[i - 1];
		}

		theList[arrayIndex] = item;

		size++;
	}
}


template <class T>
T ArrayList<T>::remove(int pos) throw (Error::Remove::OutOfBounds)
{
		//Throws Error if pos is out of bounds
    if (pos < 1 || pos > 10)
    {
        throw Error::Remove::OutOfBounds();
    }
    	//Throws Error if pos is out of bounds
    if (pos > size)
    {
    	throw Error::Remove::OutOfBounds();
    }

	int arrayIndex = pos - 1;

	T removedItem = theList[arrayIndex];

	for (int i = arrayIndex; i < size - 1; ++i)
	{
		theList[i] = theList[i + 1];
	}

	size--;
	return removedItem;
}


template <class T>
T ArrayList<T>::retrieve(int pos) throw (Error::Retrieve::OutOfBounds)
{
		//Throws Error if pos is out of bounds
	if (pos < 1 || pos > 10)
	{
		throw Error::Retrieve::OutOfBounds();
	}

	int arrayIndex = pos - 1;

	return theList[arrayIndex];
}

#endif
