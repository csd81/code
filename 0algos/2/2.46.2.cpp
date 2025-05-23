2.46.2.
#include <iostream> using namespace std;
class isoscelesTriangle { private: float a;
float b;
float c;
public: bool check() const;
float area() const;
float perimeter() const;
void display() const;
void setA(float para) {a=para;} void setB(float para) {b=para;} void setC(float 
para) {this->c=para;} float getA() const {return a;} float getB() const {return 
this->b;} float getC() const {return c;} };
bool isoscelesTriangle::check() const { bool result=false;
if (a==b || b==c || a==c) result=true;
return result;
} float isoscelesTriangle::area() const { float s=(a+b+c)/2;
float result=s*(s-a)*(s-b);
return result;
} float isoscelesTriangle::perimeter() const { float result=a+b+c;
return result;
} void isoscelesTriangle::display() const { bool valid=check();
cout << boolalpha;
cout << "The triangle is valid: " << valid << endl;
if (valid) cout << "The sides are: " << this->a << ", " << b << ", " << getC() 
<< endl;
} int main() { isoscelesTriangle myObject;
myObject.setA(3);
myObject.setB(3);
myObject.setC(5);
myObject.display();
if (myObject.check()) { cout << "Area: " << myObject.area() << endl;
cout << "Perimeter: " << myObject.perimeter() << endl;
} return 0;
} 
2.46.2. Készítsen hasonló osztályt egyenlő szárú háromszögre! 
