#include "turazo.h"

bool Turazo::resztvehet(Utvonal &u) const {
  return (teherbiras >= u.getHossz() && ugyesseg >= u.getNehezseg());
}

void Turazo::kiir() const {
  Szemely::kiir();
  cout << "teherbiras: " << teherbiras << "ugyesseg: " << ugyesseg << endl;
}

int Turazo::getTeherbiras() const { return teherbiras; }

int Turazo::getUgyesseg() const { return ugyesseg; }

Szemely *Turazo::clone() const { return new Turazo(*this); }

Turazo::Turazo(const string &nev, int eletkor, int teherbiras, int ugyesseg)
    : Szemely(nev, eletkor), teherbiras(teherbiras), ugyesseg(ugyesseg) {
  this->tipus = "T";
  this->setMaxhossz(teherbiras);
  this->setMaxnehezseg(ugyesseg);
}
