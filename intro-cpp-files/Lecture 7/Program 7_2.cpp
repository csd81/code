// Program 7_2
// Indexing with a variable
#include <iostream>
using namespace std;

int main() {
	int a[5];
	a[0] = 10; a[1] = 20; a[2] = 30; a[3] = 40; a[4] = 50;
	int i = 3;
	cout << a[i] << endl;                   // prints 40
	cout << a[i + 1] << endl;               // prints 50
	cout << a[i + 2] << endl;               // prints garbage value because a[5] is out of bounds
}

// a[5] is out of bounds because the last index of the array is 4
// the size of the array is 5
// the first index of the array is 0
// the last index of the array is (size - 1)