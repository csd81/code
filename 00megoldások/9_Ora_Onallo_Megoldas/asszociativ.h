#ifndef ASSZOCIATIV_H
#define ASSZOCIATIV_H

#include "kulcsertekpar.h"

// Asszociativ osztaly: kulcs-ertek parokat tarol dinamikusan, a tomb merete novelodik ha uj par kerul be
// Sablonos osztaly, ket parameterrel: KulcsTipus es ErtekTipus

// Megvalositja: beallit(), kulcsByIndex(), ertekByIndex(), vane(), ertek(), ertekVagyDefault(), torol(), operator[]
// Segedfuggveny: keres() - index visszateres a kulcs alapjan; novel() - tomb meretenek novelese

template <class KulcsTipus, class ErtekTipus>
class Asszociativ {
    int tombMeret; // kulcs-ertek parok szama
    KulcsErtekPar<KulcsTipus, ErtekTipus>* tomb; // dinamikus tomb

    // PRIVAT keres() fuggveny: megkeresi egy kulcs indexet, vagy tombMeret-et ad vissza, ha nem letezik
    int keres(const KulcsTipus &kulcs) const {
        int i = 0;
        while (i < tombMeret && tomb[i].kulcs != kulcs) i++;
        return i;
    }

    // PRIVAT novel() segedfuggveny: egy elemmel nagyobb tomb letrehozasa es masolas
    void novel();

public:
    // Konstruktor: ures tomb es nulla meret
    Asszociativ() : tombMeret(0), tomb(nullptr) {}

    // Destruktor: dinamikus tomb felszabaditasa
    ~Asszociativ() {
        delete[] tomb;
    }

    // meret(): visszaadja a tarolt elemek szamat
    int meret() const {
        return tombMeret;
    }

    // beallit(): uj kulcs-ertek par hozzaadasa vagy meglevo atallitasa
    void beallit(const KulcsTipus &kulcs, const ErtekTipus &ertek) {
        int index = keres(kulcs);
        if (index == tombMeret) { // uj kulcs
            novel();
            tomb[index].kulcs = kulcs;
        }
        tomb[index].ertek = ertek;
    }

    // kulcsByIndex(): visszaadja az index-hez tartozo kulcsot (nincs index ellenorzes!)
    KulcsTipus kulcsByIndex(int index) const {
        return tomb[index].kulcs;
    }

    // ertekByIndex(): visszaadja az index-hez tartozo erteket (nincs index ellenorzes!)
    ErtekTipus ertekByIndex(int index) const {
        return tomb[index].ertek;
    }

    // vane(): visszater, hogy egy kulcs szerepel-e a taroloban
    bool vane(const KulcsTipus &kulcs) const {
        return keres(kulcs) != tombMeret;
    }

    // ertek(): visszaadja a kulcshoz tartozo erteket, vagy dummy (default) erteket, ha nincs
    ErtekTipus ertek(const KulcsTipus &kulcs) const {
        int index = keres(kulcs);
        if (index == tombMeret) return ErtekTipus();
        else return tomb[index].ertek;
    }

    // ertekVagyDefault(): visszaadja az erteket, ha van, kulonben az alapertelmezett erteket
    ErtekTipus ertekVagyDefault(const KulcsTipus &kulcs, const ErtekTipus &defErtek) const {
        int index = keres(kulcs);
        if (index == tombMeret) return defErtek;
        else return tomb[index].ertek;
    }

    // torol(): egy kulcs-ertek par torlese ha letezik, egyebkent nem csinal semmit
    void torol(const KulcsTipus &kulcs);

    // operator[]: referenciaval visszaadott ertek, uj kulcs eseten letrehozza dummy ertekkel
    ErtekTipus &operator[](const KulcsTipus &kulcs);
};

// novel(): egy elemmel nagyobb tomb letrehozasa, meglevo adatok atmasolasa
template<class KulcsTipus, class ErtekTipus>
void Asszociativ<KulcsTipus, ErtekTipus>::novel() {
    auto* uj = new KulcsErtekPar<KulcsTipus, ErtekTipus>[tombMeret + 1];
    for (int i = 0; i < tombMeret; i++)
        uj[i] = tomb[i];
    delete[] tomb;
    tomb = uj;
    tombMeret++;
}

// torol(): kulcs torlese es a tomb egy elemmel valo csokkentese
template<class KulcsTipus, class ErtekTipus>
void Asszociativ<KulcsTipus, ErtekTipus>::torol(const KulcsTipus &kulcs) {
    int index = keres(kulcs);
    if (index == tombMeret) return; // nincs ilyen kulcs

    if (tombMeret == 1) {
        delete[] tomb;
        tomb = nullptr;
    } else {
        auto* uj = new KulcsErtekPar<KulcsTipus, ErtekTipus>[tombMeret - 1];
        for (int i = 0; i < index; i++) uj[i] = tomb[i];
        for (int i = index + 1; i < tombMeret; i++) uj[i - 1] = tomb[i];
        delete[] tomb;
        tomb = uj;
    }
    tombMeret--;
}

// operator[]: uj kulcs eseten letrehozza dummy ertekkel, visszater referenciaval az ertekre
template<class KulcsTipus, class ErtekTipus>
ErtekTipus &Asszociativ<KulcsTipus, ErtekTipus>::operator[](const KulcsTipus &kulcs) {
    int index = keres(kulcs);
    if (index == tombMeret) {
        novel();
        tomb[index].kulcs = kulcs;
        tomb[index].ertek = ErtekTipus();
    }
    return tomb[index].ertek;
}

#endif // ASSZOCIATIV_H
