// Program 18_1
// Pointer example using *
#include <iostream>
using namespace std;

int main()
{
	int x = 3;
	int* y;
	y = &x;
	cout << *y << endl;
	*y = 5;
	cout << x << endl;                
}

// helloworld