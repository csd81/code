#include "barlangfeltaro.h"
#include <limits>

bool Barlangfeltaro::resztvehet(Utvonal &) const { return true; }

void Barlangfeltaro::kiir() const {
  Szemely::kiir();
  cout << "ev: " << ev << "barlangok: " << barlangok << endl;
}

Szemely *Barlangfeltaro::clone() const { return new Barlangfeltaro(*this); }

Barlangfeltaro::Barlangfeltaro(const string &nev, int eletkor, int ev,
                               int barlangok)
    : Szemely(nev, eletkor), ev(ev), barlangok(barlangok) {
  this->tipus = "B";
  this->setMaxhossz(std::numeric_limits<int>::max());
  this->setMaxnehezseg(std::numeric_limits<int>::max());
}
