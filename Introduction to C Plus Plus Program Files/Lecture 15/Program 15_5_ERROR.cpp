// Program 15_5
// Using Namespace example - error
#include <iostream>
using namespace std;           
using namespace english;

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
	greeting();           
}