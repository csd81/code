#ifndef BARLANGFELTARO_H
#define BARLANGFELTARO_H
#include <iostream>
using namespace std;

#include "szemely.h"

class Barlangfeltaro : public Szemely {
  int ev;
  int barlangok;

 public:
  Barlangfeltaro(const string &nev, int eletkor, int ev, int barlangok);

  bool resztvehet(Utvonal &) const override;
  void kiir() const override;

  Szemely *clone() const override;
};

#endif  // BARLANGFELTARO_H
