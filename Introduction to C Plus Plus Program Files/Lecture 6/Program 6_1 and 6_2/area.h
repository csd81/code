#pragma once // This is a preprocessor directive that ensures the header file is included only once in a single compilation.

// Program 6_1
// Header file area.h would contain this code
// Square Area: returns the area of a square with side length equal to the argument. 
extern double square_area(double);  // This is a function prototype for the square_area function.




// This is a header file that contains the declaration of the function square_area.
// the extern keyword indicates that the function is defined in another file.
// extern means that the function is not defined in the corresponding source file, which is area.cpp.

// The function takes a double argument and returns a double value.
// The function calculates the area of a square given its side length.