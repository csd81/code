#ifndef SZEMELY_H
#define SZEMELY_H

#include <string>



class Szemely
{
    std::string vnev, knev;
	unsigned int eletkor;
public:
    Szemely(const std::string &v, const std::string &k, unsigned int kor);
    const std::string &getVezetekNev() const;
    const std::string &getKeresztNev() const;
    std::string teljesNev() const;
	unsigned int getEletkor() const;
	void kiir() const;
    bool fiatalabb(const Szemely&) const;
};

#endif // SZEMELY_H
