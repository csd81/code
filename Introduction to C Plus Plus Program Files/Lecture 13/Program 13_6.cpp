// Program 13_6
// Multiple default parameters
#include <iostream>
using namespace std;

void print_pair(int a = 1, int b = 2) {
	cout << a << " " << b << endl;
}


int main() {
	print_pair(10, 20);
	print_pair();
	print_pair(10);             
}