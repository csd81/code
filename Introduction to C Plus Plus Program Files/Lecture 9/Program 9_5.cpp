// Program 9_5
// Using getline
#include <iostream>
#include <string>
using namespace std;

int main() {
	string username;
	cout << "What is your name? ";
	getline(cin, username);
	cout << "Howdy, " << username << "!" << endl;    
}

// getline(cin, username);
// getline(cin, username) reads an entire line of input from the user, including spaces, until a newline character is encountered.
// This allows the program to capture names or phrases that may contain spaces, such as "John Doe" or "Alice in Wonderland".
// the getline() function has 2 parameters:	
// 1. cin: This is the input stream from which the function reads the data. In this case, it reads from the standard input (keyboard).
// 2. username: This is the string variable where the input will be stored. 
//		The function will fill this variable with the line of text entered by the user.