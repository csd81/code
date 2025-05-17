// Program 5_11
// Do-while for computing average age: sentinel value


// The program uses a do-while loop to compute the average age.
// The do-while loop is a control flow statement that executes a block of code at least once and then repeats the loop as long as a specified condition is true.
// The do-while loop is similar to the while loop, but the main difference is that the do-while loop guarantees that the block of code will be executed at least once, 
// even if the condition is false.
// The do-while loop is useful when you want to ensure that a block of code is executed at least once, regardless of the condition.
// The condition is checked after the block of code is executed, so the block of code will always be executed at least once.

// The syntax of the do-while loop is as follows:
// do {
//     // block of code to be executed
// } while (condition);

#include <iostream>
using namespace std;

int main() {
	int sum_of_ages = 0;
	int num_people = 0;
	int age_of_person;                                         
	cout << "Enter the age of the first person: ";
	cin >> age_of_person;
	do {
		sum_of_ages += age_of_person;
		num_people++;
		cout << "Enter the age of the next person, or enter -1 if there are no more people: ";
		cin >> age_of_person;
	} while (age_of_person >= 0);
	cout << "The average age is: " << (float)sum_of_ages / (float)num_people << endl;
}