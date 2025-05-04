// Program 2_5
// Initializing variables by assigning when declared
#include<iostream>
using namespace std;

int main() {
	int carb_grams = 30;
	int protein_grams = 5;                                                 
	int fat_grams = 15;
	int calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	cout << "There are " << calories << " calories in this dish" << endl;
}