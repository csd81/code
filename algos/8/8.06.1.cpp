
// C++11
// 8.6.1. Írjon programot, amely szavakat rendez növekvő sorrendbe az strcmp függvény használata nélkül! 
// A szavak csak nagybetűkből állnak. 
// A program olvassa be fájlból a szavakat, és írja ki azokat a képernyőre növekvő sorrendben. 
// Ha egy szó megegyezik egy másik, hosszabb szó elejével, akkor a hosszabb szó szerepel később.
// Például: SO < SOAP.
//  A szavak maximális hossza 15 karakter.
// Használjon dinamikus tömböket a szavak tárolásához!
// A sorrendnél a betűk ASCII kódja számít.
// Az input fájl formátuma: Első sor: A szavak száma. A többi sor egy-egy szót tartalmaz.
// Példa bemenet: 7 WARIOR APPLE SZOKOZSHIP BOOK SZOKOZ PHISIC LIMON
// Kimenet: Read words: 1.: WARIOR 2.: APPLE 3.: SOAP 4.: BOOK 5.: SO 6.: PHISIC 7.: LIMON *************** Sorted words : 1.: APPLE 2.: BOOK 3.: LIMON 4.: PHISIC 5.: SO 6.: SOAP 7.: WARIOR


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Compare two uppercase-only words lexicographically by ASCII,
// with shorter word coming first if it's a prefix of the longer.
bool wordLess(const string& A, const string& B) {
    size_t la = A.size(), lb = B.size();
    size_t lm = min(la, lb);
    for (size_t i = 0; i < lm; ++i) {
        if (A[i] < B[i]) return true;
        if (A[i] > B[i]) return false;
    }
    return la < lb;
}

int main(int argc, char* argv[]) {
    const char* filename = (argc > 1 ? argv[1] : "words.txt");
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    int N;
    infile >> N;
    vector<string> words;
    words.reserve(N);

    // Read words
    for (int i = 0; i < N; ++i) {
        string w;
        infile >> w;
        words.push_back(w);
    }

    // Print as read
    cout << "Read words:\n";
    for (int i = 0; i < N; ++i) {
        cout << "\t" << (i+1) << ".: " << words[i] << "\n";
    }

    // Sort using our custom comparator
    sort(words.begin(), words.end(), wordLess);

    // Print sorted
    cout << "\n***************\n";
    cout << "Sorted words:\n";
    for (int i = 0; i < N; ++i) {
        cout << "\t" << (i+1) << ".: " << words[i] << "\n";
    }

    return 0;
}

