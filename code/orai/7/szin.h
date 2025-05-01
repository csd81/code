#ifndef SZIN_H
#define SZIN_H

#include <string>

using namespace std;

class Szin
{
public:
    virtual unsigned char R() const =0;
    virtual unsigned char G() const =0;
    virtual unsigned char B() const =0;
    virtual ~Szin() = default;

    static char szamotHexava(int ertek);
    static int hexatSzamma(char ch);

    virtual string printCode() const;
};

#endif // SZIN_H
//