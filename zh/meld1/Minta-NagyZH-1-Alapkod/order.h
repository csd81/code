#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>

class Order
{
    std::vector<std::string> productIds;
    std::vector<int> quantities;
public:
    Order();
    ~Order();
    void addItem(const std::string id, int quantity);
    const std::vector<std::string> getProductIds() const;
    const std::vector<int> getQuantities() const;
};

#endif // ORDER_H
