// Program 2_13
// Using -- to decrement
#include<iostream>
using namespace std;

int main() {
	int carb_grams;
	int protein_grams;                                                   
	int fat_grams;
	carb_grams = 30;
	protein_grams = 5;
	fat_grams = 15;  // First we assign a value of 15
	fat_grams--;  // Decrements the value stored by 1
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}