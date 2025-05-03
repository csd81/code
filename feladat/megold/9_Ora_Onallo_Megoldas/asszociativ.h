#ifndef ASSZOCIATIV_H
#define ASSZOCIATIV_H

#include "kulcsertekpar.h"

template <class KulcsTipus, class ErtekTipus>
class Asszociativ
{
	int tombMeret;
	KulcsErtekPar<KulcsTipus,ErtekTipus> *tomb;

	int keres(const KulcsTipus &kulcs) const
	{
		int i=0;
		while (i<tombMeret && tomb[i].kulcs!=kulcs) i++;
		return i;
	}

	void novel(); // plusz egy segéd függvény

public:
	Asszociativ():
		tombMeret(0),
		tomb(nullptr)
	{}

	~Asszociativ()
	{
		delete [] tomb;
	}

	int meret() const
	{
		return tombMeret;
	}

	void beallit(const KulcsTipus &kulcs, const ErtekTipus &ertek)
	{
		int index=keres(kulcs);
		if (index==tombMeret)
		{
			novel();
			tomb[index].kulcs=kulcs;
		}
		tomb[index].ertek=ertek;
	}

	KulcsTipus kulcsByIndex(int index) const
	{
		return tomb[index].kulcs;
	}

	ErtekTipus ertekByIndex(int index) const
	{
		return tomb[index].ertek;
	}

	bool vane(const KulcsTipus &kulcs) const
	{
		return keres(kulcs)!=tombMeret;
	}

	ErtekTipus ertek(const KulcsTipus &kulcs) const
	{
		int index=keres(kulcs);
		if (index==tombMeret) return ErtekTipus();
		else return tomb[index].ertek;
	}

	ErtekTipus ertekVagyDefault(const KulcsTipus &kulcs, const ErtekTipus &defErtek) const
	{
		int index=keres(kulcs);
		if (index==tombMeret) return defErtek;
		else return tomb[index].ertek;
	}

	void torol(const KulcsTipus &kulcs);

	ErtekTipus &operator [] (const KulcsTipus &kulcs);
};

template<class KulcsTipus, class ErtekTipus>
void Asszociativ<KulcsTipus,ErtekTipus>::novel()
{
	KulcsErtekPar<KulcsTipus,ErtekTipus> *uj=new KulcsErtekPar<KulcsTipus,ErtekTipus>[tombMeret+1];
	for (int i=0; i<tombMeret; i++)
		uj[i]=tomb[i];
	delete [] tomb;
	tomb=uj;
	tombMeret++;
}

template<class KulcsTipus, class ErtekTipus>
void Asszociativ<KulcsTipus,ErtekTipus>::torol(const KulcsTipus &kulcs)
{
	int index=keres(kulcs);
	if (index==tombMeret) return;

	if (tombMeret==1)
	{
		delete [] tomb;
		tomb=nullptr;
	}
	else
	{
		KulcsErtekPar<KulcsTipus,ErtekTipus> *uj=new KulcsErtekPar<KulcsTipus,ErtekTipus>[tombMeret-1];
		for (int i=0; i<index; i++)
			uj[i]=tomb[i];
		for (int i=index+1; i<tombMeret; i++)
			uj[i-1]=tomb[i];
		delete [] tomb;
		tomb=uj;
		tombMeret--;
	}
}

template<class KulcsTipus, class ErtekTipus>
ErtekTipus &Asszociativ<KulcsTipus,ErtekTipus>::operator [](const KulcsTipus &kulcs)
{
	int index=keres(kulcs);
	if (index==tombMeret)
	{
		novel();
		tomb[index].kulcs=kulcs;
		tomb[index].ertek=ErtekTipus();
	}
	return tomb[index].ertek;
}

#endif // ASSZOCIATIV_H
