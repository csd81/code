// Program 13_7
// Reference example
#include <iostream>
using namespace std;

int main() {
	int a = 1;
	int& b = a;
	cout << a << " " << b << endl;
	a = 2;
	cout << a << " " << b << endl;
	b = 3;
	cout << a << " " << b << endl;                    
}