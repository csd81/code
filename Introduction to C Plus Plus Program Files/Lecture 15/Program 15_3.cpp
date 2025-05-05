// Program 15_3
// Namespace example
#include <iostream>
using namespace std;

namespace english {

	void greeting() {
		cout << "Szia!" << endl;
	}

}

int main()
{
	english::greeting();  
}