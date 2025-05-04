// Program 8_5
// Reading in values and adding on to a vector indefinitely
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> ages;
	int age;
	cout << "Enter someone's age.  Enter a negative age to stop: ";
	cin >> age;
	while (age >= 0) {
		ages.push_back(age);
		cout << "Enter another age.  Enter a negative age to stop: ";
		cin >> age;
	}               
}