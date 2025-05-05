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
	for (vector<int>::iterator my_iterator = v.begin(); my_iterator != v.end(); 
		my_iterator++) {
		cout << "This iterator refers to: " << *my_iterator << endl;              
	}                             
}