#ifndef BEVITELIMEZO_H
#define BEVITELIMEZO_H
#include<iostream>
using namespace std;

class BeviteliMezo
{

    string megnevezes;
    bool szerkesztheto;
public:
BeviteliMezo(const string &megnevezes, bool szerkesztheto);
virtual ~BeviteliMezo();

string getMegnevezes() const;
bool getSzerkesztheto() const;
void setSzerkesztheto(bool newSzerkesztheto);


virtual bool megfelelo() const = 0;
virtual void kiir(std::ostream& os) const = 0;

};

#endif // BEVITELIMEZO_H
