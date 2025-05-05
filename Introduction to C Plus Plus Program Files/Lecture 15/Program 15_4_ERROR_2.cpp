// Program 15_4
// Namespace example - error
#include <iostream>
using namespace std;

namespace english {

	void greeting() {
		cout << "Hello!" << endl;
	}

}

namespace spanish {

	void greeting() {
		cout << "Hola!" << endl;
	}

}

int main()
{
	spanish::greeting();                                                    
}