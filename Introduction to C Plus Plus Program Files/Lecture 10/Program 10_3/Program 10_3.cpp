// Program 10_3
// Using getline with a file
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	fstream grocery_file;
	grocery_file.open("GroceryList.dat", fstream::in);
	string s;
	getline(grocery_file, s);  //was: grocery_file >> s;
	cout << s << endl;
	grocery_file.close();                 
}