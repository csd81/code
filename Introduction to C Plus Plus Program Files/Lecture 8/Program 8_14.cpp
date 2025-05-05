// Program 8_14
// Vector out of bounds but accessed with "at"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 1, 2, 3 };
	for (int i = 0; i < 5; i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	cout << "Made it here!" << endl;                  
}