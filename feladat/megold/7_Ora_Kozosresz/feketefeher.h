#ifndef FEKETEFEHER_H
#define FEKETEFEHER_H

#include "szin.h"

class FeketeFeher : public Szin
{
	bool fekete;
public:
	FeketeFeher(bool fekete);
	virtual unsigned char R() const;
	virtual unsigned char G() const;
	virtual unsigned char B() const;
};

#endif // FEKETEFEHER_H
