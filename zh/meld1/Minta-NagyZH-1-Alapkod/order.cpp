#include "order.h"

Order::Order()
{
}

Order::~Order()
{
}

void Order::addItem(const std::string id, int quantity)
{
    productIds.push_back(id);
    quantities.push_back(quantity);
}

const std::vector<std::string> Order::getProductIds() const
{
    return productIds;
}

const std::vector<int> Order::getQuantities() const
{
    return quantities;
}


