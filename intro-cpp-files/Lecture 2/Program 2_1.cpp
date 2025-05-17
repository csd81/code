// Program 2_1
// Program to compute calories using carbs, protein, and fat
#include<iostream>
using namespace std;

int main() {
	// initialize variables
	int carb_grams;
	int protein_grams;
	int fat_grams;

	carb_grams = 30;
	protein_grams = 5;
	fat_grams = 15;                        
	// calculate calories
	int calories;

	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}