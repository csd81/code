// 8.3.2. Módosítsa úgy a programot, hogy a különböző előtagok (Dr., prof., PhD., …) ne befolyásolják a sorrendet! 

 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper: convert a string to lowercase
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

    // read prefixes and names
    vector<string> prefix(n), name(n);
    for (int i = 0; i < n; ++i) {
        cout << i+1 << ". prefix: ";
        cin >> prefix[i];
        cout << i+1 << ". name:   ";
        cin >> name[i];
    }

    // Bubble‐sort by name only (case‐insensitive), ignoring prefixes
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (toLower(name[j]) > toLower(name[j+1])) {
                swap(name[j],     name[j+1]);
                swap(prefix[j],   prefix[j+1]);
            }
        }
    }

    // Print sorted list
    cout << "\nSorted names:\n";
    for (int i = 0; i < n; ++i) {
        cout << prefix[i] << " " << name[i] << "\n";
    }
    return 0;
}
 