#ifndef KARAKTER_H
#define KARAKTER_H

#include <iostream>
#include <string>

class Karakter {
protected:
    std::string nev; // karakter neve
    int szint;       // karakter szintje
public:
    Karakter(const std::string &nev, int szint);
    virtual ~Karakter() = default; // virtuális destruktor

    std::string getNev() const; // getter a névhez
    int getSzint() const;     // getter a szinthez
     int getElet() const { return eletero(); }

    virtual int eletero() const = 0;
    virtual int sebzes() const = 0;
    virtual void kiir() const = 0;

    void tamad(Karakter* masik) const {
        int ujElet = masik->getElet() - this->sebzes();
        if (ujElet < 0) ujElet = 0;
    }
};



#endif
