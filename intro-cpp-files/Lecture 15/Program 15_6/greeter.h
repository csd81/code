// Program 15_6a 
// Header file for library
// greeter.h

namespace mynamespace {
	extern void greeting();
}                                      

// header files are used to declare functions, classes, and variables that can be used in multiple source files.
// they allow us to separate the interface of a library from its implementation.
// this makes it easier to manage large projects and allows us to reuse code across multiple files.
// header files typically have a .h extension and are included in source files using the #include directive.
// this allows us to use the functions, classes, and variables declared in the header file in our source file.