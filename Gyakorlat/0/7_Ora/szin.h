#ifndef SZIN_H
#define SZIN_H

#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

class Szin
{
public:
    virtual ~Szin(){}
    virtual unsigned char R() const = 0;
    virtual unsigned char G() const = 0;
    virtual unsigned char B() const = 0;
    virtual string printCode() const;
    bool megegyezik(const Szin &masik) const;
    static char szamotHexava(int szam);
    static int hexatSzamma(char c);
};

#endif // SZIN_H
