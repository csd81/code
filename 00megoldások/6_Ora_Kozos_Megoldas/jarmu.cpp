#include "jarmu.h"

#include <iostream>

using namespace std;

// A konstruktor mindkét értéket várja (tomeg, sebesseg)
Jarmu::Jarmu(unsigned int t, unsigned int s):
    tomeg(t),
    sebesseg(s)
{
}

// Virtuális destruktor - a gyermek osztályok objektumai helyesen törlődjenek.
Jarmu::~Jarmu()
{
}
