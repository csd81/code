#include "karakter.h"
#include <iostream>

class Harcos : public Karakter {
private:
    std::string fegyver;
public:

    Harcos(const std::string& _nev, int _szint, const std::string& _fegyver);

    int eletero() const override;
    int sebzes() const override;
    void kiir() const override;
};
