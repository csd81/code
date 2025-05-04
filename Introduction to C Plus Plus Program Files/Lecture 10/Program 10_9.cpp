// Program 10_9
// Using a stringstream for input, initializing with a string
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	stringstream wordreader("Apple Banana Cherry");
	string first_word;
	wordreader >> first_word;
	cout << "The first string read was: " << first_word << endl;                      
}