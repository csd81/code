// Program 8_6
// Vector size
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	cout << "Initial size is: " << v.size() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << "Later size is: " << v.size() << endl;             
}

// size() is a member function of the vector class
// the vector class is a part of the standard template library
// the vector class is a dynamic array
// the vector class is a sequence container
// the vector class is a class template 
// templates are a way to create generic classes
// templates are a way to create generic functions
// templates are a way to create generic algorithms
// templates are a way to create generic data structures
// generic means that it can work with any type of data
// types of data include:	
// 1. int
// 2. float
// 3. double
// 4. char
// 5. string
// 6. bool

// we can make a vector of bool	this way:
// vector<bool> v;
// this vector will store boolean values

