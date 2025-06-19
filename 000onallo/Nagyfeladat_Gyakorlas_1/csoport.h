#ifndef CSOPORT_H
#define CSOPORT_H
#include <iostream>
#include <vector>

#include "szemely.h"
using namespace std;

class Csoport {
  vector<Szemely*> szemelyek;

 public:
  Csoport();
  ~Csoport();
  void operator+=(Szemely*);
  Szemely* operator[](int);
  Csoport& operator=(Csoport& masik);

  bool alkalmas(Utvonal);
  void kiir();
  void maximum();
};

#endif  // CSOPORT_H
