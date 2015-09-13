// SelfAdjustingList.cpp
// Stephen Belden
// Chris Ruiz
// Meghan Haukaas
// 2015-Sept-10

#pragma once

#include <forward_list>

class SelfAdjustingList {
private:
	std::forward_list<int> data = std::forward_list<int>();
public:
	// Params: an Int to be searched for
	// Returns the non-negative number of entries that were itterated through if 
	// the requested entry is in the list. Returns a negative number if the entry
	// is not in the list
	// Does NOT alter the data structure.
	int check(int f) const;

	// Params: an Int to be searched for
	// Returns the non-negative number of entries that were itterated through if 
	// the requested entry is in the list. Returns a negative number if the entry
	// is not in the list
	// Bring the found element to the front of the list
	int find(int f); 

	// Creates and fills this SelfAdjustingList with "number" new nodes with
	// non-repeating random numbers from "lower" to "upper".
	void uniqueRandomFill(int number, int lower, int upper);
	// we either need to return a forward_list, or pass it a list
	//		as a parameter
	// forward_list uniqueRandomFill(int number, int lower, int upper);
};