/*******************************************************************************
 
 Title:                 binaryTrees.cpp
 Author:                Danny Wu
 Created on:            January 24, 2014
 Description:           Binary Tree Practice
 Note:					Unofficial practice, there are no comments here.
 
 *******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Node
{
	Node() {leftChild = NULL; rightChild = NULL;}
	int key;
	Node * leftChild;
	Node * rightChild;
};

class binaryTree
{
public:
	binaryTree() {root = NULL;}

	Node * getRoot()
	{
		return root;
	}

	void insert(int key, Node * current)
	{
		if (root == NULL)
		{
			current = new Node;
			root = current;
			root->key = key;
		}
		else 
		{
			if (key < current->key)
			{
				if (current->leftChild != NULL)
				{
					insert(key, current->leftChild);
				}
				else
				{
					Node * addNode = new Node;
					current->leftChild = addNode;
					addNode->key = key;
				}
			}

			if (key > current->key)
			{
				if (current->rightChild != NULL)
				{
					insert(key, current->rightChild);
				}
				else
				{
					Node * addNode = new Node;
					current->rightChild = addNode;
					addNode->key = key;
				}
			}
		}
	}

	Node * search(int key, Node * current)
	{
		if (current == NULL)
		{
			return NULL;
		}
		else
		{
			if (key == current->key)
			{
				return current;
			}
			if (key < current->key)
			{
				return search(key, current->leftChild);
			}
			else if (key > current->key)
			{
				return search(key, current->rightChild);
			}
		}		
	}

	void inOrderTransverse(Node * current)
	{
		if (current == NULL)
		{
			return;
		}
		inOrderTransverse(current->leftChild);
		cout << current->key << endl;
		inOrderTransverse(current->rightChild);
	}

private:
	Node * root;

};



int main(int argc, char const *argv[])
{
	binaryTree myTree;
	myTree.insert(50, myTree.getRoot());
	myTree.insert(25, myTree.getRoot());
	myTree.insert(75, myTree.getRoot());
	myTree.insert(100, myTree.getRoot());
	myTree.insert(1, myTree.getRoot());
	myTree.insert(12, myTree.getRoot());
	myTree.insert(65, myTree.getRoot());
	myTree.insert(90, myTree.getRoot());

	myTree.inOrderTransverse(myTree.getRoot());


	return 0;
}
