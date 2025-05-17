// Program 15_5
// Using Namespace example
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

namespace magyar {

	void greeting() {
		cout << "Szia!" << endl;                
	}

}

using namespace magyar; 

int main()
{
	greeting();           
}