#include "order.h"
#include <stdexcept>


Order Order::loadOrder(const string& filename)
{
    Order o;

    fstream in(filename);
    if (!in.is_open()){
        throw  std::logic_error("error");

    }

    json data;
    in >> data;

    for (unsigned int i=0; i<data.size(); i++){
        Order::Item item;
        item.name = data[i]["Name"];
        item.type = data[i]["Type"];
        item.quantity = data[i]["Quantity"];
        o.items.push_back(item);
    }

    return o;
}

ostream& operator<<(ostream& os, const Order& order)
{

    for (const auto& it : order.items)
    os << it.quantity << " * " << it.name << " "<< it.type <<"\n";

    return os;
}





