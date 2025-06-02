

#include <iostream>
#include "foodbar.h"
#include "pizza.h"
#include "order.h"

using namespace std;

#define PART1  // Etelek adatszerkezete
#define PART2  // FoodBar, betoltes
#define PART3  // printAll()
#define PART4  // printAll() arakkal
#define PART5  // Order, loadOrder
#define PART6  // processOrder()
#define PART7  // Premium feltetek
#define PART8  // Premium feltetek szamolasa az arba
#define PART9  // << operator


int main()
{
    cout << "Main eleje" << endl << endl;

#if defined(PART1) && defined(PART2)
    cout << endl << "Loading menu..." << endl;
    FoodBar foodbar("foods.json");
#endif

#if defined(PART3) || defined(PART4)
    cout << endl << "Menu:" << endl;
    foodbar.printAll();
#endif

#ifdef PART5
    cout << endl << "Loading orders..." << endl;
    Order order1 = Order::loadOrder("order1.json");
    Order order2 = Order::loadOrder("order2.json");
    Order order3 = Order::loadOrder("order3.json");
#endif

#ifdef PART6
    cout << endl << "Processing orders..." << endl;
    foodbar.processOrder(order1);
    cout << endl;
    foodbar.processOrder(order2);
    cout << endl;
    foodbar.processOrder(order3);
#endif

#ifdef PART7
    cout << endl << "Setting premium toppings" << endl;
    Pizza::addPremiumTopping("bacon");
    Pizza::addPremiumTopping("juhturo");
    Pizza::addPremiumTopping("feta sajt");
#ifdef PART8
    cout << endl << "Menu with new prices" << endl;
    foodbar.printAll();
#endif
    Pizza::clearPremiumToppings();
#endif

#ifdef PART9
    cout << endl << "<< operator" << endl;
    cout << "Order1:" << endl << order1 << endl;
    cout << "Order2:" << endl << order2 << endl;
    cout << "Order3:" << endl << order3 << endl;
#endif


    cout << endl << "main() vege!" << endl;

    return 0;
}
