// Program 10_8
// Using a stringstream for input
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	stringstream wordreader;
	wordreader.str("Apple Banana Cherry");
	string first_word;
	wordreader >> first_word;
	cout << "The first string read was: " << first_word << endl;          
}