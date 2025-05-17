// Program 2_19
// Compute calories for dish based on user input
#include<iostream>
// using namespace std;

int main() {                                                    
	int carb_grams;
	int protein_grams;
	int fat_grams;
	
	std::cout << "Enter the number of grams of carbohydrates, protein, and fat, separated by spaces." << std::endl; // endl is also in iostream, so we use std::endl
	std::cin >> carb_grams;    // Read in grams of each 
	std::cin >> protein_grams;
	std::cin >> fat_grams; // using std:: to avoid using namespace std
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	std::cout << "There are " << calories << " calories in this dish" << std::endl;
}