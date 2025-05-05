// Program 14_4
// Exception example - reading a nonexistent file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream infile;
	string filename;
	cout << "What is the file name? ";
	cin >> filename;
	infile.open(filename, fstream::in);

	int a;
	infile >> a;
	cout << "Read in: " << a << endl;             
}