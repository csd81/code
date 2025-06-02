#ifndef ASSZOCIATIV_H
#define ASSZOCIATIV_H

#include "kulcsertekpar.h"
#include <cstddef>

template<typename K, typename V>
class Asszociativ
{
private:
    KulcsErtekPar<K, V>* tomb;
    int db;

    int keres(const K& kulcs) const {
        for (int i=0; i<db; i++){
            if (tomb[i].kulcs == kulcs)
                return i;
        }
        return -1;
    }
    void ujraFoglal(int ujMeret){
        KulcsErtekPar<K,V>*  ujTomb = new KulcsErtekPar<K,V>[ujMeret];
        for (int i=0; i<db; i++)
            ujTomb[i]    = tomb[i]    ;
        delete[]  tomb;
        tomb = ujTomb;
    }

public:
    Asszociativ() : tomb(nullptr), db(0) {}
    ~Asszociativ(){
        delete[] tomb;
    }

    int meret() const{
        return db;
    }

    void beallit(const K& kulcs, const V& ertek){
        int i = keres(kulcs);
        if (i!=-1)
            tomb[i].ertek =  ertek;
        else {
            ujraFoglal(db+1);
            tomb[db++] = KulcsErtekPar<K,V>(kulcs, ertek);
        }
    }
    K kulcsByIndex(int index) const {
        return tomb[index].kulcs;
    }

    V ertekByIndex(int index) const{
        return tomb[index].ertek;
    }

    bool vane(const K& kulcs) const{
        return keres(kulcs) != -1;

    }

    V ertek(const K& kulcs) const{
        int i = keres(kulcs);
        if (i != -1)
            return tomb[i].ertek;
        return V();
    }

    V ertekVagyDefault(const K& kulcs, const V& def) const {
        int i = keres(kulcs);
        if (i != -1)
            return tomb[i].ertek;
        return def;
    }

    void torol(const K& kulcs){
        int i = keres(kulcs);
        if (i == -1)
            return;
        for (int j = i + 1; j < db; ++j)
            tomb[j - 1] = tomb[j];
        ujraFoglal(db - 1);
        --db;

    }

    V& operator[](const K& kulcs) {
        int i = keres(kulcs);
        if (i != -1)
            return tomb[i].ertek;
        ujraFoglal(db + 1);
        tomb[db] = KulcsErtekPar<K, V>(kulcs, V());

        return tomb[db++].ertek;


    }
};

#endif // ASSZOCIATIV_H
