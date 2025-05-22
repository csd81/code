// Program 22_4
// Iterator example
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	vector<int>::iterator my_iterator;
	my_iterator = v.begin();
	while (my_iterator != v.end()) {
		cout << "This iterator refers to: " << *my_iterator << endl;
		my_iterator++;
	}              
}

// This code is a simple iterator example that demonstrates how to use iterators with the vector data structure in C++.
// It includes the necessary header files, creates a vector of integers, adds some values to the vector,
// and then uses an iterator to traverse the vector and print the values. The program uses the standard namespace to avoid
// prefixing standard library functions and types with "std::". The vector is a dynamic array that can grow and shrink in size.
// The program uses a vector iterator to traverse the vector, which allows for easy access to the elements of the vector.
// The program uses a while loop to check if the iterator has reached the end of the vector and prints the value pointed to by the iterator.
// The program increments the iterator to move to the next element in the vector. The program ends when the iterator reaches the end of the vector,
// demonstrating the basic operations of an iterator in C++. The program is a simple example of how to use iterators with vectors in C++.