// Program 8_16
// Assigning vectors
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a = { 1, 2, 3 };
	vector<int> b;
	b = a;
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	cout << endl;                  
}