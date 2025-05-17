// Program 7_4_b
// Reporting temperatures greater than the average
#include <iostream>
using namespace std;

int main() {
	// Read in temperature data, keeping sum               
	// Note: 1000 is an arbitrary size, but it should be large enough for most cases
	// Array to hold temperatures

	int temps[1000];
	int counttemps = 0; 	// Number of temperatures entered
	// Current temperature
	int currenttemp = 0;
	// Total of all temperatures entered
	int total = 0;
	// Prompt for the first temperature
	cout << "Enter a temperature: ";
	// Read in the first temperature
	cin >> currenttemp;
	// Loop until the user enters a sentinel value (200 or greater)
	while (currenttemp < 200) {
		temps[counttemps] = currenttemp;
		total += currenttemp;
		counttemps++;
		cout << "Enter a temperature.  Enter 200 or greater when done: ";
		cin >> currenttemp;
	}

	// Determine and print out average
	double average; // declare average variable as a double
	average = (double)total / (double)counttemps; // Calculate average
	cout << "avg: " << average << endl; // Print the average temperature

	// Print out elements greater than the average                
	for (int i=0; i < counttemps; i++) {
		if (temps[i] > average) { // if the i-th element of the array is greater than the average, print it
			cout << temps[i] << " was above the average temperature." << endl;
		}
	}
}