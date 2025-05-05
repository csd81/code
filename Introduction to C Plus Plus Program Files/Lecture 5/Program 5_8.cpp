// Program 5_8
// While for average age: sentinel value
// sentinel value is a special value that is used to indicate the end of input or the end of a data set.
// In this program, we will use a sentinel value of -1 to indicate that there are no more people to enter.
// The program will prompt the user to enter the age of each person, and it will continue to accept input until the sentinel value is entered.
// The program will then compute the average age of all the people entered.
#include <iostream>
using namespace std;

int main() {
	int sum_of_ages = 0; // initialize sum_of_ages to 0
	int num_people = 0; // initialize num_people to 0
	int age_of_person; // declare age_of_person but do not initialize it
	cout << "Enter the age of the first person: "; // prompt the user to enter the age of the first person
	cin >> age_of_person; // read the age of the first person
	while (age_of_person >= 0) { // if we enter a negative number, we stop
		sum_of_ages += age_of_person;
		num_people++;
		cout << "Enter the age of the next person, or enter -1 if there are no more people: ";
		cin >> age_of_person;
	}
	cout << "The average age is: " << (float)sum_of_ages / (float)num_people << endl;                 // compute the average age
	cout << "The average age is: " << (float)sum_of_ages / num_people << endl;                 // one cast is enough
	// the float type cast is necessary to get a float result
	// if we do not type cast, the result will be an integer
	// because both sum_of_ages and num_people are integers

	cout << "The average age is: " << sum_of_ages / num_people << endl;                 // compute the average age

}