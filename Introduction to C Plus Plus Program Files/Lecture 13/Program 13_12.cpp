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
	int num_weeks;
	int num_days;
	days_to_weeks_days(total_days, num_weeks, num_days);
	cout << total_days << " is the same as " << num_weeks << " weeks and " 
		<< num_days << " days." << endl;    
}
