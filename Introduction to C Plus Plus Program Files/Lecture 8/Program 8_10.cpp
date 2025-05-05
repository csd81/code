// Program 8_10
// Vector initialization for all elements
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(3, 10);
	cout << "Initial vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;                     
}