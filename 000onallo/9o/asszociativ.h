#ifndef ASSZOCIATIV_H
#define ASSZOCIATIV_H
#include "kulcsertekpar.h"

template<typename KulcsTipus, typename ErtekTipus>
class Asszociativ
{
public:
    int darab;
    KulcsErtekPar<KulcsTipus,ErtekTipus> * tomb;

    Asszociativ() : darab(0), tomb(nullptr) {}

    Asszociativ(int d) : darab(d), tomb(nullptr) {}

    ~Asszociativ(){ delete [] tomb; }

    int meret() const{
        return darab;
    }

    int keres(KulcsTipus kulcs){
        for (int i=0; i<darab; i++){
            if(tomb[i].kulcs==kulcs)
                return i;
            }
        return darab;
    }

    void beallit(KulcsTipus k, ErtekTipus e){
    int index = keres(k);
        if (index!=darab){
            tomb[index].ertek=e;
        } else {
            auto* temp =  new KulcsErtekPar<KulcsTipus, ErtekTipus>[darab + 1];
            for (int i = 0; i < darab; ++i)
                temp[i] = tomb[i];
            temp[darab] = KulcsErtekPar<KulcsTipus, ErtekTipus>(k, e);
            delete[] tomb;
            tomb = temp;
            ++darab;
        }
    }

    KulcsTipus kulcsByIndex(int index) const{
    return tomb[index].kulcs;
    }

    ErtekTipus ertekByIndex(int index) const{
    return tomb[index].ertek;
    }

    bool vane(KulcsTipus k) const{
        bool vane=false;
                for (int i=0; i<darab; i++){
                if (tomb[i].kulcs==k)
                    vane=true;
                }
            return vane;

    }


    ErtekTipus ertek(KulcsTipus k) {
    int index = keres(k);
    if (index != darab)
        return tomb[index].ertek;
    return ErtekTipus(); // dummy érték
}


    ErtekTipus ertekVagyDefault(KulcsTipus k, ErtekTipus defErtek) {
    int index = keres(k);
    return index != darab ? tomb[index].ertek : defErtek;
}

    void torol(KulcsTipus k) {
    int index = keres(k);
    if (index == darab) return;
    auto* temp = new KulcsErtekPar<KulcsTipus, ErtekTipus>[darab - 1];
    for (int i = 0, j = 0; i < darab; ++i)
        if (i != index)
            temp[j++] = tomb[i];
    delete[] tomb;
    tomb = temp;
    --darab;
}

    ErtekTipus& operator[](KulcsTipus k) {
    int index = keres(k);
    if (index != darab)
        return tomb[index].ertek;

    auto* temp = new KulcsErtekPar<KulcsTipus, ErtekTipus>[darab + 1];
    for (int i = 0; i < darab; ++i)
        temp[i] = tomb[i];
    temp[darab] = KulcsErtekPar<KulcsTipus, ErtekTipus>(k, ErtekTipus());
    delete[] tomb;
    tomb = temp;
    ++darab;
    return tomb[darab - 1].ertek;
}




};



#endif // ASSZOCIATIV_H
