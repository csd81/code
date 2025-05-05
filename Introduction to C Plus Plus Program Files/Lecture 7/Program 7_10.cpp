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
			cout << "Person " << i << ", account " << j << " has balance " 
				<< accounts[i][j] << endl;
		}
	}                 
}