// Program 18_2
// Pointer example using [0]
#include <iostream>
using namespace std;

int main()
{
	int x = 3;
	int* y;
	y = &x; // y is assigned the address of x, so y now points to x, because y is a pointer to an int, 
			// here & is the address operator that gets the address of x
	cout << y[0] << endl;   // this will print the value of x, which is 3, because y[0] dereferences y,  
							// which means it gets the value at the address stored in y
							// 0 is the index of the first element of the array that y points to, 
							// that is the first element of the array that has type int
	y[0] = 5;  // this will change the value of x to 5, because y[0] dereferences y, 
			// so we can assign a new value to the variable that y points to (x)
	cout << x << endl;                 // 5 
}

// y[0] is the same as *y, because y is a pointer to an int, and y[0] is the first element of the array that y points to, 
// pointer arithmetic is used to access the elements of an array using pointers
// y[0] is the same as *(y + 0), which is the same as *y
// y[1] is the same as *(y + 1), which is the same as *(y + sizeof(int)), which is the second element of the array that y points to
// y[2] is the same as *(y + 2), which is the same as *(y + 2 * sizeof(int)), which is the third element of the array that y points to
// pointers can be used to access the elements of an array
// arrays are just a collection of variables of the same type, and pointers can be used to access the elements of an array
// arrays can have several types of data, and pointers can be used to access the elements of an array
// arrays are useful when you need to store a collection of variables of the same type
// an integer pointer allocates 4 bytes of memory, which is the size of an int
// pointers always allocate the amount of memory needed to store a variable of the type they point to
// whan we increase the pointer by 1, we are actually increasing the address by the size of the type it points to