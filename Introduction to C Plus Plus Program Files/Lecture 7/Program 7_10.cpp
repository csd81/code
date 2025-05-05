// Program 7_10
// A 2D array initialized
#include <iostream>
using namespace std;

int main() {
	double accounts[5][3];

	int i, j;                                       

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
			accounts[i][j] = 0.0;
		}
	}

	accounts[3][1] = 1000.0;
	accounts[0][2] = 50.0;


	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
			cout << "Person " << i + 1 << ", account " << j + 1  << " has balance " 
				<< accounts[i][j] << endl;
		}
	}                 

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
		cout << accounts[i][j] << "\t";
		}
		cout << endl;
	}
}

// now the program will compile and run
// the program will initialize the array with 0.0

//in the first nested for loop we are initializing the array with 0.0
//in the second nested for loop we are displaying the values of the array

 

// we can also add one to the iterator in the for loop when counting persons. 
// for (i = 0; i < 5; i++) {
// 	for (j = 0; j < 3; j++) {
// 		cout << "Person " << i + 1 << ", account " << j + 1 << " has balance "