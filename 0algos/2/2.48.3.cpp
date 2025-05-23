2.48.3.
#include <iostream>
#include <cstring> using namespace std;
class Complex { float real, im;
Complex multiply(const Complex&) const;
public: void setReal(float para) {real=para;} void setIm(float para) {im=para;} 
float getReal() const {return real;} float getIm() const {return im;} void 
display() const;
Complex sum(const Complex&) const;
Complex sub(const Complex&) const;
Complex mul(const Complex&) const;
Complex div(const Complex&) const;
friend ostream& operator <<(ostream &os,const Complex &obj);
const Complex operator+(const Complex &other) const { Complex result = 
sum(other);
return result;
} const Complex operator-(const Complex &other) const { Complex result = 
sub(other);
return result;
} const Complex operator*(const Complex &other) const { Complex result = 
mul(other);
return result;
} const Complex operator/(const Complex &other) const { Complex result = 
div(other);
return result;
} };
ostream& operator <<(ostream &os,const Complex &obj) { os<< "(" << obj.real << 
" + " << obj.im << "i) ";
return os;
} Complex Complex::sum(const Complex& para) const { float resultReal, resultIm;
Complex result;
resultReal=real+para.real;
resultIm=im+para.im;
} result.real=resultReal;
result.setIm(resultIm);
return result;
Complex Complex::sub(const Complex& para) const { float resultReal, resultIm;
Complex result;
resultReal=real-para.real;
resultIm=im-para.im;
result.real=resultReal;
result.setIm(resultIm);
return result;
} Complex Complex::mul(const Complex& para) const { float resultReal, resultIm;
Complex result;
resultReal=real*para.real - im*para.im;
resultIm=im*para.real+real*para.im;
result.real=resultReal;
result.setIm(resultIm);
return result;
} Complex Complex::multiply(const Complex& para) const { float resultReal, 
resultIm;
Complex result;
resultReal=real*para.real - im*para.im;
resultIm=im*para.real+real*para.im;
result.real=resultReal;
result.setIm(resultIm);
return result;
} Complex Complex::div(const Complex& para) const { float resultReal, resultIm;
Complex result;
if (para.real==0 && para.im==0) { cout << "Error: divison by zero." << endl;
return result;
} Complex recip;
recip.real=para.real/(para.real*para.real+para.im*para.im);
recip.setIm(-para.im/(para.real*para.real+para.im*para.im));
result=this->multiply(recip);
resultReal=result.getReal();
resultIm=result.im;
return result;
} void Complex::display() const { cout << real << " + " << im << "i";
} int main() { Complex a, b;
a.setReal(1);
} a.setIm(2);
b.setReal(3);
b.setIm(4);
cout << a << " + " << b << "=" << a + b << endl;
cout << a << " - " << b << "=" << a - b << endl;
cout << a << " * " << b << "=" << a * b << endl;
cout << a << " / " << b << "=" << a / b << endl;
return 0;

2.48.3. Valósítsa meg az aritmetikai függvényeket operátorok 
segítségével! 2.49. Telefonszámla
