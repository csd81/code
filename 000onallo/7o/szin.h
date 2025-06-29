#ifndef SZIN_H
#define SZIN_H

#include <string>

using namespace std;

class Szin
{
public:
    virtual ~Szin() {}
    virtual unsigned char R() const = 0;
    virtual unsigned char G() const = 0;
    virtual unsigned char B() const = 0;

    static char szamotHexava(int szam);
    static int hexatSzamma(char hex);

    virtual string printCode() const;

    bool megegyezik(const Szin& masik) const;
};

#endif // SZIN_H
