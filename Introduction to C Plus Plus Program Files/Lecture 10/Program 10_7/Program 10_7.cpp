// Program 10_7
// Averaging values in a file
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	fstream bank_file("balances.txt", fstream::in);                   
	float f;
	float total = 0.0;
	int num_vals = 0;
	for (bank_file >> f; !bank_file.eof(); bank_file >> f) {  
		total += f;
		num_vals++;
	}
	bank_file.close();    
	cout << "The average was " << total / num_vals  << endl;                                    
}