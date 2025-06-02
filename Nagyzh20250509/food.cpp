#include "food.h"



string Food::getName() const
{
    return name;
}

Food::Food(const string &name, const string &type) : name(name), type(type)
{}

