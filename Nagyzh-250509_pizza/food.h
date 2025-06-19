#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <vector>
using namespace std;


class Food
{
    string name;
    string type;
public:

    Food(const string &name, const string &type);
    virtual ~Food();
    virtual void print() const = 0;
    virtual int price() const = 0;
    string getName() const;
};

#endif // FOOD_H
