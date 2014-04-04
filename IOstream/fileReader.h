/*******************************************************************************
 
 Title:                 fileReader.h
 Author:                Danny Wu
 Created on:            February 7th, 2013
 Description:           Search using iostreams
 Purpose:               Assignment 1
 
 *******************************************************************************/

#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class fileReader
{
public:
	//constructor will open fileName as ifstream. No default constructor necessary
	fileReader(const char* fileName);
	~fileReader();
	

	//helper function to add currentActor to vecActorList if currentActor 
	//is not already in the vector
	void addToVector(vector<string> &vecActorList, string currentActor);


	//helper function returns 'firstname space lastname' from the string actorLine
	string parseActorName(string actorLine);


	//helper function returns movie title from movieLine
	string parseMovieTitle(string movieLine);


	//parseEntry will store the actor name in actorName and all his movies in vecMovieList
	void parseEntry(string &actorName, vector<string> &vecMovieList);


	//using movie, searchActors will find all actors and store them in 
	//vecActorList if actor is not already in the vector
	void searchActors(vector<string> &vecActorList, string movie);


	//using actor, searchCoStars will find all costars and store them in 
	//vecCoStars if costar is not already in the vector
	void searchCoStars(vector<string> &vecCoStars, string actor);

private:
	ifstream actorListFile;
};

#endif