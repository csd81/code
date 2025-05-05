// Program 2_6
// Outputting just one variable
#include<iostream>
using namespace std;

int main() {
	int carb_grams = 30;
	int protein_grams = 5;                                   
	int fat_grams = 15; 
	int calories;
	calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	// output the result
	cout << calories << endl; //  output just the variable
}