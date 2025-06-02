#ifndef JARMU_H
#define JARMU_H

class Jarmu
{
	unsigned int tomeg, sebesseg;
public:
	Jarmu(unsigned int t, unsigned int s);
    virtual ~Jarmu();
    virtual void kiir() const = 0;
    virtual Jarmu* clone() const = 0;
};

#endif // JARMU_H
