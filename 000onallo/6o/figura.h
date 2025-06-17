#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;

class Figura
{
protected:
	string pozicio;
public:
	Figura(const string &pos);
    virtual ~Figura() {}

    Figura(const Figura& masik);
    Figura& operator=(const Figura& masik);

    const string &getPozicio() const;
    static bool ervenyes(const string& pos);

    bool odalep(const string& pos);
    virtual bool lephet(const string &pos) const = 0;
    virtual char jeloles() const = 0;
};

#endif // FIGURA_H
