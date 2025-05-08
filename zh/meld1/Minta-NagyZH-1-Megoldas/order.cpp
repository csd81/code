#include "order.h"

void Order::addProduct(const string &id, int quantity)
{
    ids.push_back(id);  // vector<string
    quantities.push_back(quantity); //vector<int>
}

size_t Order::getSize() const
{
    return ids.size(); // ==quantities.size();
}

const string &Order::getId(size_t index) const
{
    return ids[index];
}

int Order::getQuantity(size_t index) const
{
    return quantities[index];
}
