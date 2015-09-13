// SelfAdjustingList.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-10

#include <iostream>
#include "SelfAdjustingList.h"
#include <forward_list>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <deque>
using namespace std;

int SelfAdjustingList::check(int f) const {
	// TODO Chris
}

int SelfAdjustingList::find(int f){
	// TODO Chris
	std::cout << "Hello World" << std::endl;
	return 0;
}

// Should this return randomList?
// if so, here's the code!
// forward_list SelfAdjustingList::uniqueRandomFill(int number, int lower, int upper) {

void SelfAdjustingList::uniqueRandomFill(int number, int lower, int upper) {
	// TODO Meghan
	std::forward_list<int> randomList;
	std::deque<int> cleverName(1,lower);
	int i(lower+1);
	while (i<= upper)
	{
		cleverName.push_front(i);
		i++;
	}
	std::random_shuffle(cleverName.begin(), cleverName.end());
	int j(0);
	while (j <= number)
	{
		randomList.push_front(cleverName.front());
		cleverName.pop_back();
		j++;
	}
	// return randomList;
}