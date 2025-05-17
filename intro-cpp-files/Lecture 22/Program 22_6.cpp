// Program 22_6
// Using "auto" to define variable type, in this case an iterator
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	for (auto my_iterator = v.begin(); my_iterator != v.end(); my_iterator++) {
		cout << "This iterator refers to: " << *my_iterator << endl;
	}
}

// auto is a C++11 feature that allows the compiler to automatically deduce the type of a variable based on its initializer.
// In this case, the type of my_iterator is deduced to be vector<int>::iterator, which is the type of the iterator for the vector<int>.
// This makes the code cleaner and easier to read, as you don't have to explicitly specify the type of the iterator.