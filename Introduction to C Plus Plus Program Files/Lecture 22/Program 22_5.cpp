// Program 22_5
// Iterator example - using a for loop
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	vector<int>::iterator my_iterator;
	for (my_iterator = v.begin();  		my_iterator != v.end();   		my_iterator++)  // for loop
		{
		cout << "This iterator refers to: " << *my_iterator << endl;              
	}                             
}

// This code is a simple iterator example that demonstrates how to use iterators with the vector data structure in C++.
// It includes the necessary header files, creates a vector of integers, adds some values to the vector,
// and then uses an iterator to traverse the vector and print the values. The program uses the standard namespace to avoid
// prefixing standard library functions and types with "std::". The vector is a dynamic array that can grow and shrink in size.
// The program uses a vector iterator to traverse the vector, which allows for easy access to the elements of the vector.