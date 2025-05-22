// Program 15_5
// Using Namespace example - error
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

using namespace english;
int main()
{
	greeting();           
}