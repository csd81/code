// 2.40. XML
// 2.40.1. Írjon programot, amely XML-ben ment el rekordokat! A kocsi típus 
// azonosítót és árat, a személy típus nevet, életkort, a kocsik számát, 
// és kocsi tömböt tartalmaz. Hozzon létre és inicializáljon egy 3 hosszú 
// személy tömböt és mentse el azokat XML fájlba! Az XML fájl legyen szépen 
// tördelve! Írjon halfTag és fullTag függvényeket! Az előbbi csak 
// „<tagName>” vagy „</tagName>” -t ír ki, az útóbbi „<tagName> Text 
// </tagName>”-t ír ki. Példa: <Person> <Name>Jani</Name> <Age>22</Age> 
// <Count>3</ Count> <Car> <ID>0</ID> <price>50.000000</price> </Car> <Car> … 
// 2.40.1.


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
    int carNumber;
    vector<Car> myCars;
};

void printHalfTag(ofstream& file, int depth, const string& tag) {
    file << string(depth, '\t') << "<" << tag << ">\n";
}

void printFullTag(ofstream& file, int depth, const string& tag, const string& text) {
    file << string(depth, '\t') << "<" << tag << ">" << text << "</" << tag << ">\n";
}

void printPerson(ofstream& file, const Person& buddy) {
    printHalfTag(file, 0, "Person");

    printFullTag(file, 1, "Name", buddy.name);
    printFullTag(file, 1, "Age", to_string(buddy.age));
    printFullTag(file, 1, "Count", to_string(buddy.carNumber));

    for (const Car& car : buddy.myCars) {
        printHalfTag(file, 1, "Car");
        printFullTag(file, 2, "ID", to_string(car.ID));
        ostringstream priceStream;
        priceStream << fixed << setprecision(6) << car.price;
        printFullTag(file, 2, "price", priceStream.str());
        printHalfTag(file, 1, "/Car");
    }

    printHalfTag(file, 0, "/Person");
}

int main() {
    const int buddyNumber = 3;

    vector<Car> cars1 = { {0, 50}, {2, 12.369}, {21, 0.569} };
    vector<Car> cars2 = { {6, 21}, {1, 15.4} };
    vector<Car> cars3 = { {3, 5.7} };

    vector<Person> buddies = {
        {"Jani", 22, static_cast<int>(cars1.size()), cars1},
        {"Evi", 36, static_cast<int>(cars2.size()), cars2},
        {"Zotya", 25, static_cast<int>(cars3.size()), cars3}
    };

    ofstream file("car.xml");
    if (!file) {
        cerr << "Error opening file for writing!\n";
        return 1;
    }

    for (const Person& p : buddies) {
        printPerson(file, p);
    }

    file.close();
    cout << "XML written to car.xml\n";
    return 0;
}

