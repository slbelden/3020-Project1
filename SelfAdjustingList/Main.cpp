// Main.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-10

#include <iostream>
#include <cstdlib>
#include "SelfAdjustingList.h"

// Where the verification happens
// TODO Stephen
int main() {
	int inputSize = 0;
	int upperBound = 0;
	int inputCluster = 0;
	std::cout << "This program demonstrates the efficency of self-adjusting lists" << std::endl;
	std::cout << "in certain situations by generating a random list of unique ints," << std::endl;
	std::cout << "then searching for clusters of adjacent natural numbers in the list." << std::endl << std::endl;
	std::cout << "Input the desired length of the list as a non-negative integer" << std::endl;
	std::cout << "(Recomended values 0-1000): ";
	std::cin >> inputSize;
	std::cout << std::endl << "Input the desired maximum value for the list. Unique, non-repeating, random" << std::endl;
	std::cout << "numbers will be added to the list from 0 to this value: ";
	std::cin >> upperBound;
	std::cout << std::endl << "Input the cluster size.";
	std::cout << std::endl << "Values in within this cluster size will be randomly generated and found.";
	std::cout << std::endl << "Cluster size serves as a “pivot”? for the cluster with 1 or 2 more values"
	std::cout << std::endl << "greater than cluster size than values less than cluster size.";
	std::cin >> inputCluster;
	// MH: Let me know if you think we need anythong else here!
	std::cout << std::endl << "The same random order is used for each test." << std::endl;

	// ask the user how long the test list should be,
	// and how wide the search clustering should be.

	// initialization
	SelfAdjustingList A = SelfAdjustingList();
	A.uniqueRandomFill(inputSize, 0, upperBound);
	
	// finding elements WITHOUT self-adjusting
	// record both the total number of iterative steps
	// and the total number of check() operations
	/*std::cout << "Searching for numbers 0 to Upper Bound once each," << std::endl;
	std::cout << "WITHOUT self-adjusting..." << std::endl;
	long steps = 0;
	for (int n = 0; n < upperBound; n++) {
		int temp = A.check(n);
		if (temp >= 1) steps += temp;
		else steps += inputSize;
	}
	std::cout << "Done Checking in " << steps << " steps." << std::endl << std::endl;*/

	//Clustered find
	{
		std::cout << "Finding elements in cluster WITHOUT self-adjusting..." << std::endl;
		int current = 0;
		long steps = 0;
		int lower = (inputCluster - 1) / 2;
		while (current < upperBound) {
			current += rand() % inputCluster - lower;
			if (current < 0)current = 0;
			int temp = A.check(current);
			if (temp >= 1) steps += temp;
			else steps += inputSize;
		}
		std::cout << "Done Finding in " << steps << " steps." << std::endl << std::endl;
	}

	{
		std::cout << "Finding elements in cluster..." << std::endl;
		int current = 0;
		long steps = 0;
		int lower = (inputCluster - 1) / 2;
		while (current < upperBound) {
			current += rand() % inputCluster - lower;
			if (current < 0)current = 0;
			int temp = A.find(current);
			if (temp >= 1) steps += temp;
			else steps += inputSize;
		}
		std::cout << "Done Finding in " << steps << " steps." << std::endl << std::endl;
	}

	// finding elements using the self-adjusting list
	// record both the total number of iterative steps
	// and the total number of find() operations
	//std::cout << "Searching for numbers 0 to Upper Bound once each," << std::endl;
	//std::cout << "WITHOUT self-adjusting..." << std::endl;
	//steps = 0;
	//for (int n = 0; n < upperBound; n++) {
	//	int temp = A.find(n);
	//	if (temp >= 1) steps += temp;
	//	else steps += inputSize;
	//}
	//std::cout << "Done Finding in " << steps << " steps." << std::endl << std::endl;

	// something about finding an element not in the list

	// compare and display test results:
	// iterative steps per check() compared to
	// iterative steps per find()
}