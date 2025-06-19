#ifndef EGYEBALKATRESZ_H
#define EGYEBALKATRESZ_H

#include "alkatresz.h"

class EgyebAlkatresz : public Alkatresz
{   string leiras;
    int aar;
public:
    EgyebAlkatresz(const string &gyarto, const string &tipus, const string &leiras, int ar);

    string getLeiras() const;
    int ar() const override;
    void kiir() const override;
};

#endif // EGYEBALKATRESZ_H
