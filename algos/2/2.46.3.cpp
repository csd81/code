// 2.46.3. Készítsen hasonló osztályt szabályos háromszögre! 
// 2.46.3.


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class EquilateralTriangle {
private:
    float a, b, c;

public:
    void setA(float val) { a = val; }
    void setB(float val) { b = val; }
    void setC(float val) { c = val; }

    float getA() const { return a; }
    float getB() const { return b; }
    float getC() const { return c; }

    bool check() const;
    float area() const;
    float perimeter() const;
    void display() const;
};

bool EquilateralTriangle::check() const {
    return (a == b && b == c);
}

float EquilateralTriangle::area() const {
    // Heron-képlet szabályos háromszögre is alkalmazható
    float s = (a + b + c) / 2;
    float areaSquared = s * (s - a) * (s - b) * (s - c);
    return areaSquared > 0 ? sqrt(areaSquared) : 0;
}

float EquilateralTriangle::perimeter() const {
    return a + b + c;
}

void EquilateralTriangle::display() const {
    cout << boolalpha;
    bool valid = check();
    cout << "The triangle is valid (equilateral): " << valid << endl;
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    EquilateralTriangle myTriangle;
    myTriangle.setA(5);
    myTriangle.setB(5);
    myTriangle.setC(5);

    myTriangle.display();

    if (myTriangle.check()) {
        cout << "Area: " << myTriangle.area() << endl;
        cout << "Perimeter: " << myTriangle.perimeter() << endl;
    }

    return 0;
}
