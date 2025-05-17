// Program 14_1
// Example program to debug - contains an error!
#include <iostream>
#include <string>
using namespace std;

string remove_spaces(string s) {
	string ret = ""; // Initialize ret to an empty string
	int i;
	for (i = 0; i < s.size(); i++) { // Loop through each character in the string
		// Check if the character is not a space
		if (s[i] != ' ') {
			ret += s[i]; // Append the character to ret
		}
	}
	return ret;
}

bool is_palindrome(string s) { 
	string no_spaces = remove_spaces(s);     // Remove spaces from the input string                      
	bool could_be_palindrome = true;  // Assume it could be a palindrome
	for (int i = 0; i < no_spaces.size() / 2; i++) { // Loop through the first half of the string
		if (no_spaces[i] != 
			no_spaces[no_spaces.size() - i - 1]) {   // Check if the characters at the two ends are equal
			could_be_palindrome = false; // If not, it's not a palindrome
		}
	}              
	return could_be_palindrome; 
}

int main()
{
	cout << "This will tell you whether certain text is a palindrome.  Enter some text:" 
		<< endl;
	string user_input; 	// Declare a string variable to store user input
	getline(cin, user_input); // Read the entire line of input
	if (is_palindrome(user_input)) { // Check if the input string is a palindrome
		cout << "It is a palindrome!" << endl;
	}
	else {
		cout << "It's not a palindrome." << endl;
	}   
}