// Program 3_2
// Any non-zero value is interpreted as true
#include <iostream>
using namespace std;

int main() {
	bool test_true = true;
	bool test_false = false;
	test_true = 2; // parse 2 as true
	cout << "test_true is: " << test_true << endl;
	cout << "test_false is: " << test_false << endl;                          
	test_false = 3; // parse 0 as false
	cout << "now test_false is 3: " << (test_false ? "TRUE" : "FALSE") << endl;                          
		// boolean values are used to represent true and false; the value are represented by 1 and 0 respectively. If the value is 0, it is false; otherwise, it is true.
	
}