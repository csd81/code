// Program 8_8
// Vector size initialization
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(3);
	cout << "Initial vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;             
}