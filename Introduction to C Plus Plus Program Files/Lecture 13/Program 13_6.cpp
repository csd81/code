// Program 13_6
// Multiple default parameters
#include <iostream>
using namespace std;

void print_pair(int a = 1, int b = 2) {
	cout << a << " and " << b << endl;
}


int main() {
	print_pair();
	print_pair(10);             
	print_pair(10, 20);
	
}
// print_pair(10) will use the default value for b, which is 2
// print_pair() will use the default values for both a and b, which are 1 and 2 respectively
// print_pair(10, 20) will use the values 10 and 20 for a and b respectively