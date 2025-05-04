// Program 10_4
// Use of the eof function in a while loop
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	fstream my_file;
	my_file.open("GroceryList.dat");                                   
	string s;                                         
	my_file >> s;
	while (!my_file.eof()) {
		cout << s << endl;
		my_file >> s;                   
	}
	my_file.close();                 
}