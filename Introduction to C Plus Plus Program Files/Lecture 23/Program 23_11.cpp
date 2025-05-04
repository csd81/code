// Program 23_11
// Sorting example
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v = { 4, 5, 9, 1, 15, 12, 3, 5, 7, 11, 14, 2, 9 };
	cout << "Before sorting: ";
	for (auto& iter : v) {
		cout << iter << " ";
	}
	cout << endl;
	sort(v.begin(), v.end());
	cout << "After sorting: ";
	for (auto& iter : v) {
		cout << iter << " ";
	}
	cout << endl;            
}