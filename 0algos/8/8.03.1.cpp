

// 8.3.1. Feladat: Írjon programot, amely abc sorrendbe rendez neveket!
// Kérje be, hogy hány nevet akar rendezni, ezután kérje be a neveket!
// Rendezze a neveket buborék rendezéssel! Ötlet: használja az stricmp függvényt! 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert a string to lowercase for comparison
string toLower(const string& s) {
    string t = s;
    transform(t.begin(), t.end(), t.begin(),
              [](unsigned char c){ return static_cast<char>(tolower(c)); });
    return t;
}

int main() {
    int n;
    cout << "Number of names: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid count.\n";
        return 1;
    }

    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cout << i+1 << ". name: ";
        cin >> names[i];
    }

    // Bubble‐sort using case‐insensitive comparison
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (toLower(names[j]) > toLower(names[j+1])) {
                swap(names[j], names[j+1]);
            }
        }
    }

    cout << "\nSorted names:\n";
    for (const auto& name : names) {
        cout << name << "\n";
    }

    return 0;
}
