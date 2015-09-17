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
		int clusterRadius = 0;

		// Only display this intro text on the first run through the program
		if (cycles <= 0) {
			std::cout << "This program demonstrates the efficiency of self-adjusting lists in certain" << std::endl;
			std::cout << "situations by generating a random list of unique ints, then searching through" << std::endl;
			std::cout << "that list both with and without the self-adjusting function of the list." << std::endl;
			std::cout << "The same initial random order of elements is used for both tests." << std::endl;
			std::cout <<  "The total and average number of steps taken to search will be returned." << std::endl ;
			std::cout <<  "A step is counted each time a new element is checked at while searching.";
			std::cout << std::endl;
			std::cout << "Explination of input variables:" << std::endl;
			std::cout << "* List Length -    The length of the list. Must be non-negative integer." << std::endl;
			std::cout << "                   (Recommended value 0-1000)" << std::endl;
			std::cout << "* Max Value -      The list will be filled with unique, non-repeating, random" << std::endl;
			std::cout << "                   numbers from 1 to this value." << std::endl;
			std::cout << "                   Must be greater than or equal to List Length." << std::endl;
			std::cout << "* Cluster Radius - While searching, the number being searched for may increace" << std::endl;
			std::cout << "                   or decreace by a maximum of this ammount. This value also" << std::endl;
			std::cout << "                   controls how long the cluster is centered around one value" << std::endl;
			std::cout << "                   before going on to the next, so making this value larger will" << std::endl;
			std::cout << "                   result in more find calls." << std::endl;
			std::cout << "                   (Recommended values 1-10, unless the list is small)" << std::endl;
			std::cout << std::endl;
			std::cout << "Some interesting values to try:" << std::endl;
			std::cout << "* Max Value 1 less than List Length - ideal situation with no misses" << std::endl;
			std::cout << "* Max value much greater than list length - more misses than hits" << std::endl;
			std::cout << "* Cluster size of 1 - plain linear search, no searches repeated" << std::endl;
			std::cout << "* Large cluster size - more opportunities for the self-adjusting function to" << std::endl;
			std::cout << "                     work effectively, which should widen the gap between tests." << std::endl;
			std::cout << std::endl;
		}

		// Input section
		std::cout << "List Length: ";
		std::cin >> inputSize;
		std::cout << "Max Value: ";
		std::cin >> upperBound;
		std::cout << "Cluster Radius: ";
		std::cin >> clusterRadius;
		std::cout << std::endl;

		// initialization
		SelfAdjustingList A = SelfAdjustingList();
		A.uniqueRandomFill(inputSize, 1, upperBound);

		// Regular linear search
		if (clusterRadius <= 1) {
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
					" numbers and actually found " << found << "," << std::endl;
				std::cout << "with an average of " << (double)steps / (double)findCalls <<
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
				std::cout << "with an average of " << (double)steps / (double)findCalls <<
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
					for (int i = 0; i < clusterRadius; i++) {
						int temp = A.check(current + i);
						findCalls++;
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
				std::cout << "with an average of " << (double)steps / (double)findCalls <<
					" steps per find operation." << std::endl << std::endl;
			}

			{
				std::cout << "Finding elements in cluster with self-adjusting..." << std::endl;
				int findCalls = 0;
				int current = 1;
				int found = 0;
				long steps = 0;
				while (current <= upperBound) {
					for (int i = 0; i < clusterRadius; i++) {
						int temp = A.find(current + i);
						findCalls++;
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
				std::cout << "with an average of " << (double)steps / (double)findCalls <<
					" steps per find operation." << std::endl << std::endl;
			}
		}

		std::cout << std::endl;
		std::cout << "////////////////////          PROGRAM REPEATS...          ////////////////////" << std::endl;
		std::cout << std::endl << std::endl;

		cycles++;
	}
}
