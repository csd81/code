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