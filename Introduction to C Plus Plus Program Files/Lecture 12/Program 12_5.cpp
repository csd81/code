// Program 12_5
// Demonstrating early return
#include<iostream>
using namespace std;

void demo_func() {
	cout << "Line 1" << endl;
	return;
	cout << "Line 2" << endl;
	return;
}

int main() {
	demo_func();                   
}