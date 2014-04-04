/*******************************************************************************
 
 Title:                 main.cpp
 Author:                Danny Wu
 Created on:            February 7th, 2013
 Description:           Search using iostreams
 Purpose:               Assignment 1
 Build:					g++ main.cpp fileReader.cpp
 						Please have "actors.2010.list" in the same directory
 *******************************************************************************/

#include "fileReader.h"

#include <iostream>
#include <string>
#include <vector>


//helper function. outputs all elements of vectorToDisplay
void displayVector(vector<string> vectorToDisplay);


//outputs main menu
void mainMenu();


int main(int argc, char const *argv[])
{
	mainMenu();
	return 0;
}


void displayVector(vector<string> vectorToDisplay)
{
	for (int i = 0; i < vectorToDisplay.size(); ++i)
	{
		cout << "* " << vectorToDisplay[i] << endl;
	}
	cout << endl;
}


void mainMenu()
{
	//this is the first and last non-intuitive variable name in this program
	vector<string> oneVectorToRuleThemAll;
	fileReader actorList("actors.2010.list");
	string userChoice;

	cout << "2010 Movie DB. Find actor or co-stars?" << endl;
	getline(cin,userChoice);

	if (userChoice == "actor" || userChoice == "actors")
	{
		cout << "Name of movie: ";
		string movie;
		getline(cin, movie);
		actorList.searchActors(oneVectorToRuleThemAll, movie);
		displayVector(oneVectorToRuleThemAll);
		oneVectorToRuleThemAll.clear();
	}
	else if (userChoice == "co-star" || userChoice == "co-stars")
	{
		cout << "Name of actor: ";
		string actor;
		getline(cin, actor);
		cout << actor << " costarred with the following actors: " << endl;
		actorList.searchCoStars(oneVectorToRuleThemAll, actor);
		displayVector(oneVectorToRuleThemAll);
		oneVectorToRuleThemAll.clear();
	}
	else
	{
		cout << "Error user entered invalid input" << endl << endl;
	}
}

