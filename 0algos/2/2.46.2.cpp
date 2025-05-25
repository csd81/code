// 2.46.2. Készítsen hasonló osztályt egyenlő szárú háromszögre! 
// 2.46.2.


#include <iostream>
#include <cmath>
#include <iomanip> // boolalpha

using namespace std;

class IsoscelesTriangle {
private:
    float a, b, c;

public:
    // Setters
    void setA(float val) { a = val; }
    void setB(float val) { b = val; }
    void setC(float val) { c = val; }

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

bool IsoscelesTriangle::check() const {
    return (a == b || b == c || a == c);
}

float IsoscelesTriangle::area() const {
    // Heron-képlet (általános háromszögre is jó)
    float s = (a + b + c) / 2;
    float areaSquared = s * (s - a) * (s - b) * (s - c);
    return areaSquared > 0 ? sqrt(areaSquared) : 0;
}

float IsoscelesTriangle::perimeter() const {
    return a + b + c;
}

void IsoscelesTriangle::display() const {
    cout << boolalpha;
    cout << "The triangle is valid (isosceles): " << check() << endl;
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    IsoscelesTriangle myTriangle;
    myTriangle.setA(3);
    myTriangle.setB(3);
    myTriangle.setC(5);

    myTriangle.display();

    if (myTriangle.check()) {
        cout << "Area: " << myTriangle.area() << endl;
        cout << "Perimeter: " << myTriangle.perimeter() << endl;
    }

    return 0;
}
