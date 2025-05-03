#ifndef TAROLO_H
#define TAROLO_H

#include "jarmu.h"

#define TAROLO_KAPACITAS 5

class Tarolo
{
	Jarmu *tomb[TAROLO_KAPACITAS];
public:
	Tarolo();
    Tarolo(const Tarolo& masik);
	~Tarolo();
	void beallit(unsigned int index, Jarmu *j);
	void megjelenit() const;

};

#endif // TAROLO_H
