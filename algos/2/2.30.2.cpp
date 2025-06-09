// 2.30.2. Módosítsa az előző programot úgy, hogy létrehoz új típusnevet a 
// struktúrának és ezt használja a továbbiakban! Külön függvényben 
// valósítsa meg a struktúra bekérő és kiíró részt! Hozzon létre egy 
// dinamikus struktúrát, amit tegyen egyenlővé a bekért struktúrával! 
// Módosítsa a dinamikus struktúrán keresztül az egész mutató által 
// mutatott értéket!
// 2.30.2.

#include <iostream>
#include <memory>   // std::unique_ptr
#include <iomanip>  // fixed, setprecision

using namespace std;

// 1) Új típusnév a struktúrának
struct Var {
    char        varChar;
    short       varShortInt;
    int         varInt;
    float       varFloat;
    double      varDouble;
    long double varLongDouble;
    int*        varPInt;
};
using VarType = Var;

// 2) Bekérő függvény
void readVarType(VarType* v) {
    cout << "varChar: ";
    cin >> v->varChar;

    cout << "varShortInt: ";
    cin >> v->varShortInt;

    cout << "varInt: ";
    cin >> v->varInt;

    cout << "varFloat: ";
    cin >> v->varFloat;

    cout << "varDouble: ";
    cin >> v->varDouble;

    cout << "varLongDouble: ";
    cin >> v->varLongDouble;

    // A mutató álljon rá az int mezőre
    v->varPInt = &v->varInt;
}

// 3) Kiíró függvény
void printVarType(const VarType& v) {
    cout << "\n--- VarType contents ---\n";
    cout << "varChar        = " << v.varChar        << "\n";
    cout << "varShortInt    = " << v.varShortInt    << "\n";
    cout << "varInt         = " << v.varInt         << "\n";
    cout << "varFloat       = " << fixed << setprecision(6) << v.varFloat       << "\n";
    cout << "varDouble      = " << v.varDouble      << "\n";
    cout << "varLongDouble  = " << v.varLongDouble  << "\n";
    cout << "varPInt (addr) = " << static_cast<void*>(v.varPInt)
         << " *varPInt      = " << *v.varPInt      << "\n";
}

int main() {
    // Statikus változó
    VarType myVar;
    readVarType(&myVar);

    // Kiírjuk az eredeti struktúrát
    printVarType(myVar);

    // Dinamikusan létrehozott másolat
    unique_ptr<VarType> copy(new VarType(myVar));

    // A dinamikus példány kiírása
    printVarType(*copy);

    // A mutatón keresztül módosítjuk a varInt-et
    *copy->varPInt = 666;

    // Visszaellenőrizzük az eredeti struktúrán
    printVarType(myVar);

    return 0;
}
