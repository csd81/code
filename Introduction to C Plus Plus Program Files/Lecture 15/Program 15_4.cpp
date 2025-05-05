// Program 15_4
// Multiple Namespace example
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
	english::greeting();
	spanish::greeting();              
}