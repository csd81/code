#ifndef JARMU_H
#define JARMU_H

class Jarmu
{
    unsigned int tomeg, sebesseg;
public:
	Jarmu(unsigned int t, unsigned int s);
    virtual void kiir() const =0;
    virtual ~Jarmu() = default;
    virtual Jarmu *clone() const =0;
};

#endif // JARMU_H

/*
 *
 * void kiir() const        =>      0x321d3cf4
 * ~Jarmu()                 =>      0x5934bdd7
 *
 */
