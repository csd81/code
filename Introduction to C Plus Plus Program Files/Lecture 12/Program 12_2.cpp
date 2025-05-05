// Program 12_2
// Demonstrating variable in a function
#include<iostream>
using namespace std;

void howdy10() {
	int i;
	for (i = 0; i < 10; i++) {
		cout << "Howdy" << endl;
	}
}

int main() {
	howdy10();                 
}