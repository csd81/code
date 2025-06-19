#ifndef CSOMAG_H
#define CSOMAG_H

#include "alkatresz.h"

class Csomag : public Alkatresz {
    Alkatresz** alkatreszek;  // dinamikus tömb Alkatresz pointerekhez
    int maxDarab;             // a csomag kapacitása
    int aktualisDarab;        // eddig hozzáadott alkatrészek száma

public:
    // Konstruktor – csak a darabszámot kapja meg
    Csomag(int darab)
        : Alkatresz("", ""), maxDarab(darab), aktualisDarab(0)
    {
        alkatreszek = new Alkatresz*[maxDarab];
    }

    // Destruktor – csak a tömböt szabadítja fel, az objektumokat nem
    ~Csomag() override {
        delete[] alkatreszek;
    }

    // Hány darab van benne?
    int darabszam() const {
        return aktualisDarab;
    }

    // Beállít egy új alkatrészt a csomagba, ha van még hely
    void beallit(Alkatresz* a) {
        if (aktualisDarab < maxDarab) {
            alkatreszek[aktualisDarab++] = a;
        }
    }

    // Visszatér az összár 90%-ával
    int ar() const override {
        int osszeg = 0;
        for (int i = 0; i < aktualisDarab; ++i) {
            if (alkatreszek[i]) {
                osszeg += alkatreszek[i]->ar();
            }
        }
        return osszeg * 0.9;
    }

    // Opcionális: kiírhatjuk a tartalmát is, de nem kötelező
    void kiir() const override {
        cout << "Csomag tartalma:\n";
        for (int i = 0; i < aktualisDarab; ++i) {
            if (alkatreszek[i]) {
                alkatreszek[i]->kiir();
            }
        }
        cout << "Csomag ára (90%): " << ar() << endl;
    }
};

#endif // CSOMAG_H
