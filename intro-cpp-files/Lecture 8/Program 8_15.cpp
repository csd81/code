// Program 8_15
// Assigning elements with brackets and "at"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3, 4, 5 };
	v[1] = 100;  // 1, 100, 3, 4, 5
	v.at(3) = 500; // 1, 100, 3, 500, 5
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	cout << "Made it here!" << endl;                                
}

// size() is a member function of the vector class
// at() is a member function of the vector class
// they are both used to access elements of the vector
// the size() function returns the number of elements in the vector
// the at() function returns a reference to the element at the given index
// indexing with brackets [] is a shorthand for the at() function but it does not check for out of bounds errors