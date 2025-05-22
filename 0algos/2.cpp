









2.11.1. Írjon programot a másodfokú egyenlet megoldására! Először kérje be az együtthatókat, azután írja ki, hogy hány megoldás van és adja meg a megoldásokat! 

2.11.1.
#include <stdio.h>
#include <math.h> int main() { float a, b, c, D, x1, x2;
printf("The next equation is to be solved:\n");
} printf("a*x^2+b*x+c=0\n");
printf("a=");
scanf("%f", &a);
printf("b=");
scanf("%f", &b);
printf("c=");
scanf("%f", &c);
D=b*b-4*a*c;
if (D>0) { printf("There are 2 solutions!\n");
x1=(-b+sqrt(D))/(2*a);
x2=(-b-sqrt(D))/(2*a);
printf("x1=%f\n", x1);
printf("x2=%f\n", x2);
} else if (D==0) { printf("There is 1 solution!\n");
x1=-b/(2*a);
printf("x1=%f\n", x1);
} else { printf("There is no solution!\n");
} return 0;

// Let us implement this code in c++

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, c, D, x1, x2;
    cout << "The next equation is to be solved:\n";
    cout << "a*x^2+b*x+c=0\n";
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    cout << "c= ";
    cin >> c;

    D = b * b - 4 * a * c;

    if (D > 0) {
        cout << "There are 2 solutions!\n";
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "x1= " << x1 << "\n";
        cout << "x2= " << x2 << "\n";
    } else if (D == 0) {
        cout << "There is 1 solution!\n";
        x1 = -b / (2 * a);
        cout << "x1= " << x1 << "\n";
    } else {
        cout << "There is no solution!\n";
    }

    return 0;
}

Below is a clean C++ solution for 2.11.1 that

1. Prompts the user for the coefficients $a$, $b$ and $c$ of the quadratic equation
2. Computes the discriminant $D = b^2 - 4ac$
3. Reports how many (real) solutions there are and prints them

```cpp
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
```

 




2.11.2. Határozza meg a komplex gyököket is! A komplex gyököket is figyelembe véve a másodfokú egyenletnek mindig két megoldása van, de azok egybeeshetnek. 

2.11.2.
#include <stdio.h>
#include <math.h> int main() { float a, b, c, D, x1, x2;
} printf("The next equation is to be solved:\n");
printf("a*x^2+b*x+c=0\n");
printf("a= ");
scanf("%f", &a);
printf("b= ");
scanf("%f", &b);
printf("c= ");
scanf("%f", &c);
D = b*b - 4*a*c;
if (D > 0) { printf("There are 2 solutions!\n");
x1 = (-b + sqrt(D)) /(2*a);
x2 = (-b - sqrt(D)) /(2*a);
printf("x1= %f\n", x1);
printf("x2= %f\n", x2);
} else if (D == 0) { printf("There is 1 solution!\n");
x1 = -b /(2*a);
printf("x1= %f\n", x1);
} else { printf("There are 2 solutions! (complex)\n");
printf("x1= %f+(%f)i\n", (-b) /(2*a), sqrt(-D));
printf("x2= %f-(%f)i\n", (-b) /(2*a), sqrt(-D));
} return 0;

Here’s a C++11 version that always computes and prints two roots—including complex ones—for

$$
a x^2 + b x + c = 0
$$

even when they coincide. It uses `<complex>` so you don’t have to branch on the sign of the discriminant yourself:

```cpp
#include <iostream>
#include <complex>
#include <iomanip>

int main() {
    double a, b, c;
    std::cout << "Solve a*x^2 + b*x + c = 0 (complex roots allowed)\n\n";
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "c = "; std::cin >> c;

    // Ensure it's really quadratic
    if (a == 0.0) {
        std::cerr << "Coefficient a must be non-zero for a quadratic equation.\n";
        return 1;
    }

    // Compute discriminant as a complex number
    std::complex<double> D = std::complex<double>(b*b - 4.0*a*c, 0.0);
    auto sqrtD = std::sqrt(D);

    // Two roots
    std::complex<double> x1 = (-b + sqrtD) / (2.0 * a);
    std::complex<double> x2 = (-b - sqrtD) / (2.0 * a);

    // Print with 4 decimal places
    auto print_root = [&](const std::complex<double>& x, const char* name) {
        double re = x.real();
        double im = x.imag();
        std::cout << name << " = "
                  << std::fixed << std::setprecision(4)
                  << re;
        if (im >= 0)
            std::cout << "+" << im << "i\n";
        else
            std::cout << im << "i\n";
    };

    std::cout << "\nThe two solutions are:\n";
    print_root(x1, "x1");
    print_root(x2, "x2");

    return 0;
}
```

### Key points

* **`<complex>`**
  We wrap the real discriminant in a `std::complex<double>` so that `std::sqrt` will automatically give a complex result when $D<0$.
* **Unified formula**

  $$
    x_{1,2} \;=\;\frac{-b \pm \sqrt{D}}{2a}
  $$

  works whether $\sqrt{D}$ is real or imaginary.
* **Formatting**
  We use `fixed` with `setprecision(4)` for all numeric output, and a small lambda to print the “+” or “–” between real and imaginary parts.




2.1.1. Írjon programot, amely bekéri egy vizsga eredményének százalékos értékét és kiírja, hogy sikeres volt-e a vizsga! A siker feltétele az 50%-nál jobb teljesítmény. Ötlet: ügyeljen arra, hogy az 50% még bukást jelent! 
2.1.1.
#include <stdio.h> int main() { float result;
printf("result=");
_flushall();
scanf("%f", &result);
if (result>50) { printf("Passed\n");
} else { printf("Failed\n");
} return 0;
} 

Here’s a clean C++11 version that reads a percentage grade, checks if it’s strictly greater than 50 % (so exactly 50 % still fails), and prints “Passed” or “Failed”:

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double result;

    std::cout << "Enter exam result (in %): ";
    std::cin  >> result;

    if (!std::cin) {
        std::cerr << "Invalid input!\n";
        return 1;
    }

    // 50.0% is still a fail; must be >50.0 to pass
    if (result > 50.0) {
        std::cout << "Passed\n";
    } else {
        std::cout << "Failed\n";
    }

    return 0;
}
```

**How it works**

* We use `double` for the percentage to handle fractional inputs (e.g. 50.5).
* `std::cin >> result` reads the value; we guard against invalid input.
* The `if (result > 50.0)` check ensures that exactly 50.0 counts as a failure.

Compile with any C++11-compliant compiler:

```bash
g++ -std=c++11 -o pass_fail pass_fail.cpp
./pass_fail
```




2.12.1. Írjon programot a relációs operátorok működésének a szemléltetésére! Kérjen be két egész változót és írja ki, hogy az egyes relációs operátorokat alkalmazva rájuk milyen eredményt kapunk. Legyen lehetőség az előző lépések ismétlésére! 
2.12.1
#include <stdio.h>
#include <math.h> int main() { int op1, op2;
char more='y';
while (more=='y') { printf("\nop1=");
scanf("%d", &op1);
printf("op2=");
scanf("%d", &op2);
printf("%d<%d = %d\n", op1, op2, op1 < op2);
printf("%d<=%d = %d\n", op1, op2, op1 <= op2);
printf("%d==%d = %d\n", op1, op2, op1 == op2);
printf("%d>=%d = %d\n", op1, op2, op1 >= op2);
printf("%d>%d = %d\n", op1, op2, op1 > op2);
printf("%d!=%d = %d\n", op1, op2, op1 != op2);
printf("Do you want to continue? (y, n) _flushall();
scanf("%c", &more);
} ");
} return 0;

```cpp
#include <iostream>
#include <limits>

