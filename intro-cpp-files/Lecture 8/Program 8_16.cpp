// Program 8_16
// Assigning vectors
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = { 1, 2, 3 };
	vector<int> b;
	
	b = a; 
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	cout << endl;                  

	// or 
	for (int i : b) {
		cout << i << " ";
	}
}

// we can only assign vectors to vectors if they are of the same type.
// if we try to assign a vector of integers to a vector of strings, we will get an error
// but we can assign a vector of integers to a vector of integers

// we can cast a vector of integers to a vector of strings as follows:
// vector<string> v = { "1", "2", "3" };
// vector<int> a = { 1, 2, 3 };
// vector<int> b = { 4, 5, 6 };
// vector<string> c = { "4", "5", "6" };


// overloaded assignment operator means that the vector class has a special member function
// that is called when we use the assignment operator =
// the overloaded assignment operator copies the elements of the vector a to the vector b
// the overloaded assignment operator is a member function of the vector class

// we can overload the assignment operator for our own classes the following way:
// class MyClass {
// public:
// 	MyClass& operator=(const MyClass& other) {
// 		// copy the elements of the other object to this object
// 		return *this; // return a reference to this object
// 	}

// return *this; means that we return a reference to the current object
// this allows us to chain assignment operators
// for example:
// MyClass a, b, c;
// a = b = c; // this is allowed because the overloaded assignment operator returns a reference to the current object
// this allows us to chain assignment operators
// the overloaded assignment operator is a member function of the class