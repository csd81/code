// Program 2_21
// Prompting user for multiple inputs
#include<iostream>
using namespace std;
                                                                          
int main() {
	int carb_grams;
	int protein_grams;                                                        
	int fat_grams;
	cout << "Enter the number of grams of carbohydrates: ";
	cin >> carb_grams;
	cout << "Enter the number of grams of protein: ";
	cin >> protein_grams;
	cout << "Enter the number of grams of fat: ";
	cin >> fat_grams;
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}