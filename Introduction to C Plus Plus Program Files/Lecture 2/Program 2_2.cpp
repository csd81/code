// Program 2_2
// Declaring multiple variables on one line
#include<iostream>
using namespace std;

int main() {
	int carb_grams, protein_grams, fat_grams, calories; // 4 variables declared

	carb_grams = 30; // initialize variables
	protein_grams = 5;                     
	fat_grams = 15;
	// calculate calories
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}