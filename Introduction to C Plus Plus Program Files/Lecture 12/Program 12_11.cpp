// Program 12_11
//Use of a global variable
#include<iostream>
using namespace std;

int a;

void my_function() {
	a++;
}

int main() {
	a = 1;
	cout << "Before the function call, the value of a is: " << a << endl;
	my_function();
	cout << "After the function call, the value of a is: " << a << endl;                    
}