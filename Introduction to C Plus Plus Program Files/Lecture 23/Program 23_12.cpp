// Program 23_12
// Lower_bound example - using binary search 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> ages = { 23, 21, 18, 22, 21, 19, 20, 19, 27, 22 };
	vector<int>::iterator findval;
	int agetofind;

	cout << "What age do you want to find? ";
	cin >> agetofind;
	sort(ages.begin(), ages.end());
	findval = lower_bound(ages.begin(), ages.end(), agetofind);
	if (findval != ages.end()) {
		cout << "Found : " << *findval << endl;
	}
	else {
		cout << agetofind << " not found" << endl;
	}             
}
// this program demonstrates the use of the lower_bound algorithm in C++.
// The program creates a vector of integers representing ages.
// It prompts the user for an age to find and uses the lower_bound algorithm to search for that age in the vector.
// The lower_bound algorithm performs a binary search on the sorted vector to find the first element that is not less than the specified value.
// If the age is found, it prints out the found age.
// If the age is not found, it prints out a message indicating that the age was not found.