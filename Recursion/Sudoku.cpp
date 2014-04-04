/*******************************************************************************
 
 Title:                 Sudoku.cpp
 Author:                Danny Wu
 Created on:            February 23th, 2013
 Description:           Sudoku with recursion
 Purpose:               Assignment 2

 *******************************************************************************/

#include "Sudoku.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

Sudoku::Sudoku()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			//initializes all values to 0
			board[i][j] = 0;
		}
	}
}

Sudoku::~Sudoku(){}

void Sudoku::displayBoard()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


bool Sudoku::isValid(int row, int col)
{
	return (isHorizontalValid(row) && isVerticalValid(col) && isSubGridValid(row,col));
}


bool Sudoku::isHorizontalValid(int row)
{
	int currentNumber;
	vector<int> rowContents;

	for (int i = 0; i < 9; ++i)
	{
		//if not default value of 0, there are contents I want to store
		if (board[row][i] != 0)
		{
			rowContents.push_back(board[row][i]);
		}
	}

	//the actual check
	for (int i = 0; i < rowContents.size(); ++i)
	{
		currentNumber = rowContents[i];
		for (int j = i+1; j < rowContents.size(); ++j)
		{
			if (currentNumber == rowContents[j])
			{
				return false;
			}
		}
	}
	return true;	
}


bool Sudoku::isVerticalValid(int col)
{
	int currentNumber;
	vector<int> colContents;

	for (int i = 0; i < 9; ++i)
	{
		//if not default value of 0, there are contents I want to store
		if (board[i][col] != 0)
		{
			colContents.push_back(board[i][col]);
		}
	}

	//the actual check
	for (int i = 0; i < colContents.size(); ++i)
	{
		currentNumber = colContents[i];
		for (int j = i+1; j < colContents.size(); ++j)
		{
			if (currentNumber == colContents[j])
			{
				return false;
			}
		}
	}
	return true;
}


bool Sudoku::isSubGridValid(int row, int col)
{
	//this function returns the top left index
	//of the subgrid you are trying to check.
	//the actual check is delegated to checkGridHelper
	if ((row <= 2) && (col <= 2))
	{
		return checkGridHelper(0,0);
	}
	else if ((row <= 2) && (col <= 5))
	{
		return checkGridHelper(0,3);
	}
	else if ((row <= 2) && (col <= 8))
	{
		return checkGridHelper(0,6);
	}
	else if ((row <= 5) && (col <= 2))
	{
		return checkGridHelper(3,0);
	}
	else if ((row <= 5) && (col <= 5))
	{
		return checkGridHelper(3,3);
	}
	else if ((row <= 5) && (col <= 8))
	{
		return checkGridHelper(3,6);
	}
	else if (col <= 2)
	{
		return checkGridHelper(6,0);
	}
	else if (col <= 5)
	{
		return checkGridHelper(6,3);
	}
	else
	{
		return checkGridHelper(6,6);
	}
}


bool Sudoku::checkGridHelper(int row, int col)
{
	//I wanted a systematic way to check each subgrid.
	//This only works if I can correctly identify which subgrid
	//I'm in, and the above function does exactly that. 
	int currentNumber;
	int reset = col;
	vector<int> subGridContents;
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			//if not default value of 0, there are contents I want to store
			if (board[row][col] != 0) 
			{
				subGridContents.push_back(board[row][col]);
			}
			//do this three times. ex: [0,0] [0,1] [0,2]
			col += 1;
		}
		col = reset; //must reset col back to original value
		//do this three times.  ex: [1,0] [1,1] [1,2]
		row += 1;
	}
	
	//the actual check
	for (int i = 0; i < subGridContents.size(); ++i)
	{	
		currentNumber = subGridContents[i];
		for (int j = i+1; j < subGridContents.size(); ++j)
		{
			if (currentNumber == subGridContents[j])
			{
				return false;
			}
		}
	}
	return true;
}


int Sudoku::nextIPosition(int row, int col)
{
	//I needed a systematic way to access each element in array
	//this, used in conjunction with nextJposition, achieves the
	//desired outcome.

	//I chose to move horizontally, then down
	//So if col is 8 (last column), I need to move to next row
	if (col == 8)
	{
		return row + 1;
	}
	//else stay on the same row (i is the same)
	else
	{
		return row;
	}
} 


int Sudoku::nextJPosition(int col)
{
	//If col isn't 8 (the last column)
	//move on to the next column
	if (col != 8)
	{
		return col + 1;
	}
	//else return to first column 
	else
	{
		return 0;
	} 
}


void Sudoku::generateBoard()
{
	srand(time(NULL));
	board[0][0] = rand() % 9 + 1;
	recursiveFill(0,1);
}


bool Sudoku::recursiveFill(int row, int col)
{
	//If board[8][8] isn't default value,
	//then the board has been filled successfully! Cheers!
	if (board[8][8] != 0)
	{
		return true;
	}

	//Without randomNumber, it would generate the same board
	//for each initial number at board[0][0]
	int randomNumber = rand() % 9 + 1;

	//Attempts to fill in board[row][col] with randomNumber to 10
	for (int i = randomNumber; i < 10; ++i)
	{
		board[row][col] = i;
		if (isValid(row,col))
		{
			if (recursiveFill(nextIPosition(row, col), nextJPosition(col)))
			{
				return true;
			}
		}
		//recursion unsuccessful, revert board[row][col] back to default value of 0
		board[row][col] = 0;
	}

	//If that fails, this attempts to fill in board[row][col] with 1 to randomNumber.
	//This combined with the above for loop is exhaustive from 1 to 9
	for (int i = 10 - randomNumber; i < 10; ++i)
	{
		board[row][col] = i;
		if (isValid(row,col))
		{
			if (recursiveFill(nextIPosition(row, col), nextJPosition(col)))
			{
				return true;
			}
		}
		//recursion unsuccessful, revert board[row][col] back to default value of 0
		board[row][col] = 0;
	}

	return false;
}

