#include "ratedproduct.h"
#include <iostream>



double RatedProduct::acceptableLevel = 4.2;

RatedProduct::RatedProduct(const std::string& name, double price, int reviewCount)
    : Product(name, price), reviewCount(reviewCount)
{
    reviews = new Review[reviewCount];
}

RatedProduct::~RatedProduct() {
    delete[] reviews;
}

void RatedProduct::setReview(int index, const Review& review) {
    reviews[index] = review;
}



void RatedProduct::print() const {
    Product::print();
    for (int i = 0; i < reviewCount; ++i) {
        reviews[i].print();
    }
}

double RatedProduct::getRating() const {
    int totalStars = 0;
    for (int i = 0; i < reviewCount; ++i) {
        totalStars += reviews[i].getStars();
    }
    return static_cast<double>(totalStars) / reviewCount;
}

bool RatedProduct::isAcceptable() const {
    return getRating() >= acceptableLevel;
}

double RatedProduct::getAcceptableLevel() {
    return acceptableLevel;
}

void RatedProduct::setAcceptableLevel(double level) {
    acceptableLevel = level;
}
