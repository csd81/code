#ifndef TAROLO_H
#define TAROLO_H

namespace EpicToolbox {

class Tarolo
{
	unsigned int darab;
	int *tomb;
public:
	Tarolo(unsigned int db);
	Tarolo();
	~Tarolo();

	void kiir() const;
	void hozzaad(int ertek);
	double atlag() const;
	unsigned int darabLeker() const;
	int tartomany() const;
	void rendez(bool novekvo);
	void hozzafuz(const Tarolo &masik);
};

} // namespace EpicToolbox

#endif // TAROLO_H
