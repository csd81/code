// 2.47. Statikus adattag
// 2.47.1. Készítsen osztályt, amelynek segítségével fájlba tud írni 
// sorokat! A fájlnevet tudjuk beállítani objektumonként és statikus adattag 
// számolja a program által eddig kiírt sorok számát! Lehessen ezt az 
// adattagot lenullázni és lekérdezni! 
// 2.47.1.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Counter {
    char fileName[500];
    ofstream file;

public:
    static int lineCount;

    void init(const char* para);
    void close() { file.close(); }

    void write(const char* line);

    static int getLineCount() { return lineCount; }
    static void resetLineCount() { lineCount = 0; }
};

// statikus tag inicializálása
int Counter::lineCount = 0;

void Counter::init(const char* para) {
    strcpy(fileName, para);
    file.open(fileName);
    if (!file) {
        cerr << "Failed to open file: " << fileName << endl;
    }
}

void Counter::write(const char* line) {
    if (file.is_open()) {
        file << line << endl;
        lineCount++;
    } else {
        cerr << "File not open for writing: " << fileName << endl;
    }
}

int main() {
    Counter obj1, obj2;

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    obj1.init("file1.txt");
    obj1.write("The first line");
    obj1.write("And the second line");

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    obj2.init("file2.txt");
    obj2.write("New line");

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    Counter::resetLineCount();
    obj1.write("Strange line");

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    obj1.close();
    obj2.close();

    return 0;
}

