// Program 8_13
// Vector ERROR indexing out of bounds
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3 };
	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
	cout << endl;                          
}

// here we use the constructor to initialize a vector with three elements
// the first element is 1, the second element is 2, and the third element is 3

// when we try to access the fourth element of the vector, we *should* get an error
// the error is called "index out of bounds"
// this means that we are trying to access an element that does not exist
// but we do not get an error !!!

// this is because the vector class does not check for out of bounds errors
// this is a design decision made by the C++ language
// the vector class does not check for out of bounds errors
// this is because the vector class is designed to be fast and efficient
// if the vector class checked for out of bounds errors, it would be slower
// this is a trade-off between speed and safety