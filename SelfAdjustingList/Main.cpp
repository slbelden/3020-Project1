// Main.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-10

#include <iostream>
#include <cstdlib>
#include "SelfAdjustingList.h"

int main() {
	int cycles = 0;
	while (1) {
		int inputSize = 0;
		int upperBound = 0;
		int inputCluster = 0;

		// Only display this intro text on the first run through the program
		if (cycles <= 0) {
			std::cout << "This program demonstrates the efficiency of self-adjusting lists in certain" << std::endl;
			std::cout << "situations by generating a random list of unique ints, then searching through" << std::endl;
			std::cout << "that list both with and without the self-adjusting function of the list." << std::endl;
			std::cout << "The same initial random order of elements is used for both tests." << std::endl;
			std::cout << std::endl;
			std::cout << "Some interesting values to try:" << std::endl;
			std::cout << "* Equal list length and max value - ideal situation with no misses" << std::endl;
			std::cout << "* Max value much greater than list length - more misses than hits" << std::endl;
			std::cout << "* Max value less than list length - should crash!!" << std::endl;
			std::cout << "* Cluster size of 1 - plain linear search, no searches repeated" << std::endl;
			std::cout << "* Large cluster size - more opportunities for the self-adjusting function to" << std::endl;
			std::cout << "                     work effectively, which should widen the gap between tests." << std::endl;
			std::cout << std::endl;
		}

		// Input section
		std::cout << "Input the desired length of the list as a non-negative integer" << std::endl;
		std::cout << "(Recommended values 0-1000): ";
		std::cin >> inputSize;
		std::cout << std::endl << "Input the desired maximum value for the list. The list will be filled with" << std::endl;
		std::cout << "unique, non-repeating, random numbers from 0 to this value: ";
		std::cin >> upperBound;
		std::cout << std::endl << "Input the cluster size.";
		// Dear MH,
		// I'm still confused. Also:
		// Unicode quotation marks don't print properly in most consoles, use escaped ASCII quotes instead.
		// Numbers like 1 or 2 probably shouldn't be mentioned, because the cluster size is unbound.
		std::cout << std::endl << "Values in within this cluster size will be randomly generated and found.";
		std::cout << std::endl << "Cluster size serves as a “pivot”? for the cluster with 1 or 2 more values";
		std::cout << std::endl << "greater than cluster size than values less than cluster size.";
		std::cout << std::endl << "(Recommended values 1-10, unless the list is very small): ";
		std::cin >> inputCluster;
		std::cout << std::endl;

		// initialization
		SelfAdjustingList A = SelfAdjustingList();
		A.uniqueRandomFill(inputSize, 0, upperBound);

		if (inputCluster <= 1) { // Regular linear search
								 // record both the total number of iterative steps
								 // and the total number of check() operations
			{ // new block to handle creating and deleting temp variables
				std::cout << "Searching for numbers 0 to Upper Bound once each, WITHOUT self-adjusting..." << std::endl;
				long steps = 0;
				for (int n = 0; n < upperBound; n++) {
					int temp = A.check(n);
					if (temp >= 1) steps += temp;
					else steps += inputSize;
				}
				std::cout << "Done with dumb search in " << steps << " steps." << std::endl << std::endl;
			}

			{
				// record both the total number of iterative steps
				// and the total number of find() operations
				std::cout << "Searching for numbers 0 to Upper Bound once each, with self-adjusting..." << std::endl;
				long steps = 0;
				for (int n = 0; n < upperBound; n++) {
					int temp = A.find(n);
					if (temp >= 1) steps += temp;
					else steps += inputSize;
				}
				std::cout << "Done with self-adjusting search in " << steps << " steps." << std::endl << std::endl;
			}
		}
		else { // Clustered find
			{ // new block to handle creating and deleting temp variables
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
				std::cout << "Done with dumb search in " << steps << " steps." << std::endl << std::endl;
			}

			{
				std::cout << "Finding elements in cluster and adjusting the list..." << std::endl;
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
				std::cout << "Done with self-adjusting search in " << steps << " steps." << std::endl << std::endl;
			}
		}

		std::cout << std::endl;
		std::cout << "////////////////////          PROGRAM REPEATS...          ////////////////////" << std::endl;
		//std::cout << std::endl << std::endl;

		cycles++;
	}
}
