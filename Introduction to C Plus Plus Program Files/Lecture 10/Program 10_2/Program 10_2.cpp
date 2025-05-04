// Program 10_2
// Streaming input from a file
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	fstream grocery_file;
	grocery_file.open("GroceryList.dat", fstream::in);      
	string s;
	grocery_file >> s;             
	cout << s << endl;
	grocery_file.close();                                             
}