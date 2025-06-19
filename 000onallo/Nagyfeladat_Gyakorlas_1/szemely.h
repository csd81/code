#ifndef SZEMELY_H
#define SZEMELY_H
#include <iostream>

#include "utvonal.h"
using namespace std;

class Szemely {
  string nev;
  int eletkor;
  int maxhossz;
  int maxnehezseg;

 protected:
  string tipus = "";

 public:
  Szemely(const string &nev, int eletkor);
  virtual ~Szemely();
  Szemely(const Szemely &);

  Szemely &operator=(const Szemely &);

  virtual bool resztvehet(Utvonal &) const = 0;
  virtual void kiir() const = 0;
  string getTipus() const;
  int getMaxhossz() const;
  int getMaxnehezseg() const;
  void setMaxhossz(int newMaxhossz);
  void setMaxnehezseg(int newMaxnehezseg);

  virtual Szemely *clone() const = 0;
};

#endif  // SZEMELY_H
