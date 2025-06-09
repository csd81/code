// 2.48.1. Írjon komplex szám osztályt! Használjon privát adattagokat! Írja 
// meg az add, sub, mul, div metódusokat! Az említett metódusok írják ki a 
// műveletek eredményét a képernyőre! 
// 2.48.1.


#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real, im;

    Complex multiply(const Complex&) const;

public:
    void setReal(float para) { real = para; }
    void setIm(float para) { im = para; }

    float getReal() const { return real; }
    float getIm() const { return im; }

    void display() const;

    void sum(const Complex&) const;
    void sub(const Complex&) const;
    void mul(const Complex&) const;
    void div(const Complex&) const;
};

// Display the complex number in standard form
void Complex::display() const {
    cout << real;
    if (im >= 0)
        cout << "+";
    cout << im << "i";
}

void Complex::sum(const Complex& para) const {
    float resultReal = real + para.real;
    float resultIm = im + para.im;
    cout << resultReal << (resultIm >= 0 ? "+" : "") << resultIm << "i";
}

void Complex::sub(const Complex& para) const {
    float resultReal = real - para.real;
    float resultIm = im - para.im;
    cout << resultReal << (resultIm >= 0 ? "+" : "") << resultIm << "i";
}

void Complex::mul(const Complex& para) const {
    float resultReal = real * para.real - im * para.im;
    float resultIm = im * para.real + real * para.im;
    cout << resultReal << (resultIm >= 0 ? "+" : "") << resultIm << "i";
}

Complex Complex::multiply(const Complex& para) const {
    float resultReal = real * para.real - im * para.im;
    float resultIm = im * para.real + real * para.im;

    Complex result;
    result.real = resultReal;
    result.im = resultIm;
    return result;
}

void Complex::div(const Complex& para) const {
    if (para.real == 0 && para.im == 0) {
        cout << "Error: division by zero.";
        return;
    }

    float denom = para.real * para.real + para.im * para.im;
    Complex recip;
    recip.real = para.real / denom;
    recip.im = -para.im / denom;

    Complex result = this->multiply(recip);
    cout << result.getReal() << (result.getIm() >= 0 ? "+" : "") << result.getIm() << "i";
}

// Main function to demonstrate operations
int main() {
    Complex a, b;
    a.setReal(1);
    a.setIm(2);

    b.setReal(3);
    b.setIm(4);

    a.display(); cout << " + "; b.display(); cout << " = ";
    a.sum(b); cout << endl;

    a.display(); cout << " - "; b.display(); cout << " = ";
    a.sub(b); cout << endl;

    a.display(); cout << " * "; b.display(); cout << " = ";
    a.mul(b); cout << endl;

    a.display(); cout << " / "; b.display(); cout << " = ";
    a.div(b); cout << endl;

    return 0;
}
