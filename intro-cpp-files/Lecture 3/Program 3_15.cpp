// Program 3_15
// Illustrating mulitple if-else statements                        
// we can nest if statements to create multiple if-else statements.
// this can complicate the code and make it difficult to read.
// instead, we can use the switch statement to create multiple if-else statements.

#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter your age: ";
	cin >> age; // input the age of the person
	float cost;
	if (age < 3) {
		cost = 0.0;
	}
	else {
		if (age <= 5) {
			cost = 1.0;
		}
		else {
			if (age <= 10) {
				cost = 3.0;
			}
			else {
				if (age <= 17) {
					cost = 5.0;
				}
				else {
					cost = 6.0;
				}
			}
		}
	}
	cout << "Your cost is " << cost << endl;                  
}