// Program 9_3
// A greeting program handling first and last names
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string firstname, lastname;
	cout << "What's your name? (Enter first name and last name) ";
	cin >> firstname;
	cin >> lastname;
	cout << "Howdy, " << firstname << " " << lastname << "!" << endl;                  
}
// cin will a white space character to separate the first name and last name
// cin will read the first name and last name into two separate variables
// cin will stop reading when it encounters a white space character