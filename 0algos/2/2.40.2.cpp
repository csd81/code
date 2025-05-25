// 2.40.2. Módosítsa úgy az XML fájlt, hogy Car tag-k egy Cars tag-on belül 
// legyenek! Ahol lehet, az adatok a tagok tulajdonságaiban szerepeljenek! 
// Például: <name value="Jani"/> 
// 2.40.2.


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Car {
    int ID;
    double price;
};

struct Person {
    string name;
    int age;
    vector<Car> myCars;
};

void indent(ofstream& file, int depth) {
    for (int i = 0; i < depth; ++i) {
        file << "\t";
    }
}

void printSelfClosingTag(ofstream& file, int depth, const string& tag, const string& attrName, const string& value) {
    indent(file, depth);
    file << "<" << tag << " " << attrName << "=\"" << value << "\"/>\n";
}

void printStartTag(ofstream& file, int depth, const string& tag) {
    indent(file, depth);
    file << "<" << tag << ">\n";
}

void printEndTag(ofstream& file, int depth, const string& tag) {
    indent(file, depth);
    file << "</" << tag << ">\n";
}

void printPerson(ofstream& file, const Person& buddy) {
    ostringstream oss;

    printStartTag(file, 0, "Person");

    printSelfClosingTag(file, 1, "Name", "value", buddy.name);
    oss << buddy.age;
    printSelfClosingTag(file, 1, "Age", "value", oss.str());
    oss.str(""); oss.clear();
    oss << buddy.myCars.size();
    printSelfClosingTag(file, 1, "Count", "value", oss.str());

    printStartTag(file, 1, "Cars");
    for (const auto& car : buddy.myCars) {
        printStartTag(file, 2, "Car");

        oss.str(""); oss.clear();
        oss << car.ID;
        printSelfClosingTag(file, 3, "ID", "value", oss.str());

        oss.str(""); oss.clear();
        oss << fixed << setprecision(6) << car.price;
        printSelfClosingTag(file, 3, "Price", "value", oss.str());

        printEndTag(file, 2, "Car");
    }
    printEndTag(file, 1, "Cars");

    printEndTag(file, 0, "Person");
}

int main() {
    vector<Person> buddies = {
        {"Jani", 22, { {0, 50}, {2, 12.369}, {21, 0.569} }},
        {"Evi", 36, { {6, 21}, {1, 15.4} }},
        {"Zotya", 25, { {3, 5.7} }}
    };

    ofstream file("car.xml");
    if (!file) {
        cerr << "Error opening output file.\n";
        return 1;
    }

    for (const auto& person : buddies) {
        printPerson(file, person);
    }

    file.close();
    cout << "XML file created in car.xml.\n";
    return 0;
}
