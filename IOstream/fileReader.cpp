/*******************************************************************************
 
 Title:                 fileReader.cpp
 Author:                Danny Wu
 Created on:            February 7th, 2013
 Description:           Search using iostreams
 Purpose:               Assignment 1
 
 *******************************************************************************/

#include "fileReader.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

fileReader::fileReader(const char* fileName)
{
	actorListFile.open(fileName);
}
fileReader::~fileReader(){}


void fileReader::addToVector(vector<string> &vecActorList, string currentActor)
{
	bool alreadyOnList = false;
	for (int i = 0; i < vecActorList.size(); ++i)
	{
		if (vecActorList[i] == currentActor)
		{
			alreadyOnList = true;
		}
	}

	if (!alreadyOnList)
	{
		vecActorList.push_back(currentActor);
	}
}


string fileReader::parseActorName(string actorLine)
{
	string fname, lname, fullname;
	stringstream actorNameStream;
	actorNameStream << actorLine;

	getline(actorNameStream, lname, ',');
	getline(actorNameStream, fname);

		//Fullname is now fname space lname as the sample output displays
	fullname = fname + " " + lname;

		//Removes the space before the first name
	return fullname.substr(1);
}


string fileReader::parseMovieTitle(string movieLine)
{
	string movieTitle;
	stringstream movieTitleStream;
	movieTitleStream << movieLine;
	getline(movieTitleStream, movieTitle, '(');

		//Removes the first tab and the space before the '('
	return movieTitle.substr(1,movieTitle.length()-2);
}


void fileReader::parseEntry(string &actorName, vector<string> &vecMovieList)
{
	string currentLine;
	getline(actorListFile, currentLine);
	if (currentLine[0] != '\t' && !currentLine.empty())
	{
			//Then I know this line has to contain name of Actor
		actorName = parseActorName(currentLine);
		getline(actorListFile, currentLine);
		while (currentLine[0] == '\t' && !actorListFile.eof())
		{
			string currentMovie = parseMovieTitle(currentLine);
			vecMovieList.push_back(currentMovie);
			getline(actorListFile, currentLine);
		}
	}
}


void fileReader::searchActors(vector<string> &vecActorList, string movie)
{
	string currentLine, currentActor;
	vector<string> vecMovieList;
	actorListFile.seekg(0);
	while (!actorListFile.eof())
	{
		currentLine.clear();
		if (currentLine.empty())
		{
			parseEntry(currentActor, vecMovieList);
			for (int i = 0; i < vecMovieList.size(); ++i)
			{
				if (vecMovieList[i] == movie)
				{
					addToVector(vecActorList, currentActor);
				}
			}
			vecMovieList.clear();
		}
	}
} 


void fileReader::searchCoStars(vector<string> &vecCoStars, string actor)
{
	string currentLine, currentActor;
	vector<string> vecMovieList;
	actorListFile.seekg(0);
	while (!actorListFile.eof())
	{
		currentLine.clear();
		if (currentLine.empty())
		{
			parseEntry(currentActor, vecMovieList);
			if (currentActor == actor)
			{
				for (int i = 0; i < vecMovieList.size(); ++i)
				{
					searchActors(vecCoStars, vecMovieList[i]);
				}
			}
			vecMovieList.clear();
		}
	}
	for (int i = 0; i < vecCoStars.size(); ++i)
	{
		if (vecCoStars[i] == actor)
		{
				//Since my function adds the actor himself to the costar vector, 
				//I must now delete him from the vector
			vecCoStars.erase(vecCoStars.begin()+i);
		}
	}
}

