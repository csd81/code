#ifndef JARMU_H
#define JARMU_H

class Jarmu
{
protected:
    unsigned int tomeg;
    unsigned int sebesseg;
public:
	Jarmu(unsigned int t, unsigned int s);
    virtual ~Jarmu() = default;
    int getSebesseg() const;
    int getTomeg() const;
    virtual void kiir() const = 0;

};

#endif // JARMU_H
