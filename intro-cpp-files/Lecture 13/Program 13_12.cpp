// Program 13_12
// Returning multiple values via references
#include<iostream>
using namespace std;

void days_to_weeks_days(int days, int& weeks, int& remaining_days) {
	weeks = days / 7;
	remaining_days = days % 7;
}

int main() {
	int total_days = 100;	
	int num_weeks; // weeks is passed by reference
	int num_days; // remaining_days is passed by reference
	days_to_weeks_days(total_days, num_weeks, num_days);
	cout << total_days << " is the same as " << num_weeks << " weeks and " 
		<< num_days << " days." << endl;
}

// // This program demonstrates how to return multiple values from a function using references.
// // The function days_to_weeks_days takes an integer number of days and calculates the number of weeks and remaining days.
// // It uses reference parameters to return the results.
// // The main function calls the days_to_weeks_days function with a total number of days and prints the results.
// // This is useful when we want to return multiple values from a function without using a struct or class.
// // In this program, we declare a function days_to_weeks_days that takes an integer number of days as its first parameter.
// // The function calculates the number of weeks and remaining days and assigns them to the reference parameters weeks and remaining_days.
// // The main function calls the days_to_weeks_days function with a total number of days and prints the results.
// // This is useful when we want to return *multiple values* from a function without using a struct or class.