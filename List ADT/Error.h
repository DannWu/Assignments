/*******************************************************************************
 
 Title:                 Error.h
 Author:                Danny Wu
 Created on:            April 28th 2014
 Description:           Templates, Inheritance, and List Data Structures
 Purpose:               Assignment 4

 Build:					g++ driver.cpp ListTester.cpp

 *******************************************************************************/
 
#ifndef _ERROR_
#define _ERROR_

	//Implementation is intentionally left blank.
	//This is a theoretical way of handling potential Errors
namespace Error
{
	namespace Insert
	{
		struct OutOfBounds
		{
			OutOfBounds(){};
			~OutOfBounds(){};
		};

		struct ListFull
		{
			ListFull(){};
			~ListFull(){};
		};
	}

	namespace Remove
	{
			//Repeated because theoretically, these Errors
			//could be handled differently
		struct OutOfBounds
		{
			OutOfBounds(){};
			~OutOfBounds(){};
		};
	}

	namespace Retrieve
	{
			//Ditto
		struct OutOfBounds
		{
			OutOfBounds(){};
			~OutOfBounds(){};
		};
	}
}

#endif
