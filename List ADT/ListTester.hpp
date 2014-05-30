#ifndef _LISTTESTER_H_
#define _LISTTESTER_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include "List.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"

using namespace std;


/*
 * ListTester
 * Tests a List instance
 * Has only a single public function (test), so call with:
 * 	ListTester t;
 * 	t.test();
 * Assumes console I/O
 */
class ListTester {
public:
	void test();  // Conducts the test - inserts 10 items then removes them

private:
			// Gets a List instance (ArrayList / LinkedList)
			// This function should be in a Factory class
	List<string> * getList ();

			// Gets the user's intention to continue
			// This function should be in a Display class
	bool           userWantsToContinue ();

			// Gets a random position for insertion
			// This function should be in a Display class
	int            getRandomPosition (int range);

			// Gets an item from the user to insert into the List
			// This function should be in a Display class
	string         getItem ();

			// Prints an error message upon failure
			// This function should be in a Display class
	void           printError (int position, string item);

			// Prints a success message
			// This function should be in a Display class
	void           printSuccess (int position, string item);

			// Prints a success message (for deleted item)
			// This function should be in a Display class
	void           printDeleted (string item);

			// Prints the list
			// This function should be in a Display class
	void           printList (List<string> * list);
};


#endif
