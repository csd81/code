// Program 4_2
// Hello, World without "using namespace std"      
// now we will not use the "using namespace std" statement       
// this is a good practice to avoid name conflicts with other libraries
// instead, we will use the std:: prefix to access the cout and endl objects
// this is called "namespace qualification"

#include <iostream>

int main()
{
	std::cout << "Hello, World!" << std::endl;                  
}