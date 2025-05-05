// Program 12_3
// Demonstrating passing a parameter in
#include<iostream>
using namespace std;

void repeat_howdy(int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << "Howdy" << endl;
	}
}

int main() {
	repeat_howdy(10);                    
}