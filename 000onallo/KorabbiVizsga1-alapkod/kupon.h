#ifndef KUPON_H
#define KUPON_H

#include "alkatresz.h"  // Feltételezzük, hogy ez tartalmazza az Alkatresz ősosztályt

template <typename T>
class Kupon {
    int kedvezmeny;

public:
    // Konstruktor
    Kupon(int kedvezmeny) : kedvezmeny(kedvezmeny) {}

    // Getter
    int getKedvezmeny() const {
        return kedvezmeny;
    }

    int alkalmaz(Alkatresz* a) const{
        T* cel = dynamic_cast<T*>(a);
        if (cel != nullptr){
            int eredetiAr = cel->ar();
            int ujAr = eredetiAr - kedvezmeny;
            return (ujAr >= 0 ? ujAr : 0);
        } else {
            return a->ar();
        }
    }
};

#endif // KUPON_H
