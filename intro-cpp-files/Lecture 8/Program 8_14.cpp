// Program 8_14
// Vector out of bounds but accessed with "at"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 11, 22, 33 };
	for (int i = 0; i < 3; i++) {
		cout << v.at(i) << " ";
	}

	// for (int i : v) {
	// 	cout << v.at(i-1) << " ";
	// }
	cout << endl;
	cout << "Made it here!" << endl;                  
}

// here we use the constructor to initialize a vector with three elements
// the first element is 1, the second element is 2, and the third element is 3
// when we try to access the fourth element of the vector, we *should* get an error
// the error is called "index out of bounds"
// this means that we are trying to access an element that does not exist
// and we get an error
// because we are using the at() function
// the at() function checks for out of bounds errors

// the at() function is a member function of the vector class
// the at() function checks for out of bounds errors.

// the syntax for the at() function is:
// vector.at(index);
// the at() function takes one argument, which is the index of the element we want to access
// the at() function returns a reference to the element at the given index
// if the index is out of bounds, the at() function throws an out_of_range exception

// we can easily debug this program by using the at() function
// the at() function checks for out of bounds errors
// the at() function is a member function of the vector class