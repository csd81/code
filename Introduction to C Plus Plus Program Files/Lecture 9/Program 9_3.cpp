// Program 9_3
// A greeting program handling first and last names
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string firstname, lastname;
	cout << "What's your name? (Enter first name and last name) ";
	cin >> firstname >> lastname;
	cout << "Howdy, " << firstname << " " << lastname << "!" << endl;                  
}