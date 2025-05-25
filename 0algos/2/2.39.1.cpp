// 2.39. Hamupipőke
// 2.39.1. Írjon programot, amely egy már meglévő, véletlen számokat 
// tartalmazó fájlban lévő számokat szétválogatja párosság alapján! A 
// páros és páratlan számokat tárolja külön fájlokban! Írjon függvényt, 
// amely kiszámolja az egy fájlban lévő számok átlagát! Alkalmazza a 
// függvényt a két fájlra és határozza meg a két fájlban lévő számok 
// mennyiségének az arányát! 
// 2.39.1.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

double average(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << fileName << endl;
        return 0;
    }

    int value, count = 0;
    double sum = 0;

    while (file >> value) {
        sum += value;
        ++count;
    }

    file.close();
    return count ? (sum / count) : 0;
}

int main() {
    string origFileName, evenFileName = "even.txt", oddFileName = "odd.txt";
    int evenCounter = 0, oddCounter = 0, value;

    cout << "This program will divide numbers based on parity.\n";
    cout << "Enter the name of the input file: ";
    cin >> origFileName;

    ifstream input(origFileName);
    if (!input.is_open()) {
        cerr << "Failed to open input file!\n";
        return 1;
    }

    ofstream evenFile(evenFileName);
    ofstream oddFile(oddFileName);

    while (input >> value) {
        if (value % 2 == 0) {
            ++evenCounter;
            evenFile << value << '\n';
        } else {
            ++oddCounter;
            oddFile << value << '\n';
        }
    }

    input.close();
    evenFile.close();
    oddFile.close();

    cout << "There were " << evenCounter << " even and "
         << oddCounter << " odd numbers.\n";

    if (oddCounter > 0)
        cout << "Their ratio is: " << fixed << setprecision(6)
             << static_cast<double>(evenCounter) / oddCounter << '\n';
    else
        cout << "No odd numbers to compare ratio.\n";

    double evenAvg = average(evenFileName);
    double oddAvg = average(oddFileName);

    cout << "Average of even numbers: " << setprecision(9) << evenAvg << '\n';
    cout << "Average of odd numbers: " << setprecision(9) << oddAvg << '\n';

    return 0;
}
