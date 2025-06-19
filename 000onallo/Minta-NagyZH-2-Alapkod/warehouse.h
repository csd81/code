#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "shipment.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
using namespace std;
using namespace nlohmann;


#include "babyproduct.h"
class Warehouse
{
vector <BabyProduct*> products;
public:
    Warehouse();
    ~Warehouse();
    void loadProducts(const string& type, const string& filename);

    bool makeOrder(const string& id, int quantity, int& cash);


    vector<BabyProduct *> getProducts() const;



    vector<BabyProduct*> getProducts(const string& type);


    template<class T>
    vector<T *> getSpecificProducts(int minp, int maxp){
                vector<T *> filtered;
            for (BabyProduct* b : products)
            {
                T* casted = dynamic_cast<T*>(b);
                if (casted && casted->getPrice() >= minp && casted->getPrice() <= maxp ){
                    filtered.push_back(casted);
                }
            }
        return filtered;
    }

    void deliverShipment(Shipment& s);

    void saveProducts(const string& type, const string& filename);

};

#endif // WAREHOUSE_H
