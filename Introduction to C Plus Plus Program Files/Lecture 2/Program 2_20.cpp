// Program 2_20
// Streaming input into multiple variables
#include<iostream>
using namespace std;

int main() {                                                
	int carb_grams;
	int protein_grams;
	int fat_grams;
	cout << "Enter the number of grams of carbohydrates, protein, and fat, separated by spaces." << endl;
	cin >> carb_grams >> protein_grams >> fat_grams;  // Read in grams of each
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}