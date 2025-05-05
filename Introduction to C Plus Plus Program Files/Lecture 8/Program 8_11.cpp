// Program 8_11
// Vector resizing
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(2,10); // initialize a vector of size 2, all elements are 10
	v.resize(5); // resize the vector to size 5, all new elements are 0
	cout << "Resized vector  : ";
	cout << endl;    
	
	for (int i = 0; i < v.size(); i++) { // loop through the vector using a for loop
		cout << v[i] << " "; // print each element of the vector by index
	}
	cout << endl;               
	cout << endl;               
	for (auto i : v) {
		cout << i << " "; // here i is a reference to each element of the vector, but it is not an index
		// this is a range-based for loop, which is a new feature in C++11
	}	 // does the same thing as the for loop above, but uses a range-based for loop

	cout << endl;               
}

// here we use the resize function to change the size of the vector
// the resize function takes one argument, which is the new size of the vector
// if the new size is larger than the current size, the new elements are initialized to 0

//the resize function can also take a second argument, which is the initial value of the new elements
//the resize function is a member function of the vector class