// Program 10_5
// Use of the eof function in a for loop
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	fstream my_file;
	my_file.open("GroceryList.dat");                           
	string s;
	for (my_file >> s; !my_file.eof(); my_file >> s) {    
		cout << s << endl;                                    
	}
	my_file.close(); 
}