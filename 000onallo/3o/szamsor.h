#ifndef SZAMSOR_H
#define SZAMSOR_H

class Szamsor
{
	unsigned int darab;
	int *tomb;

public:
	Szamsor(unsigned int db);
    Szamsor(const Szamsor &masik);
    Szamsor& operator=(const Szamsor& other);
	~Szamsor();

	unsigned int getDarab() const;
    int getErtek(unsigned int index) const;
	void setErtek(unsigned int index, int ertek);
    double atlag() const;
};

#endif // SZAMSOR_H
