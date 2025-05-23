2.45.1.
#include <iostream>
#include <cmath> using namespace std;
float heron(float a, float b, float c) { if (a<=0) throw a;
if (b<=0) throw b;
if (c<=0) throw c;
if (a>=b+c || b>=a+c || c>=a+b) throw "No triangle can be constructed from the sides";
float s=(a+b+c)/2;
float result=sqrt(s*(s-a)*(s-b)*(s-c));
return result;
} int main() { cout << "The program will calculate the area of a triangle." << endl;
float area;
try { area=heron(3, 2.54, 9);
} catch(float para) { cout << "Triangle side can not be 0 or less, it is " << para << endl;
} catch(const char* msg) { cout << msg << endl;
} } catch(...) { cout << "Unknown error" << endl;
} return 0;

2.45.1. Írjon függvényt, amely a Hérón képlet segítségével kiszámolja a háromszög területét! Dobjon float típusú kivételt, ha valamelyik oldal változó negatív és dobjon const char* típusú kivételt, ha nem teljesül a háromszög egyenlőtlenség! A kivételeket kezelje a main függvényben! 2.46. Háromszög
