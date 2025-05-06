// Program 22_7
// Insertion example on a vector
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v = { 10, 20, 30 };
	vector<int>::iterator iter;
	iter = v.begin();  //Iterator is at first element
	iter++;  // Now at second element
	v.insert(iter, 40);  // Insert 40 before the second element
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}            
}

// This code is a simple example of how to use the insert function on a vector in C++.
