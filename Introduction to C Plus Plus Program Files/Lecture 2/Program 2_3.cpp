// Program 2_3
// Using floating-point variables
#include<iostream>
using namespace std;

int main() {
	float carb_grams;                            
	float protein_grams;
	float fat_grams;
	carb_grams = 30;
	protein_grams = 5;                       
	fat_grams = 15;
	float calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}