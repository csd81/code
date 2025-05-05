// Program 3_6
// Boolean order of operations                  
#include <iostream>
using namespace std;

int main() {
	cout << "(!true || !false && true)" << endl;
	cout << ( (!true || !false && true) ? "True" : "False") << endl;
	cout << "((!true) || ((!false) && true))" << endl;                         
	cout << ( ((!true) || ((!false) && true)) ? "True" : "False") << endl;                         
}