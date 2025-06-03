#include "karakter.h"

class Magus : public Karakter {
private:
    int mana; // a mágus varázsláshoz rendelkezésre álló mana mennyisége
public:
    // Konstruktor, ami beállítja a nevet, szintet és manát
    Magus(const std::string& _nev, int _szint, int _mana);


    int eletero() const override;
    int sebzes() const override;
    void kiir() const override;
};
