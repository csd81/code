// Program 2_20
// Streaming input into multiple variables
#include<iostream>
// using namespace std;

int main() {                                                
	int carb_grams;
	int protein_grams;
	int fat_grams;
	std::cout << "Enter the number of grams of carbohydrates, protein, and fat, separated by spaces." << std::endl;
	std::cin >> carb_grams >> protein_grams >> fat_grams;  // Read in grams of each
	                           // here we use cin to read in multiple variables
	                           // separated by spaces
	                           // cin is in iostream, so we use std::cin
	                           // to avoid using namespace std
		
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	std::cout << "There are " << calories << " calories in this dish" << std::endl;
}