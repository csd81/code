#ifndef STORE_H
#define STORE_H
#include <vector>
#include "product.h"
#include "order.h"

class Store
{
    std::vector<Product*> products;
    std::vector<int> quantities;

public:
    Store();
    virtual ~Store();

    void loadStock(std::string const &filename);
    void printProducts();
    void printStock();
    int priceOfOrder(Order order);
    void exportQuantities(std::string const &filename);
    bool deliverOrder(Order order);
    void produce(std::string productId, int quantity);

    int static processingFee;
    static void setProcessingFee(int fee);
    static Order loadOrder(const std::string &filename);
};

#endif // STORE_H
