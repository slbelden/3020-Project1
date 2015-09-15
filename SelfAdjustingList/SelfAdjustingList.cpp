// SelfAdjustingList.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-10

#include <iostream>
#include "SelfAdjustingList.h"
#include <forward_list>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>      // std::rand, std::srand
#include <deque>

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

void SelfAdjustingList::print() {
	int count = 0;
	auto it = data.begin();
	while (it != data.end()) {
		std::cout << "      List element [" << count << "] : " << *it << std::endl;
		count++;
		it++;
	}
}
