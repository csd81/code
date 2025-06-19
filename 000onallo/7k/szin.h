#ifndef SZIN_H
#define SZIN_H
#include <string>

class Szin
{
public:
    virtual unsigned char R() const = 0;
    virtual unsigned char G() const = 0;
    virtual unsigned char B() const = 0;
    Szin();
    virtual ~Szin();
    static char szamotHexava(const int& szam);
    static int hexatSzamma(const char c);
    virtual std::string printCode() const;
    bool megegyezik(Szin& sz) const;
};

#endif // SZIN_H
