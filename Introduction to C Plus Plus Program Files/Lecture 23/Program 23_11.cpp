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
// this program demonstrates the use of the sort algorithm in C++.
// The program creates a vector of integers and initializes it with some values.
// It prints the vector before sorting.
// It then uses the sort algorithm to sort the vector in ascending order.
// Finally, it prints the vector after sorting.
// The program uses the standard library's sort function, which is a part of the <algorithm> header.
// The sort function takes two iterators as arguments, representing the beginning and end of the range to be sorted.
// The program uses a range-based for loop to iterate through the vector and print its elements.
