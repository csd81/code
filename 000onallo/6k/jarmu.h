#ifndef JARMU_H
#define JARMU_H
#include <iostream>
class Jarmu
{
	unsigned int tomeg, sebesseg;
public:
	Jarmu(unsigned int t, unsigned int s);
    virtual ~Jarmu();
    virtual void kiir() const = 0;
    virtual Jarmu* clone() const = 0;

    unsigned int getTomeg() const;
    void setTomeg(unsigned int newTomeg);
    unsigned int getSebesseg() const;
    void setSebesseg(unsigned int newSebesseg);
};

#endif // JARMU_H
