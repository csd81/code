// 2.46. Háromszög

// 2.46.1. Készítsen derékszögű háromszög osztályt, amelyben az adattagok 
// az oldalak! Írja meg a set és get függvényeket az adattagokra! Írja meg az 
// area, perimeter, check (ellenőrzi, hogy tényleg derékszögű-e a 
// háromszög) és display (kiírja az oldalak hosszát) függvényeket! 

// 2.46.1.


#include <iostream>
#include <cmath>
#include <iomanip> // std::boolalpha

using namespace std;

class RightAngleTriangle {
private:
    float a;
    float b;
    float c;

public:
    // Setters
    void setA(float para) { a = para; }
    void setB(float para) { b = para; }
    void setC(float para) { c = para; }

    // Getters
    float getA() const { return a; }
    float getB() const { return b; }
    float getC() const { return c; }

    // Methods
    bool check() const;
    float area() const;
    float perimeter() const;
    void display() const;
};

bool RightAngleTriangle::check() const {
    // Use a tolerance for floating-point comparison
    float epsilon = 1e-6;
    return fabs(a * a + b * b - c * c) < epsilon;
}

float RightAngleTriangle::area() const {
    return 0.5f * a * b;
}

float RightAngleTriangle::perimeter() const {
    return a + b + c;
}

void RightAngleTriangle::display() const {
    cout << boolalpha;
    cout << "The triangle is valid: " << check() << endl;
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    RightAngleTriangle myTriangle;
    myTriangle.setA(3);
    myTriangle.setB(4);
    myTriangle.setC(5);
    
    myTriangle.display();

    if (myTriangle.check()) {
        cout << "Area: " << myTriangle.area() << endl;
        cout << "Perimeter: " << myTriangle.perimeter() << endl;
    }

    return 0;
}
