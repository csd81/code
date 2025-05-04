// Program 8_7
// Printing all vector contents using size
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<float> v;
	v.push_back(10);
	v.push_back(20.0);
	v.push_back(0.05);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl; 
}