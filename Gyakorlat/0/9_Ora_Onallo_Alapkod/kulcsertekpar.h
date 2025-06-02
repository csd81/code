#ifndef KULCSERTEKPAR_H
#define KULCSERTEKPAR_H

template<typename K, typename V>
struct KulcsErtekPar {
    K kulcs;
    V ertek;

    KulcsErtekPar() : kulcs(), ertek() {}
    KulcsErtekPar(const K& k, const V& e) : kulcs(k), ertek(e) {}
};

#endif // KULCSERTEKPAR_H
