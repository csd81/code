// Program 3_16
// Formatting multiple if-else statements to improve understanding
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