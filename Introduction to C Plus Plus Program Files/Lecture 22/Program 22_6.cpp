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