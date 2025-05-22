// Program 7_6
// Array Initialization - subset of array
#include <iostream>
using namespace std;

int main() {
	int team_members[5] = { 5, 6 };
	for (int i = 0; i < 5; i++) {
		cout << team_members[i] << endl;
	}                                 
}

// to initialize an array with a subset of values, we can use the following syntax
// int team_members[5] = { 5, 6 };
// this initializes the first two elements of the array with the values 5 and 6
// the remaining elements of the array are initialized to 0
// this is equivalent to
// int team_members[5] = { 5, 6, 0, 0, 0 };
// the array is initialized with the values in the list
// the size of the array is determined by the number of values in the list
// the remaining elements of the array are initialized to 0