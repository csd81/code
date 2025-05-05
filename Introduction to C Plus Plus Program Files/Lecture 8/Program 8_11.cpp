// Program 8_11
// Vector resizing
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.resize(5);
	cout << "Resized vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;               
}