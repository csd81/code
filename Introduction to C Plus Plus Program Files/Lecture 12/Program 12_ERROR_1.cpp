// Program 12_ERROR_1
// Scope Error: b is only defined inside the while loop
#include<iostream>

using namespace std;

int main() {
	
	int a = 3;
	int b = 10;

	while (a > 0) {
		 // b is defined inside the while loop, so it is not accessible outside the loop
		 b -= a;
		 a--;
	}

	cout << b << endl; // This will cause a compilation error because b is not defined in this scope
}