// Program 23_9
// Find example - without using "find" function
#include<iostream>
#include<vector>
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
		while ((findval != ages.end()) && (*findval != agetofind)) {
			findval++;
		}
		if (findval != ages.end()) {
			cout << "Found : " << *findval << endl;
		}
		else {
			cout << agetofind << " not found" << endl;
		}
	}       
}

// this program demonstrates how to find an element in a vector without using the "find" function.
// The program creates a vector of integers representing ages.
// It prompts the user for an age to find and uses a while loop to search for that age in the vector.
// If the age is found, it prints out the found age.
// If the age is not found, it prints out a message indicating that the age was not found.
// The program continues to prompt the user for ages until the user terminates the program.