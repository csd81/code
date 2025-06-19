#ifndef SZAMMEZO_H
#define SZAMMEZO_H

#include "bevitelimezo.h"

class SzamMezo : public BeviteliMezo
{
    unsigned int ertek;
    static unsigned int maxertek;
public:
    SzamMezo(const string &megnevezes, bool szerkesztheto);

    unsigned int getErtek() const;
    void setErtek(unsigned int newErtek);
    bool megfelelo() const override;
    SzamMezo& operator=(int szam);
    static void setMaxertek(int newMaxertek);
    static int getMaxertek();
    void kiir(std::ostream& os) const override {
        os << ertek;
    }

};

#endif // SZAMMEZO_H
