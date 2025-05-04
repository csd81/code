// Program 12_8
// A more complete function: counting words in a string,           
//alternative handling multiple spaces
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int word_count(string str_to_count) {
	// Count number of spaces
	int count = 0;
	int i;
	for (i = 0; i < str_to_count.size(); i++) {
		// Only count if not a consecutive space
		if (str_to_count[i] == ' ' && str_to_count[i - 1] != ' ') {
			count++;
		}
	}
	// Number of words is one more than number of spaces
	return count + 1;
}

int main() {
	string s = "This is a string that has   eight words.";
	cout << "There are " << word_count(s) << " words in the string." << endl; 
}