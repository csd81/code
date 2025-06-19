#include "utvonal.h"

int Utvonal::getHossz() const { return hossz; }

int Utvonal::getNehezseg() const { return nehezseg; }

string Utvonal::getMegnevezes() const { return megnevezes; }

Utvonal::Utvonal(const string &megnevezes, int hossz, int nehezseg)
    : megnevezes(megnevezes), hossz(hossz), nehezseg(nehezseg) {}

ostream &operator<<(ostream &os, Utvonal &u) {
  os << "megnevezés: " << u.megnevezes << " " << "hossz: " << u.hossz << " "
     << "nehézség: " << u.nehezseg << endl;
  return os;
}
