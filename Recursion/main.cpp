/*******************************************************************************
 
 Title:                 main.cpp
 Author:                Danny Wu
 Created on:            February 23th, 2013
 Description:           Sudoku with recursion
 Purpose:               Assignment 2
 Note:					

 Build:					g++ main.cpp Sudoku.cpp

 *******************************************************************************/

#include "Sudoku.h"

int main(int argc, char const *argv[])
{
	Sudoku mySudoku;
	mySudoku.generateBoard();
	mySudoku.displayBoard();
	
	return 0;
}

