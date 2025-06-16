//
// Created by d on 6/16/25.
//

#ifndef TAROLO_H
#define TAROLO_H


namespace EpicToolbox{


class Tarolo {
    int db;
    int * szamok;
public:

    Tarolo();
    Tarolo(int db);
    ~Tarolo();
    Tarolo(const Tarolo &masik);
    Tarolo& operator=(const Tarolo &masik);

    void kiir() const;
    void hozzaad(int);
    double atlag() const;
    int tartomany() const;
    void rendez(bool incr);
    Tarolo& hozzafuz(const Tarolo & t);
    int darabLeker() const;

};



} // EpicToolbox


#endif //TAROLO_H
