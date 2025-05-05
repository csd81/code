// Program 14_6
// Exception example - reading a nonexistent file, now with try/catch
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream infile;
	infile.exceptions(fstream::failbit);
	try {
		infile.open("something.dat", fstream::in);
	}
	catch (exception& category) {
		cout << "Error opening file" << endl;
		return 1;
	}
	int a;
	infile >> a;
	cout << "Read in: " << a << endl;                             
}