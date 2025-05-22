// Program 7_4
// Reporting temperatures greater than the average
#include <iostream>
using namespace std;

int main() {
	// Read in temperature data, keeping sum
	int temps[1000]; // Array to hold temperatures
	// Note: 1000 is an arbitrary size, but it should be large enough for most cases
	int counttemps = 0; // Number of temperatures entered
	int currenttemp = 0; // Current temperature
	int total = 0; // Total of all temperatures entered
	cout << "Enter a temperature: ";
	cin >> currenttemp;
	while (currenttemp < 200) { // 200 is the sentinel value, if entered or greater, stop
		temps[counttemps] = currenttemp; // Store the temperature in the array
		total += currenttemp; // Add to the total
		counttemps++; // Increment the count of temperatures
		cout << "Enter a temperature.  Enter 200 or greater when done: "; // Prompt for next temperature
		cin >> currenttemp; // Read in the next temperature
	}

	// Determine and print out average
	float  average; // declare average variable as a float
	average = (float)total / (float)counttemps; // Calculate average
	cout << "The average temperature was " << average << endl;

	// Print out elements greater than the average
	for (int i = 0; i < counttemps; i++) { // Loop through the array
		if (temps[i] > average) { // Check if the temperature is greater than the average
			// Print the temperature if it is greater than the average
			cout << temps[i] << " was above the average temperature." << endl;
		}
	}                
}