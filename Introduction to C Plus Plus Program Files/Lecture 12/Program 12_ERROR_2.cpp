// Program 12_ERROR_2 
// Scope Error: a is only defined inside main
#include<iostream>
using namespace std;

// void demo_func() {
// 	cout << a << endl;
// 	return;
// }

// int main() {
// 	int a = 3;
// 	demo_func();                                    
// }


void demo_func(int a) { // Pass a as a parameter to the function
	cout << a << endl;
	return;
}

int main() {
	int an = 3;
	demo_func(an);                                    
}