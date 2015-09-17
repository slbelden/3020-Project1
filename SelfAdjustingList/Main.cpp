// Main.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-10

#include <iostream>
#include "SelfAdjustingList.h"

int main() {
	int cycles = 0;
	while (1) {
		int inputSize = 0;
		int upperBound = 0;
		int clusterSize = 0;

		// Only display this intro text on the first run through the program
		if (cycles <= 0) {
			std::cout << "This program demonstrates the efficiency of self-adjusting lists in clustered" << std::endl;
			std::cout << "searches by generating a random list of unique positive ints, then repeatedly" << std::endl;
			std::cout << "searching through that list for groups of sequential numbers. For example," << std::endl;
			std::cout << "a Cluster Size of 4 would search for the following numbers in this order:" << std::endl;
			std::cout << "1,2,3,4, 2,3,4,5, 3,4,5,6, ... until the maximum value is reached." << std::endl;
			std::cout << "The total and average number of steps taken to search are displayed." << std::endl;
			std::cout << "A step is counted each time a new element is visited in the list." << std::endl;
			std::cout << std::endl;
			std::cout << "Explination of input variables:" << std::endl;
			std::cout << "* List Length:  Number of elements in the list. Must be non-negative integer." << std::endl;
			std::cout << "                (Recommended value 1-1000)" << std::endl;
			std::cout << "* Max Value:    The list will be filled with non-repeating random numbers from" << std::endl;
			std::cout << "                1 to this value. MUST be greater than or equal to List Length." << std::endl;
			std::cout << "* Cluster Size: The number of sequential elements searched for before moving on" << std::endl;
			std::cout << "                to the next series. (Recommended value 1-30)" << std::endl;
			std::cout << std::endl;
			std::cout << "Some interesting values to try:" << std::endl;
			std::cout << "* Max Value equal to List Length - ideal situation with no misses" << std::endl;
			std::cout << "* Max Value much greater than List Length - more misses than hits" << std::endl;
			std::cout << "* Cluster Size of 1 - plain linear search, no searches repeated" << std::endl;
			std::cout << "* Large Cluster Size - more opportunities for the self-adjusting function to" << std::endl;
			std::cout << "                     work effectively, which should widen the gap between tests" << std::endl;
			std::cout << std::endl;
		}

		// Input section
		std::cout << "List Length: ";
		std::cin >> inputSize;
		std::cout << "Max Value: ";
		std::cin >> upperBound;
		std::cout << "Cluster Size: ";
		std::cin >> clusterSize;
		std::cout << std::endl;

		// initialization
		SelfAdjustingList A = SelfAdjustingList();
		A.uniqueRandomFill(inputSize, 1, upperBound);

		// The following is a great lesson in how NOT to design code
		// We'll try to fix this horendous code duplication when we have time

<<<<<<< HEAD
		if (inputCluster <= 1) { // Regular linear search
								 // record both the total number of iterative steps
								 // and the total number of check() operations
=======
		// Regular linear search
		if (clusterSize <= 1) {
>>>>>>> origin/master
			{ // new block to handle creating and deleting temp variables
				std::cout << "Searching for numbers 1 to Max Value once each, WITHOUT self-adjusting..." << std::endl;
				int findCalls = 0;
				int found = 0;
				long steps = 0;
				for (int n = 1; n <= upperBound; n++) {
					int temp = A.check(n);
					findCalls++;
					if (temp >= 1) {
						steps += temp;
						found++;
					}
					else steps += inputSize;
				}
				std::cout << "Linear search tried to find " << findCalls <<
					" numbers and actually found " << found << "." << std::endl;
				std::cout << "A total of " << steps << " steps were taken during this search," << std::endl;
				std::cout << "which is an average of " << (double)steps / (double)findCalls <<
					" steps per find operation." << std::endl << std::endl;
			}

			{
				std::cout << "Searching for numbers 1 to Max Value once each, with self-adjusting..." << std::endl;
				int findCalls = 0;
				int found = 0;
				long steps = 0;
				for (int n = 1; n <= upperBound; n++) {
					int temp = A.find(n);
					findCalls++;
					if (temp >= 1) {
						steps += temp;
						found++;
					}
					else steps += inputSize;
				}
				std::cout << "Self-adjusting search tried to find " << findCalls <<
					" numbers and actually found " << found << "," << std::endl;
				std::cout << "A total of " << steps << " steps were taken during this search," << std::endl;
				std::cout << "which is an average of " << (double)steps / (double)findCalls <<
					" steps per find operation." << std::endl << std::endl;
			}
		}

		// Clustered find
		else { 
			{ // new block to handle creating and deleting temp variables
				std::cout << "Finding elements in cluster WITHOUT self-adjusting..." << std::endl;
				int findCalls = 0;
				int current = 1;
				int found = 0;
				long steps = 0;
				while (current <= upperBound) {
					for (int i = 0; i < clusterSize; i++) {
						int temp = 0;
						// This loop will generate numbers greater than upperBound and shoot off the
						// end of the list, so this check is here to prevent that.
						if (current + i <= upperBound) {
							temp = A.check(current + i);
							findCalls++;
						}
						if (temp >= 1) {
							steps += temp;
							found++;
						}
						else steps += inputSize;
					}
					current++;
				}
				std::cout << "Linear search tried to find " << findCalls <<
					" numbers and actually found " << found << "," << std::endl;
				std::cout << "A total of " << steps << " steps were taken during this search," << std::endl;
				std::cout << "which is an average of " << (double)steps / (double)findCalls <<
					" steps per find operation." << std::endl << std::endl;
			}

			{
				std::cout << "Finding elements in cluster with self-adjusting..." << std::endl;
				int findCalls = 0;
				int current = 1;
				int found = 0;
				long steps = 0;
				while (current <= upperBound) {
					for (int i = 0; i < clusterSize; i++) {
						int temp = 0;
						// This loop will generate numbers greater than upperBound and shoot off the
						// end of the list, so this check is here to prevent that.
						if (current + i <= upperBound) {
							temp = A.find(current + i);
							findCalls++;
						}
						if (temp >= 1) {
							steps += temp;
							found++;
						}
						else steps += inputSize;
					}
					current++;
				}
				std::cout << "Self-adjusting search tried to find " << findCalls <<
					" numbers and actually found " << found << "," << std::endl;
				std::cout << "A total of " << steps << " steps were taken during this search," << std::endl;
				std::cout << "which is an average of " << (double)steps / (double)findCalls <<
					" steps per find operation." << std::endl << std::endl;
			}
		}

		std::cout << std::endl;
		std::cout << "////////////////////          PROGRAM REPEATS...          ////////////////////" << std::endl;
		std::cout << std::endl << std::endl;

		cycles++;
	}
}
