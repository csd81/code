#include "store.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "product.h"
#include "chair.h"
#include "wardrobe.h"
#include "table.h"

using namespace std;

int Store::processingFee = 1000;  // 1000 ft


Store::Store()
{
}

Store::~Store()
{
    for (Product* p : products){
        delete p;
    }
}

void Store::loadStock(const std::string &filename)
{
    ifstream in(filename);
    nlohmann::json js;
    in >> js;
        for (auto& elem : js["Products"]) {
            Product* p = nullptr;
            std::string id = elem["Id"];
            std::string woodType = elem["WoodType"];
            int weight = elem["Weight"];
            int width = elem["Dimensions"]["Width"];
            int height =elem["Dimensions"]["Height"];
            int length =elem["Dimensions"]["Length"];
            int price = elem["Price"];

            if (elem["Type"] == "Chair"){
            std::string style = elem["Style"];
            p = new Chair(id, woodType, weight, width, height, length, price, style);
            } else    if (elem["Type"] == "Table"){
                int legCount = elem["LegCount"];
                bool legsAdjustable = elem["LegsAdjustable"];
                p = new Table(id, woodType, weight, width, height, length, price,
                              legCount, legsAdjustable);
            } else     if (elem["Type"] == "Wardrobe"){
                int doorCount = elem["DoorCount"];
                bool hasMirror = elem["HasMirror"];
                p = new Wardrobe(id, woodType, weight, width, height, length, price,
                                 doorCount, hasMirror);
            }
            products.push_back(p);
        }

        for (auto& elem : js["Stock"]) {
            std::string id = elem["ProductId"];
            int quantity = elem["Quantity"];

            bool found = false;
            for (unsigned i=0; i<products.size(); i++){
                if (products[i]->getId() == id){
                    quantities.push_back(quantity);
                    found = true;
                    break;
                    }
                    if (!found)
                    {quantities.push_back(0);
                    }
                }
        }
        in.close();
}

void Store::exportQuantities(const std::string &filename)
{
    nlohmann::json outStock = nlohmann::json::array();

     for (size_t i = 0; i < products.size(); ++i) {
        nlohmann::json item;
        item["ProductId"] = products[i]->getId();
        item["Quantity"] = quantities[i];
        outStock.push_back(item);
    }
    std::ofstream out(filename);
    if (out.is_open()) {
        out << outStock.dump(4);
        out.close();
    } else
        cout << "Error";

}

void Store::printProducts()
{
    for (Product* p : products){
        p->print();
    }

}

void Store::printStock()
{

    for (unsigned i=0; i<products.size(); i++){
        cout << quantities[i] << " ";
        products[i]->print();
        cout << endl;
    }



}


int Store::priceOfOrder(Order order)
{
    int sum = 0;
    std::vector<std::string> ids = order.getProductIds();
    std::vector<int> quantitiesOrdered = order.getQuantities();

    for (size_t i = 0; i < ids.size(); ++i) {
        std::string id = ids[i];
        int quantity = quantitiesOrdered[i];

        // Find product by ID
        for (unsigned j = 0; j < products.size(); ++j) {
            if (products[j]->getId() == id) {
                sum += quantity * products[j]->getPrice();
                break;
            }
        }
    }

    sum += processingFee;
    return sum;
}

Order Store::loadOrder(const std::string &filename)
{
    std::ifstream in(filename);
    nlohmann::json js;
    in >> js;

    Order order;

    for (const auto& item : js) {
        std::string id = item["ProductId"];
        int quantity = item["Quantity"];
        order.addItem(id, quantity);
    }

    return order;
}



bool Store::deliverOrder(Order order)
{
    std::vector<std::string> ids = order.getProductIds();
    std::vector<int> requestedQuantities = order.getQuantities();


    for (unsigned i = 0; i < ids.size(); ++i) {
        const std::string& id = ids[i];
        int requested = requestedQuantities[i];
        bool found = false;

        for (unsigned j = 0; j < products.size(); ++j) {
            if (products[j]->getId() == id) {
                found = true;
                if (quantities[j] < requested) {
                    return false;
                }
                break;
            }
        }

        if (!found) {
            return false;
        }
    }


    for (unsigned i = 0; i < ids.size(); ++i) {
        const std::string& id = ids[i];
        int requested = requestedQuantities[i];

        for (size_t j = 0; j < products.size(); ++j) {
            if (products[j]->getId() == id) {
                quantities[j] -= requested;
                break;
            }
        }
    }

    return true;
}


void Store::produce(std::string productId, int quantity)
{
    for (unsigned i=0; i<products.size(); i++){
        if (products[i]->getId() == productId )
            quantities[i] += quantity;
    }
}

void Store::setProcessingFee(int fee)
{
    processingFee = fee;
}
