// Program 8_5
// Reading in values and adding on to a vector indefinitely
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> ages; // initialize an int vector to store ages
	// ages is an instance of the vector class
	int age; // variable to store age
	cout << "Enter someone's age.  Enter a negative age to stop: "; // prompt user for input, sentinel value is negative age
	cin >> age;
	while (age >= 0) {
		ages.push_back(age); // add age to vector instance ages
		cout << "Enter another age.  Enter a negative age to stop: ";
		cin >> age;
	}               
	int total = 0; // variable to store total age
	for (int i : ages) { // iterate through vector ages
		total += i; // add each age to total
		cout << i << " "; // print each age
	}
	cout << "average age is: " << (double)total / ages.size() << endl; // print average age
}