#include "packagedproduct.h"

PackagedProduct::PackagedProduct(const string &code, int unitPrice, int packageCount) :
    code(code),
    unitPrice(unitPrice),
    packageCount(packageCount)
{}

void PackagedProduct::setPackageSize(int newPackageSize)
{
    packageSize = newPackageSize;
}

int PackagedProduct::getPrice() const
{
    return unitPrice * packageCount * packageSize;
}
