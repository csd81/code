// Program 7_9
// A 2D array uninitialized
#include <iostream>
using namespace std;

int main() {
	double accounts[5][3];

	accounts[3][1] = 1000.0;
	accounts[0][2] = 50.0;                                

	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
			cout << "Person " << i << ", account " << j << " has balance "       
				<< accounts[i][j] << endl;
		}
	}    
}

// // this program will not compile because the array is not initialized
// it actually compiles but the values are not initialized therefore the values are garbage values
// it is not a good practice to use uninitialized variables
// it is better to initialize the variables before using them
 