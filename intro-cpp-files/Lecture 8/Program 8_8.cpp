// Program 8_8
// Vector size initialization
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(3); // initialize a vector of size 3, all elements are 0
		cout << "Initial vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;             
	v[0] = 100; // first element
	v[1] = 101; // first element
	v[2] = 102; // first element
	v.push_back	(111);
	v.push_back	(112);
	v.push_back	(114);
	cout << "Final vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;             
}