// Program 12_ERROR_1
// Scope Error: b is only defined inside the while loop
#include<iostream>
using namespace std;

int main() {
	int a = 3;
	while (a > 0) {
		int b = 10;
		a -= b;
	}
	cout << b << endl;
}