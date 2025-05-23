2.47.2.
#include <iostream>
#include <fstream>
#include <cstring> using namespace std;
class Counter { char fileName[500];
ofstream file;
public: static int lineCount;
static int wordCount;
static int charCount;
void init(const char* para);
void close() {file.close();} void write(const char* line);
};
void Counter::init(const char* para) { strcpy(fileName, para);
file.open(fileName);
} void Counter::write(const char* line) { int i=0;
while (line[i]!='\0') { file << line[i];
charCount++;
if (line[i]==' ') { wordCount++;
} i++;
} if (line[0]!='\0') { wordCount++;
} file << endl;
lineCount++;
} int Counter::lineCount=0;
// int Counter::wordCount=0;
// int Counter::charCount=0;
// class variable def. class variable def. class variable def. int main() { 
Counter obj1, obj2;
cout << "The number of lines have written till now:" << Counter::lineCount << 
endl;
obj1.init("file1.txt");
obj1.write("The first line");
obj1.write("and the second");
cout << "The number of lines have written till now:" << obj1.lineCount << endl;
obj2.init("file2.txt");
obj2.write("New line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
obj2.lineCount=0;
obj1.write("Strange line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
obj1.close();
obj2.close();
return 0;
} 
2.47.2. Módosítsa az előző programot úgy, hogy számolja a szavak és 
karakterek számát is! 2.48. Komplex számok
