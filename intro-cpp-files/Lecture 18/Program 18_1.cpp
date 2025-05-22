// Program 18_1
// Pointer example using *
#include <iostream>
using namespace std;

int main()
{
	int x = 3; // x is an int variable declared; and initialized to 3
	int* y; // y is a pointer variable declared; (which can point to an int / can store the address of an int variable), but it is not initialized yet
	y = &x;  // y is assigned the address of x, so y now points to x
	cout << *y << endl; // this will print the value of x, which is 3, because *y dereferences y, which means it gets the value at the address stored in y 
	*y = 5; // this will change the value of x to 5, because *y dereferences y, so we can assign a new value to the variable that y points to (x)
	cout << x << endl;  // this will print the new value of x, which is 5              
}


// * can also be a multiplication operator, but in this case it is used as a pointer operator
// * and & are used in C++ to declare pointers and references, but they have different meanings depending on where they are used
// pointer declaration:
// when it is put after a type name * is the pointer operator, which tells the compiler that the variable is a pointer 
// dereference operator:
// when *  is put before a pointer variable, * is the dereference operator, 

// when it is put before a variable address operator,  which tells the compiler to get the address of a variable,
// so that it can be stored in a pointer variable

// when it is put after a type name & is the reference operator, meaning that the variable is a reference to another variable
// *y is the value at the address y
// y is the address of x
// y is a pointer to an int

// pointers are variables that store the address of another variable
// when you declare a pointer, you must specify the type of data it points to, 
// so the compiler can allocate the correct amount of memory for it 
// pointers are used for dynamic memory allocation,
// which allows you to create variables at runtime instead of compile time
// this is useful when you don't know how much memory you'll need until the program is running
// pointers are also used to pass variables by reference to functions
// this allows you to modify the original variable in the function 
