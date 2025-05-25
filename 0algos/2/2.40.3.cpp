
// 2.40.3. Készítsen beolvasó programot! Jelezze ki az XML fájl szintaktikai 
// hibáit! Például hibás tag, nyitó tag párja hiányzik vagy fordítva, két 
// tag pár keresztben van. 

// 2.40.3. 

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOpeningTag(const string& tag) {
    return tag.length() > 2 && tag[0] == '<' && tag[1] != '/' && tag.back() == '>';
}

bool isClosingTag(const string& tag) {
    return tag.length() > 3 && tag[0] == '<' && tag[1] == '/' && tag.back() == '>';
}

string extractTagName(const string& tag) {
    size_t start = tag[1] == '/' ? 2 : 1;
    size_t end = tag.find('>', start);
    return tag.substr(start, end - start);
}

int main() {
    ifstream file("file.xml");
    if (!file.is_open()) {
        cerr << "Error: file.xml not found.\n";
        return 1;
    }

    string line, word;
    stack<pair<string, int>> tagStack;
    int lineNumber = 0;
    bool errorFound = false;

    while (getline(file, line)) {
        ++lineNumber;
        istringstream iss(line);
        while (iss >> word) {
            if (isOpeningTag(word)) {
                string tagName = extractTagName(word);
                tagStack.push({tagName, lineNumber});
            } else if (isClosingTag(word)) {
                string tagName = extractTagName(word);
                if (tagStack.empty()) {
                    cout << "Error at line " << lineNumber << ": Unexpected closing tag </" << tagName << ">\n";
                    errorFound = true;
                } else {
                    auto top = tagStack.top();
                    tagStack.pop();
                    if (top.first != tagName) {
                        cout << "Error at line " << lineNumber << ": Expected </" << top.first << "> but found </" << tagName << ">\n";
                        errorFound = true;
                    }
                }
            }
        }
    }

    while (!tagStack.empty()) {
        auto top = tagStack.top();
        tagStack.pop();
        cout << "Error: No closing tag found for <" << top.first << "> opened at line " << top.second << "\n";
        errorFound = true;
    }

    if (!errorFound) {
        cout << "No errors detected!\n";
    }

    return 0;
}
