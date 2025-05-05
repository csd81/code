// Program 8_7
// Printing all vector contents using size
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<float> v; // initialize a float vector
	cout << "The size of the vector is: " << v.size() << endl; // print the size of the vector
	v.push_back(10); // first element
	cout << "The size of the vector is: " << v.size() << endl; // print the size of the vector
	v.push_back(20.0); // second element
	cout << "The size of the vector is: " << v.size() << endl; // print the size of the vector
	v.push_back(0.05); // third element
	cout << "The size of the vector is: " << v.size() << endl; // print the size of the vector
	v.push_back(0.5); // fourth element
	cout << "The size of the vector is: " << v.size() << endl; // print the size of the vector
	v.push_back(0.0005); // fifth element
	cout << "The size of the vector is: " << v.size() << endl; // print the size of the vector
	v.pop_back(); // remove the last element of the vector which is 0.0005, we are left with 4 elements
	cout << "The size of the vector is: " << v.size() << endl; // print the size of the vector
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] <<  endl; 
	}
	cout << endl; 
}