// Sokszog gyerekosztály
// 23. Legyen egy Sokszog osztály a Halmaz osztályból származtatva, ami tetszőleges számú csúcsból álló sokszöglapot fog reprezentálni. Ne legyen saját adattagja. Legyen egy konstruktora, aminek ezúttal egy paramétere van: várja a megnevezést (string), ezt továbbítja az ősosztálynak. A ponthalmaz kezdetben üres.

// 24. *Legyen egy kerulet függvény a Sokszog osztályban, ami visszaadja a sokszög kerületét. A számítás módja ugyanaz, mint az Utvonal osztály hossz függvénye esetén, csak az első és utolsó pont távolságát is az összeghez kell adni.

// 25. *Legyen egy bennfoglalo függvény a Sokszog osztályban, ami nem vár paramétert, és egy minimális területű Teglalap objektumot ad vissza, ami tartalmazza a Sokszog-et.


#ifndef SOKSZOG_H
#define SOKSZOG_H

#include "halmaz.h"
#include "teglalap.h"

class Sokszog : public Halmaz
{
public:
    Sokszog(string megnevezes);
    double kerulet() const;
    Teglalap bennfoglalo() const;
};

#endif // SOKSZOG_H



// Sokszog gyerekosztály
// 23. Legyen egy Sokszog osztály a Halmaz osztályból származtatva, ami tetszőleges számú csúcsból álló sokszöglapot fog reprezentálni. Ne legyen saját adattagja. Legyen egy konstruktora, aminek ezúttal egy paramétere van: várja a megnevezést (string), ezt továbbítja az ősosztálynak. A ponthalmaz kezdetben üres.

// 24. *Legyen egy kerulet függvény a Sokszog osztályban, ami visszaadja a sokszög kerületét. A számítás módja ugyanaz, mint az Utvonal osztály hossz függvénye esetén, csak az első és utolsó pont távolságát is az összeghez kell adni.

// 25. *Legyen egy bennfoglalo függvény a Sokszog osztályban, ami nem vár paramétert, és egy minimális területű Teglalap objektumot ad vissza, ami tartalmazza a Sokszog-et.
 
