// Program 5_9
//Type conversions
// The program demonstrates type conversions in C++.
// Type conversion is the process of converting a value from one data type to another.
// In C++, there are two types of type conversions: implicit and explicit.
// Implicit conversion is done automatically by the compiler when it is safe to do so.
// Explicit conversion is done by the programmer using type casting.
#include<iostream>
using namespace std;

int main() {
	int a = 3;
	float b = 2.6;
	bool c = true;
	cout << float(a) << " " // explicit conversion -> 3.0
	<< (float)a << endl; // explicit conversion -> 3.0
	cout << bool(a) << " " << (bool)a << endl; // explicit conversion -> true
	cout << int(b) << " " << (int)b << endl; // explicit conversion -> 2
	cout << bool(b) << " " << (bool)b << endl; // explicit conversion -> true
	cout << int(c) << " " << (int)c << endl; // explicit conversion -> 1
	cout << float(c) << " " << (float)c << endl;      // explicit conversion -> 1.0
	cout << static_cast<int>(b) << " " << static_cast<int>(b) << endl; // explicit conversion -> 2
	cout << static_cast<bool>(b) << " " << static_cast<bool>(b) << endl; // explicit conversion -> true
}

// The difference between implicit and explicit type conversion is that implicit conversion is done automatically by the compiler when it is safe to do so, while explicit conversion is done by the programmer using type casting.
// int(b) is an explicit conversion from float to int, which truncates the decimal part of the float value.
// (bool)a is an explicit conversion from int to bool, which converts any non-zero integer to true and zero to false.
// there are two notations for explicit conversion: C-style cast and C++ style cast.
// The C-style cast is done using the syntax (type)value, where type is the target data type and value is the value to be converted.
// The C++ style cast is done using the syntax static_cast<type>(value), where type is the target data type and value is the value to be converted.
// The C++ style cast is preferred over the C-style cast because it is more explicit and less error-prone.