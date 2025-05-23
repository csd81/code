2.48.1.
#include <iostream>
#include <cstring> using namespace std;
class Complex { float real, im;
Complex multiply(const Complex&) const;
public: void setReal(float para) {real=para;} void setIm(float para) {im=para;} 
float getReal() const {return real;} float getIm() const {return im;} void 
display() const;
void sum(const Complex&) const;
void sub(const Complex&) const;
void mul(const Complex&) const;
void div(const Complex&) const;
};
void Complex::sum(const Complex& para) const { float resultReal, resultIm;
resultReal=real+para.real;
resultIm=im+para.im;
cout << resultReal << "+" << resultIm << "i";
} void Complex::sub(const Complex& para) const { float resultReal, resultIm;
resultReal=real-para.real;
resultIm=im-para.im;
cout << resultReal << "+" << resultIm << "i";
} void Complex::mul(const Complex& para) const { float resultReal, resultIm;
resultReal=real*para.real - im*para.im;
resultIm=im*para.real+real*para.im;
cout << resultReal << "+" << resultIm << "i";
} Complex Complex::multiply(const Complex& para) const { float resultReal, 
resultIm;
Complex result;
resultReal=real*para.real - im*para.im;
resultIm=im*para.real+real*para.im;
result.real=resultReal;
result.setIm(resultIm);
return result;
} void Complex::div(const Complex& para) const { float resultReal, resultIm;
if (para.real==0 && para.im==0) { cout << "Error: divison by zero." << endl;
return;
} Complex recip;
recip.real=para.real/(para.real*para.real+para.im*para.im);
recip.setIm(-para.im/(para.real*para.real+para.im*para.im));
Complex result=this->multiply(recip);
resultReal=result.getReal();
resultIm=result.im;
cout << resultReal << "+" << resultIm << "i";
} void Complex::display() const { cout << real << "+" << im << "i";
} int main() { Complex a, b;
a.setReal(1);
a.setIm(2);
b.setReal(3);
b.setIm(4);
a.display();
cout << " + ";
b.display();
cout << "=";
a.sum(b);
cout << endl;
a.display();
cout << " - ";
b.display();
cout << "=";
a.sub(b);
cout << endl;
a.display();
cout << " * ";
b.display();
cout << "=";
a.mul(b);
cout << endl;
a.display();
cout << " / ";
b.display();
cout << "=";
a.div(b);
cout << endl;
return 0;
} 
2.48.1. Írjon komplex szám osztályt! Használjon privát adattagokat! Írja 
meg az add, sub, mul, div metódusokat! Az említett metódusok írják ki a 
műveletek eredményét a képernyőre! 
