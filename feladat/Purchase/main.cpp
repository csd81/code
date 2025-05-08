#include <iostream>
#include "product.h"
#include "singleproduct.h"
#include "multiproduct.h"
#include "packagedproduct.h"
using namespace std;

int PackagedProduct::packageSize = 1;  // Default to 1

// Set package size for all PackagedProducts
void setPackageSize(int size) {
    PackagedProduct::setPackageSize(size);
}


vector<Product*> readProducts(const string& filename) {
    vector<Product*> products;
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        istringstream iss(line);
        string code;
        iss >> code;

        if (code[0] == 'S'){
            int price;
            iss >> price;
            products.push_back(new SingleProduct(code,price));
        } else if (code[0] == 'M') {
            int price, quantity;
            iss >> price >> quantity;
            products.push_back(new MultiProduct(code,price,quantity));
        } else if (code[0] == 'P') {
            int price, count;
            iss >> price >> count;
            products.push_back(new PackagedProduct(code,price,count));
        }
    }

    return products;
}

int getTotalCost(const vector<Product*>& products){
    int total = 0;
    for (auto p : products){
        total += p->getPrice();
    }
    return total;
}



// ----------------------------
// Main function
// ----------------------------
int main() {
    string filename;
    int size1, size2;
    cin >> filename >> size1 >> size2;

    vector<Product*> products = readProducts(filename);

    setPackageSize(size1);
    cout << getTotalCost(products) << endl;

    setPackageSize(size2);
    cout << getTotalCost(products) << endl;

    for (Product* p : products)
        delete p;

    return 0;
}
