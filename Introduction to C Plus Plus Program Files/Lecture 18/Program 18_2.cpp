// Program 18_2
// Pointer example using [0]
#include <iostream>
using namespace std;

int main()
{
	int x = 3;
	int* y;
	y = &x;
	cout << y[0] << endl;
	y[0] = 5;
	cout << x << endl;                 
}