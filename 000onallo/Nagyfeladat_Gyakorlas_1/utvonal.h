#ifndef UTVONAL_H
#define UTVONAL_H
#include <iostream>
using namespace std;

class Utvonal {
  string megnevezes;
  int hossz;
  int nehezseg;

 public:
  Utvonal(const string& megnevezes, int hossz, int nehezseg);
  friend ostream& operator<<(ostream&, Utvonal&);

  string getMegnevezes() const;
  int getHossz() const;
  int getNehezseg() const;
};

#endif  // UTVONAL_H
