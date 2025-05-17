// Program 3_6 error versions
// Boolean order of operations
//Error version with missing parentheses   
// we can easily debug this program by adding parentheses to the expression                 
#include <iostream>
using namespace std;


int main() {
	cout << "!true or !false and true" << endl;
	cout << ((!true || !false) && true) << endl;                        
}