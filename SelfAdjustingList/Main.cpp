// Main.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-10

#include <iostream>
#include "SelfAdjustingList.h"

// Where the verification happens
// TODO Stephen
int main() {
	// ask the user how long the test list should be,
	// and how wide the search clustering should be.
	int inuptSize = 1000; //TODO
	int inputCluster = 5; //TODO

	// initialization
	SelfAdjustingList A = SelfAdjustingList();
	A.uniqueRandomFill(1000, 0, 1000);
	
	// finding elements WITHOUT self-adjusting
	// record both the total number of iterative steps
	// and the total number of check() operations
	A.check(0);

	// finding elements using the self-adjusting list
	// record both the total number of iterative steps
	// and the total number of find() operations
	A.find(0);

	// something about finding an element not in the list

	// compare and display test results:
	// iterative steps per check() compared to
	// iterative steps per find()
}