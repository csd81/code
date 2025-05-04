// Program 15_4
// Missing namespace error
#include <iostream>
using namespace std;

	void greeting() {
		cout << "Hello!" << endl;
	}

	void greeting() {
		cout << "Hola!" << endl;
	}

int main()
{
	greeting();
	greeting();                                            
}