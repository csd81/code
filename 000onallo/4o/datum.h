#ifndef DATUM_H
#define DATUM_H
namespace Naptar{

class Datum
{
	unsigned int ev, honap, nap;
public:
	Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap);
	Datum();
	unsigned int getEv() const;
	void setEv(unsigned int value);
	unsigned int getHonap() const;
	void setHonap(unsigned int value);
	unsigned int getNap() const;
	void setNap(unsigned int value);
    bool korabbi(const Datum& masik) const;
};
}
#endif // DATUM_H
