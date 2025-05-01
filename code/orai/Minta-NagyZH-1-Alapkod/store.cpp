#include "store.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

#include "chair.h"
#include "table.h"
#include "wardrobe.h"

using namespace nlohmann;

Product *Store::findProductById(const string &id)
{
    for (unsigned i=0; i<products.size(); i++)
    {
        if (products[i]->getId() == id)
        {
            return products[i];
        }
    }
    return nullptr;
}

Store::~Store()
{
    for (unsigned i=0; i<products.size(); i++)
    {
        delete products[i];
    }
}

void Store::loadStock(const string &filename)
{
    ifstream input(filename);
    if (!input.is_open())
    {
        cout << "Cannot open " << filename << endl;
        return;
    }
    json data = json::parse(input);

    const json &productEntries = data["Products"];
    const json &stockEntries = data["Stock"];

    for (unsigned i=0; i<products.size(); i++)
    {
        delete products[i];
    }
    products.clear();

    for (unsigned i=0; i<productEntries.size(); i++)
    {
        string type = productEntries[i]["Type"];
        string id = productEntries[i]["Id"];
        string woodType = productEntries[i]["WoodType"];
        double weight = productEntries[i]["Weight"];
        int price = productEntries[i]["Price"];
        Dimensions dimensions{
            .width = productEntries[i]["Dimensions"]["Width"],
            .height = productEntries[i]["Dimensions"]["Height"],
            .length = productEntries[i]["Dimensions"]["Length"]
        };
        if (type == "Chair")
        {
            string style = productEntries[i]["Style"];
            products.push_back(new Chair(id, woodType, weight, dimensions, price, style));
        }
        else if (type == "Table")
        {
            int legCount = productEntries[i]["LegCount"];
            bool adjustable = productEntries[i]["LegsAdjustable"];
            products.push_back(new Table(id, woodType, weight, dimensions, price, legCount, adjustable));
        }
        else if (type == "Wardrobe")
        {
            int doorCount = productEntries[i]["DoorCount"];
            bool hasMirror = productEntries[i]["HasMirror"];
            products.push_back(new Wardrobe(id, woodType, weight, dimensions, price, doorCount, hasMirror));
        }
    }
    for (unsigned i=0; i<stockEntries.size(); i++)
    {
        string id = stockEntries[i]["ProductId"];
        int quantity = stockEntries[i]["Quantity"];
        Product *product = findProductById(id);
        if (product != nullptr)
        {
            product->setStockAmount(quantity);
        }
    }
}

void Store::printProducts() const
{
    for (unsigned i=0; i<products.size(); i++)
    {
        products[i]->printData();
        cout << endl;
    }
}

void Store::printStock() const
{
    for (unsigned i=0; i<products.size(); i++)
    {
        cout << products[i]->getStockAmount() << " X ";
        products[i]->printData();
        cout << endl;
    }
}
