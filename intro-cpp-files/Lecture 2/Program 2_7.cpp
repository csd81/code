// Program 2_7
// Program to convert weeks to days
#include <iostream>
using namespace std;

int main() { 
	int weeks = 20;                                     
	int days;
	days = weeks * 7; // 7 days in a week

	// output the result
	cout << "There are " << days << " days in " << weeks << " weeks." << endl; // 20*7 = 140
}