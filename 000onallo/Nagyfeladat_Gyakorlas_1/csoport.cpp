#include "csoport.h"
#include <limits>
#include "turazo.h"

Csoport::Csoport() {}

Csoport::~Csoport() {
  for (auto sz : szemelyek) delete sz;
  szemelyek.clear();
}

void Csoport::operator+=(Szemely *sz) { szemelyek.push_back(sz); }

Szemely *Csoport::operator[](int i) {
  if (i >= 0 && (size_t)i < szemelyek.size())
    return szemelyek[i];
  else
    return nullptr;
}

Csoport &Csoport::operator=(Csoport &masik) {
  if (&masik != this) {
    for (auto sz : szemelyek) delete sz;
    szemelyek.clear();

    for (auto sz : masik.szemelyek) szemelyek.push_back(sz->clone());
  }
  return *this;
}

bool Csoport::alkalmas(Utvonal u) {
  if (szemelyek.size() == 1 &&
      (szemelyek[0]->getTipus() == "B" || szemelyek[0]->getTipus() == "V") &&
      szemelyek[0]->resztvehet(u))
    return true;

  for (auto sz : szemelyek) {
    if (sz->resztvehet(u) == false) return false;
  }

  int vezetok = 0;
  int turazok = 0;

  for (auto sz : szemelyek) {
    if (sz->getTipus() == "B" || sz->getTipus() == "V") vezetok++;

    if (sz->getTipus() == "T") turazok++;
  }
  if (vezetok == 0) return false;
  if (turazok / vezetok <= 5)
    return true;
  else
    return false;
}

void Csoport::kiir() {
  for (auto sz : szemelyek) {
    sz->kiir();
  }
}

void Csoport::maximum() {
  int maxhossz = std::numeric_limits<int>::max();
  int maxnehezseg = std::numeric_limits<int>::max();

  for (auto sz : szemelyek) {
    if (sz->getTipus() == "T") {
      if (sz->getMaxnehezseg() < maxnehezseg)
        maxnehezseg = sz->getMaxnehezseg();
      if (sz->getMaxhossz() < maxhossz) maxhossz = sz->getMaxhossz();
    }
  }

  cout << "maxhossz: " << maxhossz << "maxnehezseg: " << maxnehezseg << endl;
}
