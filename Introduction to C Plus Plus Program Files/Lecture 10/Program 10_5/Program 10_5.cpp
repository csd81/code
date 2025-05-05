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
	int i = 0;
	for (my_file >> s; !my_file.eof(); my_file >> s) {    
		cout << s << endl;                                    
		i++;
	}
	my_file.close(); 
	cout << "The number of items in the grocery list is: " << i << endl; // output the number of items in the grocery list
}

// for (my_file >> s; !my_file.eof(); my_file >> s) is a for loop that reads data from the file until the end of the file is reached.
// The for loop consists of three parts:
// 1. Initialization: my_file >> s; // read the first string from the file UNTIL the first whitespace character (space, tab, newline)
// 2. Condition: !my_file.eof(); // check if the end of the file has been reached
// 3. Increment: my_file >> s; // read the next string from the file