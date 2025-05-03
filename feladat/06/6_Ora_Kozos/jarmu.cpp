#include "jarmu.h"

#include <iostream>

using namespace std;

Jarmu::Jarmu(unsigned int t, unsigned int s):
	tomeg(t),
	sebesseg(s)
{
}

Jarmu::~Jarmu(){

};


int Jarmu::getSebesseg() const{
    return tomeg;
};
int Jarmu::getTomeg() const{
    return sebesseg;
};

void Jarmu::kiir() const
{
	cout << "tomeg: " << tomeg << ", sebesseg: " << sebesseg << endl;
}
