// Program 12_3
// Demonstrating passing a parameter in
#include<iostream>
using namespace std;

void repeat_howdy(int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << "Howdy" << " ";
	}
	cout << "\n";
}

int main() {
	repeat_howdy(10);                    
	repeat_howdy(19);                    
	repeat_howdy(9);
}

// repeat_howdy() is a function that takes an integer parameter n and prints "Howdy" n times.