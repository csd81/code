// Program 10_10
//Using a stringstream for output
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	stringstream address;
	address << "John Keyser" << endl;
	address << "123 Any Street" << endl;
	address << "Somewhere, TX " << 77777 << endl;
	string s;
	s = address.str();
	cout << s << endl;                                                 
}