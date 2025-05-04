// Program 8_15
// Assigning elements with brackets and "at"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3, 4, 5 };
	v[1] = 100;
	v.at(3) = 500;
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	cout << "Made it here!" << endl;                                
}