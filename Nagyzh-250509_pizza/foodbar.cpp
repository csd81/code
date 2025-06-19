#include "foodbar.h"
#include "food.h"
#include "kebab.h"
#include "hamburger.h"
#include "pizza.h"



FoodBar::FoodBar(const string &filename)
{
    ifstream file(filename);
    json data;
    file >> data;
    for (size_t i=0; i<data.size(); i++){

    string n = data[i]["Name"];
    if (data[i]["Type"] == "kebab"){
        string s = data[i]["Sauce"];
        bool o = data[i]["Onion"];
        bool t = data[i]["Tomato"];
        bool f = data[i]["Feta"];
        Kebab *k =new Kebab(n,s,o,t,f);
        this->foods.push_back(k);

    }
    else if  (data[i]["Type"] == "burger"){
        string m = data[i]["MeatType"];
        int s = data[i]["MeatSize"];
        bool b = data[i]["Bacon"];
        bool c = data[i]["Cheese"];
        Hamburger *h =new Hamburger(n,m,s,b,c);
        this->foods.push_back(h);
    }
    else  if (data[i]["Type"] == "pizza"){
        json &toppings = data[i]["Toppings"];
        Pizza *p = new Pizza(n);
        for (size_t j=0; j<toppings.size(); j++){
            p->addTopping(toppings[j]);
        }
        this->foods.push_back(p);
    }

    }
}

FoodBar::~FoodBar()
{
    for (auto f : foods)
        delete f;
    foods.clear();

}

void FoodBar::printAll() const
{
    for (auto it : foods){
        it->print();
    }
}

void FoodBar::processOrder(Order o)
{
    cout << "Items in order:";
    int total = 0;
    for (const auto& item : o.items){
        for (const auto& f : foods)
            if (item.name == f->getName()){
                f->print();
                int itemTotal = item.quantity *f->price();
                cout << " => " << itemTotal << " Ft" << endl ;
                total += itemTotal;
            }
    }
    cout << "Total price: " << total << " Ft" << endl;

}


