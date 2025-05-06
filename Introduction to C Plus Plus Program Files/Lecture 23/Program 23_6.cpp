// Program 23_6
// Map example - animal shelter
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string, int> numanimals;
	numanimals["cat"] = 12;
	numanimals["dog"] = 23;
	numanimals["rabbit"] = 2;

	string whichanimal;
	cout << "Which animal do you want a count of? ";
	cin >> whichanimal;
	if (numanimals.count(whichanimal) > 0) {
		cout << "There are " << numanimals[whichanimal] << " " <<  whichanimal << "s in the shelter." << endl;      
	}
	else {
		cout << "That animal is not in the shelter." << endl;
	}         
}
// this program demonstrates the use of the map class in C++.
// The program creates a map object that holds string keys and integer values.
// It assigns values to the elements of the map using the [] operator.
// It prompts the user for an animal type and checks if that animal is in the map.
// If the animal is found, it prints out the count of that animal in the shelter.
// If the animal is not found, it prints out a message indicating that the animal is not in the shelter.

