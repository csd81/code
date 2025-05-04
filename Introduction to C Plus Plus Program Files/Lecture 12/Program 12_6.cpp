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
	while (!ss.eof()) {
		ss >> word;
		count++;
	}
	return count;
}

int main() {
	string s = "This is a string that has eight words.";
	cout << "There are " << word_count(s) << " words in the string." << endl;              
}