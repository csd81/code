// Program 3_6 error versions
// Boolean order of operations
//Error version with missing parentheses                    
#include <iostream>
using namespace std;

int main() {
	cout << !true or !false and true << endl;
	cout << (!true) or ((!false) and true) << endl;                        
}