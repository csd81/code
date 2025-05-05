// Program 12_12
// Use of local variables only
#include<iostream>
using namespace std;

void my_function(int& x) {
	x++;
}

int main() {
	int a = 1;
	cout << "Before the function call, the value of a is: " << a << endl;
	my_function(a);
	cout << "After the function call, the value of a is: " << a << endl;            
}