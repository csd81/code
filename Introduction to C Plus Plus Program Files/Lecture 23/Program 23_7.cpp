// Program 23_7
// Map example - dictionary
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string, string> dictionary;
	dictionary["rock"] = "An object that breaks scissors";
	dictionary["paper"] = "An object that covers rocks";
	dictionary["scissors"] = "An object that cuts paper";

	for (auto& iter : dictionary) {
		cout << iter.first << ": " << iter.second << endl;
	}       
}

// this program demonstrates the use of the map class in C++.
// The program creates a map object that holds string keys and string values.
// It assigns values to the elements of the map using the [] operator.
// It then iterates through the map and prints out each key-value pair.
// The program uses a range-based for loop to iterate through the map.