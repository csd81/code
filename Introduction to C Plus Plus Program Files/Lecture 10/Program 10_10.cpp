// Program 10_10
//Using a stringstream for output
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	stringstream address;
	address << "John Keyser "  	<< "123 Any Street "    << "Somewhere, TX " << 77777 << endl;
	string s;
	s = address.str();
	cout << s << endl;                                                 
}

// the stringstream::str() function is used to get the contents of the string stream as a string.
// The str() function returns a string object that contains the contents of the string stream.
// The str() function can also be used to set the contents of the string stream to a new string.