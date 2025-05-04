// Program 8_13
// Vector ERROR indexing out of bounds
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3 };
	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
	cout << endl;                          
}