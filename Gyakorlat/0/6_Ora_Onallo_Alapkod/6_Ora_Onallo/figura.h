#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;

class Figura
{
	string pozicio;
public:
	Figura(const string &pos);
    virtual ~Figura();
	const string &getPozicio() const;
    static bool ervenyes(string pozicio);
    virtual bool lephet(string pozicio) const = 0;
    bool odalep(string pozicio);
    virtual char jeloles() const = 0;
};

#endif // FIGURA_H
