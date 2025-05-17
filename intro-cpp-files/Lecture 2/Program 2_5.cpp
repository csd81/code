// Program 2_5
// Initializing variables by assigning when declared
#include<iostream>

using namespace std; // namespace for cout

int main() {
	int carb_grams = 30; // assigned when declared
	int protein_grams = 5;                                                 
	int fat_grams = 15;
	// calculate calories
	int calories = 4 * carb_grams + 4 * protein_grams + 9 * fat_grams;
	// output the result
	cout << "There are " << calories << " calories in this dish" << endl;
}