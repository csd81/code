#ifndef SZAMOK_H
#define SZAMOK_H

namespace Tarolo {

class Szamok
{
	unsigned int darab;
	double *tomb;
public:
	Szamok(unsigned int db, double def=0);
	~Szamok();

	unsigned int darabLeker() const;

	void ertekBeallit(unsigned int index, double ertek);
	double ertekLeker(unsigned int index) const;
};

} // namespace Tarolo

#endif // SZAMOK_H
