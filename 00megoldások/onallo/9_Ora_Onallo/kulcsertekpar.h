#ifndef KULCSERTEKPAR_H
#define KULCSERTEKPAR_H

// KulcsErtekPar struktura:
// Ket adatot tarol: egy kulcsot es egy hozza tartozo erteket.
// A strukturaban az adattagok publikusak, hogy konnyen elerhetok legyenek.
// A ket tag tipusai sablon parametereken keresztul szabadon valaszthatoak.

// A specifikacio szerint legyen:
// - parameter nelkuli konstruktor
// - parameteres konstruktor, ami mindket adattagot beallitja

template <class KulcsTipus, class ErtekTipus>
struct KulcsErtekPar {
    KulcsTipus kulcs; // kulcs adattag
    ErtekTipus ertek; // ertek adattag

    // parameter nelkuli konstruktor
    KulcsErtekPar() {}

    // parameteres konstruktor: mindket adattagot beallitja
    KulcsErtekPar(const KulcsTipus &_kulcs, const ErtekTipus &_ertek) :
        kulcs(_kulcs),
        ertek(_ertek)
    {}
};

#endif // KULCSERTEKPAR_H
