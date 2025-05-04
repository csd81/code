// Program 3_9
// Illustrating comparisons to create Boolean value
#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter your age: ";
	cin >> age;
	bool eligible_for_discount;
	eligible_for_discount = ((age < 18) || (age >= 65));                      
	cout << eligible_for_discount << endl;
}