// 2.11.1. Írjon programot a másodfokú egyenlet megoldására! Először kérje be az együtthatókat, azután írja ki, hogy hány megoldás van és adja meg a megoldásokat! 



#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    
    cout << "Solve quadratic equation a*x^2 + b*x + c = 0\n\n";
    cout << "Enter coefficient a: ";
    cin  >> a;
    cout << "Enter coefficient b: ";
    cin  >> b;
    cout << "Enter coefficient c: ";
    cin  >> c;

    // Handle degenerate case a == 0 → linear or no equation
    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {
                cout << "\nInfinite solutions (0 = 0).\n";
            } else {
                cout << "\nNo solution (inconsistent equation).\n";
            }
        } else {
            // bx + c = 0 → x = –c/b
            double x = -c / b;
            cout << "\nLinear equation, one solution:\n";
            cout << "x = " << fixed << setprecision(4) << x << "\n";
        }
        return 0;
    }

    double D = b*b - 4.0*a*c;

    cout << "\nDiscriminant D = " << fixed << setprecision(4) << D << "\n";

    if (D > 0.0) {
        double sqrtD = sqrt(D);
        double x1 = (-b + sqrtD) / (2.0 * a);
        double x2 = (-b - sqrtD) / (2.0 * a);
        cout << "There are 2 real solutions:\n";
        cout << "x1 = " << fixed << setprecision(4) << x1 << "\n";
        cout << "x2 = " << fixed << setprecision(4) << x2 << "\n";
    }
    else if (D == 0.0) {
        double x = -b / (2.0 * a);
        cout << "There is 1 real solution:\n";
        cout << "x = " << fixed << setprecision(4) << x << "\n";
    }
    else {
        cout << "There are no real solutions (D < 0).\n";
    }

    return 0;
}
 