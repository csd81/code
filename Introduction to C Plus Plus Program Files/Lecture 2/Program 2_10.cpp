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
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}