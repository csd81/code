// 2.48.3. Valósítsa meg az aritmetikai függvényeket operátorok 
// segítségével! 
// 2.48.3.


#include <iostream>
#include <iomanip>

class Complex {
    float real, im;

    Complex multiply(const Complex& other) const {
        Complex result;
        result.real = real * other.real - im * other.im;
        result.im = im * other.real + real * other.im;
        return result;
    }

public:
    Complex() : real(0), im(0) {}
    Complex(float r, float i) : real(r), im(i) {}

    void setReal(float val) { real = val; }
    void setIm(float val) { im = val; }

    float getReal() const { return real; }
    float getIm() const { return im; }

    void display() const {
        std::cout << real << " + " << im << "i";
    }

    Complex sum(const Complex& other) const {
        return Complex(real + other.real, im + other.im);
    }

    Complex sub(const Complex& other) const {
        return Complex(real - other.real, im - other.im);
    }

    Complex mul(const Complex& other) const {
        return Complex(real * other.real - im * other.im,
                       real * other.im + im * other.real);
    }

    Complex div(const Complex& other) const {
        Complex result;
        float denom = other.real * other.real + other.im * other.im;
        if (denom == 0.0f) {
            std::cerr << "Error: division by zero.\n";
            return result;
        }
        Complex recip(other.real / denom, -other.im / denom);
        return this->multiply(recip);
    }

    // Operator overloads
    Complex operator+(const Complex& other) const { return sum(other); }
    Complex operator-(const Complex& other) const { return sub(other); }
    Complex operator*(const Complex& other) const { return mul(other); }
    Complex operator/(const Complex& other) const { return div(other); }

    friend std::ostream& operator<<(std::ostream& os, const Complex& obj) {
        os << "(" << obj.real << " + " << obj.im << "i)";
        return os;
    }
};

int main() {
    Complex a(1, 2);
    Complex b(3, 4);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << a << " + " << b << " = " << (a + b) << "\n";
    std::cout << a << " - " << b << " = " << (a - b) << "\n";
    std::cout << a << " * " << b << " = " << (a * b) << "\n";
    std::cout << a << " / " << b << " = " << (a / b) << "\n";

    return 0;
}
