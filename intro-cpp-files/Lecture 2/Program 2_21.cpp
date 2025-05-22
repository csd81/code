// Program 2_21
// Prompting user for multiple inputs
#include<iostream>
using namespace std;
                                                                          
int main() {
	// declare variables
	int carb_grams;
	int protein_grams;                                                        
	int fat_grams;

	// prompt user for input, reading from standard input;
	cout << "Enter the number of grams of carbohydrates: ";
	cin >> carb_grams;

	cout << "Enter the number of grams of protein: ";
	cin >> protein_grams; // there is no input validation here, so if the user enters a non-integer, it will cause an error;
	
	cout << "Enter the number of grams of fat: ";
	cin >> fat_grams;

	// declare calories variable
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}