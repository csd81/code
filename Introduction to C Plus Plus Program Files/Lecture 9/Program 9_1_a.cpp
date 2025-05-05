// Program 9_1_a
// Inputting into a string
#include <iostream>
#include <string>
using namespace std;                        

int main()
{

	string my_string;
cout << "Enter your name: " << endl; //Prompt the user for input
	//Stream input into a string
	cin >> my_string;

	//Stream output into a string
	cout << "Hello " << my_string << endl;                              
}

// the iostream library is included
// the string library is included

// iostream is used for input and output, it has cout and cin

// we can stream string values into a string using cin and cout
// << is the stream insertion operator
// >> is the stream extraction operator