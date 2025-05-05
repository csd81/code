// Program 2_3
// Using floating-point variables
#include<iostream>
using namespace std;

int main() {
	// declare variables
	float carb_grams;                            // using float for grams
	float protein_grams;
	float fat_grams;
// initialize variables
	carb_grams = 30;
	protein_grams = 5;                       
	fat_grams = 15;
	// declare  calories variable
	float calories;
// calculate calories
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	// output the result
	cout << "There are " << calories << " calories in this dish" << endl;
}