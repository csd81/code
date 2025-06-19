#ifndef TURAZO_H
#define TURAZO_H
#include <iostream>
using namespace std;

#include "szemely.h"

class Turazo : public Szemely {
 protected:
  int teherbiras;
  int ugyesseg;

 public:
  Turazo(const string &nev, int eletkor, int teherbiras, int ugyesseg);

  bool resztvehet(Utvonal &) const override;
  void kiir() const override;

  string getTipus() const;
  int getTeherbiras() const;
  int getUgyesseg() const;
  Szemely *clone() const override;
};

#endif  // TURAZO_H
