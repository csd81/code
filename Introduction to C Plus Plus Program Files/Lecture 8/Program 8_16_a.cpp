// Program 8_16_a
// ERROR - Attempting to assign arrays is not allowed
#include <iostream>
using namespace std;

int main() {
	int a[3] = { 1, 2, 3 };
	int b[3];
	b = a;                                        
}