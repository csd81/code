// Program 10_11
//Using concatenation to build a string
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	s = "John Keyser\n";
	s += "123 Any Street\n";
	s += "Somewhere, TX ";
	s += to_string(77777);
	s += '\n';
	cout << s << endl;             
}