// Program 10_7
// Averaging values in a file
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() { // beginning of main
	fstream bank_file("balances.txt", fstream::in);     // open the file for input              
	float f; // declare a float variable to hold the values
	float total = 0.0; // declare a float variable and initialize it to 0.0
	int num_vals = 0; // declare an int variable to hold the number of values
	for (bank_file >> f; !bank_file.eof(); bank_file >> f) {   // iterate through the file word by word until the end of the file is reached
		// we read the first float from the file
		total += f; // add the float value to the total
		num_vals++; // increment the number of values
	}
	bank_file.close();     // close the file
	cout << "The average was " << total / num_vals  << endl;                       // output the average               
} // end of main


// The program reads a file called "balances.txt" that contains a list of float values, one per line.
// It calculates the average of these values and outputs the result to the console.
// The program uses a fstream object to open the file for input, and a for loop to read the values from the file.
// The loop continues until the end of the file is reached, at which point the program calculates the average and outputs it to the console.
// The program uses the fstream class to create a file stream object that can be used to read from and write to files.