#ifndef RATEDPRODUCT_H
#define RATEDPRODUCT_H

#include "product.h"
#include "review.h"



class RatedProduct : public Product
{
private:
    Review* reviews;
    int reviewCount;
    static double acceptableLevel;

public:
    RatedProduct(const std::string& name, double price, int reviewCount);
    ~RatedProduct();
    void setReview(int index, const Review& review);
    void print() const override;
    double getRating() const;
    bool isAcceptable() const;

    static double getAcceptableLevel();
    static void setAcceptableLevel(double level);

};


#endif // RATEDPRODUCT_H
