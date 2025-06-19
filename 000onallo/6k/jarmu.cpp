#include "jarmu.h"

#include <iostream>

using namespace std;

unsigned int Jarmu::getTomeg() const
{
    return tomeg;
}

void Jarmu::setTomeg(unsigned int newTomeg)
{
    tomeg = newTomeg;
}

unsigned int Jarmu::getSebesseg() const
{
    return sebesseg;
}

void Jarmu::setSebesseg(unsigned int newSebesseg)
{
    sebesseg = newSebesseg;
}

Jarmu::Jarmu(unsigned int t, unsigned int s):
	tomeg(t),
	sebesseg(s)
{
}

Jarmu::~Jarmu()
{

}

void Jarmu::kiir() const
{
	cout << "tomeg: " << tomeg << ", sebesseg: " << sebesseg << endl;
}
