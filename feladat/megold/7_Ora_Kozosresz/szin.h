#ifndef SZIN_H
#define SZIN_H

#include <string>

using namespace std;

class Szin
{
public:
	virtual ~Szin() = default;

	virtual unsigned char R() const = 0;
	virtual unsigned char G() const = 0;
	virtual unsigned char B() const = 0;
};

#endif // SZIN_H
