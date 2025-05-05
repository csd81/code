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