// Program 3_16
// Formatting multiple if-else statements to improve understanding
// This program illustrates how to format multiple if-else statements to improve understanding.
// The program calculates the cost of a ticket based on the age of the person.
// The cost is based on the following criteria:
// 	- If the age is less than 3, the cost is $0.00
// 	- If the age is between 3 and 5, the cost is $1.00
// 	- If the age is between 6 and 10, the cost is $3.00
// 	- If the age is between 11 and 17, the cost is $5.00
// 	- If the age is greater than 17, the cost is $6.00
// indentation is used to improve readability and understanding of the code.

#include <iostream>
using namespace std;

int main() {
	int age = 10;
	float cost;
	if (age < 3) {
		cost = 0.0;
	}                                                                 
	else if (age <= 5) {
		cost = 1.0;
	}
	else if (age <= 10) {
		cost = 3.0;
	}
	else if (age <= 17) {
		cost = 5.0;
	}
	else {
		cost = 6.0;
	}
	cout << "Your cost is " << cost << endl;

}