// SelfAdjustingList.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-17

#include <iostream>
#include "SelfAdjustingList.h"
#include <forward_list>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::rand, std::srand
#include <deque>
#include <string>

// Written by Chris
int SelfAdjustingList::check(int f) const {
	int steps = 0;
	auto it = data.begin();
	bool matched = false;

	while (it != data.end()) {
		steps++;
		if (*it == f) {
			matched = true;
			break;
		}
		it++;
	}

	if (!matched) {
		steps = -1 * steps;
	}
	return steps;
}

// Written by Chris
int SelfAdjustingList::find(int f) {
	int steps = 0;
	auto it = data.begin();
	auto it_prev = data.before_begin();
	bool matched = false;

	while (it != data.end()) {
		steps++;
		if (*it == f) {
			matched = true;
			break;
		}
		it++;
		it_prev++;
	}

	if (!matched) {
		steps = -1 * steps;
	}
	else {
		it_prev = data.erase_after(it_prev);
		fill(f);
	}

	return steps;
}

void SelfAdjustingList::uniqueRandomFill(int number, int lower, int upper) {
	// Authored by Meghan
	std::deque<int> cleverName(1,lower);
	int i(lower+1);
	while (i <= upper)
	{
		cleverName.push_front(i);
		i++;
	}
	std::random_shuffle(cleverName.begin(), cleverName.end());
	int j(0);
	while (j < number)
	{
		SelfAdjustingList::data.push_front(cleverName.front());
		cleverName.pop_front();
		j++;
	}
}

// Chris test functions
void SelfAdjustingList::fill(int f) {
	data.push_front(f);
}

// Modified by Chris to make the output pretty.
// Designed for inputs of int 99999 or below. Any larger will break formatting.
// For our test cases, this should be fine.
void SelfAdjustingList::print() {
	std::string output = "";
	std::string dummy = "   [";
	int count = 0;
	auto it = data.begin();

	while (it != data.end()) {
		if ( count % 10 == 0) {
			output += dummy;
			dummy = (count > 2) ? ("\n    ") : ("");
		}
		dummy += " " + std::to_string(*it) + ",";
		count++;
		it++;
	}

	output += dummy;
	if (count > 1) {
		output.pop_back();
	}
	output += " ]";

	//std::cout << "Printing list of " << count << " elements:" << std::endl;
	std::cout << output << std::endl;
}
