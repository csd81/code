// 2.48. Komplex számok
// 2.48.2. Módosítsa úgy a programot, hogy a metódusok ne végezzenek 
// kiírást, hanem adják vissza az eredményt objektumként! Valósítsa meg 
// kiíró operátort a komplex osztályra! 
// 2.48.2.


#include <iostream>

class Complex {
    float real, im;

    Complex multiply(const Complex& other) const {
        return Complex(
            real * other.real - im * other.im,
            real * other.im + im * other.real
        );
    }

public:
    Complex() : real(0), im(0) {}
    Complex(float r, float i) : real(r), im(i) {}

    void setReal(float val) { real = val; }
    void setIm(float val) { im = val; }

    float getReal() const { return real; }
    float getIm() const { return im; }

    Complex sum(const Complex& other) const {
        return Complex(real + other.real, im + other.im);
    }

    Complex sub(const Complex& other) const {
        return Complex(real - other.real, im - other.im);
    }

    Complex mul(const Complex& other) const {
        return Complex(
            real * other.real - im * other.im,
            real * other.im + im * other.real
        );
    }

    Complex div(const Complex& other) const {
        float denom = other.real * other.real + other.im * other.im;
        if (denom == 0.0f) {
            std::cerr << "Error: division by zero." << std::endl;
            return Complex();
        }
        Complex reciprocal(other.real / denom, -other.im / denom);
        return multiply(reciprocal);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& obj) {
        os << "(" << obj.real << " + " << obj.im << "i)";
        return os;
    }
};

int main() {
    Complex a, b;
    a.setReal(1);
    a.setIm(2);
    b.setReal(3);
    b.setIm(4);

    std::cout << a << " + " << b << " = " << a.sum(b) << std::endl;
    std::cout << a << " - " << b << " = " << a.sub(b) << std::endl;
    std::cout << a << " * " << b << " = " << a.mul(b) << std::endl;
    std::cout << a << " / " << b << " = " << a.div(b) << std::endl;

    return 0;
}
