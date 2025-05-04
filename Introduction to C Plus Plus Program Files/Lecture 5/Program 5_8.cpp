// Program 5_8
// While for average age: sentinel value
#include <iostream>
using namespace std;

int main() {
	int sum_of_ages = 0;
	int num_people = 0;
	int age_of_person;
	cout << "Enter the age of the first person: ";
	cin >> age_of_person;
	while (age_of_person >= 0) {
		sum_of_ages += age_of_person;
		num_people++;
		cout << "Enter the age of the next person, or enter -1 if there are no more people: ";
		cin >> age_of_person;
	}
	cout << "The average age is: " << (float)sum_of_ages / (float)num_people << endl;                
}