int main() {
    int op1, op2;
    char more = 'y';

    std::cout << "Demonstrate relational operators on two integers\n\n";

    while (more == 'y' || more == 'Y') {
        // Read first integer
        std::cout << "Enter first integer (op1): ";
        while (!(std::cin >> op1)) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Read second integer
        std::cout << "Enter second integer (op2): ";
        while (!(std::cin >> op2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Print results of each relational operator (as 0 or 1)
        std::cout << "\nResults:\n";
        std::cout << op1 << " <  " << op2 << "  → " << (op1 <  op2) << "\n";
        std::cout << op1 << " <= " << op2 << "  → " << (op1 <= op2) << "\n";
        std::cout << op1 << " == " << op2 << "  → " << (op1 == op2) << "\n";
        std::cout << op1 << " != " << op2 << "  → " << (op1 != op2) << "\n";
        std::cout << op1 << " >= " << op2 << "  → " << (op1 >= op2) << "\n";
        std::cout << op1 << " >  " << op2 << "  → " << (op1 >  op2) << "\n";

        // Ask if the user wants to repeat
        std::cout << "\nDo you want to try again? (y/n): ";
        std::cin >> more;

        // Consume any leftover input up to newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }

    std::cout << "Program terminated.\n";
    return 0;
}
```

### Notes

* We use `std::cin` and validate to ensure the user enters integers.
* Each relational expression (`<`, `<=`, `==`, `!=`, `>=`, `>`) is evaluated and printed as `0` (false) or `1` (true).
* After showing the results, the program asks if you’d like to repeat; entering `y` or `Y` restarts the loop.
* `std::numeric_limits<std::streamsize>::max()` and `ignore()` clear out any extra characters (e.g., stray letters) so input remains in a good state.



2.12.2. Írjon programot a logikai és bitenkénti operátorok használatának a szemléltetésére! 
2.12.2.
#include <stdio.h>
#include <math.h> int main() { int op1, op2;
char more = 'y';
while (more == 'y') { printf("\nop1= ");
scanf("%d", &op1);
printf("op2= ");
scanf("%d", &op2);
printf("%d&%d = %d\n", op1, op2, op1 & op2);
printf("%d|%d = %d\n", op1, op2, op1 | op2);
printf("%d^%d = %d\n", op1, op2, op1 ^ op2);
printf("~%d = %d\n", op1, ~op1);
printf("~%d = %d\n", op2, ~op2);
printf("Do you want to continue? (y, n) ");
_flushall();
scanf("%c", &more);
} return 0;
} 

```cpp
#include <iostream>
#include <limits>

int main() {
    int op1, op2;
    char more = 'y';

    std::cout << "Demonstrate logical and bitwise operators on two integers\n\n";

    while (more == 'y' || more == 'Y') {
        // Read first integer
        std::cout << "Enter first integer (op1): ";
        while (!(std::cin >> op1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Read second integer
        std::cout << "Enter second integer (op2): ";
        while (!(std::cin >> op2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Bitwise operations
        std::cout << "\nBitwise operations:\n";
        std::cout << op1 << " &  " << op2 << "  = " << (op1 & op2) << "\n";
        std::cout << op1 << " |  " << op2 << "  = " << (op1 | op2) << "\n";
        std::cout << op1 << " ^  " << op2 << "  = " << (op1 ^ op2) << "\n";
        std::cout << "~"  << op1 << "       = " << (~op1) << "\n";
        std::cout << "~"  << op2 << "       = " << (~op2) << "\n";

        // Logical operations
        std::cout << "\nLogical operations (treating 0 as false, non-zero as true):\n";
        std::cout << op1 << " && " << op2 << " = " << ( (op1 && op2) ? 1 : 0 ) << "\n";
        std::cout << op1 << " || " << op2 << " = " << ( (op1 || op2) ? 1 : 0 ) << "\n";
        std::cout << "!"  << op1 << "       = " << ( (!op1) ? 1 : 0 ) << "\n";
        std::cout << "!"  << op2 << "       = " << ( (!op2) ? 1 : 0 ) << "\n";

        // Repeat?
        std::cout << "\nDo you want to try again? (y/n): ";
        std::cin >> more;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }

    std::cout << "Program terminated.\n";
    return 0;
}
```

**How it works**

* We read two integers `op1` and `op2`, validating input to ensure they’re integers.
* **Bitwise operators**

  * `&` (AND), `|` (OR), `^` (XOR), `~` (NOT).
* **Logical operators**

  * `&&` (logical AND), `||` (logical OR), `!` (logical NOT).
    Results are normalized to `1` (true) or `0` (false) in the output.
* After displaying all results, the program asks if you’d like to repeat; entering `y` or `Y` continues the loop.
* We use `std::numeric_limits<std::streamsize>::max()` with `ignore()` to clear any leftover input and keep the stream in a good state.




2.1.2. Kérjen be pontszámot, amelynek -25 és 50 közé kell esnie! A vizsga sikerességét csak akkor vizsgálja, ha a pontszám a helyes intervallumban van! A siker feltétele a 25 pontnál jobb eredmény. 

2.1.2.
#include <stdio.h> int main() { float result;
printf("result=");
_flushall();
scanf("%f", &result);
if (result>50) { printf("Passed\n");
} else { printf("Failed\n");
} return 0;
} 

2.13.1. Kérjen be egy előjel nélküli karakter típusú változót egészként és írja ki a kettes számrendszerbeli alakját! 
2.13.1.
#include <stdio.h>
#include <math.h> int main() { unsigned char number=0, result, delMask=0x80;
int idxI;
printf("number=");
scanf("%d", &number);
printf("Its value in number system 2: ");
} for (idxI=0;
idxI<8;
idxI++) { result = number & delMask;
printf("%u", result?1:0);
delMask = delMask>>1;
} printf("\n");
return 0;

2.13.2. Kérjen be egy számot és az előző programmal írja ki a kettes számrendszerbeli alakját! Kérjen be egy bit pozíciót és állítsa azt a bitet egyesre! Írja ki az új értéket tízes és kettes számrendszerben is! 
2.13.2.
#include <stdio.h>
#include <math.h> #define SIZE 8 int main() { unsigned char number = 0, result, delMask=0x80;
unsigned char stringNumber[SIZE], newNumber;
int idxI, position;
printf("Number= ");
scanf("%d", &number);
printf("Its value in system 2: ");
for (idxI = 0;
idxI < SIZE;
idxI++) { result = number & delMask;
printf("%u", result?1:0);
stringNumber[idxI] = result?1:0;
delMask = delMask>>1;
} printf("\nPlease enter a position, this bit will be set to 1!(1 is the lowest) ");
scanf("%d", &position);
printf("Here comes the new number in system 2: ");
if (!stringNumber[SIZE - position]) newNumber = number + pow(2, position-1);
else newNumber = number;
stringNumber[SIZE - position] = 1;
for (idxI = 0;
idxI < SIZE;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number in system 10: ");
} printf("%d\n", newNumber);
return 0;


2.13.3. Folytassa az előző programot úgy, hogy bekér még két bit pozíciót! Az elsőnél törölje a bitet a másodiknál negálja. Minden részeredményt írjon ki a képernyőre! 2.14. Hatványsor
2.13.3.
#include <stdio.h>
#include <math.h> #define SIZE 8 int main() { unsigned char number=0, result, delMask=0x80;
unsigned char stringNumber[SIZE], newNumber;
int idxI, position, positionDelete, positionNegate;
printf("Number= ");
scanf("%d", &number);
printf("Its value in system 2: ");
for (idxI = 0;
idxI < SIZE;
idxI++) { result = number & delMask;
printf("%u", result?1:0);
stringNumber[idxI] = result?1:0;
delMask = delMask>>1;
} printf("\nPlease enter a position, this bit will be set to 1!(1 is the lowest) ");
scanf("%d", &position);
printf("Here comes the new number in system 2: ");
if (!stringNumber[SIZE - position]) newNumber = number + pow(2, position-1);
else newNumber = number;
stringNumber[SIZE - position] = 1;
for (idxI = 0;
idxI < SIZE;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number in system 10: ");
printf("%d\n", newNumber);
if (stringNumber[SIZE-position]) newNumber = number + pow(2, position-1);
else newNumber = number;
printf("%d\n", newNumber);
printf("Please enter 2 new position, the first position bit will be deleted, the second will be negated.(ex: 1 5) ");
scanf("%d%d", &positionDelete, &positionNegate);
for (idxI = SIZE-positionDelete;
idxI < SIZE;
++idxI) stringNumber[idxI] = stringNumber[idxI+1];
printf("Here comes the new number after bit delete in system 2: ");
for (idxI = 0;
idxI < 7;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number after bit delete in system 10: ");
newNumber = 0;
for (idxI = 6;
idxI >= 0;
--idxI) if (stringNumber[idxI] != 0) newNumber += pow(2, (6-idxI)* stringNumber[idxI]);
printf("%d\n", newNumber);
printf("Here comes the new number after bit delete and bit negate in system 2: ");
if (stringNumber[SIZE-positionNegate] == 0) stringNumber[SIZE-positionNegate] = 1;
else stringNumber[SIZE-positionNegate] = 0;
for (idxI=0;
idxI<7;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number after bit delete and bit negate in system 10: ");
newNumber = 0;
for (idxI = 6;
idxI >= 0;
--idxI){ if (stringNumber[idxI] != 0) { newNumber += pow(2, (6-idxI)* stringNumber[idxI]);
} } printf("%d\n", newNumber);
return 0;
} 

2.14.1. Írjunk programot, amely hatványsor és könyvtári függvény segítségével is kiszámolja ex értékét a következő képlettel: = ! Megfelelően pontos értéket kapunk, ha a sort a negyedik elemig határozzuk meg. Írjuk ki a hatványsor és a valós érték közötti különbséget!
2.14.1.
#include <math.h>
#include <stdio.h> int main() { double result, accurateResult, value;
int length, faktor, idxI;
printf("The accuracy of power series calculating e^x\n");
printf("x=" );
scanf("%lf", &value);
printf("lengtgh of the power series=" );
scanf("%d", &length);
accurateResult = exp(value);
result = 1;
faktor = 1;
for (idxI=1;
idxI<length;
idxI++) { result += pow(value, idxI)/faktor;
faktor*=(idxI+1);
} printf("The difference between the power series and the exact value is %lf", accurateResult-result);
return 0;
} 

2.14.2. Kérjünk be egy pontosságot és határozzuk meg, hogy a sor hány tagját kell figyelembe venni, az adott pontosság eléréséhez! 
#include <math.h>
#include <stdio.h> int main() { double result = 1, accurateResult, value;
int length = 0, faktor = 1, idxI;
double accuracy, difference;
ala printf("The accuracy of power series calculating e^x\n");
printf("x= " );
scanf("%lf", &value);
printf("How big the accuracy should be? ");
scanf("%lf", &accuracy);
accurateResult = exp(value);
difference = accuracy+1;
for (idxI = 1;
difference > accuracy;
idxI++) { result += pow(value, idxI) /faktor;
faktor *= (idxI+1);
difference = accurateResult - result;
length = idxI;
} printf("A length of %d was necessary to get a difference lower than %lf\n", length, accuracy);
return 0;
} 

2.14.3. Határozzuk meg a sin(x)-t hatványsor segítségével! 2.15. Típuskonverzió

#include <math.h>
#include <stdio.h> int factorial_compute(int);
int main() { double result = 0, value;
int length, idxI;
printf("The accuracy of sinus series calculating sin(x)\n");
printf("x= " );
scanf("%lf", &value);
printf("length of the sinus series= " );
scanf("%d", &length);
for (idxI=0;
idxI < length;
idxI++) { result += (pow(-1, idxI) /factorial_compute(2*idxI + 1)) * pow(value, 2*idxI + 1);
} printf("The sin(%lf) value with %d length sinus series is: %lf\n", value, length, result);
return 0;
} konnyiteseert int factorial_compute(int factorial) { if (factorial == 0) return 1;
return factorial * factorial_compute(factorial - 1);
} 

2.15.1. Írjon programot, amely bekér egy double értéket kiírja az eredeti értéket a float, int, short int, char típussá konvertált változatok nagyságát és értékeit! A változók méretei jobbra legyenek rendezve és az értékek kiírása azonos oszlopban kezdődjön! 

#include <math.h>
#include <stdio.h> int main() { double doubleValue=1.12345678912346789123456789e5;
printf("%20.20s”, „doubleValue=");
scanf("%lf", &doubleValue);
float floatValue=(float)doubleValue;
int intValue=(int)floatValue;
short int shortIntValue=(short int)intValue;
char charValue=(char)shortIntValue;
printf("%20.20s%d ", "size of double=", sizeof doubleValue);
printf("doubleValue=%25.20lf\n", doubleValue);
printf("%20.20s%d ", "size of float=", sizeof floatValue);
printf("floatValue=%25.20f\n", floatValue);
printf("%20.20s%d ", "size of int=", sizeof intValue);
printf("intValue=%d\n", intValue);
printf("%20.20s%d ", "size of short int=", sizeof shortIntValue);
printf("shortIntValue=%d\n", shortIntValue);
printf("%20.20s%d ", "size of char=", sizeof charValue);
printf("charValue=%d\n", charValue);
return 0;
} 

2.15.2. Határozza meg az eredeti és a konvertált értékek közötti különbségeket! 2.16. DeMorgan


#include <stdio.h> int main() { double number;
printf("Mennyi legyen a szam? ");
scanf("%lf", &number);
printf("Double-float: %lf\n", number - (float)number);
printf("Double-int: %lf\n", number - (int)number);
printf("Double-short: %.2lf\n", number - (short)number);
printf("Double-char: %.2lf\n", number - (char)number);
return 0;
} 

2.16.1. Írjon programot, amelyben egész változókat használ logikaiként! A változók a következőek: a - van pénzem, b - van kedvem, c - nincs időm, d - nagyon érdekel. Kérje be a változók értékeit és a következők alapján döntse el, hogy megy-e nyaralni: ha van pénze, kedve és ideje, akkor megy, ha az előzőek közül csak egyik igaz, de nagyon érdekli akkor is megy. Írja át a feltételeket DeMorgan azonosságok segítségével! 
#include <math.h>
#include <stdio.h> int main() { int gotMoney, gotMood, noTime, veryInterested;
printf("Type 1 for yes and 0 for no!\n");
printf("gotMoney=");
scanf("%d", &gotMoney);
printf("gotMood=");
scanf("%d", &gotMood);
printf("noTime=");
scanf("%d", &noTime);
printf("veryInterested=");
scanf("%d", &veryInterested);
if ( (gotMoney && gotMood && !noTime) || (gotMoney && veryInterested) || (gotMood && veryInterested) || (!noTime && veryInterested) ) { printf("I will go to holiday!\n");
} else { printf("I will not go to holiday!\n");
} return 0;
} 

2.16.2. Kérje be a következő változókat: a - esik az eső, b - jönnek mások is, c - van szabadnapom. Ezen változók alapján határozzuk meg, hogy mikor megy a felhasználó túrázni. A feltételek a következőek: akkor megyek túrázni ha, nem esik az eső és van szabadnapom;
akkor is túrázom, ha mások nem jönnek, de az eső esik. Írja át a feltételeket De Morgan azonosságok segítségével! 
#include <stdio.h> int main() { int isRaining, comeOthers, gotFreeTime;
} printf("Type 1 for yes and 0 for no!\n");
printf("isRaining: ");
scanf("%d", &isRaining);
printf("comeOthers: ");
scanf("%d", &comeOthers);
printf("gotFreeTime: ");
scanf("%d", &gotFreeTime);
if( (!(isRaining || !gotFreeTime)) || (!(!isRaining || comeOthers)) ) printf("I'm going hiking!\n");
else printf("Peharps next time.\n");
return 0;


2.17.1. Írjon programot, amely a víz hőmérséklete alapján megállapítja annak halmazállapotát! 

#include <stdio.h> int main() { float temperature;
printf("temperature of water=");
} scanf("%f", &temperature);
if (temperature < 0) { printf("Solid water\n");
} else if (temperature < 100) { printf("Liquid water\n");
} else { printf("Gaseous water\n");
} return 0;


2.17.2. Alakítsa át a programot, hogy ne Celsius fokot, hanem Farenheit-t kér be. Külön függvény végezze el a konvertálást! 2.18. Római számok
2.17.2.
#include <stdio.h> float changer(float);
int main() { float celsius;
float fahrenheit;
printf("temperature of water(in fahrenheit): ");
scanf("%f",&fahrenheit);
celsius = changer(fahrenheit);
if (celsius < 0) printf("The water is solid now.\n");
else if (celsius > 100) printf("The water is gaseous now.\n");
else printf("The water is liquid now.\n");
return 0;
} float changer(float temp) { return temp = (temp-32) * 5 / 9;
} 



2.18.1.
#include <stdio.h> int main() { char num;
printf("Roman to arabic number converter");
printf("\nGive me a roman number: ");
scanf("%c", &num);
if (num > 'Z') num = num - ('a'-'A');
switch (num) { case 'I': printf("\n1");
break;
case 'V': printf("\n5");
break;
case 'X': printf("\n10");
break;
case 'L': printf("\n50");
break;
case 'C': printf("\n100");
break;
case 'D': printf("\n500");
break;
case 'M': printf("\n1000");
break;
default: printf("\nWrong character");
} return 0;
} 
2.18.1. Írjon programot, amely megadja, hogy mik a római számjegyek (I, V, L, C, D, M) arab megfelelői! Kérjen be egy római számjegyet, konvertálja nagybetűre, ha szükséges és adja meg a szám értéket! 
2.18.2.
#include <stdio.h>
#include <ctype.h> int main() { char roman[30];
int arabian = 0, size, idxI;
printf("Roman number: ");
scanf("%s", roman);
size = strlen(roman);
for (idxI = 0;
idxI < size;
idxI++) { roman[idxI] = toupper(roman[idxI]);
} for (idxI = 0;
idxI < size;
idxI++) { switch (roman[idxI]) { case 'I': if (roman[idxI + 1] == 'X') { arabian += 9;
idxI += 1;
} else { if (roman[idxI + 1] == 'V') { arabian += 4;
idxI += 1;
} else { arabian += 1;
} } break;
case 'V': arabian += 5;
break;
case 'X': if (roman[idxI + 1] == 'C') { arabian += 90;
idxI += 1;
} else { if (roman[idxI + 1] == 'L') { arabian += 40;
idxI += 1;
} else { arabian += 10;
} } break;
case 'L': arabian += 50;
break;
case 'C': if (roman[idxI + 1] == 'M') { arabian += 900;
idxI += 1;
} else { if (roman[idxI + 1] == 'D') { arabian += 400;
idxI += 1;
} else { arabian += 100;
} } break;
case 'D': arabian += 500;
break;
case 'M': arabian += 1000;
break;
} } } printf("%d\n", arabian);
return 0;

2.18.2. Ne csak egy darab számjegyet, hanem egy több karakterből álló számot alakítson át! 
2.18.3.
#include <stdio.h> int main() { char roman[20];
int arabian, idxI = 0;
printf("Arabianian number(1-4999): ");
scanf("%d", &arabian);
while (arabian > 0) { while ((arabian - 1000) >= 0) { roman[idxI++] = 'M';
arabian -= 1000;
} while ((arabian - 900) >= 0) { roman[idxI++] = 'C';
roman[idxI++] = 'M';
arabian -= 900;
} while ((arabian - 500) >= 0) { roman[idxI++] = 'D';
arabian -= 500;
} while ((arabian - 400) >= 0) { roman[idxI++] = 'C';
roman[idxI++] = 'D';
arabian -= 400;
} while ((arabian - 100) >= 0) { roman[idxI++] = 'C';
arabian -= 100;
} while ((arabian - 90) >= 0) { roman[idxI++] = 'X';
roman[idxI++] = 'C';
arabian -= 90;
} while ((arabian - 50) >= 0) { roman[idxI++] = 'L';
arabian -= 50;
} while ((arabian - 40) >= 0) { roman[idxI++] = 'X';
roman[idxI++] = 'L';
arabian -= 40;
} while ((arabian - 10) >= 0) { roman[idxI++] = 'X';
arabian -= 10;
} while ((arabian - 9) >= 0) { roman[idxI++] = 'I';
roman[idxI++] = 'X';
arabian -= 9;
} while ((arabian - 5) >= 0) { roman[idxI++] = 'V';
arabian -= 5;
} while ((arabian - 4) >= 0) { roman[idxI++] = 'I';
roman[idxI++] = 'V';
arabian -= 4;
} while ((arabian - 1) >= 0) { roman[idxI++] = 'I';
arabian -= 1;
} } roman[idxI++] = '\0';
printf("%s\n", roman);
return 0;
} 
2.18.3. Valósítsa meg a visszafele történő konverziót! 2.19. Háromszög
2.19.1.
#include <stdio.h> int main() { int idxI, idxJ, size=15;
for(idxI = 1;
idxI <= size;
idxI++) { for(idxJ = 1;
idxJ <= idxI;
idxJ++) { printf("*");
} printf("\n");
} return 0;
} 
2.19.1. Rajzoljon ki a karakteres képernyőre egy derékszögű, egyenlő szárú háromszöget csillagokból dupla for ciklus segítségével! 2.1. ábra: Lehetséges képernyőkép
2.19.2. Fordítsa el a háromszöget úgy, hogy a másik befogó kerüljön alulra! 2.20. Négyzet animáció
2.19.2.
#include <stdio.h> int main() { int idxI, idxJ, size = 6;
for (idxI = 0;
idxI < size;
++idxI) { for (idxJ = 1;
idxJ <= size;
++idxJ) { if (idxJ < size -idxI) printf("");
else printf("*");
} printf("\n");
} return 0;
} 
2.20.1.
#include <stdio.h> int main() { character big int idxA, idxB, idxC, size=600;
int idxI, idxJ, idxK, drop=22, consoleSize=25;
} for (idxI=0;
idxI<drop;
idxI++) { for (idxJ=0;
idxJ<consoleSize;
idxJ++) { printf("\n");
} for (idxK=0;
idxK<idxI;
idxK++) { printf("\n");
} printf(" ***\n");
printf(" ***\n");
printf(" ***\n");
for (idxK=0;
idxK<consoleSize-idxI-3;
idxK++) { printf("\n");
} _flushall();
for(idxA = 0;
idxA <= size;
idxA++) { for(idxB = 1;
idxB <= size;
idxB++) { for(idxC = 1;
idxC <= size;
idxC++) { } } } } return 0;

2.20.1. Készítsen a karakteres képernyőn videót egy leeső négyzetről! A négyzet 3*3 csillagból álljon! Miután megjelenített egy képet, várjon rövid ideig, törölje a képernyőt és jelenítse meg a következő képet egy sorral lejjebb! Feltesszük, hogy a karakteres képernyő 80*25-ös. 
2.20.2.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> void wait(int seconds) { clock_t endwait;
endwait = clock() + seconds * CLOCKS_PER_SEC;
while (clock() < endwait) { } } int main() { int idxI, idxJ = 0, size = 0;
while (1) { system("clear");
size = 4;
if (idxJ == 25) idxJ = 0;
if (idxJ >= 23) { for (idxI = idxJ;
idxI >= 23;
idxI--) { printf("***\n");
size -= 1;
} } for (idxI = 1;
idxI <= idxJ;
idxI++) printf("\n");
for (idxI = 1;
idxI < size;
idxI++) printf("***\n");
wait(1);
idxJ++;
} } return 0;

2.20.2. Módosítsa úgy a programot, hogy amint a négyzet eltűnik alul, felül jelenjen meg újból! 
2.20.3.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> void wait(int seconds) { clock_t endwait;
endwait = clock() + seconds * CLOCKS_PER_SEC;
while (clock() < endwait) ;
} int main(){ int idxI, idxJ, row = 0, direction;
while(1) { system("clear");
for (idxI = 1;
idxI <= row;
idxI++) printf("\n");
for (idxJ = 0;
idxJ < 3;
idxJ++) { for (idxI = 2 - idxJ;
idxI > 0;
idxI--) printf("");
for (idxI = 0;
idxI <= 2*idxJ;
idxI++) printf("*");
printf("\n");
} wait(1);
if (row == 22) direction = 0;
else if (row == 0) direction = 1;
if (direction) row++;
else row--;
} return 0;
} 
2.20.3. Módosítsa úgy a programot, hogy négyzet helyett háromszög jelenjen meg, ami alulról pattanjon vissza! 
2.20.4.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> void wait(int seconds) { clock_t endwait;
endwait = clock() + seconds * CLOCKS_PER_SEC;
while (clock() < endwait) ;
} int main() { int idxI, idxJ = 0, direction;
char string [] = "*****";
while (1) { system("clear");
for (idxI = 1;
idxI < 4;
idxI++) eggyel elcsusztatva printf("%*.5s\n", idxJ + 5, string);
wait(1);
if (idxJ == 75) direction = 0;
else if (idxJ == 0) direction=1;
if (direction) idxJ++;
else idxJ--;
} } return 0;

2.20.4. Négyzet helyett téglalap mozogjon vízszintesen a szélekről visszapattanva! 2.21. Legnagyobb közös osztó
2.21.1.
#include <stdio.h> int main() { int x, y;
printf("Give me the first number: ");
scanf("%d",&x);
printf("Give me the second number: ");
scanf("%d",&y);
while (x!=y) { if (x>y) x=x-y;
else y=y-x;
} printf("The biggest common denominator: %d\n", x);
return 0;
} 
2.21.1. Írjon programot, amely kiszámolja két szám legnagyobb közös osztóját a következő algoritmus segítségével! ciklus amíg a két szám nem egyenlő a nagyobb szám értékét csökkentsük a kisebb számmal 
2.21.2.
#include <stdio.h> int biggest_denominator(int, int);
int main() { int x, y, z;
int first, second;
printf("Give me the first number: ");
scanf("%d", &x);
printf("Give me the second number: ");
scanf("%d", &y);
printf("Give me the third number: ");
scanf("%d", &z);
first = biggest_denominator(x, y);
second = biggest_denominator(y, z);
printf("The biggest common denominator: %d\n", biggest_denominator(first, second));
and second denominations return 0;
} int biggest_denominator(int x, int y) { while (x!=y) { if (x>y) x=x-y;
else y=y-x;
} return x;
} 
2.21.2. Módosítsa úgy a programot, hogy az három szám legnagyobb közös osztóját számolja ki! 2.22. main paraméterek
2.2.1. A sakktábla elkészítéséhez csak printf függvényt használjon a programban! Ötlet: minden sorhoz külön printf-t használjon! 
2.2.1.
#include <stdio.h> int main() { printf(" |a |b |c |d |e |f |g |h |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 1| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 2| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 3| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 4| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 5| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 6| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 7| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
printf(" 8| | | | | | | | |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
return 0;
} 
2.22.1.
#include <stdio.h> int main(int argc, char* argv[]) { int idxI;
for (idxI=argc-1;
idxI>=0;
idxI--) { printf("The %d. parameter is: %s\n", idxI, argv[idxI]);
} return 0;
} 
2.22.1. Írjon programot, amely kiírja a program paramétereit fordított sorrendben! 
2.22.2.
#include <stdio.h> int main(int argc, char* argv[]) { int idxI = argc-1;
do { printf("The %d. parameter is: %s\n", idxI, argv[idxI]);
idxI--;
} while (idxI>=0);
return 0;
} 
2.22.2. Írja át úgy a programot, hogy elől tesztelős ciklust használ és a program nevét nem írja ki! 2.23. continue, break
2.2.2. Az azonos sorok kiírásához használjon ciklust! 
2.2.2.
#include <stdio.h> #define SIZE 8 int main() { int id;
printf(" |a |b |c |d |e |f |g |h |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
for (id = 0;
id < SIZE;
id++) { printf(" %d| | | | | | | | |\n", id + 1);
printf(" -|--|--|--|--|--|--|--|--|\n");
} return 0;
} 
2.23.1.
#include <stdio.h> int main(int argc, char* argv[]) { int idxI=0;
float x, y;
do { printf("x=");
scanf("%f", &x);
printf("y=");
scanf("%f", &y);
if ( x>100 || -x>100) { printf("x is too big!\n");
continue;
} if (!y) { printf("y equals 0!\n");
break;
} printf("%f/%f=%f\n\n", x, y, x/y);
idxI++;
if (idxI==3) break;
} } while (1);
return 0;

2.23.1. Írjon programot, amely osztást végez el egy hátul tesztelős ciklusban! Használjon végtelen ciklust, amelyet majd break paranccsal fog megszakítani! Kérje be a két változót! Ha az osztandó abszolút értéke nagyobb, mint 100, akkor hiba üzenet után hajtsa végre a következő iterációt! Ha az osztó értéke 0, akkor szakítsa meg a ciklust! Szintén szakítsa meg a ciklust, ha már három osztást elvégzett! 2.24. Deriválás
2.2.3. Egy adott sor kirajzolásához is használjon ciklust! Keresse meg egy sor ismétlődő mintáját és az kerüljön a ciklus magjába! Figyeljen különösen a fejlécek helyes megjelenítésére. 2.3. Terület és kerületszámítás
2.2.3.
#include <stdio.h> #define SIZE 8 int main() { int id1, id2;
printf(" |");
for (id1 = 'a';
id1 < 'a'+SIZE;
id1++) { printf("%c |",id1);
} printf("\n -|");
for (id2 = 0;
id2 < SIZE;
id2++) { printf("--|");
} for (id1 = 0;
id1 < SIZE;
id1++) { printf("\n %d|", id1+1);
for (id2 = 0;
id2 < SIZE;
id2++) { printf(" |");
} printf("\n -|");
for (id2 = 0;
id2 < SIZE;
id2++) { printf("--|");
} } printf("\n");
return 0;
} 
2.24.1.
#include <stdio.h> float deriv(int whichDerivate, float where) { float result;
switch (whichDerivate) { case 1: result = 9*where*where-4*where+6;
break;
case 2: result = 18*where-4;
break;
case 3: result = 18;
break;
default: result = 0;
printf("\nFirst parameter (%d) is wrong, it should be in 1, 2, or 3\n", whichDerivate);
break;
} return result;
} int main() { int idxI;
float where, rez;
printf("Where do you want to calculate the derivate: ");
scanf("%f", &where);
for (idxI=1;
idxI<5;
idxI++) { rez=deriv(idxI, where);
printf("The %d. derivative of 9x^2-4x+6 at %f is: %f\n", idxI, where, rez);
} return 0;
} 
2.24.1. Írjon függvényt és hozzá tartozó programot, amely a 3x3-2x2+6x-1 függvénynek megadja az 1., 2. vagy 3. deriváltjának az értékét egy adott pontban! A függvény paraméterei: hányadik deriváltról van szó, milyen pontban tekintjük a deriváltat. A függvény visszatérési értéke: a derivált értéke. 
2.24.2. A sin(x) függvénynek határozza meg az 1., 2. vagy 3. deriváltjának az értékét egy adott pontban! Használja fel, hogy sin'(x) = cos(x), cos'(x) = -sin(x). 
2.24.2.
#include <stdio.h>
#include <math.h> float deriv(int whichDerivate, float posX) { float result;
switch (whichDerivate%4) { case 0: result = sin(posX);
break;
case 1: result = cos(posX);
break;
case 2: result = -sin(posX);
break;
case 3: result = -cos(posX);
break;
default: result = 0;
printf("\nError!\n");
break;
} return result;
} int main() { int idxI;
float posX, result;
int times;
printf("Where do you want to calculate the derivate of sin(x) (in radian): ");
scanf("%f", &posX);
printf("How many times? ");
scanf("%d", &times);
for (idxI = 1;
idxI <= times;
idxI++) { result = deriv(idxI, posX);
printf("The %d. derivative of sin(x) at %f is: %f\n", idxI, posX, result);
} return 0;
} 
2.24.3.
#include <stdio.h> float deriv(float posX, float poly4, float poly3, float poly2, float poly1, float poly0) { return ( 4*poly4*pow(posX,3) + 3*poly3*pow(posX,2) + 2*poly2*pow(posX,1) + poly1 );
} int main() { float posX, poly4, poly3, poly2, poly1, poly0;
printf("What function do you want to derivate?\n");
printf("x^4: ");
scanf("%f", &poly4);
printf("x^3: ");
scanf("%f", &poly3);
printf("x^2: ");
scanf("%f", &poly2);
printf("x^1: ");
scanf("%f", &poly1);
printf("constant: ");
scanf("%f", &poly0);
printf("So, the ");
if (poly4) printf("%f x^4 ", poly4);
if (poly3) printf("%+f x^3 ", poly3);
if (poly2) printf("%+f x^2 ", poly2);
if (poly1) printf("%+f x^1 ", poly1);
if (poly0) printf("%+f ", poly0);
printf("will be derivated.\n");
printf("Where do you want to calculate the derivate: ");
scanf("%f", &posX);
printf("The first derivative of the function at %f is: %f\n", posX, deriv(posX, poly4, poly3, poly2, poly1, poly0));
return 0;
} 
2.24.3. Tetszőleges negyed-fokú polinomnak határozza meg a deriváltját adott pontban! Legyen a függvénynek egy harmadik paramétere, ahol jelezzük, ha hiba történt, vagyis ha az első paraméter értéke helytelen, vagyis négynél nagyobb! 2.25. Lépésenkénti összegzés
2.25.1.
#include <stdio.h> int sum(int data) { static int result;
result += data;
return result;
} int main() { int num, total;
char more='y';
do { printf("Provide the next number: ");
scanf("%d", &num);
total = sum(num);
printf("Are there more number: (y/n) ");
_flushall();
scanf("%c", &more);
} while (more=='y');
printf("The The total is %d.\n", total);
return 0;
} 
2.25.1. Írjon programot, amely a konzolról kér be egész számokat egy ciklus segítségével és egy függvény segítségével számolja ki azok összegét! Ezt a függvényt minden szám bekérése után hívja, ami ezután visszaadja az eddigi számok összegét. Használjon statikus változót a részösszeg tárolására! 
2.25.2. Írjon olyan függvényt az előző programhoz, amely lenullázza az aktuális összeget! 
2.25.2. void cancel() { int act;
act = sum(0);
sum(-act);
} 
2.25.3.
#include <stdio.h> int sum(int data, int subTotal) { subTotal += data;
return subTotal;
} int main() { int num, total, subTotal=0;
char more = 'y';
} do { printf("Provide the next number: ");
scanf("%d", &num);
subTotal = sum(num, subTotal);
printf("Are there more number: (y/n) ");
_flushall();
scanf("%c", &more);
} while (more == 'y');
total = subTotal;
printf("The total is %d.\n", total);
return 0;

2.25.3. Módosítsa úgy az előző programot, hogy nem használ statikus változót, hanem paraméterként adja át az eddigi részösszeget! 2.26. Alias változók
2.26.1.
#include <stdio.h> int main() { int side;
int *side1=&side, *side2=&side, *side3=&side;
int surface, volume;
} printf("The side of the cube is: ");
scanf("%d", &side);
surface = 6**side1*(*side2);
volume = *side1*(*side2)**side3;
printf("The volume of the cube is: %d\n", volume);
printf("The surface of the cube is: %d\n", surface);
return 0;

2.26.1. Írjon programot, amelyben egy kocka felületét és térfogatát számolja ki! Úgy írja fel a képletet, hogy két ugyanolyan nevű változó ne szerepeljen benne, hanem használjon alias változókat mutatók segítségével. 
2.26.2. Demonstrálja, hogy a * és a & ellentétes hatású műveletek! 
2.26.2. printf("The volume of the cube is: %d\n", *&*&volume);

2.26.3.
#include <stdio.h> #define _USE_MATH_DEFINES
#include <math.h> int main() { float radius;
float *radius1 = &radius, *radius2 = &radius, *radius3 = &radius;
float surface, volume;
} printf("The radius of the ball is: ");
scanf("%f", &radius);
surface = 4 * (*radius1) * (*radius2) * (*radius3) * (M_PI) / 3;
volume = 4 * (*radius1) * (*radius2) * (M_PI);
printf("The volume of the ball is: %f\n", volume);
printf("The surface of the ball is: %f\n", surface);
return 0;

2.26.3. Írjon az előzőhöz hasonló programot gömbre vonatkozóan! 2.27. Két kulcsos hozzáférés
2.27.1
#include <stdio.h> int main() { int data=42, code=666, temp;
int *realAddress=&data, *changedAddress=0, *tryAddress;
changedAddress = realAddress - code;
printf("The 1st key: %p\n", changedAddress);
printf("Press 1 if the other person arrived: ");
scanf("%d", &temp);
printf("The 2nd key: %d\n", code);
changedAddress = NULL;
code = 0;
printf("To retrieve the data provide the 1st key: ");
scanf("%p", &changedAddress);
printf("Provide the 2nd key: ");
scanf("%d", &code);
tryAddress = changedAddress + code;
} if (tryAddress==realAddress) printf("Access granted, the data is: %d\n", *tryAddress);
else printf("Access denied!\n");
return 0;

2.27.1. Írjon programot, amely egy titkos adatnak (változónak) a címét egy mutatóba és egy egészbe kódolja úgy, hogy a mutató és az egész összege a változó címét eredményezi! A program adja meg a két adatot két embernek egyenként. Később kérje be a mutatót és az egészet és ha őket összeadva visszakapjuk a változó címét, akkor írja ki a változó értékét. 2.28. Többszörös indirekció
2.28.1.
#include <stdio.h> int main() { int data=42, *pData=&data, **ppData=&pData, ***pppData=&ppData;
int idxI;
printf("%10s %#p %#p %#p %#p \n", "address: ", &pppData, &ppData, &pData, &data);
printf("%10s ", "");
for (idxI=0;
idxI<4;
idxI++) printf("-----------");
printf("\n%10s |%#p| |%#p| |%#p| |%10d| \n", "value:", pppData, ppData, pData, data);
printf("%10s ", "");
for (idxI=0;
idxI<4;
idxI++) printf("-----------");
printf("\n%10s %-15s%-15s%-15s%-15s", "variable:", "pppData", "ppData", "pData", "data");
printf("\n%10s %-15s%-15s%-15s%-15s", "", "", "*pppData", "*ppData", "*pData");
printf("\n%10s %-15s%-15s%-15s%-15s", "", "", "", "**pppData", "**ppData");
printf("\n%10s %-15s%-15s%-15s%-15s", "", "", "", "", "***pppData");
return 0;
} 
2.28.1. Írjon programot, amely a konzolos képernyőn szemléltet egy int*** mutatót és az általa mutatott értékeket! Írja ki a jelenlévő változók címét, értékét és hogy milyen alternatív módon lehet hivatkozni a változókra! 
 
2.28.2
#include <stdio.h> int main() { double** myMatrix;
int *pData=&myMatrix, **ppData=&pData, ***pppData=&ppData;
int idxI, idxJ, idxK, temp = 0;
myMatrix = (double**)malloc(2 * sizeof(double*));
for (idxI=0;
idxI<2;
idxI++) { myMatrix[idxI] = (double*)malloc(3 * sizeof(double));
} for(idxI = 0;
idxI < 2;
idxI++) for(idxJ = 0;
idxJ < 3;
idxJ++) myMatrix[idxI][idxJ] = ++temp;
printf("****Adresses****\n");
printf("myMatrix**: [%#p] -> myMatrix[0,1]*: [%#p, %#p]\n", &myMatrix, &myMatrix[0], &myMatrix[1]);
printf("myMatrix[0]*: [%#p]-> myMatrix[0][0,1,2]: [%#p, %#p, %#p]\n", &myMatrix[0], &myMatrix[0][0], &myMatrix[0][1], &myMatrix[0][2]);
printf("myMatrix[1]*: [%#p]-> myMatrix[1][0,1,2]: [%#p, %#p, %#p]\n", &myMatrix[1], &myMatrix[1][0], &myMatrix[1][1], &myMatrix[1][2]);
printf("\n***Values****\n");
printf("myMatrix**: [%#p] : myMatrix[0,1]*: [%#p, %#p]\n", myMatrix, myMatrix[0], myMatrix[1]);
printf("myMatrix[0]*: [%#p] : myMatrix[0][0,1,2]: [%.2lf, %.2lf, %.2lf]\n", myMatrix[0], myMatrix[0][0], myMatrix[0][1], myMatrix[0][2]);
printf("myMatrix[1]*: [%#p] : myMatrix[1][0,1,2]: [%.2lf, %.2lf, %.2lf]\n", myMatrix[1], myMatrix[1][0], myMatrix[1][1], myMatrix[1][2]);
} for (idxI=0;
idxI<2;
idxI++) free(myMatrix[idxI]);
free(myMatrix);
return 0;

2.28.2. Írjon programot, amely a konzolos képernyőn szemléltet egy 2*3 dinamikus double tömböt! 2.29. Típusválasztás
2.29.1.
#include <stdio.h>
#include <malloc.h> int main() { int choice;
short int *si1=NULL, *si2=NULL;
long double *ld1=NULL, *ld2=NULL;
printf("Short int operands (1)\n");
printf("Long double operands (2)\n");
scanf("%d", &choice);
switch (choice) { case 1: si1 = (short int*)malloc(1*sizeof(short int));
si2 = (short int*)malloc(1*sizeof(short int));
printf("si1=");
scanf("%hd", si1);
printf("si2=");
scanf("%hd", si2);
*si1 = *si1 + * si2;
printf("The increased value is: %hd\n", *si1);
free(si1);
si1=NULL;
free(si2);
si2=NULL;
break;
case 2: ld1 = (long double*)malloc(1*sizeof(long double));
ld2 = (long double*)malloc(1*sizeof(long double));
printf("ld1=");
scanf("%Lf", ld1);
printf("ld2=");
scanf("%Lf", ld2);
*ld1 = *ld1 + *ld2;
printf("The increased value is: %Lf\n", *ld1);
free(ld1);
ld1=NULL;
free(ld2);
ld2=NULL;
break;
} return 0;
} 
2.29.1. Írjon programot, amelyben bekéri, hogy rövid egész vagy hosszú lebegőpontos típussal akar dolgozni. Hozzon létre két dinamikus változót a megfelelő típusból! Kérje be a változók értékeit és az első változó értékét növelje meg a másodikéval! 2.30. Struktúra kezelés
2.30.1.
#include <stdio.h> struct Var { char varChar;
short int varShortInt;
int varInt;
float varFloat;
double varDouble;
};
long double varLongDouble;
int *varPInt;
int main() { struct Var myVar;
printf("varChar=");
scanf("%c", &myVar.varChar);
printf("varShortInt=");
scanf("%hd", &myVar.varShortInt);
printf("varInt=");
scanf("%d", &myVar.varInt);
printf("varFloat=");
scanf("%f", &myVar.varFloat);
printf("varDouble=");
scanf("%lf", &myVar.varDouble);
printf("varLongDouble=");
scanf("%Lf", &myVar.varLongDouble);
printf("varPInt=");
scanf("%p", &myVar.varPInt);
} printf("\nmyVar\n");
printf("varChar=%c\n", myVar.varChar);
printf("varShortInt=%hd\n", myVar.varShortInt);
printf("varInt=%d\n", myVar.varInt);
printf("varFloat=%g\n", myVar.varFloat);
printf("varDouble=%lg\n", myVar.varDouble);
printf("varLongDouble=%Lg\n", myVar.varLongDouble);
printf("varPInt=%p", myVar.varPInt);
return 0;

2.30.1. Készítsen struktúrát, amely minden egyszerű adattípusból tartalmaz egyet valamint egy egészre mutató mutatót! Kérje be a struktúra adattagjait a konzolról, majd írja ki azokat! 
2.30.2.
#include <stdio.h>
#include <malloc.h> struct Var { char varChar;
short int varShortInt;
int varInt;
float varFloat;
double varDouble;
long double varLongDouble;
int *varPInt;
};
typedef struct Var VarType;
void readVarType(VarType *myVar) { printf("varChar=");
scanf("%c", &myVar->varChar);
printf("varShortInt=");
scanf("%hd", &myVar->varShortInt);
printf("varInt=");
scanf("%d", &myVar->varInt);
printf("varFloat=");
scanf("%f", &myVar->varFloat);
printf("varDouble=");
scanf("%lf", &myVar->varDouble);
printf("varLongDouble=");
} scanf("%Lf", &myVar->varLongDouble);
myVar->varPInt = &myVar->varInt;
void printVarType(VarType myVar) { printf("\nmyVar\n");
printf("varChar=%c\n", myVar.varChar);
printf("varShortInt=%hd\n", myVar.varShortInt);
printf("varInt=%d\n", myVar.varInt);
printf("varFloat=%g\n", myVar.varFloat);
printf("varDouble=%lg\n", myVar.varDouble);
printf("varLongDouble=%Lg\n", myVar.varLongDouble);
printf("*varPInt=%d", *myVar.varPInt);
} int main() { VarType myVar, *copy=NULL;
readVarType(&myVar);
printVarType(myVar);
copy = (VarType*)malloc(sizeof(VarType)*1);
*copy = myVar;
printVarType(*copy);
*((*copy).varPInt)=666;
printVarType(myVar);
free(copy);
copy=NULL;
return 0;
} 
2.30.2. Módosítsa az előző programot úgy, hogy létrehoz új típusnevet a struktúrának és ezt használja a továbbiakban! Külön függvényben valósítsa meg a struktúra bekérő és kiíró részt! Hozzon létre egy dinamikus struktúrát, amit tegyen egyenlővé a bekért struktúrával! Módosítsa a dinamikus struktúrán keresztül az egész mutató által mutatott értéket! 2.31. Esküvő
2.31.1.
#include <stdio.h>
#include <malloc.h> typedef struct { char name[200];
int age;
int ID;
} Person;
typedef struct { int carat;
float price;
int numberOfStones;
} Ring;
typedef struct { Person man, wife;
Ring weddingRing, engagementRing;
int guestNumber;
Person *guests;
} Wedding;
void printPerson(Person myPerson) { printf("person{");
printf("name=%s, ", myPerson.name);
printf("age=%d, ", myPerson.age);
printf("ID=%d}", myPerson.ID);
} void printRing(Ring myRing) { printf("ring{");
} printf("carat=%d, ", myRing.carat);
printf("price=%f, ", myRing.price);
printf("number of stones=%d}", myRing.numberOfStones);
void printWedding(Wedding myWedding) { int idxI;
printf("wedding{\n\tman=");
printPerson(myWedding.man);
printf(",\n\twife=");
printPerson(myWedding.wife);
printf(",\n\twedding ring=");
printRing(myWedding.weddingRing);
printf(",\n\tengagement ring=");
printRing(myWedding.engagementRing);
printf(",\n\tGuests={");
for (idxI=0;
idxI<myWedding.guestNumber;
idxI++) { printf("\n\t\t");
printPerson(myWedding.guests[idxI]);
printf(",");
} printf("\n\t}\n}");
} int main() { const int friendNumber=3;
Person friends[friendNumber]={{"Jani", 28, 12345}, {"Emese", 29, 66666}, {"Zoli", 32, 222222}};
Wedding brotherWedding={ {"Arpi", 32, 23332}, {"Panna", 29, 22222}, {16, 60000, 0}, {24, 200000, 3}, friendNumber, friends };
printf("brotherWedding=");
printWedding(brotherWedding);
return 0;
} 
2.31.1. Készítsen programot, amely tartalmazza a következő adatszerkezeteket: ember típus: név, életkor, azonosító;
gyűrű típus: karát, érték, kövek száma;
esküvő típus: férj, feleség, eljegyzési gyűrű, esküvői gyűrű, vendégek (dinamikus tömb), vendégek száma. Inicializáljon egy esküvő típusú változót, írja ki a változó értékét szépen tördelve úgy, hogy minden struktúra kiíráshoz külön függvényt hoz létre! 2.32. Ventilátor
2.3.1.
#include <stdio.h> int main() { int a, b;
char decision;
printf("Program to calculate the area or perimeter of a rectengular.\n");
printf("a=");
scanf("%d", &a);
printf("b=");
scanf("%d", &b);
printf("Would you like to calculate area (a) or perimeter (p) ? ");
scanf("%c", &decision);
if (decision=='a') { printf("The area of the rectengular is: %d", a*b);
} else { printf("The perimeter of the rectengular is: %d", (a+b)*2);
} } return 0;

2.3.1. Írjon programot, amely bekéri egy téglalap két oldalának a hosszát, és hogy területet vagy kerületet akar-e a felhasználó számolni! A választástól függően számolja ki a területet vagy a kerületet! Az oldal hosszak egész értékek, a választás karakter típusú. Ötlet: ügyeljen arra, hogy negatív nagyságú oldal nincsen! 
2.32.1.
#include <stdio.h>
#include <string.h>
#include <malloc.h> typedef struct { char manufacturer[20];
int productNumber;
char* description;
float price;
} Fan;
Fan readFan() { Fan rec;
int descriptionLength;
printf("Provide the data of the fan!\n");
printf("manufacturer: ");
gets(rec.manufacturer);
printf("product number: ");
scanf("%d", &rec.productNumber);
printf("max description length: ");
scanf("%d", &descriptionLength);
rec.description = (char*)malloc(sizeof(char)*descriptionLength);
_flushall();
printf("description: ");
gets(rec.description);
printf("price:");
scanf("%f", &rec.price);
return rec;
} void printFan(Fan rec) { printf("Fan data\n");
printf("manufacturer: %s\n", rec.manufacturer);
printf("product number:%d\n", rec.productNumber);
printf("description:%s\n", rec.description);
printf("price:%5.2f HUF\n", rec.price);
} int main() { Fan myFan;
myFan = readFan();
printFan(myFan);
free(myFan.description);
myFan.description=NULL;
return 0;
} 
2.32.1. Írjon programot, amelyben létrehoz egy ventilátor típust: gyártó (statikus tömb), termékszám, leírás (dinamikus tömb), ár! Írjon függvényt, amely bekéri az adattagok értékét és a rekordot visszatérési értékként adja vissza! Szintén írjon függvényt a struktúra kiírásához!
2.32.2.
#include <stdio.h>
#include <string.h>
#include <malloc.h> typedef struct { char manufacturer[20];
int productNumber;
char* description;
float price;
} Fan;
Fan readFan() { Fan rec;
int descriptionLength;
} printf("Provide the data of the fan!\n");
printf("manufacturer: ");
scanf("%s", rec.manufacturer);
printf("product number: ");
scanf("%d", &rec.productNumber);
printf("max description length: ");
scanf("%d", &descriptionLength);
rec.description = (char*) malloc(sizeof(char) * descriptionLength);
printf("description: ");
scanf("%s", rec.description);
printf("price: ");
scanf("%f", &rec.price);
return rec;
void printFan(Fan rec) { printf("manufacturer: %s\n", rec.manufacturer);
} printf("product number:%d\n", rec.productNumber);
printf("description:%s\n", rec.description);
printf("price:%5.2f HUF\n", rec.price);
int main() { Fan myFan,myFan2;
myFan = readFan();
myFan2=myFan;
myFan.description="A new file";
printf("Fan data\n");
printFan(myFan);
printf("Fan2 data\n");
printFan(myFan2);
free(myFan.description);
myFan.description = NULL;
free(myFan2.description);
myFan2.description = NULL;
} return 0;

2.32.2. Módosítsa úgy a programot, hogy a ventilátor változó értékét tegye egyenlővé egy másik változóval, módosítsa az eredeti változóban a gyártót és a leírást! Írassa ki újból mindkét struktúrát! Milyen furcsaságot tapasztal? Hogy lehet azt korrigálni? 2.33. Többszörösen összetett típus
2.3.2.
#include <stdio.h> int main() { float a, b;
char figure, property;
printf("Program to calculate the area or perimeter of a rectengular or square.\n");
printf("Calculate rectengular (r) or square (s) ");
scanf("%c", &figure);
if (figure=='r') { printf("a=");
scanf("%f", &a);
printf("b=");
scanf("%f", &b);
printf("Would you like to calculate area (a) or perimeter (p) ? ");
scanf("%c", &property);
if (property=='a') { printf("The area of the rectengular is: %f", a*b);
} else { printf("The perimeter of the rectengular is: %f", (a+b)*2);
");
} } } else { printf("a=");
scanf("%f", &a);
printf("Would you like to calculate area (a) or perimeter (p) ? scanf("%c", &property);
if (property=='a') { printf("The area of the square is: %f", a*a);
} else { printf("The perimeter of the square is: %f", a*4);
} } return 0;

2.3.2. Módosítsa az előző programot úgy, hogy az oldalak hossza tört érték is lehessen! A program elején kérje be, hogy négyzet vagy téglalapot vizsgál-e és ennek függvényében kérjen be egy vagy két oldal hosszat! 
2.33.1.
#include <stdio.h> const int maxStudentNumber=100;
const int maxCodeLength=6;
typedef struct { int sNum;
char sCode[maxStudentNumber][maxCodeLength+1];
float sPoints[maxStudentNumber];
} Class;
void printClass(Class *myClass, char comments[4][3][40]) { int idxI;
printf("%+10s%#20p%#20p%#20p\n", "address: ", myClass, myClass>sCode, myClass->sPoints);
printf("%+10s%20d%20c%20.1f\n", "value: ", myClass->sNum, myClass>sCode[0][0], myClass->sPoints[0]);
for (idxI=0;
idxI<4;
idxI++) { printf("%10s%20s%20s%20s\n", "", comments[idxI][0], comments[idxI][1], comments[idxI][2]);
} } int main() { Class myCl[2]={ {3, {"AA34", "BE3E", "CLY56"}, {16.4, 23.2, 40.0}}, {2, {"NMA444", "SE63"}, {13.2, 50.0}}, };
char myComments[4][3][40]= { {"myCl[0] "}, {"myCl[0].sNum", "myCl[0].sCode", "myCl[0].sPoints"}, {"", "myCl[0].sCode[0]", "myCl[0].sPoints[0]"}, {"", "myCl[0].sCode[0][0]"} };
printClass(&myCl[0], myComments);
printf("\n\n");
myComments[0][0][5] = '1';
myComments[1][0][5] = '1';
myComments[1][1][5] = '1';
myComments[1][2][5] = '1';
myComments[2][1][5] = '1';
myComments[2][2][5] = '1';
myComments[3][1][5] = '1';
printClass(&myCl[1], myComments);
return 0;
} 
2.33.1. Írjon programot, amelyben szemlélteti a karakteres képernyőn a struktúrák elhelyezkedését a memóriában! Hozzon létre egy osztály típusú struktúrát: hallgatók száma, hallgatók Neptun kódjai (statikus sztring tömb), hallgatók pontszámai (statikus lebegőpontos tömb)! Írjon függvényt, amely megjelenti a paraméterként átadott struktúra adattagjainak a címeit és értékeit (a tömb típusú mezőknek csak az első elemét kell megjeleníteni)! Írja ki azt is, hogy milyen más módon tud az adott címre hivatkozni! Ezt az információt is paraméterként adja át a kiíró függvénynek! Hozzon létre kételemű tömböt osztály típusú struktúrákból! Inicializálja a tömböt és hívja meg mindkét elemre a kiíró függvényt! 2.3. ábra: Lehetséges képernyőkép 2.34. Bitmezők
2.3.3. Bővítse ki a programot úgy, hogy az oldalak hossza csak pozitív érték lehet, síkidomválasztáskor a kis és a nagy betűket is fogadjuk el, ha rossz választ adtunk, akkor az jelezzük, vegyük be a választható idomok közé a szabályos háromszöget! 2.4. Számláló ciklus
2.3.3.
#include <stdio.h>
#include <math.h> int main() { float a, b;
char figure, prop;
printf("Program to calculate the area or perimeter of a rectengular, square or triangle.\n");
printf("Calculate rectengular (r) or square (s) or triangle (t)");
scanf("%c", &figure);
if (figure == 'r' || figure == 'R') { printf("a= ");
");
");
scanf("%f", &a);
if (a < 0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("b= ");
scanf("%f", &b);
if (b < 0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("Would you like to calculate area (a) or perimeter (p) ? scanf("%c", &prop);
if (prop == 'a') { printf("The area of the rectengular is: %f", a*b);
} else { printf("The perimeter of the rectengular is: %f", (a+b)*2);
} } else if (figure == 's' || figure == 'S') { printf("a= ");
scanf("%f", &a);
if (a<0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("Would you like to calculate area (a) or perimeter (p) ? scanf("%c", &prop);
if (prop == 'a') { printf("The area of the square is: %f", a*a);
} else { printf("The perimeter of the square is: %f", a*4);
} } else if (figure == 't' || figure == 'T') { printf("a=");
scanf("%f", &a);
if (a<0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("Would you like to calculate area (a) or perimeter (p) ? ");
scanf("%c", &prop);
if (prop == 'a') { printf("The area of the trianegle is: %f", a*a*sqrt(3)/4);
} else { printf("The perimeter of the triangle is: %f", a*3);
} } else { printf("Incorrect type of shape!\n");
return 1;
} return 0;
} 
2.34.1.
#include <stdio.h> const int maxStudentNumber=100;
const int maxCodeLength=6;
typedef struct { char name[100];
unsigned int sex :1;
unsigned int grownUp :1;
unsigned int zodiac :6;
10 - Aquarious unsigned int religion :3;
- Hinduism, 4 - Budhism, 5 - other unsigned int bloodType :2;
unsigned int RH :1;
} Person;
void readPerson(Person *myPerson) { int dummy;
printf("name=");
scanf("%s", myPerson->name);
printf("sex: 0 - female, 1 - male ");
scanf("%d", &dummy);
myPerson->sex=dummy;
printf("grown up: 0 - no, 1 - yes ");
scanf("%d", &dummy);
myPerson->grownUp=dummy;
printf("zodiac: 0 - Aries, 1 - Taurus, 2 - Gemini, 3 - Cancer, 4 Leo, 5 - Virgo, \ 6 - Libra, 7 - Scorpio, 8 - Sagittarius, 9 - Capricorn, 10 Aquarious, 11 - Pisces ");
scanf("%d", &dummy);
myPerson->zodiac=dummy;
printf("religion: 0 - Judaism, 1 - Christian, 2 - Islam, 3 Hinduism, \ 4 - Budhism, 5 - other ");
scanf("%d", &dummy);
myPerson->religion=dummy;
printf("bloodType: 0 - 0, 1 - A, 2 - B, 3 - AB ");
scanf("%d", &dummy);
myPerson->bloodType=dummy;
} printf("RH: 0 - -, 1 - + ");
scanf("%d", &dummy);
myPerson->RH=dummy;
void printPerson(Person *myPerson) { printf("person={name=%s, sex=", myPerson->name);
switch (myPerson->sex) { case 0: printf("female, ");
break;
case 1: printf("male, ");
break;
} printf("grown up=");
switch (myPerson->grownUp) { case 0: printf("no, ");
break;
case 1: printf("yes, ");
break;
} printf("zodiac=");
switch (myPerson->zodiac) { case 0: printf("Aries, ");
break;
case 1: printf("Taurus, ");
break;
case 2: printf("Gemini, ");
break;
case 3: printf("Cancer, ");
break;
case 4: printf("Leo, ");
break;
case 5: printf("Virgo, ");
break;
case 6: printf("Libra, ");
break;
case 7: printf("Scorpio, ");
break;
case 8: printf("Sagittarius, ");
break;
case 9: printf("Capricorn, ");
break;
case 10: printf("Aquarious, ");
break;
case 11: printf("Pisces, ");
break;
} printf("religion=");
switch (myPerson->religion) { case 0: printf("Judaism, ");
break;
case 1: printf("Christian, ");
break;
case 2: printf("Islam, ");
break;
case 3: printf("Hinduism, ");
break;
case 4: printf("Budhism, ");
break;
case 5: printf("other, ");
break;
} printf("bloodType=");
switch (myPerson->bloodType) { case 0: printf("0, ");
break;
case 1: printf("A, ");
break;
case 2: printf("B, ");
break;
case 3: printf("AB, ");
break;
} printf("RH=");
switch (myPerson->RH) { case 0: printf("-} ");
break;
case 1: printf("+} ");
break;
} printf("structure size in bytes = %d\n", sizeof(*myPerson));
} int main() { Person me;
readPerson(&me);
printf("\n");
printPerson(&me);
return 0;
} 
2.34.1. Írjon programot egyén adatainak a tárolásához! Az ember típus mezői a név (statikus tömb), nem, nagykorú-e, csillagjegye, vallása (5 nagy vallás vagy egyéb), élő személy-e, vércsoport, RH csoport! Használjon megfelelő hosszú bitmezőket! Írjon bekérő és kiíró függvényt, a kiíró függvénynél ne számokat, hanem azok jelentéseit írja ki! Határozza meg a struktúra méretét! 
2.34.2.
#include <stdio.h> const int maxStudentNumber = 100;
const int maxCodeLength = 6;
typedef struct { char name[100];
unsigned int sex;
unsigned int grownUp;
unsigned int zodiac;
10 - Aquarious unsigned int religion;
unsigned int bloodType;
unsigned int RH;
} Person;
void readPerson(Person *myPerson) { int dummy;
printf("name=");
scanf("%s", myPerson->name);
printf("sex: 0 - female, 1 - male ");
scanf("%d", &dummy);
myPerson->sex = dummy;
printf("grown up: 0 - no, 1 - yes ");
scanf("%d", &dummy);
myPerson->grownUp = dummy;
printf( "zodiac: 0 - Aries, 1 - Taurus, 2 - Gemini, 3 - Cancer, 4 Leo, 5 - Virgo, \ 6 - Libra, 7 - Scorpio, 8 - Sagittarius, 9 - Capricorn, 10 Aquarious, 11 - Pisces ");
scanf("%d", &dummy);
myPerson->zodiac = dummy;
printf( "religion: 0 - Judaism, 1 - Christian, 2 - Islam, 3 Hinduism, \ 4 - Budhism, 5 - other ");
scanf("%d", &dummy);
myPerson->religion = dummy;
printf("bloodType: 0 - 0, 1 - A, 2 - B, 3 - AB ");
scanf("%d", &dummy);
myPerson->bloodType = dummy;
} printf("RH: 0 - -, 1 - + ");
scanf("%d", &dummy);
myPerson->RH = dummy;
void printPerson(Person *myPerson) { printf("person={name=%s, sex=", myPerson->name);
switch (myPerson->sex) { case 0: printf("female, ");
break;
case 1: printf("male, ");
break;
} printf("grown up=");
switch (myPerson->grownUp) { case 0: printf("no, ");
break;
case 1: printf("yes, ");
break;
} printf("zodiac=");
switch (myPerson->zodiac) { case 0: printf("Aries, ");
break;
case 1: printf("Taurus, ");
break;
case 2: printf("Gemini, ");
break;
case 3: printf("Cancer, ");
break;
case 4: printf("Leo, ");
break;
case 5: printf("Virgo, ");
break;
case 6: printf("Libra, ");
break;
case 7: printf("Scorpio, ");
break;
case 8: printf("Sagittarius, ");
break;
case 9: printf("Capricorn, ");
break;
case 10: printf("Aquarious, ");
break;
case 11: printf("Pisces, ");
break;
} printf("religion=");
switch (myPerson->religion) { case 0: printf("Judaism, ");
break;
case 1: printf("Christian, ");
break;
case 2: printf("Islam, ");
break;
case 3: printf("Hinduism, ");
break;
case 4: printf("Budhism, ");
break;
case 5: printf("other, ");
break;
} printf("bloodType=");
switch (myPerson->bloodType) { case 0: printf("0, ");
break;
case 1: printf("A, ");
break;
case 2: printf("B, ");
break;
case 3: printf("AB, ");
break;
} printf("RH=");
switch (myPerson->RH) { case 0: printf("-}");
break;
case 1: printf("+}");
break;
} printf("structure size in bytes = %d\n", sizeof(*myPerson));
} int main() { Person me;
readPerson(&me);
printf("\n");
printPerson(&me);
return 0;
} 
2.34.2. Módosítsa úgy a struktúrát, hogy bitmezők helyett egész változókat használ! Mennyivel nő a struktúra mérete? 2.35. Szóbeli vizsga
2.35.1.
#include <stdio.h> typedef enum { awfull, bad, weak, good, excelent } Result;
void printResult(Result value) { switch (value) { case awfull: printf("awfull");
break;
case bad: printf("bad");
break;
case weak: printf("weak");
break;
case good: printf("good");
break;
case excelent: printf("excelent");
break;
} } int main() { Result exam1, exam2;
int dummy;
printf("Provide the result of your exam:\nawfull - %d, bad - %d, weak - %d, good- %d, excelent - %d ", awfull, bad, weak, good, excelent);
scanf("%d", &dummy);
exam1 = (Result)dummy;
printf("\nYour result is: ");
printResult(exam1);
printf("\n\nProvide the result of your repeating exam:\nawfull - %d, bad - %d, weak - %d, good- %d, excelent - %d ", awfull, bad, weak, good, excelent);
scanf("%d", &dummy);
exam2 = (Result)dummy;
} if (exam1 < exam2) { printf("Very good, you improved!");
} if (exam1 == exam2) { printf("At least you tried!");
} if (exam1 > exam2) { printf("You must be very unlucky!");
} return 0;

2.35.1. Írjon programot, amelyben bekéri egy szóbeli vizsga minősítését! A minősítés lehet: szörnyű, rossz, gyenge, jó, kiváló. Használjon felsorolás típust! Írjon függvényt a minősítés szöveges kiírására! Kérje be az ismétlő vizsga eredményét, határozza meg, hogy javított-e az illető! 
2.35.2. 
2.35.2. Oldja meg az eredeti feladatot #define-ok segítségével! Vezesse be a közepes minősítést! Miért jobb felsorolás típust használni define helyett? 2.36. Csak olvasható fájl
2.36.1.
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h> int main() { char buffer[50];
char dosCommand[200] = "echo >> ";
printf("file name=");
scanf("%s", buffer);
if( _chmod(buffer, _S_IREAD | _S_IREAD) == -1 ) printf("File not found\n");
else printf("Mode changed to read-only\n");
strcat(dosCommand, buffer);
system(dosCommand);
if( _chmod(buffer, _S_IWRITE ) == -1) printf("File not found\n");
else printf("Mode changed to read/write\n");
system(dosCommand);
return 0;
} 
2.36.1. Írjon programot, amely beállítja egy fájl „csak olvasható” tulajdonságát! Kérje be egy szöveges fájl nevét! Állítsa be a fájl csak olvasható tulajdonságát, majd próbáljon meg a fájl végéhez fűzni egy szöveget C-ből hívott DOS parancs segítségével (DOS parancs: echo text >>fileName)! Futtassa a DOS parancsot C-ből: system(char*) segítségével! Törölje a csak olvasható tulajdonságot és próbáljon ismét a fájl végéhez fűzni egy szöveget! 
2.36.2.
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h> int main() { char buffer[50];
char dosCommand[200] = "echo >> ";
printf("file name=");
scanf("%s", buffer);
strcat(dosCommand, buffer);
if (_chmod(buffer, _S_IWRITE) == -1) printf("File not found\n");
else { printf("Mode changed to read/write\n");
remove(buffer);
printf("File deleted\n");
} return 0;
} 
2.36.2. Írja meg a tuti törlés programot! A program először törli a csak olvasható tulajdonságot és utána DOS parancs segítségével törli a fájlt. 2.37. Átnevezés
2.37.1. Feladat: Írjon programot fájlok átnevezésére! A régi és az új fájlnév a program paraméterében legyen adott! Ha valamelyik paraméter hiányzik, akkor írja ki a helyes használatot! Ha hiba történik átnevezés közben, akkor írja ki a megfelelő hibaüzenetet a hibakód alapján! 2.38. Szövegfájl
2.37.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> extern int errno;
int main(int argc, char* argv[]) { char oldName[50], newName[50];
int result;
if (argc != 3) { printf("Usage:\n prgName oldName newName\n");
exit(1);
} strcpy(oldName, argv[1]);
strcpy(newName, argv[2]);
rename(oldName, newName);
result = errno;
switch (result) { case 0: printf("Done! ");
break;
case EEXIST: printf("%s already exists!", newName);
break;
case ENOENT: printf("%s does not exist!", oldName);
break;
case EINVAL: printf("Wrong characters in '%s'!", newName);
break;
} } return 0;

2.38.1.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> int main() { FILE* tf;
int idxI, data, min, max;
char fileName[200];
double num;
printf("This program will save certain ammount number random number in a file.\n");
printf("file name=");
scanf("%s", fileName);
printf("min number=");
scanf("%d", &min);
printf("max number=");
scanf("%d", &max);
printf("number of data=");
scanf("%lf", &num);
srand((unsigned)time(NULL));
tf=fopen(fileName, "w");
if (tf==NULL) { fprintf(stderr, "File open to write has failed!\n");
exit(-1);
} for(idxI=0;
idxI<(int)num;
idxI++) { data = rand()+max+1-min;
fprintf(tf, "%d\n", data);
} fclose(tf);
tf = NULL;
return 0;
} 
2.38.1. Írjon programot, amely bekéri a következő információkat: minimális érték, maximális érték fájl név, adatok száma! Generáljon adott számú véletlen számot a megfelelő határok között és mentse el azokat egy szövegfájlba külön sorokba! 
2.38.2.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> int main() { FILE* tf;
int idxI, data, min, max, db = 0;
char fileName[200];
int num;
printf("This program will save certain ammount number random number in a file.\n");
printf("file name=");
scanf("%s", fileName);
printf("min number=");
scanf("%d", &min);
printf("max number=");
scanf("%d", &max);
printf("number of data=");
scanf("%d", &num);
srand((unsigned) time(NULL));
tf = fopen(fileName, "w");
if (tf == NULL) { fprintf(stderr, "File open to write has failed!\n");
exit(-1);
} fprintf(tf, "%d\n", num);
for (idxI = 0;
idxI < num;
idxI++) { data = rand() % (max + 1 - min) + min;
fprintf(tf, „%d\t”, data);
db++;
if (db == 100) { fprintf(tf, "\n");
db = 0;
} } fclose(tf);
tf = NULL;
return 0;
} 
2.38.2. Módosítsa úgy a programot, hogy az első sorba írja ki az adatok számát! Szóközökkel válassza el az egyes értékeket és minden számot fix hosszan írjon ki! 100 számonként szúrjon be egy üres sort! 2.39. Hamupipőke
2.39.1.
#include <stdio.h>
#include <stdlib.h> double average(char* fileName) { double result, sum=0;
int counter=0, data;
FILE* file;
file = fopen(fileName, "r");
while ( !feof(file) ) { fscanf(file, "%d", &data);
counter++;
sum += data;
} } fclose(file);
file = NULL;
result = sum / counter;
return result;
int main() { FILE *orig=NULL, *even=NULL, *odd=NULL;
int evenCounter=0, oddCounter=0, data;
char origFileName[200], evenFileName[200]="even.txt", oddFileName[200]="odd.txt";
double evenAverage, oddAverage;
printf("This program will divide a bunch of number according to parity.\n");
printf("file name=");
scanf("%s", origFileName);
orig = fopen(origFileName, "r");
if (orig == NULL) { fprintf(stderr, "File open to read has failed!\n");
exit(-1);
} even = fopen(evenFileName, "w");
odd = fopen(oddFileName, "w");
while ( !feof(orig) ) { fscanf(orig, "%d", &data);
if (data%2 == 0) { evenCounter++;
fprintf(even, "%d\n", data);
} else { oddCounter++;
fprintf(odd, "%d\n", data);
} } fclose(orig);
orig = NULL;
fclose(even);
even = NULL;
fclose(odd);
odd = NULL;
printf("There were %d even and %d odd number, their ratio is: %8lg\n", evenCounter, oddCounter, (double)evenCounter/oddCounter);
evenAverage = average(evenFileName);
oddAverage = average(oddFileName);
printf("The average of the even numbers: %.9lg\nThe average of the odd numbers: %.9lg\n", evenAverage, oddAverage);
return 0;
} 
2.39.1. Írjon programot, amely egy már meglévő, véletlen számokat tartalmazó fájlban lévő számokat szétválogatja párosság alapján! A páros és páratlan számokat tárolja külön fájlokban! Írjon függvényt, amely kiszámolja az egy fájlban lévő számok átlagát! Alkalmazza a függvényt a két fájlra és határozza meg a két fájlban lévő számok mennyiségének az arányát! 2.40. XML
2.40.1.
#include <stdio.h>
#include <stdlib.h> typedef struct { int ID;
double price;
} Car;
typedef struct { char name[200];
int age;
int carNumber;
Car* myCars;
} Person;
void printHalfTag(FILE* file, int depth, char* tag) { int idxI;
for (idxI=0;
idxI<depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s>\n", tag);
} void printFullTag(FILE* file, int depth, char* tag, char* text) { int idxI;
for (idxI=0;
idxI<depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s>%s</%s>\n", tag, text, tag);
} void printPerson(FILE* file, Person* buddy) { int idxI;
char temp[500];
printHalfTag(file, 0, "Person");
printFullTag(file, 1, "Name", buddy->name);
sprintf(temp, "%d", buddy->age);
printFullTag(file, 1, "Age", temp);
printFullTag(file, 1, "Count", buddy-> carNumber);
for (idxI=0;
idxI<buddy->carNumber;
idxI++) { printHalfTag(file, 1, "Car");
sprintf(temp, "%d", buddy->myCars[idxI].ID);
printFullTag(file, 2, "ID", temp);
sprintf(temp, "%lf", buddy->myCars[idxI].price);
printFullTag(file, 2, "price", temp);
printHalfTag(file, 1, "/Car");
} printHalfTag(file, 0, "/Person");
} int main() { const int buddyNumber=3;
int idxI;
Car init[buddyNumber][3]={ { {0, 50}, {2, 12.369}, {21, 0.569} }, {{6, 21}, {1, 15.4}}, {{3, 5.7}}, };
Person buddies[buddyNumber]={{"Jani", 22, 3, init[0]}, {"Evi", 36, 2, init[1]}, {"Zotya", 25, 1, init[2]} };
FILE *file=NULL;
char fileName[200]="car.txt";
file = fopen(fileName, "w");
for (idxI=0;
idxI<buddyNumber;
idxI++) { printPerson(file, &buddies[idxI]);
} fclose(file);
file = NULL;
return 0;
} 
2.40.1. Írjon programot, amely XML-ben ment el rekordokat! A kocsi típus azonosítót és árat, a személy típus nevet, életkort, a kocsik számát, és kocsi tömböt tartalmaz. Hozzon létre és inicializáljon egy 3 hosszú személy tömböt és mentse el azokat XML fájlba! Az XML fájl legyen szépen tördelve! Írjon halfTag és fullTag függvényeket! Az előbbi csak „<tagName>” vagy „</tagName>” -t ír ki, az útóbbi „<tagName> Text </tagName>”-t ír ki. Példa: <Person> <Name>Jani</Name> <Age>22</Age> <Count>3</ Count> <Car> <ID>0</ID> <price>50.000000</price> </Car> <Car> … 
2.40.2.
#include <stdio.h>
#include <stdlib.h> typedef struct { int ID;
double price;
} Car;
typedef struct { char name[200];
int age;
int carNumber;
Car* myCars;
} Person;
void printHalfTag(FILE* file, int depth, char* tag) { int idxI;
} for (idxI = 0;
idxI < depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s>\n", tag);
void printFullTag(FILE* file, int depth, char* tag, char* text) { int idxI;
} for (idxI = 0;
idxI < depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s\"%s\"/>\n", tag, text);
void printPerson(FILE* file, Person* buddy) { int idxI;
char temp[500];
} printHalfTag(file, 0, "Person");
printFullTag(file, 1, "Name value=", buddy->name);
sprintf(temp, "%d", buddy->age);
printFullTag(file, 1, "Age value=", temp);
printHalfTag(file, 1, "Cars");
for (idxI = 0;
idxI < buddy->carNumber;
idxI++) { printHalfTag(file, 2, "Car");
sprintf(temp, "%d", buddy->myCars[idxI].ID);
printFullTag(file, 3, "Id value", temp);
sprintf(temp, "%lf", buddy->myCars[idxI].price);
printFullTag(file, 3, "Price value=", temp);
printHalfTag(file, 2, "/Car");
} printHalfTag(file, 1, "/Cars");
printHalfTag(file, 0, "/Person");
int main() { const int buddyNumber = 3;
int idxI;
Car init[3][3] = { { { 0, 50 }, { 2, 12.369 }, { 21, 0.569 } }, { { 6, 21 }, { 1, 15.4 } }, { { 3, 5.7 } }, };
Person buddies[3] = { { "Jani", 22, 3, init[0] }, { "Evi", 36, 2, init[1] }, { "Zotya", 25, 1, init[2] } };
FILE *file = NULL;
char fileName[200] = "car.txt";
} file = fopen(fileName, "w");
for (idxI = 0;
idxI < buddyNumber;
idxI++) { printPerson(file, &buddies[idxI]);
} fclose(file);
file = NULL;
printf("XML file created in car.txt.\n");
return 0;

2.40.2. Módosítsa úgy az XML fájlt, hogy Car tag-k egy Cars tag-on belül legyenek! Ahol lehet, az adatok a tagok tulajdonságaiban szerepeljenek! Például: <name value="Jani"/> 
2.40.3. Készítsen beolvasó programot! Jelezze ki az XML fájl szintaktikai hibáit! Például hibás tag, nyitó tag párja hiányzik vagy fordítva, két tag pár keresztben van. 2.41. Stopper
2.40.3. <Person> <Name>Jani</Name> <Age>22</Age> <Car> <ID>0</ID> <price>50.000000</price> </Car> <Car> <ID>2</ID> <price>12.369000<price> </Car> <Car> <ID>21</ID> <price>0.569000</price> </Car> </Person> <Person> <Name>Evi</Name> <Age>36</Age> <Car> <ID>6</ID> <price>21.000000</price> </Car> <Car> <ID>1<ID> <price>15.400000</price> </Car> </Person> <Person> <Name>Zotya</Name> <Age>25</Age> <Car> <ID>3</ID> <price>5.700000</price> </Car> </Person>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> int main() { char data[200][200];
char tag[50], newtag[50];
int idxI, idxJ, idxK, rows = 0, TagIdx = 0, Found = 0,Error=0;
FILE * fd = fopen("file.xml", "r");
if (!fd) { printf("file.xml is not found");
exit(1);
} while (!feof(fd)) { fscanf(fd, "%s", data[rows]);
rows++;
} for (idxI = 0;
idxI < rows;
idxI++) { idxJ = 0;
TagIdx = 0;
Found = 0;
if (data[idxI][idxJ] == '<' && data[idxI][idxJ + 1] != '/') { do { tag[TagIdx] = data[idxI][idxJ];
TagIdx++;
idxJ++;
} while (data[idxI][TagIdx - 1] != '>');
tag[TagIdx] = '\0';
newtag[strlen(tag) + 1] = '\0';
for (idxK = strlen(tag);
idxK > 0;
idxK--) { if (idxK != 1) { newtag[idxK] = tag[idxK - 1];
} else newtag[idxK] = '/';
} newtag[0] = tag[0];
if (strlen(data[idxI]) > strlen(tag)) { if (strstr(data[idxI], newtag)) { Found = 1;
data[idxK][0] = '\0';
} else { printf("Error at line: %d.\n\tNo close TAG for %s.\n", idxI + 1, tag);
Error=1;
} } else { for (idxK = idxI+1;
idxK < rows;
idxK++) { if (!strcmp(tag, data[idxK]) && !Found) { printf("At line %d.\n\tNo closeTAG for %s.\n", idxI+1,tag);
Error=1;
idxK=rows;
} else if (strstr(data[idxK], newtag) && !Found) { Found = 1;
data[idxK][0] = '\0';
} } } } } } if(!Error){ printf("No errors detected!\n");
} return 0;

2.41.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { clock_t actClock;
double actSec=0;
while (actSec < 11) { actClock = clock();
actSec = (double)actClock / CLOCKS_PER_SEC;
printf("\n%lf", actSec);
} return 0;
} 
2.41.1. Készítsünk stopperórát, amely a program indításától eltelt időt írja ki folyamatosan! A program 11 másodperc után álljon meg! 
2.41.2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { clock_t actClock;
double actSec=0;
int intActSec=0, intOldSec=0;
while (actSec < 11) { actClock = clock();
actSec = (double)actClock / CLOCKS_PER_SEC;
intActSec = (int)actSec;
if (intActSec>intOldSec) { printf("\n%d", intActSec);
intOldSec = intActSec;
} } return 0;
} 
2.41.2. Módosítsa a programot úgy, hogy csak minden egész másodpercben írja ki az eltelt időt! 2.42. Időpont formázása
2.4.1.
#include <stdio.h> int main() { int idxI;
for(idxI = 0;
idxI < 10;
idxI = idxI + 1) { printf(" idxI is %d\n", idxI);
} return 0;
} 
2.4.1. Írjon programot, amely kiírja az egész számokat 0-tól 9-ig! 
2.42.1.
#include <stdio.h>
#include <sys/timeb.h>
#include <time.h> int main() { struct _timeb timebuffer;
char* timeline;
int start, act;
_ftime(&timebuffer);
start = timebuffer.time;
do { _ftime(&timebuffer);
timeline = ctime(&timebuffer.time);
act = timebuffer.time;
printf("\n%.8s.%hu", &timeline[11], timebuffer.millitm);
} while (act-start < 10);
return 0;
} 
2.42.1. Írjon programot, amely 10 másodpercen keresztül folytonosan kiírja az aktuális időt ezredmásodperc pontossággal! Használja az _ftime és ctime függvényeket! 2.43. Tippelés
2.4.2.
#include <stdio.h> int main() { int idxI;
for(idxI = 60;
idxI >= 40;
idxI = idxI - 2) { printf(" idxI is %d\n", idxI);
} return 0;
} 
2.4.2. Módosítsa az előző programot úgy, hogy 40-től 60-ig fordított sorrendben, a páros számokat írja ki! Az intervallum mindkét határát írja ki! 2.5. Sebességmérés
2.43.1.
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h> int main() { clock_t start, end;
int wait;
char temp[50];
double actWait;
srand((unsigned)time(NULL));
printf("Press 'a' and enter to start the clock!\n");
printf("Do the same to stop it!\n");
printf("Type quit to end program!\n");
while (strcmp(temp, "quit") != 0) { wait = rand()%4 + 1;
printf("\nWait for %d seconds!\n", wait);
printf("Begin: ");
scanf("%s", temp);
if (strcmp(temp, "quit")==0) break;
start = clock();
printf("End: ");
scanf("%s", temp);
end = clock();
actWait = (double)(end - start) / CLOCKS_PER_SEC;
printf("You have waited %6.2lf seconds instead of %d. ", actWait, wait);
} return 0;
} 
2.43.1. Írjon időtippelő programot! A program állítson elő egy véletlen számot 1 és 5 között és ezt írja ki a képernyőre! Ennyi időt kell majd várni a felhasználónak. Ezután kérjen be két sztringet úgy, hogy méri a bekérések között eltelt időt! Írja ki, hogy ténylegesen mennyi idő telt el a két bekérés között! Ha a bemenet a „quit” sztring, akkor lépjen ki a programból! 2.44. Milyen nap?
2.44.1.
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h> int main() { int year, month, day, guessWeekDay, guessYearDay;
tm tmBuffer;
char string[30];
tmBuffer.tm_hour = 0;
tmBuffer.tm_min = 0;
tmBuffer.tm_sec = 0;
tmBuffer.tm_isdst = -1;
srand((unsigned)time(NULL));
year = rand()%40+1970;
month = rand()%12+1;
day = rand()%30+1;
tmBuffer.tm_year = year-1900;
tmBuffer.tm_mon = month;
tmBuffer.tm_mday = day;
printf("What is the day of the week on %d/%d %d?\n", month, day, year);
printf("0 - Sunday, 1 - Monday, ...;
your guess: ");
scanf("%d", &guessWeekDay);
mktime(&tmBuffer);
strftime(string, 30, "%A", &tmBuffer);
if (tmBuffer.tm_wday == guessWeekDay) { printf("You are rigth %d/%d %d is really %s.\n", month, day, year, string);
} else { printf("You are wrong %d/%d %d is %s.\n", month, day, year, string);
} printf("\nWhat is the day of the year on the same date? ");
scanf("%d", &guessYearDay);
if (tmBuffer.tm_yday == guessYearDay) { printf("You are rigth %d/%d %d is the %d day of the year.\n", month, day, year, tmBuffer.tm_yday);
} else { printf("You are wrong %d/%d %d is the %d day of the year.\n", month, day, year, tmBuffer.tm_yday);
} return 0;
} 
2.44.1. Írjon programot, amely véletlenszerűen meghatároz egy évet, hónapot, napot és utána tippelni kell, hogy az a hét illetve év napjai közül a hányadik! Adja meg hogy helyesek voltak-e a tippek! 2.45. Hérón képlet
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
2.46.2.
#include <iostream> using namespace std;
class isoscelesTriangle { private: float a;
float b;
float c;
public: bool check() const;
float area() const;
float perimeter() const;
void display() const;
void setA(float para) {a=para;} void setB(float para) {b=para;} void setC(float para) {this->c=para;} float getA() const {return a;} float getB() const {return this->b;} float getC() const {return c;} };
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
if (valid) cout << "The sides are: " << this->a << ", " << b << ", " << getC() << endl;
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
2.46.3.
#include <iostream> using namespace std;
class equilateralTriangle { private: float a;
float b;
float c;
public: bool check() const;
float area() const;
float perimeter() const;
void display() const;
void setA(float para) {a=para;} void setB(float para) {b=para;} void setC(float para) {this->c=para;} float getA() const {return a;} float getB() const {return this->b;} float getC() const {return c;} };
bool equilateralTriangle::check() const { bool result=false;
if (a==b && b==c) result=true;
return result;
} float equilateralTriangle::area() const { float s=(a+b+c)/2;
float result=s*(s-a)*(s-b);
return result;
} float equilateralTriangle::perimeter() const { float result=a+b+c;
return result;
} void equilateralTriangle::display() const { bool valid=check();
cout << boolalpha;
cout << "The triangle is valid: " << valid << endl;
if (valid) cout << "The sides are: " << this->a << ", " << b << ", " << getC() << endl;
} int main() { equilateralTriangle myObject;
myObject.setA(3);
myObject.setB(3);
myObject.setC(5);
myObject.display();
if (myObject.check()) { cout << "Area: " << myObject.area() << endl;
cout << "Perimeter: " << myObject.perimeter() << endl;
} return 0;
} 
2.46.3. Készítsen hasonló osztályt szabályos háromszögre! 2.47. Statikus adattag
2.47.1.
#include <iostream>
#include <fstream>
#include <cstring> using namespace std;
class Counter { char fileName[500];
ofstream file;
public: static int lineCount;
void init(char* para);
void close() {file.close();} void write(const char* line);
static int getLineCount() {return lineCount;} static void resetLineCount() {lineCount=0;} };
void Counter::init(char* para) { strcpy(fileName, para);
file.open(fileName);
} void Counter::write(const char* line) { file << line << endl;
lineCount++;
} int Counter::lineCount=0;
// class variable def. int main() { Counter obj1, obj2;
cout << "The number of lines have written till now:" << Counter::lineCount << endl;
obj1.init("file1.txt");
obj1.write("The first line");
obj1.write("and the second");
cout << "The number of lines have written till now:" << obj1.lineCount << endl;
obj2.init("file2.txt");
obj2.write("New line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
Counter::resetLineCount();
obj1.write("Strange line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
obj1.close();
obj2.close();
return 0;
} 
2.47.1. Készítsen osztályt, amelynek segítségével fájlba tud írni sorokat! A fájlnevet tudjuk beállítani objektumonként és statikus adattag számolja a program által eddig kiírt sorok számát! Lehessen ezt az adattagot lenullázni és lekérdezni! 
2.47.2.
#include <iostream>
#include <fstream>
#include <cstring> using namespace std;
class Counter { char fileName[500];
ofstream file;
public: static int lineCount;
static int wordCount;
static int charCount;
void init(const char* para);
void close() {file.close();} void write(const char* line);
};
void Counter::init(const char* para) { strcpy(fileName, para);
file.open(fileName);
} void Counter::write(const char* line) { int i=0;
while (line[i]!='\0') { file << line[i];
charCount++;
if (line[i]==' ') { wordCount++;
} i++;
} if (line[0]!='\0') { wordCount++;
} file << endl;
lineCount++;
} int Counter::lineCount=0;
// int Counter::wordCount=0;
// int Counter::charCount=0;
// class variable def. class variable def. class variable def. int main() { Counter obj1, obj2;
cout << "The number of lines have written till now:" << Counter::lineCount << endl;
obj1.init("file1.txt");
obj1.write("The first line");
obj1.write("and the second");
cout << "The number of lines have written till now:" << obj1.lineCount << endl;
obj2.init("file2.txt");
obj2.write("New line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
obj2.lineCount=0;
obj1.write("Strange line");
cout << "The number of lines have written till now:" << obj2.lineCount << endl;
obj1.close();
obj2.close();
return 0;
} 
2.47.2. Módosítsa az előző programot úgy, hogy számolja a szavak és karakterek számát is! 2.48. Komplex számok
2.48.1.
#include <iostream>
#include <cstring> using namespace std;
class Complex { float real, im;
Complex multiply(const Complex&) const;
public: void setReal(float para) {real=para;} void setIm(float para) {im=para;} float getReal() const {return real;} float getIm() const {return im;} void display() const;
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
} Complex Complex::multiply(const Complex& para) const { float resultReal, resultIm;
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
2.48.1. Írjon komplex szám osztályt! Használjon privát adattagokat! Írja meg az add, sub, mul, div metódusokat! Az említett metódusok írják ki a műveletek eredményét a képernyőre! 
2.48.2.
#include <iostream>
#include <cstring> using namespace std;
class Complex { float real, im;
Complex multiply(const Complex&) const;
public: void setReal(float para) {real=para;} void setIm(float para) {im=para;} float getReal() const {return real;} float getIm() const {return im;} void display() const;
Complex sum(const Complex&) const;
Complex sub(const Complex&) const;
Complex mul(const Complex&) const;
Complex div(const Complex&) const;
friend ostream& operator <<(ostream &os,const Complex &obj);
};
ostream& operator <<(ostream &os,const Complex &obj) { os<< "(" << obj.real << " + " << obj.im << "i)";
return os;
} Complex Complex::sum(const Complex& para) const { float resultReal, resultIm;
Complex result;
} resultReal=real+para.real;
resultIm=im+para.im;
result.real=resultReal;
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
} Complex Complex::multiply(const Complex& para) const { float resultReal, resultIm;
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
} a.setReal(1);
a.setIm(2);
b.setReal(3);
b.setIm(4);
cout << a << " + " << b << "=" << a.sum(b) << endl;
cout << a << " - " << b << "=" << a.sub(b) << endl;
cout << a << " * " << b << "=" << a.mul(b) << endl;
cout << a << " / " << b << "=" << a.div(b) << endl;
return 0;

2.48.2. Módosítsa úgy a programot, hogy a metódusok ne végezzenek kiírást, hanem adják vissza az eredményt objektumként! Valósítsa meg kiíró operátort a komplex osztályra! 
2.48.3.
#include <iostream>
#include <cstring> using namespace std;
class Complex { float real, im;
Complex multiply(const Complex&) const;
public: void setReal(float para) {real=para;} void setIm(float para) {im=para;} float getReal() const {return real;} float getIm() const {return im;} void display() const;
Complex sum(const Complex&) const;
Complex sub(const Complex&) const;
Complex mul(const Complex&) const;
Complex div(const Complex&) const;
friend ostream& operator <<(ostream &os,const Complex &obj);
const Complex operator+(const Complex &other) const { Complex result = sum(other);
return result;
} const Complex operator-(const Complex &other) const { Complex result = sub(other);
return result;
} const Complex operator*(const Complex &other) const { Complex result = mul(other);
return result;
} const Complex operator/(const Complex &other) const { Complex result = div(other);
return result;
} };
ostream& operator <<(ostream &os,const Complex &obj) { os<< "(" << obj.real << " + " << obj.im << "i) ";
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
} Complex Complex::multiply(const Complex& para) const { float resultReal, resultIm;
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

2.48.3. Valósítsa meg az aritmetikai függvényeket operátorok segítségével! 2.49. Telefonszámla
2.49.1.
#include <stdio.h>
#include <stdlib.h> #define NEV_HOSZ 11 #define INPUT_FILE "in.txt" struct TSubscriber { char FirstName[NEV_HOSZ];
char LastName[NEV_HOSZ];
int InRushH, OutRushH;
int TotalMin, Fee;
};
void read(FILE * fd, int num, struct TSubscriber * Subscribers) { int i;
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s", Subscribers[i].FirstName, Subscribers[i].LastName);
fscanf(fd, "%d %d", &Subscribers[i].InRushH, &Subscribers[i].OutRushH);
} } void calc(int num, struct TSubscriber * A, int csucs, int kedv) { int i;
int MaxMin = 0;
int MaxFee = 0;
for (i = 0;
i < num;
i++) { A[i].Fee = A[i].InRushH * csucs + A[i].OutRushH * kedv;
A[i].TotalMin = A[i].InRushH + A[i].OutRushH;
printf("\t\t\t %5d Ft %5d minute\r%s %s :\n", A[i].Fee, A[i].TotalMin, A[i].FirstName, A[i].LastName);
if (MaxMin < A[i].TotalMin) MaxMin = A[i].TotalMin;
if (MaxFee < A[i].Fee) MaxFee = A[i].Fee;
} printf("\nHighest fee: %d Ft\n", MaxFee);
for (i=0;
i<num;
i++) { if (A[i].Fee == MaxFee) } printf("\t%s %s\n", A[i].FirstName, A[i].LastName);
} printf("\nLongest speaking: %d Ft\n", MaxMin);
for (i=0;
i<num;
i++) { if (A[i].TotalMin == MaxMin) printf("\t%s %s\n",A[i].FirstName, A[i].LastName);
} int main() { struct TSubscriber * Subscribers = NULL;
int inrush, outrush, num;
FILE * fd = fopen(INPUT_FILE, "r");
if (fd == NULL) { perror("Hiba");
return 0;
} fscanf(fd, "%d", &num);
fscanf(fd, "%d %d", &inrush,&outrush);
Subscribers = (struct TSubscriber *)malloc(num * sizeof(struct TSubscriber));
read(fd, num, Subscribers );
fclose(fd);
calc(num, Subscribers, inrush, outrush);
free(Subscribers);
Subscribers = NULL;
} return 0;

2.49.1. Írjon programot egy telefontársaság számára, ami az egyes előfizetők telefonszámláit szeretné kiszámolni! Az előfizetők adatai az „in.txt” nevű fájlban tárolja! A program készítsen felsorolást minden előfizető számára, amelynek tartalmaznia kell a teljes beszélgetési időt, és a fizetendő összeget! Ezután a program számolja ki, melyik előfizető telefonált összesen a legtöbb ideig, ez milyen hosszú idő, kinek kell a legtöbbet fizetni, és mennyit! Használjon dinamikus tömböket! Feltételezzük, hogy a bemeneti fájl az előírásoknak megfelelő. Az input formátuma: Első sor: az előfizetők száma Második sor: két tízes számrendszerbeli szám, a csúcsidőben való telefonálás tarifája, és a csúcsidőn kívüli telefonálás tarifája. A többi sor az előfizetők adatait tárolja: az előfizető neve (keresztnév, vezetéknév), majd két tízes számrendszerbeli szám: mennyi időt telefonált az illető csúcsidőben, illetve csúcsidőn kívül. Mind a keresztnév, mind a vezetéknév maximum 10 karakterből áll. Példa bemenet: 2 3 1 csúcsidőn kívül Bela Kovacs 731 123 123 percet csúcsidőn kívül Mihaly Toth 300 35 Kimenet: Bela Kovacs: Mihaly Toth: 2316 Ft 935 Ft 854 minute 335 minute Highest fee: 2316 Ft Bela Kovacs Longest speaking: 854 Ft Bela Kovacs 2.50. Halmazok metszete
2.50.1.
#include <stdio.h>
#include <stdlib.h> #define INPUT_FILE "sets.txt" #define max(a, b) ((a) > (b) ? (a) : (b)) #define min(a, b) ((a) > (b) ? (b) : (a)) void ReadSet(FILE * fd, int * size, int ** set) { int i;
fscanf(fd, "%d", size);
*set = (int *)malloc(sizeof(int) * (*size) );
for (i = 0;
i < *size;
i++) fscanf(fd, "%d", *set + i);
printf("\n");
} void PrintSet(char * name, int size, int * set) { int i;
printf("%s = ", name);
printf("{");
for (i = 0;
i < size - 1;
i++) } printf("%d, ", set[i]);
if (size > 0) printf("%d", set[size - 1]);
printf("}\n");
int Element(int e, int size, int * S) { int i = 0;
while ((i < size) && (S[i] != e)) i++;
return i < size;
} void Intersection(int SizeA, int SizeB, int * SizeI, int * SA, int * SB, int ** C) { int size = 0;
int i;
*SizeI = 0;
int * A = SizeA > SizeB ? SA : SB;
int * B = SizeA > SizeB ? SB : SA;
for (i = 0;
i < max(SizeA, SizeB);
i++) { if (Element(A[i], max(SizeA, SizeB), A) && Element(A[i], min(SizeA, SizeB), B) ) (*SizeI)++;
} *C = (int *)malloc(sizeof(int) * (*SizeI) );
for (i = 0;
i < max(SizeA, SizeB);
i++) { if (Element(A[i], max(SizeA, SizeB), A) && Element(A[i], min(SizeA, SizeB), B) ) (*C)[size++] = A[i];
} } int IsSubset(int SizeA, int SizeS, int * A, int * S) { int i;
if (SizeS > SizeA) return 0;
for (i = 0;
i < SizeS;
i++) if (!Element(S[i], SizeA, A)) return 0;
return 1;
} int main(int argc, char *argv[]) { int SetASize, SetBSize, SetISize;
int * SetA;
int * SetB;
int * SetI;
int num;
FILE * fd = fopen(argc > 1 ? argv[1] : INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadSet(fd, &SetASize, &SetA);
ReadSet(fd, &SetBSize, &SetB);
fclose(fd);
Intersection(SetASize, SetBSize, &SetISize, SetA, SetB, &SetI);
printf("Type a number: ");
scanf("%d", &num);
if (Element(num, SetASize, SetA)) printf("%d is element of A\n", num);
else printf("%d is not element of A\n", num);
if (Element(num, SetBSize, SetB)) printf("%d is element of B\n", num);
else printf("%d is not element of B\n", num);
if (Element(num, SetISize, SetI)) printf("%d is element of intersection of A and B\n", num);
else printf("%d is not element of intersection of A and B\n", num);
PrintSet("A", SetASize, SetA);
PrintSet("B", SetBSize, SetB);
PrintSet("Intersection of A and B", SetISize, SetI);
if (IsSubset(SetASize, SetBSize, SetA, SetB)) printf("B is subset of A\n");
else printf("B is not subset of A\n");
if (IsSubset(SetBSize, SetASize, SetB, SetA)) printf("A is subset of B\n");
else printf("A is not subset of B\n");
} free(SetA);
SetA = NULL;
free(SetB);
SetB = NULL;
free(SetI);
SetI = NULL;
return 0;

2.50.1. Írjon programot, amely két halmaz metszetét generálja! Mindkét halmaz egész számokat tartalmaz. A program olvassa be az input fájlt! Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám eleme-e az első halmaznak, a második halmaznak, illetve ezek metszetének! Írassa ki a képernyőre az előbbi három halmazt! Végül írassa ki, hogy az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz mérete Negyedik sor: a második halmaz elemei A számok egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is not element of intersection of A and B A = {80, 54, 41} B = {41, 21, 54, 76, 80} Intersection of A and B = {41, 54, 80} B is not subset of A A is subset of B 2.51. Halmazok uniója
2.51.1.
#include <stdio.h>
#include <stdlib.h> #define INPUT_FILE "sets.txt" #define max(a, b) ((a) > (b) ? (a) : (b)) #define min(a, b) ((a) > (b) ? (b) : (a)) void ReadSet(FILE * fd, int * size, int ** set) { int i;
fscanf(fd, "%d", size);
} *set = (int *)malloc(sizeof(int) * (*size) );
for (i = 0;
i < *size;
i++) fscanf(fd, "%d", *set + i);
printf("\n");
void PrintSet(char * name, int size, int * set) { int i;
printf("%s = ", name);
printf("{");
for (i = 0;
i < size - 1;
i++) printf("%d, ", set[i]);
if (size > 0) printf("%d", set[size - 1]);
printf("}\n");
} int Element(int e, int size, int * S) { int i = 0;
while ((i < size) && (S[i] != e)) i++;
return i < size;
} void Union(int SizeA, int SizeB, int * SizeU, int * SA, int * SB, int ** C) { int size = max(SizeA, SizeB);
int i;
*SizeU = 0;
int * A = SizeA > SizeB ? SA : SB;
int * B = SizeA > SizeB ? SB : SA;
for (i = 0;
i < min(SizeA, SizeB);
i++) { if ( !Element(B[i], max(SizeA, SizeB), A) ) size++;
} *C = (int *)malloc(sizeof(int) * size );
*SizeU = size;
for (i = 0;
i < max(SizeA, SizeB);
i++) (*C)[i] = A[i];
size = max(SizeA, SizeB);
for (i = 0;
i < min(SizeA, SizeB);
i++) { if ( !Element(B[i], max(SizeA, SizeB), A) ) (*C)[size++] = B[i];
} } int IsSubset(int SizeA, int SizeS, int * A, int * S) { int i;
if (SizeS > SizeA) return 0;
for (i = 0;
i < SizeS;
i++) } if (!Element(S[i], SizeA, A)) return 0;
return 1;
int main(int argc, char *argv[]) { int SetASize, SetBSize, SetUSize;
int * SetA;
int * SetB;
int * SetU;
int num;
FILE * fd = fopen(argc > 1 ? argv[1] : INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadSet(fd, &SetASize, &SetA);
ReadSet(fd, &SetBSize, &SetB);
fclose(fd);
Union(SetASize, SetBSize, &SetUSize, SetA, SetB, &SetU);
printf("Type a number: ");
scanf("%d", &num);
if (Element(num, SetASize, SetA)) printf("%d is element of A\n", num);
else printf("%d is not element of A\n", num);
if (Element(num, SetBSize, SetB)) printf("%d is element of B\n", num);
else printf("%d is not element of B\n", num);
if (Element(num, SetUSize, SetU)) printf("%d is element of union of A and B\n", num);
else printf("%d is not element of union of A and B\n", num);
PrintSet("A", SetASize, SetA);
PrintSet("B", SetBSize, SetB);
PrintSet("Union of A and B", SetUSize, SetU);
if (IsSubset(SetASize, SetBSize, SetA, SetB)) printf("B is subset of A\n");
else printf("B is not subset of A\n");
if (IsSubset(SetBSize, SetASize, SetB, SetA)) printf("A is subset of B\n");
else printf("A is not subset of B\n");
} free(SetA);
SetA = NULL;
free(SetB);
SetB = NULL;
free(SetU);
SetU = NULL;
return 0;

2.51.1. Írjon programot, amely két halmaz unióját generálja! Mindkét halmaz egész számokat tartalmaz! A program olvassa be az input fájlt. Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám eleme-e az első halmaznak, a második halmaznak, illetve ezek uniójának! Írassa ki a képernyőre az előbbi három halmazt! Végül írassa ki, hogy az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz mérete Negyedik sor: a második halmaz elemei A számok egy-egy space karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is element of union of A and B A = {80, 54, 41} B = {41, 21, 54, 76, 80} Union of A and B = {41, 21, 54, 76, 80} B is not subset of A A is subset of B 2.52. Halmazok különbsége
2.5.1. Egymásba ágyazott ciklusok segítségével határozza meg, hogy hány üres iteráció tesz ki egy másodpercet, ha a ciklusváltozó egész, illetve ha lebegőpontos! Minden ciklus 1000 lépést tegyen meg! Hány egymásba ágyazott ciklus kell, hogy a végrehajtási idő 5-10 másodperc legyen? 
2.5.1.
#include <stdio.h> int main() { int idxA, idxB, idxC, size=1000;
for(idxA = 0;
idxA < size;
idxA++) { for(idxB = 1;
idxB < size;
idxB++) { for(idxC = 1;
idxC < size;
idxC++) { } } } return 0;
} 
2.52.1.
#include <stdio.h>
#include <stdlib.h> #define INPUT_FILE "sets.txt" #define max(a, b) ((a) > (b) ? (a) : (b)) #define min(a, b) ((a) > (b) ? (b) : (a)) void ReadSet(FILE * fd, int * size, int ** set) { int i;
fscanf(fd, "%d", size);
*set = (int *)malloc(sizeof(int) * (*size) );
for (i = 0;
i < *size;
i++) fscanf(fd, "%d", *set + i);
printf("\n");
} void PrintSet(char * name, int size, int * set) { int i;
printf("%s = ", name);
printf("{");
for (i = 0;
i < size - 1;
i++) printf("%d, ", set[i]);
if (size > 0) printf("%d", set[size - 1]);
printf("}\n");
} int Element(int e, int size, int * S) { int i = 0;
while ((i < size) && (S[i] != e)) i++;
return i < size;
} void SetDifference(int SizeA, int SizeB, int * SizeD, int * SA, int * SB, int ** C) { int size = 0;
int i;
for (i = 0;
i < SizeA;
i++) { if (!Element(SA[i], SizeB, SB)) size++;
} *C = (int *)malloc(sizeof(int) * size);
*SizeD = size;
size = 0;
for (i = 0;
i < SizeA;
i++) { if (!Element(SA[i], SizeB, SB)) (*C)[size++] = SA[i];
} } int IsSubset(int SizeA, int SizeS, int * A, int * S) { int i;
if (SizeS > SizeA) return 0;
for (i = 0;
i < SizeS;
i++) if (!Element(S[i], SizeA, A)) return 0;
return 1;
} int main(int argc, char *argv[]) { int SetASize, SetBSize, SetD1Size, SetD2Size;
int * SetA;
int * SetB;
int * SetD1;
int * SetD2;
int num;
FILE * fd = fopen(argc > 1 ? argv[1] : INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadSet(fd, &SetASize, &SetA);
ReadSet(fd, &SetBSize, &SetB);
fclose(fd);
SetDifference(SetASize, SetBSize, &SetD1Size, SetA, SetB, &SetD1);
SetDifference(SetBSize, SetASize, &SetD2Size, SetB, SetA, &SetD2);
printf("Type a number: ");
scanf("%d", &num);
if (Element(num, SetASize, SetA)) printf("%d is element of A\n", num);
else printf("%d is not element of A\n", num);
if (Element(num, SetBSize, SetB)) printf("%d is element of B\n", num);
else printf("%d is not element of B\n", num);
if (Element(num, SetD1Size, SetD1)) printf("%d is element of A \\ B\n", num);
else printf("%d is not element of A \\ B\n", num);
if (Element(num, SetD2Size, SetD2)) printf("%d is element of B \\ A\n", num);
else printf("%d is not element of B \\ A\n", num);
PrintSet("A", SetASize, SetA);
PrintSet("B", SetBSize, SetB);
PrintSet("Set difference A\\B", SetD1Size, SetD1);
PrintSet("Set difference B\\A", SetD2Size, SetD2);
if (IsSubset(SetASize, SetBSize, SetA, SetB)) printf("B is subset of A\n");
else printf("B is not subset of A\n");
if (IsSubset(SetBSize, SetASize, SetB, SetA)) printf("A is subset of B\n");
else printf("A is not subset of B\n");
} free(SetA);
SetA = NULL;
free(SetB);
SetB = NULL;
free(SetD1);
SetD1 = NULL;
free(SetD2);
SetD2 = NULL;
return 0;

2.52.1. Írjon programot, amely két halmaz különbségét generálja! Mindkét halmaz egész számokat tartalmaz. A program olvassa be az input fájlt! Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám eleme-e az első halmaznak, a második halmaznak, az A\B vagy a B\A halmaznak! Írassa ki a képernyőre az előbbi négy halmazt! Végül írassa ki, hogy az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz mérete Negyedik sor: a második halmaz elemei A számok egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is not element of A \ B 76 is element of B \ A A = {80, 54, 41} B = {41, 21, 54, 76, 80} Set difference A\B = {} Set difference B\A = {21, 76} B is not subset of A A is subset of B 2.53. Binomiális tétel
2.5.2. Határozza meg az összeadás, szorzás, osztás, hatványozás időigényét úgy, hogy az előző program legbelsejébe beírja a megfelelő utasítást! 2.6. Adatbekérés
2.5.2.
#include <stdio.h> int main() { int idxA, idxB, idxC, size=1000;
int a, b = 2364, c = 9754;
for (idxA = 0;
idxA < size;
idxA++) { for (idxB = 1;
idxB < size;
idxB++) { for (idxC = 1;
idxC < size;
idxC++) { a = b + c;
} } } return 0;
} 
2.53.1.
#include <stdio.h>
#include <stdlib.h> typedef unsigned long int ULint;
ULint BinomialCoefficient(int n, int k) { ULint bc = n;
int i;
if (k == 0) return 1;
for (i = n - 1 ;
i > (n - k);
i--) { bc *= i;
// printf("%d %ld\n", i, bc);
} for (i = 2;
i <= k;
i++) bc /= i;
return bc;
} void PrintPow(char ch, int p) { if (p == 0) return;
if (p == 1) printf("%c", ch);
else printf("%c^%d", ch, p);
} void PrintBinom(int a) { int i;
int b;
printf("( a + b )^%d = ", a);
for (i = 0;
i <= a;
i++) { b = BinomialCoefficient(a, i);
if (b > 1) printf("%d", b);
PrintPow('b', i);
PrintPow('a', a - i);
if (i < a) printf(" + ");
} } printf("\n");
int main(int argc, char * argv[] ) { int a;
if (argc > 1) a = atoi(argv[1]);
else { printf(„Degree: „);
scanf("%d", &a);
} printf("\n");
PrintBinom(a);
printf("\n");
return 0;
} 
2.53.1. Írjon programot, amely beolvas egy n értéket a billentyűzetről, majd a binomiális tétel jobb oldalának kifejtett alakját kiírja a képernyőre! n ne legyen nagyobb 10-nél! A binomiális tétel szerint: (a + b)n = ahol n pozitív egész szám, és (a + b)n = Példa bemenet: n=3 Kimenet: ( a + b )^3 = a^3 + 3ba^2 + 3b^2a + b^3 2.54. Hazárdjáték
2.54.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> #define MIN_TIP 1 #define EASY_MAX 5 #define MEDIUM_MAX 10 #define HARD_MAX 15 #define START_MONEY 1000 int GetStake() { int stake;
do { printf("Take your stake: ");
scanf("%d", &stake);
if (stake <= 0) printf("The stake have to higher than zero!\n");
} while (stake <= 0);
return stake;
} int GetTip(int min, int max) { int tip;
do { printf("What's your tip (%d..%d)? ", min, max);
scanf("%d", &tip);
if ((tip > max) || (tip < min)) printf("The tip have to be between %d and %d!\n", min, max);
} while ((tip > max) || (tip < min));
return tip;
} int GetMax() { int d;
do { printf("Choose the difficulty!\n\n");
printf("\tEasy:...........1\n");
printf("\tMedium:.........2\n");
printf("\tHard:...........3\n\n");
scanf("%d", &d);
if ((d > 3) || (d < 1)) printf("Wrong number!\n");
} while ((d > 3) || (d < 1));
switch (d) { case 1: return EASY_MAX;
case 2: return MEDIUM_MAX;
case 3: return HARD_MAX;
} return 0;
} int Random(int min, int max) { return (rand() % (max - min)) + min;
} int main() { int stake, tip;
int max;
int num;
int Money = START_MONEY;
char s[5];
srand(time(NULL));
max = GetMax();
printf("You have %d HUF now.\n", Money);
do { printf("\n\n");
stake = GetStake();
num = Random(MIN_TIP, max);
tip = GetTip(MIN_TIP, max);
if (tip == num) { Money += stake;
printf("You've hit the number!\nYou have %d HUF!\n", Money);
} else { printf("The number was %d\n", num);
Money -= stake;
printf("You have %d HUF!\n", Money);
} if (Money > 0) { printf("Try again? (y/n)\n");
scanf("%s", s);
} } while (((s[0] == 'y') || (s[0] == 'Y')) && (Money > 0));
if (Money > 0) printf("Congratulations!\nYou get %d HUF!\n", Money);
else printf("I'm sorry, you lost\n");
srand(time(NULL));
return 0;
} 
2.54.1. Írjon hazárdjátékot! A szabályok a következők: A játék kezdetekor a játékosnak 1000 Ft-ja van. A program generál egy véletlen számot, a játékosnak pedig meg kell adnia egy tippet, és egy tétet. Ha eltalálja a számot, megkapja a tét összegét, ha nem, elveszíti. Ezután a program megkérdezi: „Try again? (y/n)”, a játékosnak pedig egy „y” vagy egy „n” karakterrel kell válaszolnia. Ha újból próbálkozik, akkor a program új számot generál. A játék addig folytatódik, amíg a játékosnak van pénze, vagy amíg nem szeretné befejezni a játékot. 3 különböző szint van: a „könnyű”, amelyben a program 1 és 5 közötti számot generál, a „közepes”, amelyben 1 és 10 közötti számot generál, és a „nehéz”, amelyben 1 és 15 közötti számot generál. A szintet a játék megkezdése előtt választja ki a játékos, egy egyszerű menü segítségével. A játék végén a program írja ki a képernyőre, mennyit nyert vagy veszített a játékos. Példa játék: Choose the difficulty! Easy:...........1 Medium:.........2 Hard:...........3 2 You have 1000 HUF now. Take your stake: 10 What's your tip (1..10)? 5 You've hit the number! You have 1010 HUF! Try again? (y/n) y Take your stake: 1000 What's your tip (1..10)? 1 The number was 7 You have 10 HUF! Try again? (y/n) n Congratulations! You get 10 HUF! 2.55. Dátumellenőrzés
2.55.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "date.txt" #define DOT '.' #define MAX_LENGTH 10 struct TDate { char Year[MAX_LENGTH];
char Month[MAX_LENGTH];
char Day[MAX_LENGTH];
};
void InitDate(struct TDate * Date) { Date->Year[0] = Date->Month[0] = Date->Day[0] = 0;
} void ReadDate(FILE * fd, struct TDate * Date) { fscanf(fd, "%s", Date->Year);
fscanf(fd, "%s", Date->Month);
fscanf(fd, "%s", Date->Day);
} void PrintDate(struct TDate * Date) { printf("%s %s %s\n", Date->Year, Date->Month, Date->Day);
} int CheckNumAndDots(char * S, char * A) { int i;
int len = strlen(S);
int errnum = 0;
for (i = 0;
i < len - 1;
i++) { if ((S[i] > '9') || (S[i] < '0')) { errnum++;
printf("Error: the %s cannot contain %c character!\n", A, S[i]);
} } if (S[len - 1] != DOT) { errnum++;
printf("Error: A \"%c\" have to follow the number, not \”%c\”!\n", DOT, S[len - 1]);
} return errnum;
} int CheckNums(struct TDate * Date) { int errnum = 0;
int month = atoi(Date->Month);
int day = atoi(Date->Day);
if ((month > 12) || (month < 1)) { errnum++;
printf("Error: There are only 12 months!\n");
} if ((day > 31) || (day < 1)) { errnum++;
printf("Error: There are atmost 31, at least 1 days in a month!\n");
} return errnum;
} void CheckDate(struct TDate * Date) { int errnum = CheckNumAndDots(Date->Year, "Year");
errnum += CheckNumAndDots(Date->Month, "Month");
errnum += CheckNumAndDots(Date->Day, "Day");
if (errnum == 0) errnum += CheckNums(Date);
printf("*******************************\nI found %d errors\n", errnum);
} int main(int argc, char *argv[]) { struct TDate Date;
InitDate(&Date);
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == 0) { perror("Error");
return 0;
} ReadDate(fd, &Date);
PrintDate(&Date);
CheckDate(&Date);
fclose(fd);
return 0;
} 
2.55.1. Írjon programot, amely beolvas egy dátumot egy fájlból, szintaktikai és szemantikai ellenőrzést végez rajta és kiírja az esetleges hibákat! Szintaktikai ellenőrzés: A dátum 3 számot tartalmaz, mindegyik szám után egy pont szerepel. A számok csak számjegyet tartalmazhatnak! Például a „2007.” megfelelő, de a következők nem: „2A07.”, „2007”. Szemantikai ellenőrzés: Akkor hajtódik végre, ha a szintaktikai ellenőrzés nem jelzett hibát. A hónap értéke 1 és 12 közt, a napé 1 és 31 közt változhat. Ha az értékek valamelyike hibás, ezt a program írja ki a képernyőre. Az input fájl formátuma: Év. Hónap. Nap. Példa bemenet: 2007. 12. 31. Kimenet: 2007. 12. 31. ******************************* I found 0 errors Példa bemenet: 2007 1u2. 31 Kimenet: 2007 1u2. 31 Error: A "." have to follow the number, not "7"! Error: the Month cannot contain u character! Error: A "." have to follow the number, not "1"! ******************************* I found 3 errors Példa bemenet: 2007. 13. 0. Kimenet: 2007. 13. 0. Error: There are only 12 months! Error: There are at most 31, at least 1 days in a month! ******************************* I found 1 errors 
2.55.2.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "date.txt" #define YEAR_MIN 1000 #define YEAR_MAX 3000 #define MONTH_MAX 12 #define DAY_MAX 31 const char * Months_Strings[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
enum Months{ jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
struct TDate { int Year;
int Month;
int Day;
};
void ReadDate(FILE * fd, struct TDate * Date) { fscanf(fd, "%d.", &Date->Year);
fscanf(fd, "%d.", &Date->Month);
fscanf(fd, "%d.", &Date->Day);
} void PrintDate(struct TDate * Date) { printf("Year: %d\nMonth: %s\nDay: %d\n", Date->Year, ((Date->Month >= 1) && (Date->Month <= 12)) ? Months_Strings[Date->Month - 1] : "Bad month", Date->Day);
} int CheckYear(int Y) { int errnum = 0;
if (Y > YEAR_MAX) { errnum++;
printf("Error: %d is too high for the year!\n", Y);
} if (Y < YEAR_MIN) { errnum++;
printf("Error: %d is too low for the year!\n", Y);
} return errnum;
} int CheckMonth(int M) { } int errnum = 0;
if (M > MONTH_MAX) { errnum++;
printf("Error: %d is too high for the month!\n", M);
} if (M < 1) { errnum++;
printf("Error: %d is too low for the month!\n", M);
} return errnum;
int LeapYear(int y) { if (y % 4 == 0) { if (y % 100 == 0) { if (y % 400 == 0) return 1;
else return 0;
} else return 1;
} return 0;
} int CheckDay(struct TDate * Date) { int errnum = 0;
switch (Date->Month) { case jan: case mar: case may: case jul: case aug: case oct: case dec: if (Date->Day > 31) { errnum++;
printf("Error: In %s there are 31 days!\n", Months_Strings[ Date-> Month - 1]);
} break;
case apr: case jun: case sep: case nov: if (Date->Day > 30) { errnum++;
printf("Error: In %s there are 30 days!\n", Months_Strings[ Date-> Month - 1]);
} break;
case feb: if (LeapYear(Date->Year)) { if (Date->Day > 29) { errnum++;
printf("Error: In %dth %s there are 29 days!\n", Date->Year, Months_Strings[ Date-> Month - 1 ]);
} } else { if (Date->Day > 28) { errnum++;
printf("Error: In %dth %s there are 28 days!\n", Date->Year, Months_Strings[ Date-> Month - 1 ]);
} } break;
} return errnum;
} void CheckDate(struct TDate * Date) { int errnum = CheckYear(Date->Year);
errnum += CheckMonth(Date->Month);
if (!errnum) errnum = CheckDay(Date);
printf("*******************************\nI found %d errors\n", errnum);
} int main(int argc, char *argv[]) { struct TDate Date;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == 0) { perror("Error");
return 0;
} ReadDate(fd, &Date);
PrintDate(&Date);
CheckDate(&Date);
fclose(fd);
return 0;
} 
2.55.2. Írja át az előző programot úgy, hogy csak szemantikai ellenőrzés legyen, de abból szigorúbb! Az év 1000 és 3000 közti érték lehet. A hónap 1 és 12 közti érték lehet. A nap értéke 1 és 31 között lehet januárban, márciusban, májusban, júliusban, augusztusban, októberben és decemberben. A nap értéke 1 és 30 közti értéket vehet fel áprilisban, júniusban, szeptemberben és novemberben. Ha az év szökőév, februárban a nap értéke 1 és 29 közt lehet, ha nem, akkor 1 és 28 között. Szökőév minden 4-gyel osztható év, de a 100-zal oszthatóak nem. A 400-zal osztható évek mindig szökőévek. Például 1992, 1996, 2000, 1600 szökőév, de 1800, 1900 nem az. A program elsőként az évet és a hónapot ellenőrizze, majd ha ezek megfelelőek, akkor a napot is! Írja ki a képernyőre a felfedezett hibákat! 2.56. Pascal háromszög
2.56.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_ROWNUM 10 #define SZOKOZS 4 int BinomialCoefficient(int n, int k) { int bc = n;
int i;
if (k == 0) return 1;
for (i = n - 1 ;
i > (n - k);
i--) { bc *= i;
} for (i = 2;
i <= k;
i++) bc /= i;
return bc;
} int GetWidth(int n) { return n * 3 + (n - 1) * SZOKOZS;
} void PascalsTriangle(int rows) { int i, sp, r, j;
int width = GetWidth(rows);
for (r = 0;
r < rows;
r++) { for (sp = 0;
sp < (width / 2) - (GetWidth(r) / 2);
sp++) printf("");
for (i = 0;
i <= r;
i++) { printf("%3d", BinomialCoefficient(r, i));
for (j = 0;
j < SZOKOZS;
j++) printf("");
} } } printf("\n");
int main(int argc, char * argv[]) { int rows = argc > 1 ? atoi(argv[1]) : DEFAULT_ROWNUM;
PascalsTriangle(rows);
return 0;
} 
2.56.1. Írjon programot, amely kiírja a képernyőre a Pascal háromszög első 10 sorát! Két szám között 4 szóköz karakter legyen! Az r-edik sor i-edik tagját számolja a következőképlettel: r! / ( i! * ( r - i )! ) Kimenet: 1 1 1 1 1 1 1 9 1 1 8 7 1 6 1 5 4 2 3 6 1 3 4 1 5 1 6 1 7 1 8 1 9 1 1 2.57. Lottó
2.57.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> #define DEFAULT_INPUTFILE "tipp1.txt" void GetNumbers(int * A) { int i, j, num;
for (i = 0;
i < 5;
i++) { } } do { num = rand() % 90 + 1;
j = 0;
while ((j < i) && (A[j] != num)) j++;
} while (j < i);
A[i] = num;
void PrintNumbers(int * A) { int i;
for (i = 0;
i < 4;
i++) printf("%d, ", A[i]);
printf("%d\n", A[4]);
} void Check(FILE * fd, int * A, int * H) { int i, j, k, c, num, a;
fscanf(fd, "%d", &c);
for (k = 0;
k < c;
k++) { a = 0;
for (i = 0;
i < 5;
i++) { fscanf(fd, "%d", &num);
j = 0;
while ((j < 5) && (A[j] != num)) j++;
if (j < 5) a++;
} if (a > 0) H[a - 1]++;
} } void InitHits(int * A) { int i;
for (i = 0;
i < 5;
i++) A[i] = 0;
} void PrintHits(int * A) { int i;
for (i = 0;
i < 5;
i++) { printf("There ");
if (A[i] > 1) printf("are ");
else printf("is ");
printf("%d %d hit", A[i], i + 1);
if (A[i] > 1) } } printf("s\n");
else printf("\n");
int main(int argc, char * argv[]) { int Numbers[5];
int Hits[5];
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, „r”);
if (fd == NULL) { perror("Error");
return 0;
} srand(time(NULL));
InitHits(Hits);
GetNumbers(Numbers);
printf("Generated numbers: ");
PrintNumbers(Numbers);
Check(fd, Numbers, Hits);
PrintHits(Hits);
fclose(fd);
return 0;
} 
2.57.1. Írjon lottó-generáló programot! A program generáljon 1 és 90 között 5 különböző pozitív egész számot! Egy fájl tippeket tartalmaz. Olvassa be a tippeket a fájlból, majd hasonlítsa össze őket a generált számokkal! Írja ki a képernyőre a generált nyerőszámokat, és azt, hogy hány embernek van 1-es, 2-es, 3as, 4-es, illetve 5-ös találata a lottón! Az input fájl formátuma: Első sor: a tippek száma Minden további sor 5 tippet tartalmaz, szóköz karakterekkel elválasztva. Példa bemenet: 6 5 64 23 80 42 4 34 44 62 72 75 43 3 64 80 53 52 21 56 10 1 37 87 9 53 75 10 64 69 78 Kimenet: Generated numbers: 55, 64, 68, 75, 50 There is 1 1 hit There are 2 2 hits There is 0 3 hit There is 0 4 hit There is 0 5 hit 2.58. Hanoi tornyai
2.58.1. A Hanoi tornyai játék 3 rudat tartalmaz (start, segéd, cél). Az első rúdon N db korong van egymás fölött, amelyek különböző méretűek. A korongok fentről lefelé növekvő sorrendben következnek, legnagyobb van legalul, a legkisebb legfelül, ahogyan az ábrán látható. A feladat a következő: a korongokat át kell rakni a start rúdról a célra, a segédrúd segítségével. Az átrakás szabálya, hogy nagyobb korongot kisebbre nem rakhatunk rá. Írjon programot ennek a feladatnak a szimulálására! A program argumentumként megkapja N értékét. Kezdetben minden korong a start rúdon van. Minden lépésben kérdezze meg, melyik rúdról melyikre tegyük át a legfelső korongot! Ha ez nem ellenkezik a szabályokkal, helyezzük át a korongot! Minden mozgatás után írja ki a képernyőre a korongok helyzetét, a példában látható módon! Ha a felhasználó 0-t gépel, vagy minden korong a cél rúdon van, a program véget ér. Használjon dinamikus tömböket és struktúrákat a korongok helyének tárolására! 2.4. ábra: Hanoi tornyai szemléltetése Példa bemenet: ************************************* Source: 3, 2, 1 Auxiliary: 0 Destination: 0 From: aux To: src Incorrect step! ************************************* Source: 3, 2, 1 Auxiliary: 0 Destination: 0 From: src To: aux ************************************* Source: 3, 2 Auxiliary: 1 Destination: 0 From: src To: dst ************************************* Source: 3 Auxiliary: 1 Destination: 2 From: aux To: dst ************************************* Source: 3 Auxiliary: 0 Destination: 2, 1 From: 0 The disks are not on the destination! ************************************* Source: 3 Auxiliary: 0 Destination: 2, 1 2.59. Törtek összeadása
2.58.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_RINGNUM 3 #define TRUE 1 #define FALSE 0 #define NAMELEN 12 struct TTower { int MaxHeight;
int Height;
int * Disks;
char Name[NAMELEN];
};
void InitTower(struct TTower * T, int height, int full, char * name) { int i;
T->Disks = (int*)malloc(sizeof(int) * height);
T->MaxHeight = height;
strcpy(T->Name, name);
if (full) { for (i = height;
i >= 1;
i--) T->Disks[height - i] = i;
T->Height = height;
} else { for (i = 0;
i < height;
i++) T->Disks[i] = 0;
T->Height = 0;
} } void FreeTower(struct TTower * T) { free(T->Disks);
T->Disks = NULL;
T->Height = T->MaxHeight = 0;
} void PrintTower(struct TTower * T) { int i;
printf("%s: ", T->Name);
for (i = 0;
i < T->Height - 1;
i++) printf("%d, ", T->Disks[i]);
printf("%d\n", T->Disks[i]);
} int GetIndex(char * S) { if (strcmp(S, "src") == 0) return 0;
if (strcmp(S, "aux") == 0) return 1;
if (strcmp(S, "dst") == 0) return 2;
return -1;
} int IsCorrect(int f, int t, struct TTower * Towers) { if ((f == -1) || (t == -1)) return FALSE;
if (f == t) return FALSE;
if (Towers[f].Height == 0) return FALSE;
if (Towers[f].Disks[Towers[f].Height - 1] > Towers[t].Disks[Towers[t].Height - 1]) return FALSE;
return TRUE;
} int isComplete(struct TTower * T) { int i;
for (i = T->MaxHeight;
i >= 1;
i--) if (T->Disks[ T->MaxHeight - i] != i) return FALSE;
return TRUE;
} int main(int argc, char * argv[]) { char From[5];
char To[5];
int f, t;
int giveup;
struct TTower Towers[3];
int MaxH = argc > 1 ? atoi(argv[1]) : DEFAULT_RINGNUM;
InitTower(Towers, MaxH, TRUE, "Source");
InitTower(Towers + 1, MaxH, FALSE, "Auxiliary");
InitTower(Towers + 2, MaxH, FALSE, "Destination");
do { printf("\n\n*************************************\n\n");
PrintTower(Towers);
PrintTower(Towers + 1);
PrintTower(Towers + 2);
printf("From: ");
scanf("%s", From);
if (From[0] != '0') { printf("To: ");
scanf("%s", To);
} giveup = ((From[0] == '0') || (To[0] == '0'));
if (!giveup) { f = GetIndex(From);
t = GetIndex(To);
if (IsCorrect(f, t, Towers)) { Towers[t].Disks[Towers[t].Height++] = Towers[f].Disks[Towers[f].Height - 1];
Towers[f].Disks[--Towers[f].Height] = 0;
} else printf("Incorrect step!\n");
} } while ((!giveup) && !isComplete(Towers + 2));
if (!giveup) printf("The disks are on their's place!\n");
else printf("The disks are not on the destination!\n");
} printf("\n\n*************************************\n\n");
PrintTower(Towers);
PrintTower(Towers + 1);
PrintTower(Towers + 2);
FreeTower(Towers);
FreeTower(Towers + 1);
FreeTower(Towers + 2);
return 0;

2.59.1. Egy fájl több törtet tartalmaz. Írjon programot, amely beolvassa a törteket, és összeadja őket! Minden összeadás után számolja ki az aktuális összeg számlálójának és nevezőjének legnagyobb közös osztóját az Euklideszi algoritmus segít- ségével, és ha lehet, akkor egyszerűsítse a törtet, majd folytassa az összeadást! Minden műveletet írjon ki a képernyőre a példában látható módon! Az Euklideszi algoritmus megadja két szám legnagyobb közös osztóját. procedure Euclidean(A, B) M = B while M is not zero { B = M M = A mod B A = B } Az input fájl formátuma: Első sor: a törtek száma A többi sorban két pozitív egész található, az első a számláló, a második a nevező értéke. A két érték szóköz karakterrel van elválasztva. Példa bemenet: 3 2 3 4 5 6 11 Kimenet: 2 4 ------ + ------ = 3 5 -----15 6 ------ + ------ = -----165 4 ------ + ------ = 3 1656 ------ = -----55 2.60. Nevezetes számok Számelmélettel már az ókori Görögországban is sokat foglalkoztak, például sok nevezetes tulajdonságú számot próbáltak meghatározni.
2.59.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "nums.txt" int Eukl(int a, int b) { int m = b;
while (m != 0) { b = m;
m = a % b;
a = b;
} } return b;
void ReadAndAdd(FILE * fd) { int count, i;
int num1, num2;
int den = 0, numer = 0;
int tmp1, tmp2;
int d;
fscanf(fd, "%d", &count);
for (i = 0;
i < count;
i++) { fscanf(fd, "%d %d", &num1, &num2);
if (den != 0) { tmp2 = den * num2;
tmp1 = num2 * numer + den * num1;
d = Eukl(tmp1, tmp2);
if (d != 1) { printf("%4d %4d %4d %4d\n", numer, num1, tmp1, tmp1 / d);
printf("------ + ------ = ------ = ------\n");
printf("%4d %4d %4d %4d\n\n", den, num2, tmp2, tmp2 / d);
} else { printf("%4d %4d %4d\n", numer, num1, tmp1);
printf("------ + ------ = ------\n");
printf("%4d %4d %4d\n\n", den, num2, tmp2);
} numer = tmp1 / d;
den = tmp2 / d;
}else { den = num2;
numer = num1;
} } } int main(int argc, char * argv[]) { FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, „r”);
if (fd == NULL) { perror("Error");
return 0;
} ReadAndAdd(fd);
fclose(fd);
return 0;
} 
2.60.1-2.60.4.
#include <stdio.h>
#include <stdlib.h> int osztokOsszege(int szam) { if (szam == 1) { return 0;
} int oszto = 2;
int osszeg = 1;
while (oszto * oszto < szam) { if (szam % oszto == 0) { osszeg += oszto;
osszeg += szam / oszto;
} oszto++;
} return osszeg;
} #define N1 10000 #define N2 100 #define N3 1000 int main() { int i;
int tokeletes = 0;
int hianyos = 0;
int bovelkedo = 0;
int bovelkedo2 = 0;
for (i = 1;
i <= N1;
i++) { if (osztokOsszege(i) == i) { tokeletes++;
} } for (i = 1;
i <= N2;
i++) { if (osztokOsszege(i) < i) { hianyos++;
} } for (i = 1;
i <= N3;
i++) { if (osztokOsszege(i) > i) { bovelkedo++;
if (i % 6 == 0) { bovelkedo2++;
} } } printf("Tokeletes szamok 1 es %d kozott: %d\n", N1, tokeletes);
printf("Hianyos szamok 1 es %d kozott: %d\n", N2, hianyos);
printf("Bovelkedo szamok 1 es %d kozott: %d\n", N3, bovelkedo);
printf("2-vel es 3-al oszthato bovelkedo szamok 1 es %d kozott: %d\n", N3, bovelkedo2);
return EXIT_SUCCESS;
} 
2.60.1. Írjon programot, amely megszámolja, hogy 1 és 10000 között mennyi tökéletes szám van! Tökéletes számnak tekintjük azokat a számokat, amelyekre igaz, hogy megegyeznek az osztóik összegével. Az osztók közé az 1-et is hozzávesszük, de magát a számot nem. Például tökéletes szám a 6, mert 1 + 2 + 3 = 6. 
2.60.2. Írjon programot, amely megszámolja, hogy 1 és 100 között mennyi hiányos szám található! Hiányos szám az, amely nagyobb az osztóinak összegénél, önmagát nem számítjuk az osztói közé. Például a 21 hiányos szám, mert 1 + 3 + 7 < 21. 
2.60.3. Írjon programot, amely megszámolja, hogy 1 és 1000 között mennyi bővelkedő szám található! Bővelkedő szám az, amely kisebb az osztóinak összegénél, önmagát szintén nem számítjuk az osztói közé. Például a 12 bővelkedő szám, mert 1 + 2 + 3 + 4 + 6 > 12.
2.60.4. Módosítsa az előző feladatot úgy, hogy azon 1 és 1000 között található bővelkedő számokat adja meg, amelyek 2-vel vagy 3-al oszthatóak! 3. Tömbök és mátrixok feladatai 3.1. Egy sztring címei
2.6.1.
#include <stdio.h> int main() { int id;
unsigned int age;
char sex, name[200];
float weight;
double accountBalance;
} printf("id=");
scanf("%d", &id);
printf("age=");
scanf("%u", &age);
_flushall();
printf("sex=");
scanf("%c", &sex);
printf("weight=");
scanf("%f", &weight);
printf("account balance=");
scanf("%lf", &accountBalance);
printf("name=");
scanf("%s", name);
printf("\nYour data!\n");
printf("id=%d\n", id);
printf("age=%u\n", age);
printf("sex=%c\n", sex);
printf("weight=%f\n", weight);
printf("account balance=%lf\n", accountBalance);
printf("name=%s", name);
return 0;

2.6.1. Írjon programot, amellyel bekéri egy ember adati közül a következőket: azonosító szám - int, életkor - unsigned int, neme - char, súlya - float, bankszámla egyenlege - double, neve - char[200]! A bekért adatokat írja ki újból a képernyőre! A megadott és a kiírt érték mikor különbözhet? Mutasson rá példát! 
2.6.2.
#include <stdio.h> int main() { const float a=3.14;
char dir;
printf("const float a=%f\n", a);
printf("Select direction! (1/2)\n");
scanf("%c", &dir);
if (a=='1') { char a[200]= "Maroknyi szekely porlik, mint a szikla";
printf("string a=%s\n", a);
} else { unsigned long int a=456789;
printf("unsigned long int a=%lu\n", a);
} return 0;
} 
2.6.2. Kérje be majd írassa ki egy autó tulajdonságait! A tulajdonságok a következőek: márka - char[200], végsebesség - float, regisztrációs szám - hexa, tömeg double, típus név - char[300], utas szám - int, műholdas navigáció - char. 2.7. Blokkon belüli változók
2.7.1. Hozzon létre egy olyan main függvényt, amelyben 3 különböző típusú, 'a' nevű változó szerepel! Az egyes változók típusai: const float, char [200], unsigned long int. Ugyanolyan nevű változókat egy függvényben belül úgy tud létrehozni, hogy a változó definiálások különböző blokkokban vannak. Egy negyedik változóba kérje be, melyik blokkba menjen be a program, írassa ki az ott lévő a változó értékét! 2.8. Formázott kimenet
2.7.1.
#include <iostream> using namespace std;
int main () { int direction;
cout << "Choose a direction: (1) const float, (2) char [200], (3) unsigned long int" << endl;
cin >> direction;
} if (direction==1) { const float a=12.345;
cout << "a=" << a << endl;
} if (direction==2) { char a[200]=„test123”;
cout << "a=" << a << endl;
} if (direction==3) { unsigned long int a=98765;
cout << "a=" << a << endl;
} if (direction<1 || direction>3) { cout << "The direction value is incorrect" << endl;
} return 0;

2.8.1.
#include <stdio.h> int main() { float a=12.45, b=-234.1, c=57967.2, d=134567;
printf("%+7.2f\n", a);
printf("%7.1f\n", b);
printf("%+8.1f\n", c);
printf("%+6.0f\n", d);
return 0;
} 
2.8.1. printf segítségével írja ki a következő sorokat, úgy hogy változókban tárolja az egyes értékeket! A szóközt „_”-al jelöljük. A kiírandó szöveg: _+12.45 _-234.1 +57967.2 +134567 
2.8.2. Az előző feladathoz hasonlóan írassuk ki a következő sorokat: _ _+235 _-1.291E4 00026 0XAB2 1.64e-003 2.9. Hagyományos vagy normál forma
2.8.2.
#include <stdio.h> int main() { int a = 235, c = 26, d = 2*1+11*16+10*16*16;
float b = -12910;
float e = 0.00164;
printf("%+6d\n", a);
printf("%12.3E\n", b);
printf("%05d\n", c);
printf("%#X\n", d);
printf("%.2e\n", e);
return 0;
} 
2.9.1.
#include <stdio.h> int main() { const int size=5;
double array[]={3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
int idxI, points=0;
char choice;
printf("How do you think the %%g will display the next numbers? Regular or normal?\n");
for (idxI=0;
idxI<size;
idxI++) { printf("\n%15.10lf ", array[idxI]);
_flushall();
printf("Decide and press enter to continue!");
scanf("%c", &choice);
printf("result: %g\n", array[idxI]);
printf("Was you selection correct? (y)es, (n)o:");
_flushall();
scanf("%c", &choice);
if (choice=='y') { points++;
} } } printf("You have %d of %d points.", points, size);
return 0;

2.9.1. Írjon programot, amely öt darab tömbben tárolt float típusú számról kérdezi meg, hogy azt a printf %g-el történő kiírásakor hagyományos (f) vagy normál (e) alakban jeleníti meg! A számot jelenítsük meg először %f-el! Írjuk ki a felhasználónak, hogy tippeljen, jelenítsük meg a választ %g-el, kérdezzük meg, hogy helyes volt-e a tipp! Számoljuk a helyes válaszokat! 
2.9.2. Alakítsuk át a programot úgy, hogy ne a tipp helyességét kérjük be, hanem magát a tippet! Használjunk sprintf parancsot és használjuk ki azt, hogy normál forma mindig tartalmaz egy 'e' betűt. A program elején kérjük be a tömb nagyságát, a program végén, %-ban adjuk meg a helyes megoldások számát! 
2.9.2.
#include <stdio.h> int main() { int size = 5;
double myArray [] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
int idxI, idxJ, points = 0;
char choice;
char correctChoice;
char buffer [50];
int stringSizeOfAnswer;
printf("How do you think the %%g will display the next numbers? Regular or normal?\n");
for (idxI = 0;
idxI < size;
idxI++) { printf("\n%15.10lf ", myArray[idxI]);
stringSizeOfAnswer = sprintf (buffer, "%g", myArray[idxI]);
printf("Decide, rather %%(e) or %%(f)");
scanf("%c", &choice);
getchar();
correctChoice = 'f';
for(idxJ=0;
idxJ < stringSizeOfAnswer;
++idxJ) { if(buffer[idxJ] == 'e') correctChoice = 'e';
} if (choice == correctChoice) { printf("Correct!\n");
points++;
} else printf("Incorrect!\n");
} printf("You achieved a(n) %.lf %% result.\n", (double)points/(double)size*100);
return 0;
} 
2.9.3. Alakítsuk át a programot úgy, hogy minden iterációban kérje be a %g-ben használt pontosságot is! A válasz ne csak az legyen, hogy hagyományos vagy normál formában történik a kiírás, hanem pontosan meg kell adni számot a megfelelő formában! 2.10. Szorzótábla
2.9.3.
#include <stdio.h> int main() { int size = 5;
double myArray [] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
int idxI, idxJ, points = 0;
int correct;
char buffer [50];
char tip [50];
int stringSizeOfAnswer;
int precision;
printf("How do you think the %%g will display the next numbers? Regular or normal?\n");
for (idxI=0;
idxI < size;
idxI++) { printf("\n%15.10lf ", myArray[idxI]);
printf("How long should the %%g precision be? ");
scanf("%d", &precision);
stringSizeOfAnswer = sprintf (buffer, "%.*g", precision, myArray[idxI]);
printf("Your tip: ");
scanf("%s", tip);
correct = 1;
for(idxJ = 0;
idxJ < stringSizeOfAnswer;
++idxJ) { if(buffer[idxJ] == tip[idxJ]) ;
else correct = 0;
} printf("%s\n", buffer);
if (correct) { printf("Correct!\n");
points++;
} else printf("Incorrect!\n");
} printf("You achieved a(n) %.lf %% result.\n", (double)points/(double)size*100);
return 0;
} 
