// Program 9_2
// A greeting program
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// string username;
	// cout << "What's your name? ";
	// cin >> username;
	// cout << "Hello, " << username << " !!!" << endl;                 

	// cout << "Welcome to the world of C++ programming!" << endl;
	// cout << "Let's start coding!" << endl;
	// cout << "Enjoy your journey!" << endl;

	string full_username;
	
	cout << "What's your full name with spaces? ";
	getline(cin, full_username);
	cout << "Hello, " << full_username << " !!!" << endl;                 
}

// The program prompts the user for their name
// The program reads the name from the user
// The program greets the user with their name

// cout is an object of the ostream class
// cin is an object of the istream class
// the ostream class is a subclass of the ios class
// the ios class is the base class for all input and output classes
// >> is the stream extraction operator
// << is the stream insertion operator
// it has several member functions, including:
// put(), get(), read(), write(), flush(), seekg(), seekp(), tellg(), tellp(), clear(), eof(), fail(), bad(), good()


// the istream class is a subclass of the ios class
// it has several member functions, including:
// get(), getline(), read(), ignore(), peek(), putback(), unget(), seekg(), tellg(), clear(), eof(), fail(), bad(), good()


// the ostream class is used for output
// the ostream class is a subclass of the ios class
// it has several member functions, including:
// put(), write(), flush(), seekp(), tellp(), clear(), eof(), fail(), bad(), good()

// the string class is a subclass of the ios class
// it has several member functions, including:
// length(), size(), empty(), clear(), append(), insert(), erase(), replace(), find(), substr(), compare(), c_str(), data()

// the getline() function is used to read a line of text from the input stream, it reads until a *newline* character is encountered
// cin >>  reads a single word from the input stream, it stops reading when a *whitespace* character is encountered