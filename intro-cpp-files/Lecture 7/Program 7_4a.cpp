// Program 7_4_a
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
	
	while (currenttemp < 200) {
		temps[counttemps] = currenttemp;
		total += currenttemp;
		counttemps++;
		cout << "Enter a temperature.  Enter 200 or greater when done: "; 
		cin >> currenttemp;

	 }
	 
	
	// Determine and print out average

	float avg = 0.0; // declare average variable as a float
	avg = (float)total / (float)counttemps;
	cout << "The average temperature was " << avg << endl;

	// Print out elements greater than the average                
	
	for (int i = 0; i < counttemps; i++) {
 		if (temps[i] > avg) {
 			cout << temps[i] << " was above the average temperature." << endl;
 		}
 	}
}

