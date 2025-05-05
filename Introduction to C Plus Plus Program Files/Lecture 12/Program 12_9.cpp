// Program 12_9
// Function to find largest value in vector
#include<iostream>
#include<vector>
using namespace std;

int find_largest(vector<int> v) {
	int largest = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > largest) largest = v[i]; // compare each element with the largest
		// if the current element is larger, update largest
		// if the current element is not larger, do nothing
	}
	return largest;
}

int main() {
	vector<int> test_data = { 12, 35, 21, 10, 18, 99 };
	int large_one = find_largest(test_data);
	cout << large_one << endl;         
}