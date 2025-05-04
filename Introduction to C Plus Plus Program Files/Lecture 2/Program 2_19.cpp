// Program 2_19
// Compute calories for dish based on user input
#include<iostream>
using namespace std;

int main() {                                                    
	int carb_grams;
	int protein_grams;
	int fat_grams;
	cout << "Enter the number of grams of carbohydrates, protein, and fat, separated by spaces." << endl;
	cin >> carb_grams;    // Read in grams of each
	cin >> protein_grams;
	cin >> fat_grams;
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}