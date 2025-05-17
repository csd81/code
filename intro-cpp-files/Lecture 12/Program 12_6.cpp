// Program 12_6
// A more complete function: counting words in a string
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int word_count(string str_to_count) {
	//Turn the string into a stringstream
	stringstream ss(str_to_count);
	int count = 0;
	string word;
	// count the number of individual words by reading from the stringstream
	while (!ss.eof()) { // check if the end of the string stream has been reached
		ss >> word; // read a word from the string stream, until the first whitespace character (space, tab, newline)
		count++; // increment the word count
	}
	return count; // return the word count
}

int main() {
	string s = "This is a string that has eight words."; //  NINE";
	cout << "There are " << word_count(s) << " words in the string." << endl;               // 8 
}

// The program defines a function called word_count() that takes a string as input and counts the number of words in the string.
// The function uses a stringstream object to read the string word by word and counts the number of words.
// The main() function calls the word_count() function with a sample string and outputs the result to the console.