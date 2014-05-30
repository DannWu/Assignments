/*******************************************************************************
 
 Title:                 Sudoku.h
 Author:                Danny Wu
 Created on:            February 23th, 2013
 Description:           Sudoku with recursion
 Purpose:               Assignment 2

 *******************************************************************************/

#ifndef _SUDOKU_H
#define _SUDOKU_H

class Sudoku
{
public:
		//Initializes all values to 0
	Sudoku();
	~Sudoku();
	

		//displays entire board to standard output
	void displayBoard();


		//returns true if the board is a valid Sudoku board
	bool isValid(int row, int col);


		//Returns false if duplicate is found in row
		//is used by isValid()
	bool isHorizontalValid(int row);


		//Returns false if duplicate is found in col
		//is used by isValid()
	bool isVerticalValid(int col);


		//Returns false if duplicate is found in subgrid
		//is used by isValid()
	bool isSubGridValid(int row, int col);


		//Detailed explanation in function
		//is used by isSubGridValid
	bool checkGridHelper(int row, int col);


	//returns next position to check, used with nextJposition
	int nextIPosition(int row, int col);


	//returns next position to check, used with nextIposition
	int nextJPosition(int col);


	//inserts a random value from 1-9 into board[0][0], then recursively 
	//fills in the remainder of the board
	void generateBoard();


	//recursively fills in the board from row and col
	bool recursiveFill(int row, int col);
	
private:
	int board[9][9];
};

#endif