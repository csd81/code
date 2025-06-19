#include "shipment.h"

vector<Shipment::Item> Shipment::getItems() const
{
    return items;
}

Shipment::Shipment(const string &filename) {

    ifstream ifs(filename);
    json data;

    ifs >> data;


    for(size_t i=0; i<data.size(); i++){
        Item singleitem;
        singleitem.productid=data["ShipmentItems"][i]["ProductId"];
        singleitem.quantity=data["ShipmentItems"][i]["Quantity"];
        items.push_back(singleitem);
    }


}
