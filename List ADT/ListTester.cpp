#include "ListTester.hpp"


// getList
// Prompts user for List type to return.
// @return List instance: ArrayList or (default) LinkedList
List<string> * ListTester::getList () {
	List<string> * list = NULL;
	string response;

	cout << "Use ArrayList? (Y/N) ";
	cin >> response;
	while (response != "Y" && response != "y" 
			&& response != "N" && response != "n") {
		cout << "Only Y/N: ";
		cin >> response;
	} 

	if (response == "Y" || response == "y") {
		list = new ArrayList<string>();
	}
	else {
		list = new LinkedList<string>();
	}

	return list;
}


// userWantsToContinue
// Prompts the user to continue with the test or not.
// @return true if the user wants to continue; false if not
bool ListTester::userWantsToContinue() {
	string response;
	cout << "Another test? (Y/N) ";
	cin >> response;
	while (response != "Y" && response != "y"
			&& response != "N" && response != "n") {
		cout << "Only Y/N: ";
		cin >> response;
	}
	if (response == "Y" || response == "y") {
		return true;
	}
	// else
	return false;
}


// getRandomPosition
// Generates a random insert/delete position.
// @param range (int): half the size to be returned.
// @return int = a random position
int ListTester::getRandomPosition (int range) {
	int newRange = (range + 1) * 2;
	int pos = rand() % newRange - range;
	cout << "Random position for " << range << "-item list = " << pos;
	if (pos < 1 || pos > range + 1) {
		// Note that this is true for list->insert(...), but not
		// completely accurate for list->delete(...)
		cout << " (... which maybe should fail)." << endl;
	}
	else {
		cout << " (... which should succeed)." << endl;
	}
	return pos;
}


// getItem
// Prompts the user for an item to insert.
// @return item to be inserted (string).
string ListTester::getItem () {
	string item;
	cout << "Item to insert: ";
	cin >> item;
	return item;

}


// printError
// Prints an error message if an error (due to position?) occurs
// @param position (int) = position at which insert/delete was attempted
// @param item (string) = item which would have been inserted
void ListTester::printError (int position, string item) {
	cout << "Failed to insert " << item << " to position " << position << endl;
}


// printSuccess
// Prints a helpful message when the item has been successfully inserted
// @param position (int) = the position at which the insert was attempted
// @param item (string) = the item which has been successfully inserted
void ListTester::printSuccess (int position, string item) {
	cout << "Inserted " << item << " to position " << position << endl;
}


// printDeleted
// Prints a helpful message when the item has been successfully deleted
// @param item (string) = the item deleted from the list
void ListTester::printDeleted (string item) {
	cout << "Deleted " << item << endl;
}


// printList
// Prints the list
// @param list (List *) = the list to be printed
void ListTester::printList (List<string> * list) {
	if (list->getLength() == 0) {
		cout << "List is currently empty" << endl;
	}
	else {
		cout << "List is currently as follows: " << endl;
		for (int i = 0; i < list->getLength(); i++) {
			cout << "\t[" << i+1 << "] = " << list->retrieve(i+1) << endl;
		}
	}
}


// test
// Inserts 10 items to the list, printing them along the way... then
// removes 10 items from the list, printing the list along the way.
void ListTester::test () {
	List<string> * list;
	do {
		list = getList();

		// Add items to list... in random positions
		while (list->getLength() < 10) {
			int position = getRandomPosition(list->getLength());
			string item = getItem();
			try {
				list->insert(position, item);
				printSuccess(position, item);
			}
			catch (...) {
				printError(position, item);
			}
			printList(list);
		}

		// Remove items from list ... again, random positions;
		while (list->getLength() > 0) {
			int position = getRandomPosition(list->getLength());
			string deleted = "";
			try {
				deleted = list->remove(position);
				printDeleted(deleted);
			}
			catch (...) {
				printError(position, deleted);
			}
			printList(list);
		}

		// Done. Cleaning up:
		delete list;
		list = NULL;

	} while (userWantsToContinue());
}



