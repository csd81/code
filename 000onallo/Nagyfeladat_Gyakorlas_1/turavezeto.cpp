#include "turavezeto.h"

bool Turavezeto::resztvehet(Utvonal &u) const {
  if (ev >= 10)
    return (szint + 1 >= u.getNehezseg());
  else
    return (szint >= u.getNehezseg());
}

void Turavezeto::kiir() const {
  Szemely::kiir();
  cout << "szint: " << szint << "ev: " << ev << endl;
}

Szemely *Turavezeto::clone() const { return new Turavezeto(*this); }

Turavezeto::Turavezeto(const string &nev, int eletkor, int szint, int ev)
    : Szemely(nev, eletkor), szint(szint), ev(ev) {
  this->tipus = "V";
  this->setMaxhossz(1000000000);
  if (ev >= 10)
    this->setMaxnehezseg(szint - 1);
  else
    this->setMaxnehezseg(szint);
}
