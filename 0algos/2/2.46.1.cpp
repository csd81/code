2.46.1.
#include <iostream> using namespace std;
class rightAngleTriangle { private: float a;
float b;
float c;
public: bool check() const;
float area() const;
float perimeter() const;
void display() const;
void setA(float para) {a=para;} void setB(float para) {b=para;} void setC(float para) {this->c=para;} float getA() const {return a;} float getB() const {return this->b;} float getC() const {return c;} };
bool rightAngleTriangle::check() const { bool result=false;
if (a*a+b*b==c*c) result=true;
return result;
} float rightAngleTriangle::area() const { float result=a*b/2;
return result;
} float rightAngleTriangle::perimeter() const { float result=a+b+c;
return result;
} void rightAngleTriangle::display() const { bool valid=check();
cout << boolalpha;
cout << "The triangle is valid: " << valid << endl;
if (valid) cout << "The sides are: " << this->a << ", " << b << ", " << getC() << endl;
} int main() { rightAngleTriangle myObject;
myObject.setA(3);
myObject.setB(4);
myObject.setC(5);
myObject.display();
if (myObject.check()) { cout << "Area: " << myObject.area() << endl;
cout << "Perimeter: " << myObject.perimeter() << endl;
} } return 0;

2.46.1. Készítsen derékszögű háromszög osztályt, amelyben az adattagok az oldalak! Írja meg a set és get függvényeket az adattagokra! Írja meg az area, perimeter, check (ellenőrzi, hogy tényleg derékszögű-e a háromszög) és display (kiírja az oldalak hosszát) függvényeket! 
