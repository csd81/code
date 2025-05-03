#ifndef DATUMLISTA_H
#define DATUMLISTA_H

#include "datum.h"
#include <string>
#include <fstream>

using namespace std;

namespace Naptar {

class DatumLista
{
	unsigned int darab;
	Datum *datumok;
	string megjegyzes;
	static unsigned int maxDarab;
public:
	DatumLista(unsigned int darab, const string &megj);
	~DatumLista();
	DatumLista(const DatumLista &dl);

	string getMegjegyzes() const;
	void setMegjegyzes(const string &megj);
	const Datum &getDatum(unsigned int index) const;
	void setDatum(unsigned int index, const Datum &d);
	unsigned int getDarab() const;
	void hozzaad(const Datum &d);
	const Datum &legkorabbi() const;
	static unsigned int getMaxDarab();
	static void setMaxDarab(unsigned int newMaxDarab);
};

} // namespace Naptar

#endif // DATUMLISTA_H
