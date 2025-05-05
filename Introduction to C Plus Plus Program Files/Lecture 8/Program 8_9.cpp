// Program 8_9
// Vector initialization
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3 };
	cout << "Initial vector  : ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;   
}