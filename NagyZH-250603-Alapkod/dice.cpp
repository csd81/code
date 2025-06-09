#include "dice.h"

//
// Az osztaly kodja nem modosithato!
//

#include <random>
using namespace std;

mt19937 engine;

void Dice::seed(unsigned int newSeed)
{
    engine.seed(newSeed);
}

int Dice::roll()
{
    return engine()%6+1;
}
