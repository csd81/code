// 2.47.2. Módosítsa az előző programot úgy, hogy számolja a szavak és 
// karakterek számát is! 
// 2.47.2.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Counter {
    char fileName[500];
    std::ofstream file;

public:
    static int lineCount;
    static int wordCount;
    static int charCount;

    void init(const char* para) {
        std::strcpy(fileName, para);
        file.open(fileName);
    }

    void close() {
        if (file.is_open()) file.close();
    }

    void write(const char* line) {
        if (!file.is_open()) return;

        int i = 0;
        bool inWord = false;

        while (line[i] != '\0') {
            file << line[i];
            charCount++;

            if (std::isspace(line[i])) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }

            ++i;
        }

        if (inWord) {
            wordCount++;
        }

        file << std::endl;
        lineCount++;
    }
};

// statikus változók definíciója
int Counter::lineCount = 0;
int Counter::wordCount = 0;
int Counter::charCount = 0;

int main() {
    Counter obj1, obj2;

    std::cout << "Initial line count: " << Counter::lineCount << std::endl;

    obj1.init("file1.txt");
    obj1.write("The first line");
    obj1.write("and the second");

    std::cout << "After writing to file1.txt:" << std::endl;
    std::cout << "  Lines: " << Counter::lineCount << std::endl;
    std::cout << "  Words: " << Counter::wordCount << std::endl;
    std::cout << "  Characters: " << Counter::charCount << std::endl;

    obj2.init("file2.txt");
    obj2.write("New line");

    std::cout << "After writing to file2.txt:" << std::endl;
    std::cout << "  Lines: " << Counter::lineCount << std::endl;
    std::cout << "  Words: " << Counter::wordCount << std::endl;
    std::cout << "  Characters: " << Counter::charCount << std::endl;

    obj1.write("Strange line");

    std::cout << "Final statistics:" << std::endl;
    std::cout << "  Lines: " << Counter::lineCount << std::endl;
    std::cout << "  Words: " << Counter::wordCount << std::endl;
    std::cout << "  Characters: " << Counter::charCount << std::endl;

    obj1.close();
    obj2.close();

    return 0;
}
