// Program 10_6
// Writing an address to a file
#include<fstream>
#include<string>
using namespace std;

int main() {
	fstream my_file("address.txt", fstream::out);
	my_file << "John Keyser" << endl;
	my_file << "123 Any St." << endl;
	my_file << "Somewhere, TX   77777" << endl;                       
	my_file.close();                                    
}