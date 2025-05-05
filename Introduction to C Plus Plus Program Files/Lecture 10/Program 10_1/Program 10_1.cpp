// Program 10_1
// Streaming output to a file
#include<fstream>
using namespace std;

int main() {
	fstream grocery_file;
	grocery_file.open("GroceryList.dat", fstream::out);
	grocery_file << "Skim Milk" << endl;
	grocery_file << "Eggs" << endl;      
	grocery_file.close();                          
}                             