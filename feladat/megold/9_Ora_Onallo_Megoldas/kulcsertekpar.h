#ifndef KULCSERTEKPAR_H
#define KULCSERTEKPAR_H

template <class KulcsTipus, class ErtekTipus>
struct KulcsErtekPar
{
	KulcsTipus kulcs;
	ErtekTipus ertek;

	KulcsErtekPar(){}

	KulcsErtekPar(const KulcsTipus &_kulcs, const ErtekTipus &_ertek):
		kulcs(_kulcs),
		ertek(_ertek)
	{}
};

#endif // KULCSERTEKPAR_H
