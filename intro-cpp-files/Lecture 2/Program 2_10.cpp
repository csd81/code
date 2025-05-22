// Program 2_10
// Using a variable name on both sides of the assignment statement
#include<iostream>
using namespace std;

int main() {
	int carb_grams;
	int protein_grams;
	int fat_grams;                                                         
	carb_grams = 30;
	protein_grams = 5;
	fat_grams = 15;  // First we assign a value of 15

	fat_grams = fat_grams + 1;  // Evaluate right side first, then assign to left
	// fat_grams is now 16

	// declare calories variable
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams; // calculate calories 4 * 30 (120) + 4 * 5 (20) + 9 * 16 (144) = 284
	cout << "There are " << calories << " calories in this dish" << endl;
}