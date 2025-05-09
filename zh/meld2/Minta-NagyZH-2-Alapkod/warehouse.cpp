#include "warehouse.h"

#include <fstream>
#include <stdexcept>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

#include "btoy.h"
#include "bclothes.h"
#include "bchair.h"

Warehouse::~Warehouse()
{
    for (size_t i=0; i<products.size(); i++)
        delete products[i];
}

void Warehouse::loadProducts(const string &type, const string  &filePath)
{
    ifstream in(filePath);
    if (!in.is_open())
        throw runtime_error("e!");

    json root = json::parse(in);
    for (size_t i=0; i<root.size(); i++)
    {
        json& product = root[i];
        string  id = product["Id"];
        string  name = product["Name"];
        int  price = product["Price"];
        int  quantity = product["Quantity"];
        BProduct* p = nullptr;

        if (type == "toy")
        {
            int age = product["Age"];
            p = new BToy(id, name, price, quantity, age);
        }
        else if (type == "clothes")
        {
            string size = product["Size"];
            p = new BClothes(id, name, price, quantity, size);
        }
        else if (type == "chair")
        {
            bool canBeSet = product["CanBeSet"];
            p = new BChair(id, name, price, quantity,canBeSet);
        }
        products.push_back(p);

    }
}





void Warehouse::saveProducts(const string &type,
                             const string &filePath) const
{
    json root;
    for (size_t i=0;i<products.size();i++)
    {
        if (products[i]->type() == type)
        {
            json product;
            product["Id"] = products[i]->getId();
            product["Name"] = products[i]->getName();
            product["Price"] = products[i]->getPrice();
            product["Quantity"] = products[i]->getQuantity();
        {
            BToy* p = dynamic_cast<BToy*>(products[i]);
            if (p)
            product["Age"] = p->getAge();
        }
        {
            BClothes* p = dynamic_cast<BClothes*>(products[i]);
            if (p)
                product["Size"] = p->getSize();
        }
        {
            BChair * p = dynamic_cast<BChair*>(products[i]);
            if (p)
                product["CanBeSet"] = p->getCanBeSet();
        }
        root.push_back(product);
    }
    ofstream out(filePath);
    if (!out.is_open())
        throw runtime_error("!");
    out << root.dump(4) << endl;
}












































