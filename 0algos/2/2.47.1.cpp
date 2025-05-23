2.47.1.
#include <iostream>
#include <fstream>
#include <cstring> using namespace std;
class Counter { char fileName[500];
ofstream file;
public: static int lineCount;
void init(char* para);
void close() {file.close();} void write(const char* line);
static int getLineCount() {return lineCount;} static void resetLineCount() 
{lineCount=0;} };
void Counter::init(char* para) { strcpy(fileName, para);
file.open(fileName);
} void Counter::write(const char* line) { file << line << endl;
lineCount++;
} int Counter::lineCount=0;
// class variable def. int main() { Counter obj1, obj2;
cout << "The number of lines have written till now:" << Counter::lineCount << 
endl;
obj1.init("file1.txt");
obj1.write("The first line");
obj1.write("and the second");
cout << "The number of lines have written till now:" << obj1.lineCount << endl;
obj2.init("file2.txt");
obj2.write("New line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
Counter::resetLineCount();
obj1.write("Strange line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
obj1.close();
obj2.close();
return 0;
} 
2.47.1. Készítsen osztályt, amelynek segítségével fájlba tud írni 
sorokat! A fájlnevet tudjuk beállítani objektumonként és statikus adattag 
számolja a program által eddig kiírt sorok számát! Lehessen ezt az 
adattagot lenullázni és lekérdezni! 
