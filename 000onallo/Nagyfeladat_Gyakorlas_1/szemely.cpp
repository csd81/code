#include "szemely.h"

string Szemely::getTipus() const { return tipus; }

int Szemely::getMaxhossz() const { return maxhossz; }

int Szemely::getMaxnehezseg() const { return maxnehezseg; }

void Szemely::setMaxhossz(int newMaxhossz) { maxhossz = newMaxhossz; }

void Szemely::setMaxnehezseg(int newMaxnehezseg) {
  maxnehezseg = newMaxnehezseg;
}

Szemely::Szemely(const string &nev, int eletkor) : nev(nev), eletkor(eletkor) {}
Szemely::~Szemely() {}
Szemely::Szemely(const Szemely &other)
    : nev(other.nev), eletkor(other.eletkor) {}

Szemely &Szemely::operator=(const Szemely &other) {
  if (this != &other) {
    this->nev = other.nev;
    this->eletkor = other.eletkor;
  }
  return *this;
}

void Szemely::kiir() const {
  cout << "név: " << nev << "életkor: " << eletkor << endl;
}
