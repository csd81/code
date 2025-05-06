// Program 23_8
// Find example
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> ages = { 23, 21, 18, 22, 21, 19, 20, 19, 27, 22 };
	vector<int>::iterator findval;
	int agetofind;

	cout << "I have a list of ages of participants." << endl;
	while (true) {
		cout << "What age do you want to find? ";
		cin >> agetofind;
		findval = find(ages.begin(), ages.end(), agetofind);
		if (findval != ages.end()) {
			cout << "Found : " << *findval << endl;
		}
		else {
			cout << agetofind << " not found" << endl;
		}
	}           
}
// this program demonstrates the use of the find algorithm in C++.
// The program creates a vector of integers representing ages.
// It prompts the user for an age to find and uses the find algorithm to search for that age in the vector.
// If the age is found, it prints out the found age.
// If the age is not found, it prints out a message indicating that the age was not found.
// The program continues to prompt the user for ages until the user terminates the program.