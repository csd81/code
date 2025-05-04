// Program 8_12
// Vector resizing and initializing
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(3);
	v.resize(5, 1);
	cout << "Resized vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;                
}