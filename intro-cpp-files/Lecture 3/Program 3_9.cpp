// Program 3_9
// Illustrating comparisons to create Boolean value
#include <iostream>
using namespace std;

int main() {
	int age;
	std::cout << "Enter your age: ";
	std::cin >> age;

	bool eligible_for_discount; // eligible_for_discount is a Boolean variable; we declare it but do not initialize it

	eligible_for_discount = ((age < 18) || (age >= 65));                      
		// if age is less than 18 
		// or greater than or equal to 65, 
		// then eligible_for_discount is true; otherwise, it is false
	cout << (eligible_for_discount ? "you are eligible" : "you are not eligible") << endl;
}