// Program 12_7
// A more complete function: counting words in a string, alternative
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int word_count(string str_to_count) {
	// Count number of spaces
	int count = 0;
	int i;
	for (i = 0; i < str_to_count.size(); i++) {
		if (str_to_count[i] == ' ') {
			count++;
		}
	}
	// Number of words is one more than number of spaces
	return count + 1;
}

int main() {
	string s = "This is a string that has eight words.";
	cout << "There are " << word_count(s) << " words in the string." << endl;     
}