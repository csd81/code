// Program 11_2
// Program to illustrate debugging
#include<iostream>
using namespace std;

int main() {
	cout << "Line 1" << endl;                                 
	cout << "Line 2" << endl;    
	cout << "Line 3" << endl;                      
	int i;
	for (i = 0; i < 5; i++) {                    
		cout << i << endl;                
	}    
}                                   

// The program outputs the numbers 0 to 4, one per line.
// The program uses a for loop to iterate from 0 to 4 and outputs the value of i in each iteration.