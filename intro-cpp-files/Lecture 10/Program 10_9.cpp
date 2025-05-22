// Program 10_9
// Using a stringstream for input, initializing with a string
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	stringstream wordreader("Apple Banana Cherry");
	string first_word, s;
	wordreader >> first_word;
	wordreader >> s;
	cout << "The first string read was: " << first_word << endl;                      
	cout << "The 2 string read was: " << s << endl;                      
}

// we can initialize a stringstream object with a string by passing the string as an argument to the constructor.
// This allows us to create a stringstream object that contains the contents of the string, which can then be used for input and output operations.
// The stringstream class provides a convenient way to manipulate strings as if they were input/output streams.