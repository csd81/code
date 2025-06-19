#ifndef TURAVEZETO_H
#define TURAVEZETO_H
#include <iostream>
using namespace std;

#include "szemely.h"

class Turavezeto : public Szemely {
 protected:
  int szint;
  int ev;

 public:
  Turavezeto(const string &nev, int eletkor, int szint, int ev);
  bool resztvehet(Utvonal &) const override;
  void kiir() const override;
  Szemely *clone() const override;
};

#endif  // TURAVEZETO_H
