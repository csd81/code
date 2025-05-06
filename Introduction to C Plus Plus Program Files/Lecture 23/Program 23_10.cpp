// Program 23_10
// Find example - finding all instances
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
		findval = ages.begin();
		while (true) {
			findval = find(findval, ages.end(), agetofind);
			if (findval != ages.end()) {
				cout << "Found : " << *findval << endl;
				findval++;
			}
			else {
				cout << agetofind << " not found any more" << endl;
				break;
			}
		}
	}    
}

// this program demonstrates how to find all instances of an element in a vector.
// The program creates a vector of integers representing ages.
// It prompts the user for an age to find and uses a while loop to search for all instances of that age in the vector.
// If the age is found, it prints out the found age and continues searching for more instances.
// If the age is not found, it prints out a message indicating that the age was not found any more.
// The program continues to prompt the user for ages until the user terminates the program.