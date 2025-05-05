// Program 14_2
// Example program to debug - fixed!
#include <iostream>
#include <string>
using namespace std;

string remove_spaces(string s) {
	string ret = "";
	int i;
	for (i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			ret += s[i];
		}
	}
	return ret;
}

bool is_palindrome(string s) {
	string no_spaces = remove_spaces(s);
	bool could_be_palindrome = true;
	for (int i = 0; i < no_spaces.size() / 2; i++) {
		if (no_spaces[i] != no_spaces[no_spaces.size() - 1 - i]) { // Fix the index
			could_be_palindrome = false;
		}
	}
	return could_be_palindrome;
}

int main()
{
	cout << "This will tell you whether certain text is a palindrome.  Enter some text:" 
		<< endl;
	string user_input;
	getline(cin, user_input);
	if (is_palindrome(user_input)) {
		cout << "It is a palindrome!" << endl;
	}
	else {
		cout << "It's not a palindrome." << endl;
	}                         
}