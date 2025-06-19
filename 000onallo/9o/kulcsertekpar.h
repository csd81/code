#ifndef KULCSERTEKPAR_H
#define KULCSERTEKPAR_H

template<typename KulcsTipus, typename ErtekTipus>
struct KulcsErtekPar
{    
    KulcsTipus kulcs;
    ErtekTipus ertek;
    KulcsErtekPar(){

    }
    KulcsErtekPar(KulcsTipus kulcs, ErtekTipus ertek) : kulcs(kulcs), ertek(ertek) {

    }
};

#endif // KULCSERTEKPAR_H
