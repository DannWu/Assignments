#include <cstdlib>
#include <ctime>
#include "ListTester.hpp"


/*
 * Cheesy test for a List.
 */
int main () {
	srand(time(NULL));
	ListTester tester;

	tester.test();

	return 0;
}
