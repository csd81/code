#include "karakter.h"

class Ijasz : public Karakter {
private:
    int pontossag; // az íjász célzásának pontossága
public:
    // Konstruktor, ami beállítja a nevet, szintet és pontosságot
    Ijasz(const std::string& _nev, int _szint, int _pontossag);


    int eletero() const override;

    int sebzes() const override;

    void kiir() const override;
};
    
