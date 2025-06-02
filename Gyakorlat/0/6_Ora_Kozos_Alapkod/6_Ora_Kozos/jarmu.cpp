#include "jarmu.h"

#include <iostream>

using namespace std;

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
