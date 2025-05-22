//3.10.1. Írjon függvényeket a következő feladatokra: határozza meg egy tömbben lévő elemek összegét, átlagát, minimumát, hogy egy adott elem szerepel-e benne! Egy fájlban legyen a main függvény és egy másikban a többi függvény! 

Below is a C++11 solution split into three files:

---

**inc.hpp**

```cpp
#ifndef INC_HPP_
#define INC_HPP_

// Print the array elements in [a0, a1, …, aN-1] format
void print(const double* arr, int size);

// Return the sum of all elements
double sum(const double* arr, int size);

// Return the average of all elements (assumes size > 0)
double avg(const double* arr, int size);

// Return the index of the minimum element (assumes size > 0)
int minIndex(const double* arr, int size);

// Return true if value is found in the array
bool searchFor(const double* arr, int size, double value);

#endif // INC_HPP_
```

---

**functions.cpp**

```cpp
#include "inc.hpp"
#include <iostream>

// Print the array as [e0, e1, …, eN-1]
void print(const double* arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i + 1 < size) 
            std::cout << ", ";
    }
    std::cout << "]";
}

double sum(const double* arr, int size) {
    double s = 0.0;
    for (int i = 0; i < size; ++i) {
        s += arr[i];
    }
    return s;
}

double avg(const double* arr, int size) {
    return sum(arr, size) / size;
}

int minIndex(const double* arr, int size) {
    int mi = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[mi]) {
            mi = i;
        }
    }
    return mi;
}

bool searchFor(const double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
```

---

**main.cpp**

```cpp
#include "inc.hpp"
#include <iostream>

int main() {
    // sample data
    double myArray[] = { 12.0, 56.0, -7.0 };
    int size = sizeof(myArray) / sizeof(myArray[0]);
    double what = -8.0;

    std::cout << "Array: ";
    print(myArray, size);

    double s = sum(myArray, size);
    double a = avg(myArray, size);
    std::cout << "\nSum: " << s
              << ", Average: " << a << "\n";

    int idx = minIndex(myArray, size);
    std::cout << "Minimum at index " << idx
              << " → value " << myArray[idx] << "\n";

    if (searchFor(myArray, size, what)) {
        std::cout << what << " is found.\n";
    } else {
        std::cout << what << " is not found.\n";
    }

    return 0;
}
```

---

### Build and run

```bash
g++ -std=c++11 -o myprog main.cpp functions.cpp
./myprog
```






//3.10.2. Egészítse ki az előző programot a következő feladatokat ellátó függvényekkel! Maximális eleme indexének a meghatározása, szórás kiszámítása, két tömb elemeinek a felcserélése! 

Below is a C++11 solution split into three files. It adds:

* `maxIndex` – returns the index of the largest element
* `stdDev` – computes the population standard deviation
* `change` – swaps element‐by‐element two arrays

---

**function.hpp**

```cpp
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

// Print array elements as [e0, e1, …, eN-1]
void print(const double* arr, int size);

// Sum of elements
double sum(const double* arr, int size);

// Average of elements (size > 0)
double avg(const double* arr, int size);

// Index of minimum element (size > 0)
int minIndex(const double* arr, int size);

// Index of maximum element (size > 0)
int maxIndex(const double* arr, int size);

// Population standard deviation: sqrt( Σ(xi–μ)² / N )
double stdDev(const double* arr, int size);

// Swap the contents of arr1 and arr2 (both length size)
void change(double* arr1, double* arr2, int size);

// Return true if value exists in arr
bool searchFor(const double* arr, int size, double value);

#endif // FUNCTION_HPP
```

---

**functions.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <cmath>

void print(const double* arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i + 1 < size) std::cout << ", ";
    }
    std::cout << "]";
}

double sum(const double* arr, int size) {
    double s = 0.0;
    for (int i = 0; i < size; ++i) {
        s += arr[i];
    }
    return s;
}

double avg(const double* arr, int size) {
    return sum(arr, size) / size;
}

int minIndex(const double* arr, int size) {
    int mi = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[mi]) mi = i;
    }
    return mi;
}

int maxIndex(const double* arr, int size) {
    int ma = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[ma]) ma = i;
    }
    return ma;
}

double stdDev(const double* arr, int size) {
    double mean = avg(arr, size);
    double sumSq = 0.0;
    for (int i = 0; i < size; ++i) {
        double diff = arr[i] - mean;
        sumSq += diff * diff;
    }
    return std::sqrt(sumSq / size);
}

void change(double* arr1, double* arr2, int size) {
    for (int i = 0; i < size; ++i) {
        double tmp   = arr1[i];
        arr1[i]      = arr2[i];
        arr2[i]      = tmp;
    }
}

bool searchFor(const double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) return true;
    }
    return false;
}
```

---

**main.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <iomanip>

int main() {
    double A[] = { 12.0, 56.0, -7.0 };
    double B[] = { 24.0, -26.0,  4.0 };
    int size   = sizeof(A) / sizeof(A[0]);
    double what = -8.0;

    std::cout << "Array A: "; print(A, size); 
    std::cout << "\nArray B: "; print(B, size);
    
    double s  = sum(A, size);
    double m  = avg(A, size);
    int    iMin = minIndex(A, size);
    int    iMax = maxIndex(A, size);
    double sd = stdDev(A, size);
    
    std::cout << "\n\n-- Statistics for A --\n"
              << "Sum:       " << s  << "\n"
              << "Average:   " << m  << "\n"
              << "Min index: " << iMin 
                 << " (value " << A[iMin] << ")\n"
              << "Max index: " << iMax
                 << " (value " << A[iMax] << ")\n"
              << "Std Dev:   " << std::fixed << std::setprecision(4) << sd << "\n";

    std::cout << "\n-- Swapping A and B --\n";
    change(A, B, size);
    std::cout << "A: "; print(A, size);
    std::cout << "\nB: "; print(B, size);

    std::cout << "\n\n-- Search --\n";
    if (searchFor(A, size, what))
        std::cout << what << " is in A\n";
    else
        std::cout << what << " is NOT in A\n";

    return 0;
}
```

---

**Build & run**

```bash
g++ -std=c++11 -o program main.cpp functions.cpp
./program
```


//3.10.3. Egészítse ki az előző programot a következő feladatokat ellátó függvényekkel! Adott elem első előfordulásának meghatározása, utolsó előfordulásának meghatározása, két tömb között az alapműveletek elvégzése az azonos indexű elemek között, skaláris szorzat meghatározása.  

Below is a clean C++11 solution, organized into three files:

---

**function.hpp**

```cpp
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

// Print array elements as [e0, e1, …, eN-1]
void print(const double* arr, int size);

// Sum of elements
double sum(const double* arr, int size);

// Average of elements (size > 0)
double avg(const double* arr, int size);

// Index of minimum element (size > 0)
int minIndex(const double* arr, int size);

// Index of maximum element (size > 0)
int maxIndex(const double* arr, int size);

// Swap the contents of a1 and a2 (both length size)
void change(double* a1, double* a2, int size);

// Element-wise basic operations (+, –, *, /) between a1 and a2, printed to stdout
void elementWiseOps(const double* a1, const double* a2, int size);

// Scalar (dot) product of a1 and a2
double dotProduct(const double* a1, const double* a2, int size);

// First occurrence of value in arr, or –1 if not found
int firstOccurrence(const double* arr, int size, double value);

// Last occurrence of value in arr, or –1 if not found
int lastOccurrence(const double* arr, int size, double value);

// Returns true if value is found in arr
bool searchFor(const double* arr, int size, double value);

#endif // FUNCTION_HPP
```

---

**functions.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <cmath>

// Print array as [e0, e1, …]
void print(const double* arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i + 1 < size) std::cout << ", ";
    }
    std::cout << "]";
}

double sum(const double* arr, int size) {
    double s = 0.0;
    for (int i = 0; i < size; ++i) {
        s += arr[i];
    }
    return s;
}

double avg(const double* arr, int size) {
    return sum(arr, size) / size;
}

int minIndex(const double* arr, int size) {
    int mi = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[mi]) mi = i;
    }
    return mi;
}

int maxIndex(const double* arr, int size) {
    int ma = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[ma]) ma = i;
    }
    return ma;
}

void change(double* a1, double* a2, int size) {
    for (int i = 0; i < size; ++i) {
        double tmp = a1[i];
        a1[i] = a2[i];
        a2[i] = tmp;
    }
}

void elementWiseOps(const double* a1, const double* a2, int size) {
    std::cout << "\nElement-wise operations:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Index " << i << ":\n";
        std::cout << "  " << a1[i] << " + " << a2[i]
                  << " = " << (a1[i] + a2[i]) << "\n";
        std::cout << "  " << a1[i] << " - " << a2[i]
                  << " = " << (a1[i] - a2[i]) << "\n";
        std::cout << "  " << a1[i] << " * " << a2[i]
                  << " = " << (a1[i] * a2[i]) << "\n";
        std::cout << "  " << a1[i] << " / " << a2[i]
                  << " = " << (a1[i] / a2[i]) << "\n";
    }
}

double dotProduct(const double* a1, const double* a2, int size) {
    double dot = 0.0;
    for (int i = 0; i < size; ++i) {
        dot += a1[i] * a2[i];
    }
    return dot;
}

int firstOccurrence(const double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int lastOccurrence(const double* arr, int size, double value) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

bool searchFor(const double* arr, int size, double value) {
    return firstOccurrence(arr, size, value) != -1;
}
```

---

**main.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <iomanip>

int main() {
    double A[]     = { 12.0, 56.0, -7.0, 56.0 };
    double B[]     = { 24.0, -26.0, 4.0,  19.0 };
    int    size    = sizeof(A) / sizeof(A[0]);
    double what1   = -8.0;
    double what2   = 56.0;

    std::cout << "Array A: "; print(A, size);
    std::cout << "\nArray B: "; print(B, size);

    // basic stats on A
    double s       = sum(A, size);
    double m       = avg(A, size);
    int    iMin    = minIndex(A, size);
    int    iMax    = maxIndex(A, size);

    std::cout << "\n\n-- Statistics for A --\n"
              << "Sum:     " << s << "\n"
              << "Average: " << m << "\n"
              << "Min idx: " << iMin
              << " (value " << A[iMin] << ")\n"
              << "Max idx: " << iMax
              << " (value " << A[iMax] << ")\n";

    // presence test
    std::cout << "\n-- Search for " << what1 << " in A --\n";
    if (searchFor(A, size, what1))
        std::cout << what1 << " is found in A\n";
    else
        std::cout << what1 << " is NOT found in A\n";

    // swap A and B
    std::cout << "\n-- Swap A and B --\n";
    change(A, B, size);
    std::cout << "A: "; print(A, size);
    std::cout << "\nB: "; print(B, size);

    // element-wise ops
    elementWiseOps(A, B, size);

    // dot product
    double dot = dotProduct(A, B, size);
    std::cout << "\n\nDot product: " << dot << "\n";

    // first & last occurrence in B
    int firstIdx = firstOccurrence(B, size, what2);
    int lastIdx  = lastOccurrence(B, size, what2);
    std::cout << "\n-- Occurrences of " << what2 << " in B --\n";
    if (firstIdx != -1) {
        std::cout << "First at index " << firstIdx
                  << ", last at index " << lastIdx << "\n";
    } else {
        std::cout << what2 << " not found in B\n";
    }

    return 0;
}
```

---

**Build & run**

```bash
g++ -std=c++11 -o demo main.cpp functions.cpp
./demo
```


//3.11.1. Írjon programot, amely egy szöveg minden negyedik karakterét kihagyja, ha az nem white space! inicializálja úgy a sztringet, hogy abban több sor legyen és ezek a sorok a program kódban is sorokban legyenek (külön idézőjel párok felhasználásával)! A néggyel való oszthatóságot külön függvénnyel valósítsa meg! 
3.11.1.
#include <stdio.h>
#include <string.h> int devisableBy4(int num) { if (num/4==num/4.) return 1;
return 0;
} int main() { char s[]="The project will scale up to 1,200 marine sites,\n" "including different conditions such as surface waters,\n" "waters near methane emissions from the sea floor, and deep-sea sediments. ";
int idxI, size;
size = strlen(s);
for (idxI=0;
idxI<size;
idxI++) { if (!devisableBy4(idxI) || (s[idxI]=='\n' || s[idxI]=='\t' || s[idxI]==' ')) printf("%c", s[idxI]);
} return 0;
} 

//3.11.2. Módosítsa úgy a programot, hogy a magánhangzókat hagyja ki, de csak akkor, ha nem egy szó elején vannak! 
3.11.2.
#include <stdio.h>
#include <string.h>
#include <ctype.h> int main() { char string[] = "The project will scale up to 1,200 marine sites,\n" "including different conditions such as surface waters,\n" "waters near methane emissions from the sea floor, and deepseasediments.";
int idxI, size;
size = strlen(string);
for (idxI = 0;
idxI < size;
idxI++) { if ( (toupper(string[idxI]) == 'A' || toupper(string[idxI]) == 'E' || toupper(string[idxI]) == 'I' || toupper(string[idxI]) == 'O' || toupper(string[idxI])== 'U') && string[idxI - 1] != ' ') ;
keudobetu, akkor nem csinal semmit else printf("%c", string[idxI]);
} return 0;
} 

// 3.1.1. Készítsünk programot, amely bekér egy legfeljebb 6 karakter hosszú sztringet és a karakteres képernyőn megjeleníti azt úgy, hogy kiírja az egyes karakterek értékeit, karakteresen és ASCII kóddal 16-os számrendszerben, valamint kiírja az egyes karakter változóknak a neveit és ezeknek a címeit. Ötlet mutatók kiírásához használja a %p-t!  

// 3.1.1.
#include <stdio.h> int main() { const int size=6;
int idxI;
char string[size+1];
printf("string=");
scanf("%6s", string);
printf("The string is: %s\n", string);
printf("The static string address, string: %p\n", string);
printf("The dynamic string address, &string: %p\n", &string);
for (idxI=0;
idxI<size;
idxI++) { printf("\'%c\' ", string[idxI]);
} printf("\n");
for (idxI=0;
idxI<size;
idxI++) { if (string[idxI]==0) printf("0x");
printf("%#-2x ", string[idxI]);
} printf("\n");
for (idxI=0;
idxI<size;
idxI++) { printf("string[%d] ", idxI);
} printf("\n");
for (idxI=0;
idxI<size;
idxI++) { printf("%p ", &(string[idxI]));
} return 0;
} 

// 3.12.1. Készítsen magánhangzó statisztikát egy bekért sorról! A magánhangzó kis és nagy betűs alakját nem különböztetjük meg, csak az angol magánhangzókat tekintjük. 
3.12.1.
#include <stdio.h>
#include <string.h> int main() { char sz[80];
char c;
int n, a, o, i, e, u, idxI;
printf("text=\n");
gets(sz);
n = strlen(sz);
a = o = i = e = u = 0;
for(idxI = 0;
idxI < n;
idxI++) { c = sz[idxI];
switch (c) { case 'a': case 'A': a++;
break;
case 'o': case 'O': o++;
break;
case 'i': case 'I': i++;
break;
case 'e': case 'E': e++;
break;
case 'u': case 'U': u++;
break;
} } } printf("Vowel statistics:\n");
printf(" a,A: %d\n", a);
printf(" e,E: %d\n", e);
printf(" i,I: %d\n", i);
printf(" o,O: %d\n", o);
printf(" u,U: %d\n", u);
return 0;

// 3.12.2. Készítsen statisztikát egy szövegben lévő szavak és mondatok számáról! 3.13. Kódolt beszéd
3.12.2.
#include <stdio.h>
#include <string.h> int main() { char text[80];
char nextChar;
int textSize, sentence, word, idxI;
} printf("Text= ");
gets(text);
textSize = strlen(text);
if (text[0] == '\0') sentence = word = 0;
else { sentence = 0;
word = 1;
} for (idxI = 0;
idxI < textSize;
idxI++) { nextChar = text[idxI];
switch (nextChar) { case ' ': word++;
break;
case '.': case '!': case '?': sentence++;
break;
} } printf("Vowel statistics:\n");
printf("Word: %d\n", word);
printf("Sentence: %d\n", sentence);
return 0;


// 3.1.2. Alakítsa át a program kiírását úgy, hogy a bekért szó függőlegesen jelenjen meg és a hozzá tartozó kiírások az egyes karakterektől jobbra helyezkedjenek el! 3.2. Osztás és maradékképzés
3.1.2.
#include <stdio.h> int main() { const int size = 6;
int idxI;
char string[size + 1];
} printf("string=");
scanf("%6s", string);
printf("The string is: %s\n", string);
printf("The static string address, string: %p\n", string);
printf("The dynamic string address, &string: %p\n", &string);
for (idxI = 0;
idxI < size;
idxI++) { printf("\'%c\'", string[idxI]);
if (string[idxI] == 0) { printf("\t0x");
printf("%#-2x", string[idxI]);
} else { printf("\t%#-2x", string[idxI]);
} printf("\tstring[%d] ", idxI);
printf("\t%p ", &(string[idxI]));
printf("\n");
} return 0;

// 3.13.1. Írja meg a „tuvudsz ivigy beveszevelnivi” programot! A kimenet csupa nagybetű legyen! írja meg azt a függvényt, amely eldönti, hogy egy betű magánhangzó-e! 
3.13.1.
#include <stdio.h>
#include <string.h>
#include <ctype.h> int in(char c) { char s[]="AEIOU";
unsigned int idxI;
idxI=0;
do { if (c == s[idxI]) return 1;
idxI++;
} while (idxI <= strlen(s));
return 0;
} int main() { char orig[255], newVer[255], kar;
unsigned int idxI;
int idxJ;
printf("sentence=\n");
gets(orig);
idxJ=-1;
for(idxI=0;
idxI<strlen(orig);
idxI++) { idxJ++;
kar=toupper(orig[idxI]);
newVer[idxJ]=kar;
if( in(kar) ) { newVer[++idxJ]='V';
newVer[++idxJ]=kar;
} } newVer[++idxJ]='\0';
printf("%s", newVer);
return 0;
} 

// 3.13.2. Bővítse úgy a programot, hogy az új sztring egy megfelelően hosszú dinamikus tömbbe kerüljön! Készítse el a visszafele kódoló függvényt! 3.14. Sztring kivonás
3.13.2.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h> int main() { char original[255], *newVer;
int idxI, idxJ;
printf("Sentence: ");
gets(original);
newVer = (char*) malloc (sizeof(char)*strlen(original));
foglalas idxJ = 0;
for (idxI = 0;
idxI < strlen(original);
idxI++) { if (toupper(original[idxI]) != 'V') { newVer[idxJ] = toupper(original[idxI]);
idxJ++;
} else { if ( toupper(original[idxI]) == toupper(original[idxI + 2]) ) { newVer[idxJ++] = toupper(original[idxI++]);
newVer[idxJ++] = toupper(original[idxI++]);
idxI++;
} else idxI++;
} } newVer[idxJ] = '\0';
printf("%s\n", newVer);
free(newVer);
return 0;
} 

// 3.14.1. Írjon programot, amely egy sztringből kivon egy másikat! Például: almafavirág - fa = almavirág. Ha a második paraméter nincs az elsőben, akkor ne változzon az első paraméter érétke! 
3.14.1.
#include <stdio.h>
#include <string.h> void substract(char* from, char* what) { char* subString=0;
int len;
subString=strstr(from, what);
if (!subString) return;
len = strlen(what);
strcpy(subString, subString+len);
} int main() { char from[200], what[100];
} printf("Substract from=");
scanf("%s", from);
printf("Substract what=");
scanf("%s", what);
substract(from, what);
printf("\nThe reduced word is: %s", from);
return 0;

// 3.14.2. Módosítsa úgy a programot, hogy a második sztring minden előfordulását kiveszi az elsőből! 3.15. Kisbetű - nagybetű
3.14.2.
#include <stdio.h>
#include <string.h> void substract(char* from, char* what) { char* subString = 0;
int length;
subString = strstr(from, what);
if (!subString) return;
length = strlen(what);
strcpy(subString, subString + length);
substract(from, what);
} int main() { char from[200], what[100];
printf("Substract from=");
scanf("%s", from);
printf("Substract what=");
scanf("%s", what);
substract(from, what);
printf("\nThe reduced word is: %s\n", from);
return 0;
} 

// 3.15.1. Írjon programot, amely bekért mondatot formáz adott választás szerint! Menüből választhatóak a következő lehetőségek: UPPER CASE (mindent nagybetűre), lower case (mindent kisbetűre), tOGGLE CASE (kis betűket nagyra és nagyokat kicsire), Sentense case (a sor első betűje nagy csak), Title Case (minden szókezdő betű nagy). Mind a konvertálások, mind a menü függvénnyel legyen megoldva! 
3.15.1.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h> char* upperCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) result[idxI]=toupper(result[idxI]);
return result;
} char* lowerCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) result[idxI]=tolower(result[idxI]);
return result;
} char* toggleCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) { if (isupper(result[idxI])) result[idxI]=tolower(result[idxI]);
else result[idxI]=toupper(result[idxI]);
} return result;
} char* sentenceCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
result[0]=toupper(result[0]);
for (idxI=1;
idxI<len;
idxI++) result[idxI]=tolower(result[idxI]);
return result;
} char* titleCase(char* string) { char* result=0;
int len, idxI, startWord=1;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) { if (startWord) result[idxI]=toupper(result[idxI]);
else result[idxI]=tolower(result[idxI]);
if (result[idxI]==' ') startWord = 1;
else startWord = 0;
} return result;
} int menu() { int select;
printf("UPPER CASE - 1\n");
printf("lower case - 2\n");
printf("tOGGLE CASE - 3\n");
printf("Sentence case - 4\n");
printf("Title Case - 5\n");
scanf("%d", &select);
return select;
} int main() { char myString[200], *result;
int cheoice;
printf("orinigal string=");
gets(myString);
choice = menu();
switch (choice) { case 1: result = upperCase(myString);
break;
case 2: result = lowerCase(myString);
break;
case 3: result = toggleCase(myString);
break;
case 4: result = sentenceCase(myString);
break;
case 5: result = titleCase(myString);
break;
} printf("\nresult=\"%s\"", result);
free(result);
return 0;
} 

// 3.15.2. Valósítsa meg a „Nice Title Case” formázást! A szavak első betűje nagy kivéve az alábbi szavak esetén: and, of, the, a, an, from, for, in. A kivételt nem kell figyelembe venni a sor első karakterénél és egy kettős pont után. Például: „The Life of an English Man and the War” 3.16. Tömbnövelés
3.15.2.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h> char* lowerCase(char* string) { char* result=0;
int len, idxI;
result = _strdup(string);
len = strlen(string);
for (idxI = 0;
idxI < len;
idxI++) result[idxI] = tolower(result[idxI]);
return result;
} char* sentenceCase(char* string) { char* result = 0;
int len, idxI;
result = _strdup(string);
len = strlen(string);
result[0] = toupper(result[0]);
for (idxI = 1;
idxI < len;
idxI++) result[idxI] = tolower(result[idxI]);
return result;
} char* niceTitleCase(char* string) { char* result = 0;
int len, idxI, startWord = 1;
result = _strdup(string);
len = strlen(string);
result = lowerCase(result);
result = sentenceCase(result);
for (idxI = 0;
idxI < len;
idxI++) { if (result[idxI] == ':') { legyen mindenfele keppen nagybetu result[idxI+1] = toupper(result[idxI+1]);
idxI++;
} else if( result[idxI] == 'f' && result[idxI+1] == 'o' && result[idxI+2] == 'r' && result[idxI+3] == ' ') idxI += 3;
else if (result[idxI] == 'a' && result[idxI+1] == 'n' && result[idxI+2] == 'd' && result[idxI+3] == ' ') idxI += 3;
else if (result[idxI] == 't' && result[idxI+1] == 'h' && result[idxI+2] == 'e' && result[idxI+3] == ' ') idxI += 3;
else if (result[idxI] == 'f' && result[idxI+1] == 'r' && result[idxI+2] == 'o' && result[idxI+3] == 'm' && result[idxI+4] == ' ') idxI += 4;
else if (result[idxI] == 'o' && result[idxI+1] == 'f' && result[idxI+2] == ' ') idxI += 2;
else if (result[idxI] == 'i' && result[idxI+1] == 'n' && result[idxI+2] == ' ') idxI += 2;
else if (startWord) result[idxI] = toupper(result[idxI]);
else result[idxI] = tolower(result[idxI]);
if (result[idxI] == ' ' || result[idxI] == '\t' || result[idxI] == '\n') startWord = 1;
else startWord = 0;
} return result;
} int main() { char myString[200], *result;
printf("original string=");
gets(myString);
result = niceTitleCase(myString);
} printf("\nresult= \"%s\"\n", result);
free(result);
return 0;

// 3.16.1. Írjon programot, amely bekéri egy tömb méretét, lefoglalja a helyet a tömb számára és feltölti elemekkel! Növelje meg a tömb méretét duplájára úgy, hogy létrehoz egy új tömböt, és belemásolja a régi tömböt! Töltse fel a maradék helyet is új értékekkel! 

3.16.1.
#include <malloc.h>
#include <memory.h> int main() { int size, idxI;
double *array=NULL, *temp=NULL;
} printf("array size: ");
scanf("%d", &size);
array = (double*)malloc(size*sizeof(double));
for (idxI=0;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} temp = (double*)malloc(size*2*sizeof(double));
memcpy(temp, array, size*sizeof(double));
array = temp;
size *= 2;
temp = NULL;
for (idxI=size/2;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} free(array);
array = NULL;
return 0;

// 3.16.2. Alakítsa át úgy az előző programot, hogy függvényben kérje be tömb méretet és ott hozza azt létre!  
3.16.2.
#include <stdio.h>
#include <malloc.h>
#include <memory.h> double* allocArray(int* size) { double* result=NULL;
printf("\narray size: ");
scanf("%d", size);
result = (double*)malloc(*size * sizeof(double));
return result;
} int main() { int size, idxI;
double *array=NULL, *temp=NULL;
array = allocArray(&size);
for (idxI=0;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} temp = (double*)malloc(size*2*sizeof(double));
memcpy(temp, array, size*sizeof(double));
array = temp;
} size *= 2;
temp = NULL;
for (idxI=size/2;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} free(array);
array = NULL;
return 0;

// 3.17.1. Írjon programot két dinamikus mátrix összeszorzására! Függvényben foglaljon helyet a mátrixoknak, amelyeket véletlen egészekkel töltsön fel! Írjon függvényt a mátrixszorozásra, ellenőrizze, hogy a mátrix mértek kompatibilisek-e, a függvény visszatérési értéke legyen az új eredmény mátrix! Írassa ki az eredetei és az eredmény mátrixokat függvényben, majd szabadítsa fel azokat! 
3.17.1.
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <time.h> double** allocMatrix(int rows, int cols) { double** result=NULL;
int idxI;
if (rows<=0 || cols<=0) return NULL;
result = (double**)malloc(rows * sizeof(double*));
for (idxI=0;
idxI<rows;
idxI++) { result[idxI] = (double*)malloc(cols * sizeof(double));
} return result;
} void freeMatrix(double** mat, int rows) { int idxI;
if (rows<=0) return;
if (!mat) return;
for (idxI=0;
idxI<rows;
idxI++) { if (!mat[idxI]) free(mat[idxI]);
} free(mat);
} void randMatrix(double** mat, int rows, int cols, int min, int max) { int idxI, idxJ;
if (rows<=0 || cols<=0) return;
srand((unsigned int)time(NULL));
for (idxI=0;
idxI<rows;
idxI++) { for (idxJ=0;
idxJ<cols;
idxJ++) { mat[idxI][idxJ] = rand()%(max-min+1)+min;
} } } double** multMatrix(double** matA, int rowA, int colA, double** matB, int rowB, int colB, int *rowC, int *colC) { double** result=NULL, sum;
int idxI, idxJ, idxK;
if (colA != rowB) } return NULL;
*rowC = rowA;
*colC = colB;
result = allocMatrix(*rowC, *colC);
srand((unsigned int)time(NULL));
for (idxI=0;
idxI<rowA;
idxI++) { for (idxJ=0;
idxJ<colB;
idxJ++) { sum = 0;
for (idxK=0;
idxK<colA;
idxK++) { sum += matA[idxI][idxK]*matB[idxK][idxJ];
} result[idxI][idxJ] = sum;
} } return result;
void printMatrix(double** mat, int rows, int cols) { int idxI, idxJ;
if (rows<=0 || cols<=0) return;
for (idxI=0;
idxI<rows;
idxI++) { printf("[");
for (idxJ=0;
idxJ<cols;
idxJ++) { printf("%lf, ", mat[idxI][idxJ]);
} printf("]\n");
} } int main() { int rowA, colA, rowB, colB, rowC, colC;
double **matA=NULL, **matB=NULL, **matC=NULL;
printf("Number of rows of matrix A: ");
scanf("%d", &rowA);
printf("Number of columns of matrix A: ");
scanf("%d", &colA);
printf("Number of rows of matrix B: ");
scanf("%d", &rowB);
printf("Number of columns of matrix B: ");
scanf("%d", &colB);
matA = allocMatrix(rowA, colA);
matB = allocMatrix(rowB, colB);
randMatrix(matA, rowA, colA, 12, 16);
randMatrix(matB, rowB, colB, -4, 5);
matC = multMatrix(matA, rowA, colA, matB, rowB, colB, &rowC, &colC);
printf("matrix A =\n");
printMatrix(matA, rowA, colA);
printf("matrix B =\n");
printMatrix(matB, rowB, colB);
printf("matrix A*B =\n");
printMatrix(matC, rowC, colC);
freeMatrix(matA, rowA);
matA = NULL;
freeMatrix(matB, rowB);
matB = NULL;
freeMatrix(matC, rowC);
matC = NULL;
return 0;
} 

// 3.17.2. Készítse el az újraméretez függvényt, amely vagy levág a mátrixból egy darabot, és/vagy a mátrix jobb oldalához illetve aljához hozzáfűz egy új részt! Az új rész egységmátrix szerűen tartalmazzon 0-kat és 1-ket, ha az új rész nem négyzet alakú, akkor az egyesek fűrészfog szerűen helyezkedjenek el! 1 1 1 1 1 1 1 3.3. ábra: Téglalap alakú egységmátrix 3.18. Virtuális memória
3.17.2.
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <time.h> double** allocMatrix(int rows, int cols) { double** result = NULL;
int idxI;
if (rows <= 0 || cols <= 0) return NULL;
result = (double**) malloc(rows * sizeof(double*));
for (idxI = 0;
idxI < rows;
idxI++) { result[idxI] = (double*) malloc(cols * sizeof(double));
} return result;
} void freeMatrix(double** mat, int rows) { int idxI;
if (rows <= 0) return;
if (!mat) return;
for (idxI = 0;
idxI < rows;
idxI++) { free(mat[idxI]);
} free(mat);
} void randMatrix(double** mat, int rows, int cols, int min, int max) { int idxI, idxJ;
if (rows <= 0 || cols <= 0) return;
srand((unsigned int) time(NULL));
for (idxI = 0;
idxI < rows;
idxI++) { for (idxJ = 0;
idxJ < cols;
idxJ++) { mat[idxI][idxJ] = rand() % (max - min + 1) + min;
} } } void printMatrix(double** mat, int rows, int cols) { int idxI, idxJ;
if (rows <= 0 || cols <= 0) return;
for (idxI = 0;
idxI < rows;
idxI++) { printf("[");
for (idxJ = 0;
idxJ < cols;
idxJ++) { printf("%.2lf, ", mat[idxI][idxJ]);
} printf("]\n");
} } void cutMatrix(double ** mat, int rows, int cols) { double** result = NULL;
int selected, newcols = 0, newrows = 0, i, j, db = 0;
printf("1. Cut the bottom and add to the right side.\n");
printf("2. Cut the bottom\n");
printf("3. Add to the right side\n");
printf("Choose: ");
scanf("%d", &selected);
switch (selected) { case 1: printf("How many rows whould you like to delete? ");
scanf("%d", &newrows);
printf("How many columns whould you like to add to the right side? ");
scanf("%d", &newcols);
newcols += cols;
newrows = cols - newrows;
result = allocMatrix(newrows, newcols);
for (i = 0;
i < newrows;
i++) { for (j = 0;
j < newcols;
j++) { result[i][j] = mat[i][j];
} } for (i = 0;
i < cols;
i++) { if ((i + 1) % (newrows) == 0) { db++;
} } 1) for (i = cols;
i < newcols;
i++) { for (j = 0;
j < newrows;
j++) { if ((((i + 1) - (newrows * db)) / (j + 1)) == 1 && (((i + - (newrows * db)) % (j + 1)) == 0) { result[j][i] = 1;
} else { result[j][i] = 0;
} } if ((i + 1) % (newrows) == 0) { db++;
} } break;
break;
case 2: printf("How many rows whould you like to delete? ");
scanf("%d", &newrows);
newcols += cols;
newrows = rows - newrows;
result = allocMatrix(newrows, newcols);
for (i = 0;
i < newrows;
i++) { for (j = 0;
j < newcols;
j++) { result[i][j] = mat[i][j];
} } break;
case 3: printf("How many columns whould you like to add to the right side? ");
1) scanf("%d", &newcols);
newcols += cols;
newrows += rows;
result = allocMatrix(newrows, newcols);
for (i = 0;
i < rows;
i++) { for (j = 0;
j < cols;
j++) { result[i][j] = mat[i][j];
} } for (i = 0;
i < cols;
i++) { if ((i + 1) % (newrows) == 0) { db++;
} } for (i = cols;
i < newcols;
i++) { for (j = 0;
j < newrows;
j++) { if ((((i + 1) - (newrows * db)) / (j + 1)) == 1 && (((i + - (newrows * db)) % (j + 1)) == 0) { result[j][i] = 1;
} else { result[j][i] = 0;
} } if ((i + 1) % (newrows) == 0) { db++;
} } break;
} } printf("matrix A =\n");
printMatrix(mat, rows, cols);
printf("new matrix A =\n");
printMatrix(result, newrows, newcols);
freeMatrix(result, newrows);
int main() { int rowA, colA;
double **matA = NULL;
printf("Number of rows of matrix A: ");
scanf("%d", &rowA);
printf("Number of columns of matrix A: ");
scanf("%d", &colA);
matA = allocMatrix(rowA, colA);
randMatrix(matA, rowA, colA, 12, 16);
cutMatrix(matA, rowA, colA);
} freeMatrix(matA, rowA);
matA = NULL;
return 0;

// 3.18.1. Kérje be egy lebegőpontos tömb méretét! Ha az 5 vagy kisebb, akkor hozzon létre dinamikus tömböt a memóriában, ha nagyobb, akkor pedig bináris fájlt a háttértáron! Készítsen struktúrát, amely tartalmaz egy FILE*, double* és méret adattagot! Készítsen függvényeket: tároló inicializálására és felszabadítására, tároló adott pozíciójában történő olvasásra és írásra. Menüben kérje be, hogy írni vagy olvasni akar, a fő függvény számára a tárolás módja legyen transzparens! 3.19. Gépelés
3.18.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> const int limit=5;
typedef struct { FILE* bf;
double* array;
long int size;
} Store;
void initStore(Store* myStore) { printf("Size of the array: ");
scanf("%ld", &myStore->size);
if (myStore->size>limit) myStore->bf = fopen("temp.txt", "w+b");
else myStore->array = (double*)malloc(sizeof(double)*myStore->size);
return;
} void delStore(Store* myStore) { if (myStore->size>limit) { fclose(myStore->bf);
myStore->bf = NULL;
} else free(myStore->array);
myStore->array = NULL;
return;
} void readStore(Store* myStore) { double result;
int idx;
printf("Index of element to read: ");
scanf("%d", &idx);
if (myStore->size>limit) { fseek(myStore->bf, sizeof(double)*idx, SEEK_SET);
fread(&result, sizeof(double), 1, myStore->bf);
} else { result = myStore->array[idx];
} printf("At %d there is: %lf\n", idx, result);
} void writeStore(Store* myStore) { double value;
int idx;
printf("Index of element to write: ");
scanf("%d", &idx);
printf("value: ");
scanf("%lf", &value);
if (myStore->size>limit) { fseek(myStore->bf, sizeof(double)*idx, SEEK_SET);
fwrite(&value, sizeof(double), 1, myStore->bf);
} else { myStore->array[idx] = value;
} printf("%lf is written at %d\n", value, idx);
} int main() { Store myStore={NULL, NULL, 0};
int selection=0;
} initStore(&myStore);
while (selection!=3) { printf("\nRead - 1\nWrite - 2\nQuit - 3\n");
scanf("%d", &selection);
switch (selection) { case 1: readStore(&myStore);
break;
case 2: writeStore(&myStore);
break;
} } delStore(&myStore);
return 0;

// 3.19.1. Készítsen gépelést tanító programot! Sztring tömbben tároljon 20 különféle szót! Kérje be, hogy hány szót akar gépelni, véletlenszerűen válasszon ki egyet, amit megjelenít, és aztán várja azt bemenetként! Hibás bevitel esetén kérje be újból a szót! A gyakorlás végén írja ki az eltelt időt és a helyes és elrontott szavak számát! 3.20. Nagy számok összeadása
3.19.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> int main() { char words[][50]={"element", "size", "love", "ball", "toy", "gambit", "cruiser", "shadow", "console", "Atlantis", "port", "staple", "Leonardo", "bug", "hope", "vanity", "time", "issue", "fan", "strength"};
char temp[50];
int size=sizeof(words)/sizeof(*words);
int trial, idxI, randIndex, errors=0;
clock_t start, finish;
double duration;
srand((unsigned)time(NULL));
printf("How much word would you like to type: ");
scanf("%d", &trial);
start = clock();
for (idxI=0;
idxI<trial;
idxI++) { randIndex = rand() % size;
printf("type: %s\n", words[randIndex]);
scanf("%s", temp);
while (strcmp(temp, words[randIndex]) != 0) { printf("error!\n");
errors++;
scanf("%s", temp);
} } finish = clock();
duration = (double)(finish - start) / CLOCKS_PER_SEC;
printf("Ellapsed time: %4.2lf\n", duration);
} printf("Number of good trials: %d, bad trials: %d", trial, errors);
return 0;

// 3.20.1. Írjon programot két nagyon nagy pozitív egész szám összeadására! A számok legfeljebb 100 jegyűek. Írja ki a képernyőre a két számot, majd az összegüket, a következő formátumban. A két számot fájlból olvassa be, a számok szóközzel vannak elválasztva. A számokat statikus karaktertömbökben tárolja! Példa bemenet: 434234643643746 575434253245430 Kimenet: 434234643643746 + 575434253245430 = 1009668896889176 3. 

3.20.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define INPUT_FILE "numbers.txt" #define MAX_NUMBER_LENGTH 101 #define max(a, b) ((a) > (b) ? (a) : (b)) #define min(a, b) ((a) > (b) ? (b) : (a)) char AddChar(char A, char B, char C) { int n = (A - '0') + (B - '0') + (C - '0');
return ( (n % 10)) + '0';
} char AddM(char A, char B, char C) { int n = (A - '0') + (B - '0') + (C - '0');
return ( (n / 10)) + '0';
} void Add(char * NA, char * NB, char * C) { char m;
int AI, BI;
char * A;
char * B;
int i, j;
AI = strlen(NA);
BI = strlen(NB);
A = (AI > BI) ? NA : NB;
B = (AI <= BI) ? NA : NB;
if (BI > AI) { int temp = BI;
BI = AI;
AI = temp;
} C[0] = '0';
strcpy(C + 1, A);
j = BI - 1;
m = '0';
for (i = AI - 1;
i >= 0;
i--) { if (j >= 0) { C[i + 1] = AddChar(A[i], B[j], m);
m = AddM(A[i], B[j], m);
j--;
} else { if (m != '0') { } } } C[i + 1] = AddChar(A[i], '0', m);
m = AddM(A[i], '0', m);
} C[0] = m;
if (C[0] == '0') strcpy(C, C + 1);
void Read(FILE * fd) { char Num1[MAX_NUMBER_LENGTH];
char Num2[MAX_NUMBER_LENGTH];
char Num3[MAX_NUMBER_LENGTH];
fscanf(fd, "%s %s", Num1, Num2);
printf("%s + %s = ", Num1, Num2);
Add(Num1, Num2, Num3);
printf("%s\n", Num3);
} int main() { FILE * fd = fopen(INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} Read(fd);
return 0;
} 

// 3.21.1. Írjon programot, amely számokat olvas be fájlból, majd kiszámítja ezek átlagát és mediánját! A program írja ki a képernyőre a számokat, az átlagot, és a mediánt is! A medián kiszámításához először sorba kell rendeznie a számokat. Páratlan számú adat esetén a medián ebben a sorban a középső elem, páros számú adat esetén a két középső elem átlaga. Az input fájl formátuma: Első sor: Az adatok száma. Második sor: A számok, egy-egy szóköz karakterrel elválasztva. Példa bemenet: 4 2 5 3 4 2 5 1 3 5 1 5 5 5 4 4 3 4 4 2 5 5 1 5 5 3 2 5 2 5 Kimenet: 30 numbers: 4 2 5 3 4 2 5 1 3 5 1 5 5 5 4 4 3 4 4 2 5 5 1 5 5 3 2 5 2 5 The average is 3.63333 The median is: 4 3.22. Ösztöndíj

3.21.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUT "datas.txt" int Read(FILE * fd, int ** nums) { int count, i;
fscanf(fd, "%d", &count);
printf("%d numbers:\n", count);
*nums = (int *)malloc(sizeof(int) * count);
for (i = 0;
i < count;
i++) { fscanf(fd, "%d", (*nums) + i);
printf("%d ", (*nums)[i]);
} printf("\n");
return count;
} double Median(int count, int * A) { int i, j, pos, temp;
for (i = 0;
i < count - 1;
i++) { pos = i;
for (j = i;
j < count;
j++) { if (A[j] < A[pos]) pos = j;
} temp = A[i];
A[i] = A[pos];
A[pos] = temp;
} return count % 2 ? A[count / 2] : (A[ count / 2 - 1] + A[ count / 2]) / 2.0 ;
} double Average(int count, int * A) { long int sum = 0;
int i;
for (i = 0;
i < count;
i++) sum += A[i];
return (double)sum / count;
} int main(int argc, char * argv[]) { int count;
int * datas = NULL;
FILE * fd = fopen( argc > 0 ? argv[1] : DEFAULT_INPUT, "r");
if (fd == NULL) { perror("Error");
return 0;
} count = Read(fd, &datas);
fclose(fd);
printf("The average is %g\n", Average(count, datas));
printf("The median is: %g\n", Median(count, datas));
free(datas);
return 0;
} 


// 3.2.1. Tároljon két tömbben 5-5 egész számot, az osztókat és az osztandókat! Az értékeket inicializálással adja át a tömböknek, legyen köztük negatívok is! Tippelje meg az egészosztás és maradékképzés eredményét! Írja ki a helyes választ és számolja, a helyes válaszok számát! Ötlet: ellenőrizze, hogy a második tömbben ne legyen nulla! 

3.2.1.
#include <stdio.h>
#include <math.h> int main() { const int size=4;
int idxI, op1[size]={2, -3, 0, 1}, op2[size]={4, 2, -4, 5}, points=0, answer, result;
for (idxI=0;
idxI<size;
idxI++) { printf("%d/%d=", op1[idxI], op2[idxI]);
scanf("%d", &answer);
result=op1[idxI]/op2[idxI];
printf("%d/%d=%d\n", op1[idxI], op2[idxI], result);
if (answer==result) { points++;
} printf("%d%%%d=", op1[idxI], op2[idxI]);
scanf("%d", &answer);
result=op1[idxI]%op2[idxI];
printf("%d%%%d=%d\n\n", op1[idxI], op2[idxI], result);
if (answer==result) { points++;
} } } printf("You have %d points.\n", points);
return 0;


// 
3.22.1. Írjon programot, amely kiszámítja a hallgatók ösztöndíját a tanulmányi átlaguk alapján! Fájl tartalmazza a hallgatók adatait: neptun kódjukat, és a tárgyaik kreditértékét, illetve a szerzett érdemjegyeket. A program írja ki a képernyőre minden hallgató esetében a neptun kódot, a felvett tárgyak számát, a szerzett érdemjegyek kredittel súlyozott átlagát, a felvett és a teljesített kreditek összegét, és a hallgató számára megítélt ösztöndíjat! Egy tárgy teljesített, ha a hallgató átment az adott tárgyból. Az átlagba a felvett tárgyak és nem a teljesítettek tartoznak. Az ösztöndíjak összege: · 0 <= átlag < 2 → 0 HUF · 2 <= átlag < 3 → 15 000 HUF · 3 <= átlag < 4 → 20 000 HUF · 4 <= átlag < 4.5 → 25 000 HUF · 4.5 <= átlag <= 5 → 30 000 HUF Az input fájl formátuma: Első sor: A hallgatók száma. A hallgatók adatait tartalmazó sor: Sztring number1 Az egyes tárgyakhoz tartozó sor: number2 number3 Példa bemenet: 2 TGDS32 3 4 2 3 5 3 4 FBG4SW 3 4 5 2 3 4 1 A TGDS32 és FBG4SW neptun kódú hallgató adatait látjuk. TGDS32 3 tárgyat vett fel, az első tárgya 4 kredit értékű, az érdemjegye belőle 2. Kimenet: Neptun: TGDS32 3 subjects Neptun: FBG4SW 3 subjects TGDS32: Credits: 10/10 Average: 3.5 Bursary: 20000 HUF FBG4SW: Credits: 10/6 Average: 3 Bursary: 20000 HUF 3.23. Szavak keresése
3.22.1.
#include <stdio.h>
#include <stdlib.h> #define INPUT_FILE "students.txt" #define MIN_AVERAGE 2.0 #define MIDDLE_AVERAGE 3.0 #define GOOD_AVERAGE 4.0 #define EXCELLENT_AVERAGE 4.5 #define MIN_BURSARY 15000 #define MIDDLE_BURSARY 20000 #define GOOD_BURSARY 25000 #define EXCELLENT_BURSARY 30000 struct TSubject { int credit;
int mark;
};
struct TStudent { char Neptun[7];
int SubjNum;
struct TSubject * Subjects;
};
void ReadStudent(FILE * fd, struct TStudent * S) { int i;
fscanf(fd, "%s %d", S->Neptun, &S->SubjNum);
printf("Neptun: %s %d subjects\n", S->Neptun, S->SubjNum);
S->Subjects = (struct TSubject *)malloc(sizeof(struct TSubject) * S>SubjNum);
for (i = 0;
i < S->SubjNum;
i++) fscanf(fd, "%d %d", &(S->Subjects + i)->credit, &(S->Subjects + i)>mark);
} void Calc(struct TStudent * S, int SNum) { int i, j, sum;
int Credits, MaxCredits, Bursary;
double Average;
struct TSubject * Subj;
for (i = 0;
i < SNum;
i++) { Subj = S->Subjects;
Credits = MaxCredits = 0;
sum = 0;
for (j = 0;
j < S->SubjNum;
j++) { sum += Subj->credit * Subj->mark;
MaxCredits += Subj->credit;
if (Subj->mark >= 2) Credits += Subj->credit;
Subj++;
} Average = (double)sum / MaxCredits;
if (Average < MIN_AVERAGE) Bursary = 0;
else if (Average < MIDDLE_AVERAGE) Bursary = MIN_BURSARY;
else if (Average < GOOD_AVERAGE) Bursary = MIDDLE_BURSARY;
else if (Average < EXCELLENT_AVERAGE) Bursary = GOOD_BURSARY;
else Bursary = EXCELLENT_BURSARY;
printf("%s:\n\tCredits: %d/%d\n\tAverage: %g\n\tBursary: %d HUF\n",S>Neptun, MaxCredits, Credits, Average, Bursary);
S++;
} } int Read(FILE * fd, struct TStudent ** S) { int num, i;
fscanf(fd, "%d", &num);
*S = (struct TStudent *)malloc(sizeof(struct TStudent) * num);
for (i = 0;
i < num;
i++) ReadStudent(fd, (*S) + i);
return num;
} void FreeStudents(struct TStudent * S, int SNum) { int i;
for (i = 0;
i < SNum;
i++) { free(S[i].Subjects);
S[i].Subjects = NULL;
} } int main() { int StudentNum;
struct TStudent * Students;
FILE * fd = fopen(INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} StudentNum = Read(fd, &Students);
fclose(fd);
Calc(Students, StudentNum);
FreeStudents(Students, StudentNum);
return 0;
} 



// 3.2.2. Továbbra is meg kell tippelni a megoldást, de az operandusokat generálja véletlenszerűen -10 és 10 között! Véletlenszerűen döntse el azt is, hogy egész vagy lebegőpontos osztást végez! Utóbbinál függvényt kell használni a maradékképzésre. Lebegőpontos osztásnál mindig írja ki a tizedes pontot az operandusoknál! 3.3. Sztring konvertálás

3.2.2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { int A,B,TIP;
double result;
} srand(time(NULL));
A=((rand() % 20));
B=((rand() % 20));
TIP=(rand() % 2);
if(!TIP){ result=A/B;
printf("Integer division:\n");
printf("%d/%d=%d\n",A,B,(int)result);
}else{ result=(double)A/(double)B;
printf("Floating point division:\n");
printf("%d/%d=%.4lf\n",A,B,result);
} return 0;


3.23.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define MAX_LENGTH 100 #define DEFAULT_INPUTFILE "dune.txt" #define DEFAULT_WORD "Atreides" #define FALSE 0 #define TRUE 1 int CheckWord(char * W, int len) { int l = strlen(W);
int i;
for (i = len;
i < l;
i++) { if (((W[i] >= 'A') && (W[i] <= 'Z')) || ((W[i] >= 'a') && (W[i] <= 'z'))) } return FALSE;
} return TRUE;
int SearchWord(FILE * fd, char * W) { int count = 0;
int len = strlen(W);
char ReadedWord[MAX_LENGTH]={0};
char BeforeWord[MAX_LENGTH]={0};
BeforeWord[0] = 0;
do { strcpy(BeforeWord, ReadedWord);
ReadedWord[0] = 0;
fscanf(fd, "%s", ReadedWord);
if (strncmp(ReadedWord, W, len) == 0) { if (CheckWord(ReadedWord, len)) { printf("%s %s\n",BeforeWord, ReadedWord);
count++;
} } } while (!feof(fd));
return count;
} int main(int argc, char *argv[]) { char * FileName = argc > 1 ? argv[1] : DEFAULT_INPUTFILE;
char Word[MAX_LENGTH];
FILE * fd = fopen(FileName, "r");
if (fd == NULL) { perror(FileName);
return 0;
} if (argc > 2) strcpy(Word, argv[2]);
else strcpy(Word, DEFAULT_WORD);
printf("%d hits\n", SearchWord(fd, Word));
fclose(fd);
return 0;
} 
3.23.1. Írjon programot, amely beolvassa a „dune.txt” nevű fájlt és keresi benne az „Atreides” szót! A program írja ki a képernyőre az összes találatot az előtte lévő szóval együtt! Írja ki a találatok számát is! Ha egy írásjel szerepel az Atreides szó után, pl. „Atreides.”, „Atreides,”, az jó találatnak minősül, azonban amikor az Atreides szó egy részsztringje egy szónak, azt nem tekintjük jó találatnak, pl. „Atreides-Harkonnen”, „Atreides's”. Az input fájl formátuma: A szavak szóköz karakterekkel vannak elválasztva. Példa bemenet: Leto Atreides is the head of the Atreides house. Leto Atreides's son is Paul. Kimenet: Leto Atreides the Atreides 2 hits 3.24. Egyszerű sztringfordító
3.24.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "script.txt" #define MAX_COMMAND_LEN 10 #define MAX_OPERAND_LEN 5 #define STOP_CMD "STOP" #define GET_CMD "GET" #define ADD_CMD "ADD" #define SUB_CMD "SUB" #define MUL_CMD "MUL" #define DIV_CMD "DIV" #define WRITE_CMD "WRITE" void Get(FILE * fd, int * N) { char Op[MAX_OPERAND_LEN];
fscanf(fd, "%s", Op);
scanf("%d", N + (Op[0] - 'A'));
} void WriteComment(FILE * fd) { char ch;
fscanf(fd, "%c", &ch);
do { fscanf(fd, "%c", &ch);
if (ch != '#') printf("%c", ch);
} while (ch != '#');
} void Add(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] += N[ ch2 - 'A' ];
} void Sub(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] -= N[ ch2 - 'A' ];
} void Mul(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] *= N[ ch2 - 'A' ];
} void Div(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
} char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] /= N[ ch2 - 'A' ];
void Write(FILE * fd, int * N) { char Op[MAX_OPERAND_LEN];
fscanf(fd, "%s", Op);
printf("%d\n", N[ Op[0] - 'A' ]);
} void Run(FILE * fd) { int Numbers[3];
Numbers[0] = Numbers[1] = Numbers[2] = 0;
char Command[MAX_COMMAND_LEN];
do { fscanf(fd, "%s", Command);
if (strcmp(Command, "#") == 0) WriteComment(fd);
if (strcmp(Command, GET_CMD) == 0) Get(fd, Numbers);
if (strcmp(Command, ADD_CMD) == 0) Add(fd, Numbers);
if (strcmp(Command, SUB_CMD) == 0) Sub(fd, Numbers);
if (strcmp(Command, MUL_CMD) == 0) Mul(fd, Numbers);
if (strcmp(Command, DIV_CMD) == 0) Div(fd, Numbers);
} if (strcmp(Command, WRITE_CMD) == 0) Write(fd, Numbers);
} while (strcmp(Command, STOP_CMD) != 0);
int main(int argv, char * argc[]) { FILE * fd = fopen(argv > 1 ? argc[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} Run(fd);
fclose(fd);
return 0;
} 
3.24.1. Írjon programot, amely beolvas egy fájlból utasításokat és végrehajtja a benne foglaltakat! Az utasítások három integer típusú változót használhatnak: A, B, C. A script elején a változók értéke 0. A lehetséges utasítások a következők: GET Op: Op lehet egy változó (A, B, or C), ez a parancs beolvas egy tízes számrendszerbeli számot a billentyűzetről, és az Op-ban tárolja. WRITE Op: Op értékét a képernyőre írja. ADD Op1 Op2: Hozzáadja Op2-t Op1-hez, azaz Op1 = Op1 + Op2. SUB Op1 Op2: Kivonja Op2-t Op1-ből, azaz Op1 = Op1 - Op2. MUL Op1 Op2: Megszorozza Op1-et Op2-vel, azaz Op1 = Op1 * Op2. DIV Op1 Op2: Elosztja Op1-et Op2-vel, azaz Op1 = Op1 / Op2. STOP: Ez a parancs a script végét jelzi. Minden sorban csak egy parancs szerepel. Ha a sor # karakterrel kezdődik, azt a sort megjegyzésnek tekintjük. Ezeknek a soroknak a végét is egy # karakter jelzi. Az első # után egy szóköz karakter következik. A program írja ki ezeket a sorokat a képernyőre, a # karakterek kivételével! Például ha a sor a következő „# This is a comment! #”, a program a következőt írja ki: „This is a comment!” Példa bemenet: # Type A: # GET A # Type B: # GET B ADD A B # The sum: # WRITE A STOP Kimenet: Type A: 1 Type B: 2 The sum: 3 3.25. Riemann integrál
3.25.1.
#include <stdio.h>
#include <stdlib.h>
#include <math.h> #define DEFAULT_A 0 #define DEFAULT_B 1 #define DEFAULT_NUM 1000000 #define min(a, b) ((a) > (b)) ? ( b ) : ( a ) #define max(a, b) ((a) > (b)) ? ( a ) : ( b ) double f1(double x) { return sqrt( (2.0 - x) * x } ) * 4.0;
double f2(double x) { return x * x;
} void Integral(int a, int b, int num, double (*fptr)(double), char * funct ) { int i;
double res = 0.0;
double interval = b - a;
double mini = interval / num;
double t;
for (i = 0;
i < num - 1;
i++) { t = min(fptr(mini * i), fptr(mini * (i + 1))) * mini;
res += t;
} printf("The Riemann integral of %s over x from %d to %d: %g\n", funct, a, b, res);
} int main(int argc, char * argv[]) { int a, b, num;
a = argc > 1 ? atoi(argv[1]) : DEFAULT_A;
b = argc > 2 ? atoi(argv[2]) : DEFAULT_B;
num = argc > 3 ? atoi(argv[3]) : DEFAULT_NUM;
printf("\n");
Integral(a, b, num, f1, "f1(x) ");
Integral(a, b, num, f2, "f2(x) ");
Integral(a, b, num, sin, "sin(x) ");
Integral(a, b, num, tan, "tan(x) ");
printf("\n");
return 0;
} 
3.25.1. Írjon programot, amely négy függvény Riemann-integrálját számítja ki 0 és 1 között! Elsőként az [a, b] intervallumot felosztjuk N db (1000000) részre, azaz egy kis intervallum hossza: h = (b - a)/N. N téglalapot képzünk úgy, hogy egyik téglalap se lógjon a függvény fölé. Az i-dik téglalap alapja tehát h magassága pedig f(h*i) és f(h*(i + 1)) közül a kisebbik. Az integrál a téglalapok összege. A számolandó függvények: f1(x) = f2(x) = x2 f3(x) = sin(x) f4(x) = tan(x) Ábra: Riemann integrál szemléltetése Példa bemenet: The Riemann integral of f1(x) over x from 0 to 1: 3.14159 The Riemann integral of f2(x) over x from 0 to 1: 0.333332 The Riemann integral of sin(x) over x from 0 to 1: 0.459696 The Riemann integral of tan(x) over x from 0 to 1: 0.615624 3.26. Polinomok összeadása
3.26.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "polynoms.txt" #define TRUE 1 #define FALSE 0 struct TPolynom { int Degree;
int * A;
};
void InitPolynom(struct TPolynom * P) { P->Degree = 0;
P->A = NULL;
} void FreePolynom(struct TPolynom * P) { free(P->A);
P->A = NULL;
P->Degree = 0;
} void ReadPolynom(FILE * fd, struct TPolynom * P) { int i;
fscanf(fd, "%d", &(P->Degree));
printf("Degree: %d\n", P->Degree);
P->A = (int *)malloc(sizeof(int) * (P->Degree + 1));
for (i = 0;
i <= P->Degree;
i++) fscanf(fd, "%d", P->A + i);
} void PrintPolynom(struct TPolynom * P) { int first = TRUE;
int i;
for (i = 0;
i < P->Degree;
i++) { if (P->A[i] != 0) { if (!first) { first = TRUE;
if (P->A[i] > 0) printf(" + ");
} if (P->A[i] < 0) printf(" - ");
first = FALSE;
if (abs(P->A[i]) == 1) printf("x");
else printf("%dx", abs(P->A[i]));
if (i < P->Degree - 1) printf("^%d", P->Degree - i);
} } if (P->A[ P->Degree ] != 0) { if (first) { } } printf("%d", P->A[ P->Degree ]);
} else { if (P->A[ P->Degree ] < 0) printf(" - %d", abs(P->A[ P->Degree ]));
else printf(" + %d", abs(P->A[ P->Degree ]));
} void AddPolynom(struct TPolynom * A, struct TPolynom * B, struct TPolynom * C) { int i;
if (C->A != NULL) { free(C->A);
InitPolynom(C);
} int * Max = A->Degree > B->Degree ? A->A : B->A;
int * Min = A->Degree > B->Degree ? B->A : A->A;
int min = A->Degree > B->Degree ? B->Degree : A->Degree;
C->Degree = A->Degree > B->Degree ? A->Degree : B->Degree;
C->A = (int*)malloc(sizeof(int) * (C->Degree + 1));
for (i = 0;
i <= C->Degree;
i++) C->A[i] = Max[i];
for (i = 0;
i <= min;
i++) C->A[i + ( C->Degree - min ) ] += Min[i];
} int main(int argc, char *argv[]) { struct TPolynom A, B, C;
InitPolynom(&A);
InitPolynom(&B);
InitPolynom(&C);
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadPolynom(fd, &A);
ReadPolynom(fd, &B);
fclose(fd);
PrintPolynom(&A);
printf(" +\n");
PrintPolynom(&B);
printf(" =\n");
AddPolynom(&A, &B, &C);
PrintPolynom(&C);
printf("\n");
FreePolynom(&A);
FreePolynom(&B);
FreePolynom(&C);
return 0;
} 
3.26.1. Írjon programot, amely polinomokat ad össze! Olvasson be fájlból két polinomot! Írja ki a képernyőre a két polinomot, illetve ezek összegét! A polinomok tárolására használjon dinamikus tömböket és struktúrákat. Az input fájl formátuma: Első sor: Number1 - az első polinom foka Második sor: Number1 + 1 egész szám, az első polinom együtthatói (az utolsó szám a konstans). Harmadik sor: Number2 - a második polinom foka Negyedik sor: Number2 + 1 egész szám, a második polinom (az utolsó szám a konstans). A számok egy-egy szóköz karakterrel vannak elválasztva Példa bemenet: 5 -3 5 -4 0 4 2 4 5 4 5 -1 0 Kimenet: - 3x^5 + 5x^4 - 4x^3 + 4x + 2 + 5x^4 + 4x^3 + 5x^2 - x = - 3x^5 + 10x^4 + 5x^2 + 3x + 2 3.27. Caesar dekódoló
3.27.1. A Cézár-kódolás a következőképpen működik: Minden karaktert egy előre meghatározott N pozícióval eltolunk. Például, ha N = 1, az „APPLE” szó BQQMD lesz, ugyanis A-ból B lett, P-ből Q, stb. Ha N = 1, Z-ből A lesz. Példa N = 3-ra: eredeti szöveg: THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG kódolt szöveg: WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ Az ellenségtől egy kódolt üzenetet kaptunk. Nem ismerjük N értékét, de a kémünk azt állítja, hogy az eredeti üzenet szavai közt szerepel a „THE” szó. Írjon programot, amely beolvassa a kódolt üzenetet a „codedmessage.txt” fájlból, és megfejti, mi volt az eredeti üzenet! N értéke 1 és 26 közt van, a programnak tehát meg kell vizsgálnia minden N-t, amíg az üzenet nem tartalmazza a „THE” szót. Az üzenet tárolására használjon dinamikus tömböt! Ábra: Caesar kódolás szemléltetése Az input fájl formátuma: Első sor: Az üzenet szavainak száma. Második sor: Az üzenet szavai, egy-egy szóköz karakterrel elválasztva. Példa bemenet: 9 WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ Kimenet: The coded message: WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ The original message: THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG 
3.27.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "codedmsg.txt" #define WORD "THE" #define MAX_WORD_LEN 15 typedef char TWord[MAX_WORD_LEN];
int ReadMessage(FILE * fd, TWord ** M) { int num, i;
fscanf(fd, "%d", &num);
(*M) = (TWord*)malloc(sizeof(TWord) * num);
for (i = 0;
i < num;
i++) fscanf(fd, "%s", (*M)[i]);
return num;
} void PrintMessage(TWord * M, int num) { int i;
for (i = 0;
i < num;
i++) printf("%s ", M[i]);
printf("\n");
} void Offset(TWord * M, int num, int offs) { int i, j, len;
for (i = 0;
i < num;
i++) { len = strlen(M[i]);
for (j = 0;
j < len;
j++) { M[i][j] += offs;
if (M[i][j] > 'Z') M[i][j] -= ('Z' - 'A' + 1 );
} } } void Decoding(TWord * M, int num) { int i = 0;
int j = num;
while ((i <= 'Z' - 'A') && (j >= num)) { Offset(M, num, 1);
j = 0;
while ((j < num) && (strcmp(M[j], WORD) != 0)) j++;
} } int main(int argc, char * argv[]) { int num;
TWord * Message;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} num = ReadMessage(fd, &Message);
fclose(fd);
printf("\nThe coded message: ");
PrintMessage(Message, num);
Decoding(Message, num);
printf("The original message: ");
PrintMessage(Message, num);
printf("\n");
free(Message);
Message = NULL;
return 0;
} 
3.27.2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "codedmsg.txt" #define MAX_WORD_LEN 15 char WORD[500];
typedef char TWord[MAX_WORD_LEN];
int ReadMessage(FILE * fd, TWord ** M) { int num, i;
fscanf(fd, "%d", &num);
(*M) = (TWord*)malloc(sizeof(TWord) * num);
for (i = 0;
i < num;
i++) fscanf(fd, "%s", (*M)[i]);
return num;
} void PrintMessage(TWord * M, int num) { int i;
for (i = 0;
i < num;
i++) printf("%s ", M[i]);
printf("\n");
} void Offset(TWord * M, int num, int offs) { int i, j, len;
for (i = 0;
i < num;
i++) { len = strlen(M[i]);
for (j = 0;
j < len;
j++) { M[i][j] += offs;
if (M[i][j] > 'Z') M[i][j] -= ('Z' - 'A' + 1 );
} } } void Decoding(TWord * M, int num) { int i = 0;
int j = num;
while ((i <= 'Z' - 'A') && (j >= num)) { Offset(M, num, 1);
j = 0;
while ((j < num) && (strcmp(M[j], WORD) != 0)) j++;
} } int main(int argc, char * argv[]) { int num;
TWord * Message;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} num = ReadMessage(fd, &Message);
fclose(fd);
printf("\nKnown word: ");
scanf("%s", WORD);
printf("\nThe coded message: ");
PrintMessage(Message, num);
Decoding(Message, num);
printf("The original message: ");
PrintMessage(Message, num);
printf("\n");
free(Message);
Message = NULL;
return 0;
} WKH TXLFN IRA 
3.27.2. Legyen a tartalmazott szó, a mostani „THE” is bemenet! Ha több lehetséges visszakódolás van, akkor jelenítse meg az összest! 3.28. CD katalógus
3.28.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "cds.txt" #define MAX_WORD_LENGTH 16 #define TRUE 1 #define FALSE 0 typedef char TWord[MAX_WORD_LENGTH];
struct TCD { int Num;
TWord Name;
TWord * P;
};
void ReadCD(FILE * fd, struct TCD * A) { int i;
fscanf(fd, "%s", A->Name);
fscanf(fd, "%d", &A->Num);
printf("%s:\n", A->Name);
A->P = (TWord *)malloc(sizeof(TWord) * A->Num);
for (i = 0;
i < A->Num;
i++) { fscanf(fd, "%s", A->P[i]);
printf("\t%s\n", A->P[i]);
} } int ReadCDs(FILE * fd, struct TCD ** A) { int num, i;
fscanf(fd, "%d", &num);
(*A) = (struct TCD * )malloc(sizeof(struct TCD) * num);
for (i = 0;
i < num;
i++) ReadCD(fd, (*A) + i);
return num;
} void Search(struct TCD * A, char * S, int num) { int i = 0;
int j;
int success = FALSE;
while ((i < num) && (!success)) { j = 0;
while ((j < A[i].Num) && (strcmp(A[i].P[j], S) != 0)) j++;
success = j < A[i].Num;
i++;
} if (success) printf("The %s is here: %s\n", S, A[i - 1].Name);
else printf("%s does not exists!\n", S);
} void FreeCDs(struct TCD * A, int num) { int i;
for (i = 0;
i < num;
i++) { free(A[i].P);
A[i].P = NULL;
} } int main(int argc, char * argv[]) { int CDNum;
struct TCD * CDs;
TWord Word;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} CDNum = ReadCDs(fd, &CDs);
fclose(fd);
printf("Program name: ");
scanf(„%s”, Word);
Search(CDs, Word, CDNum);
FreeCDs(CDs, CDNum);
free(CDs);
CDs = NULL;
return 0;
} 
3.28.1. Rendelkezik egy CD katalógussal, amit fájlban tárol. Írjon programot, amely képes arra, hogyha begépeli egy szoftver nevét, akkor megmondja, melyik CD-n van a szoftver! A szoftverek nevei maximum 15 karakter hosszúak, és minden CD-nek van egy neve, amely szintén maximum 15 karakter hosszú. Használjon struktúrákat, illetve dinamikus tömböket a fájlból beolvasott adatok tárolására! Az input fájl formátuma: Első sor: A CD-k száma. A további sorok: String: A CD neve Egész szám: A CD-n lévő szoftverek száma Ezután a CD-n lévő szoftverek neve következik. Példa bemenet: 2 2007/11 2 BurningStudio RadioRama 2005/4 3 Doc2PDF Apollo Stellarium A példában Jamesnek 2 CD-je van, az első neve „2007/11”, ezen a CD-n két szoftver van: BurningStudio és RadioRama. A másik CD 3 szoftvert tartalmaz. Kimenet: Software name: Apollo The Apollo is here: 2005/4 
3.28.2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "cds.txt" #define MAX_WORD_LENGTH 16 #define TRUE 1 #define FALSE 0 typedef char TWord[MAX_WORD_LENGTH];
struct TCD { int Num;
TWord Name;
TWord * P;
};
void ReadCD(FILE * fd, struct TCD * A) { int i;
fscanf(fd, "%s", A->Name);
fscanf(fd, "%d", &A->Num);
printf("%s:\n", A->Name);
A->P = (TWord *)malloc(sizeof(TWord) * A->Num);
for (i = 0;
i < A->Num;
i++) { fscanf(fd, "%s", A->P[i]);
printf("\t%s\n", A->P[i]);
} } int ReadCDs(FILE * fd, struct TCD ** A) { int num, i;
fscanf(fd, "%d", &num);
(*A) = (struct TCD * )malloc(sizeof(struct TCD) * num);
for (i = 0;
i < num;
i++) ReadCD(fd, (*A) + i);
return num;
} int spec_strcmp(const char* s1, const char* s2) { int l1=strlen(s1), l2=strlen(s2);
int l=l1<l2?l1:l2,i;
for (i=0;i<l;i++) { if (s1[i]!='?' && s1[i]!=s2[i] && s1[i]!='*') { return -1;
} } return 0;
} void Search(struct TCD * A, char * S, int num) { int i = 0;
int j;
int success = FALSE;
while ((i < num) && (!success)) { j = 0;
while ((j < A[i].Num) && (spec_strcmp(A[i].P[j], S) != 0)) j++;
success = j < A[i].Num;
i++;
} if (success) printf("The %s is here: %s\n", S, A[i - 1].Name);
else printf("%s does not exists!\n", S);
} void FreeCDs(struct TCD * A, int num) { int i;
for (i = 0;
i < num;
i++) { free(A[i].P);
A[i].P = NULL;
} } int main(int argc, char * argv[]) { int CDNum;
struct TCD * CDs;
TWord Word;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} CDNum = ReadCDs(fd, &CDs);
fclose(fd);
printf("Program name: ");
scanf("%s", Word);
Search(CDs, Word, CDNum);
FreeCDs(CDs, CDNum);
free(CDs);
CDs = NULL;
return 0;
} 2 2007/11 2 BurningStudio RadioRama 2005/4 3 Doc2PDF Apollo Stellarium 
3.28.2. Írja át úgy az előző programot, hogy lehessen a keresésnél egy ? vagy egy * karaktert használni! A ? egy tetszőleges karakter helyett állhat, a * pedig a sztring végén lehet és azt jelezi, hogy még valamennyi karakter hátra van. Ha egy minta több program nevére is illeszkedik, akkor jelenítse meg mindet! 3.29. Leltár
3.29.1. Egy cég termékek vásárlásával és eladásával foglalkozik. Az év elején 10.000 Ft-ja van. Egy fájlban tárolja az információkat a termékekről, az eladásokról és a beszerzésekről. Írjon programot, amely a fájlból beolvassa az adatokat, és megmondja az egyes termékek mennyiségét, illetve a cég egyenlegét az eladások és beszerzések után! Használjon dinamikus tömböket és struktúrákat az adatok tárolására! Az input fájl formátuma: Első sor: Number1 - a termékek száma A következő Number1 db sor: String Number2 Number3 Number4 String: az i-edik termék neve Number2: az i-edik termék mennyisége Number3: az i-edik termék beszerzési ára Number4: az i-edik termék eladási ára Number5: a termékekkel kapcsolatos adás-vételek száma Az ezután következő Number5 db sor: Number6 Number7 Number6: Az aktuális termék indexe (nem a neve, hanem a sorszáma) Number7: Ha ez a szám pozitív, a cég beszerzett a Number6-os termékből Number7 db-ot, beszerzési áron;
ha negatív, akkor a cég a Number6-os termékből eladott Number7 abszolút értékének megfelelő számú darabot, eladási áron. Példa bemenet: 2 hammer 100 500 800 screwdriver 50 300 400 2 1 10 2 -5 A példafájl esetében kétféle termékünk van: 100 db hammer és 50 db screwdriver. A cég 500 Ft-ért tud hammer-t beszerezni, és 800 Ft-ért tudja eladni. 2 féle termékmozgás történt, először vásároltak 500 Ft/db áron 10 db hammer-t, majd 400 Ft/db áron eladtak 5 db screwdriver-t. Kimenet: Inventory: **************************************** hammer: Count: 100 Purchase price: 500 Shop price: 800 screwdriver: Count: 50 Purchase price: 300 Shop price: 400 Inventory: **************************************** hammer: Count: 110 Purchase price: 500 Shop price: 800 screwdriver: Count: 45 Purchase price: 300 Shop price: 400 We have got 7000 HUF 3.30. Könyvtári rendszer
3.29.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "inventory.txt" #define MAX_LENGTH 15 #define START_MONEY 10000 struct TGood { int count;
int purchaseprice;
int shopprice;
char name[MAX_LENGTH];
};
int ReadInventory(FILE * fd, struct TGood ** Good) { int num, i;
fscanf(fd, "%d", &num);
(*Good) = (struct TGood*)malloc(sizeof(struct TGood) * num);
for (i = 0;
i < num;
i++) fscanf(fd, "%s %d %d %d", (*Good)[i].name, &(*Good)[i].count, &(*Good)[i].purchaseprice, &(*Good)[i].shopprice);
return num;
} void PrintInventory(struct TGood * G, int num) { int i;
printf("Inventory:\n****************************************\n");
for (i = 0;
i < num;
i++) printf("%s:\n\tCount: %d\n\tPurchase price: %d\n\tShop price: %d\n", G[i].name, G[i].count, G[i].purchaseprice, G[i].shopprice);
} int ReadLog(FILE * fd, int Money, int num, struct TGood * G) { int lognum, i;
int good, a;
fscanf(fd, "%d", &lognum);
for (i = 0;
i < lognum;
i++) { fscanf(fd, "%d %d", &good, &a);
G[good - 1].count += a;
if (a > 0) Money -= abs(a) * G[good - 1].purchaseprice;
else Money += abs(a) * G[good - 1].shopprice;
} return Money;
} int main(int argc, char *argv[]) { struct TGood * Inventory;
int GoodNum;
int Money = START_MONEY;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} GoodNum = ReadInventory(fd, &Inventory);
PrintInventory(Inventory, GoodNum);
Money = ReadLog(fd, Money, GoodNum, Inventory);
PrintInventory(Inventory, GoodNum);
printf("We have got %d HUF\n", Money);
fclose(fd);
free(Inventory);
Inventory = NULL;
return 0;
} 
3.30.1. A könyvtárakban a könyvek az Egyetemes Tizedes Osztályozás (ETO, angolul UDC) szerint vannak osztályozva. Minden könyvnek van egy ETO száma, amit a könyv témája határoz meg. Az ETO szám első számjegye a fő témát határozza meg: 0. Általános művek, bibliográfia, könyvtárügy. 1. Filozófia, pszichológia, logika, etika. 2. Vallás, egyházak, teológia. 3. Társadalomtudományok, közigazgatás, jog, oktatás. 4. Nem használt 5. Matematika, természettudományok, fizika, kémia. 6. Alkalmazott tudományok, műszaki tudományok, orvostudományok. 7. Művészetek, játék, sport, szórakozás. 8. Nyelvészet, irodalom 9. Régészet, földrajz, életrajz, történelem Például egy 543-as ETO számú könyvről tudjuk, hogy matematikával, vagy természettudományokkal foglalkozik. A többi számjegy a program szempontjából nem fontos. A „lib1.txt” fájlban könyvek adatai szerepelnek. A fájl tartalmazza a szerző nevét, a könyv címét, a kiadási évet és a könyv ETO számát. Írjon programot, amely beolvassa ezt a fájlt, listázza az egyes könyveket, végül összesítést ad, hogy hány könyv található a könyvtárban egy-egy a témában! Használjon dinamikus tömböket és struktúrákat az adatok tárolására! Az input fájl formátuma: Első sor: A könyvek száma. A többi sor formátuma: Szerző Rövid_Cím Kiadási év ETO (szóköz karakterekkel elválasztva). A szerző neve és a könyv címe maximum 20 karakterből áll, mindkettő egy-egy szó csak. Az ETO szám 3 karakterből áll. Példa bemenet: 3 Asimov Foundation 1980 820 Herbert Dune 1990 820 Dancs Terror 2001 512 Kimenet: Author: Asimov Title: Foundation Year of edition: 1980 UDC: 820 Language, Linguistics, Literature Author: Herbert Title: Dune Year of edition: 1990 UDC: 820 Language, Linguistics, Literature Author: Dancs Title: Terror Year of edition: 2001 UDC: 512 Matematika and natural sciences ************************************** Generalities: 0 books Philosophy, Psychology: 0 books Religion, Theology: 0 books Social sciences: 0 books vacant: 0 books Matematika and natural sciences: 1 books Applied sciences, Medicine, Technology: 0 books Arts, Recreation, Entertainment, Sport: 0 books Language, Linguistics, Literature: 2 books Geography, Biography, History: 0 books 3.31. Kikölcsönzött könyvek
3.30.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "lib1.txt" #define MAXLEN 21 #define MAXUDC 4 char * UDCClasses[10] = { "Generalities", "Philosophy, Psychology", "Religion, Theology", "Social sciences", "vacant", "Mathematics and natural sciences", "Applied sciences, Medicine, Technology", "Arts, Recreation, Entertainment, Sport" , "Language, Linguistics, Literature", "Geography, Biography, History"};
struct TBook { char title[MAXLEN];
char author[MAXLEN];
int edition;
char UDC[MAXUDC];
};
int ReadBooks(FILE * fd, struct TBook ** Books) { int num, i;
struct TBook * B;
fscanf(fd, "%d", &num);
(*Books) = B = (struct TBook*)malloc(sizeof(struct TBook) * num);
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s %d %s", B->title, B->author, &B->edition, B->UDC);
B++;
} return num;
} void CountBooks(struct TBook * B, int num) { int i;
int types[10];
for (i = 0;
i < 10;
i++) types[i] = 0;
printf("\n\n");
for (i = 0;
i < num;
i++) { printf("Author: %s\n Title: %s\nYear of edition: %d\nUDC: %s %s\n\n", B[i]. author, B[i].title, B[i].edition, B[i].UDC, UDCClasses[ B[i].UDC[0] - '0' ]);
types[ B[i].UDC[0] - '0' ]++;
} printf("\n**************************************\n\n");
for (i = 0;
i < 10;
i++) printf("%s: %d books\n", UDCClasses[i], types[i]);
printf("\n\n");
} int main(int argc, char * argv[]) { int booknum;
struct TBook * Books;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} booknum = ReadBooks(fd, &Books);
fclose(fd);
CountBooks(Books, booknum);
free(Books);
Books = NULL;
return 0;
} 
3.31.1. A könyvtárak nyilvántartást vezetnek a kikölcsönzött könyvekről. Ez tartalmazza a könyvek szerzőjét, címét, illetve a kölcsönzés lejáratának idejét. Tételezzük fel, hogy az aktuális dátum 2008. december 15. Írjon programot, amely beolvassa a kikölcsönzött könyvek listáját egy fájlból, és kilistázza azoknak a könyveknek az adatait, amelyek kölcsönzési ideje már lejárt! Használjon dinamikus tömböket és struktúrákat az adatok tárolására! Az input fájl formátuma: Első sor: A könyvek száma. A többi sor: Szerző Rövid_cím Év Hónap Nap A szerző neve és a könyv címe is egy-egy szó csak. Az év, hónap, nap a lejárat idejét jelölik. Példa bemenet: 3 Asimov Foundation 2009 1 20 Herbert Dune 2008 12 1 Dancs Terror 2008 11 30 Kimenet: Title: Herbert Author: Dune Expiraton: 2008 12 1 Title: Dancs Author: Terror Expiraton: 2008 11 30 3.32. Szótár
3.31.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "lib1.txt" #define MAXLEN 20 #define YEAR 2008 #define MONTH 12 #define DAY 15 #define TRUE 1 #define FALSE 0 struct TBook { char title[MAXLEN];
char author[MAXLEN];
int year, month, day;
};
int ReadBooks(FILE * fd, struct TBook ** Books) { int num, i;
struct TBook * B;
fscanf(fd, "%d", &num);
(*Books) = B = (struct TBook*)malloc(sizeof(struct TBook) * num);
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s %d %d %d", B->title, B->author, &B->year, &B>month, &B->day);
B++;
} return num;
} int Later(int y, int m, int d) { if (y < YEAR) return TRUE;
else if (y == YEAR) { if (m < MONTH) return TRUE;
else if (m == MONTH) { if (d < DAY) return TRUE;
} } return FALSE;
} void PrintBooks(struct TBook * B, int num) { int i;
printf("\n");
for (i = 0;
i < num;
i++) { } } if (Later(B[i].year, B[i].month, B[i].day)) printf("Title: %s\nAuthor: %s\nExpiraton: %d %d %d\n\n", B[i].title, B[i].author, B[i].year, B[i].month, B[i].day);
int main(int argc, char * argv[]) { int booknum;
struct TBook * Books;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} booknum = ReadBooks(fd, &Books);
fclose(fd);
PrintBooks(Books, booknum);
free(Books);
Books = NULL;
return 0;
} 
3.3.1.
#include <stdio.h> int main() { char string[]="23 35678 1.2345e11 -9.8765432e-11";
short int shortIntValue;
int intValue;
float floatValue;
double doubleValue, sum;
sscanf(string, "%hd %d %f %lf", &shortIntValue, &intValue, &floatValue, &doubleValue);
sum = shortIntValue + intValue + floatValue + doubleValue;
sprintf(string, "%lf", sum);
printf("The sum is %s", string);
return 0;
} 
3.3.1. Készítsen programot, amely statikus karaktertömbben lévő 4 számot átkonvertál short int, int, float és double típusra! A számok összegét írja be az eredeti tömbbe! 
3.32.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define MAXLEN 21 #define DEFAULT_INPUTFILE "dict.txt" void Search(FILE * fd, char * word) { int num, i, hits = 0;
char hword[MAXLEN], eword[MAXLEN];
fscanf(fd, "%d", &num);
eword[0] = 0;
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s", eword, hword);
if (strncmp(eword, word, strlen(word)) == 0) { printf("Eng->Hun: %s %s\n", eword, hword);
hits++;
} if (strcmp(hword, word) == 0) { printf("Hun->Eng: %s %s\n", hword, eword);
hits++;
} } printf("\n%d hits\n\n", hits);
} int main(int argc, char * argv[]) { char word[MAXLEN];
} FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} printf("\nType the word: ");
scanf("%s", word);
Search(fd, word);
fclose(fd);
printf("\n");
return 0;

3.32.1. Írjon angol-magyar szótár programot! Fájl tartalmazza az angol-magyar szópárokat! A program olvasson be egy szót a billentyűzetről! A szó a két nyelv bármelyikén lehet. Ezután olvassa be a szópárokat a fájlból, és keresse meg a megadott szóhoz tartozó szópárt! Az is találatnak számít, ha a begépelt szó, az előtagja az egyik szótári bejegyzésnek. Írja ki a képernyőre a találatokat! Az input fájl formátuma: Első sor: A szópárok száma A többi sor: Angol_szó Magyar_szó (szóköz karakterrel elválasztva) Egy-egy szó maximális hossza 20 karakter. Példa bemenet: 5 SUN NAP DOG KUTYA BICYCLE BICIKLI VILLAGE FALU SUNSHINE NAPSUTES Kimenet: Type the word: NAP Hun->Eng: NAP SUN 1 hits Kimenet: Type the word: SUN Eng->Hun: SUN NAP Eng->Hun: SUNSHINE NAPSUTES 2 hits 3.33. Sudoku ellenőrző
3.3.2. A kezdeti sztringben 3 double típusú szám legyen, az elsőt eggyel, a másodikat kettővel, a harmadikat hárommal növeljük meg! A megnövelt értékeket egy új tömbbe írjuk ki normál alakban, 8 tizedes pontossággal és előjellel! 3.4. Sztring bekérés
3.3.2.
#include <stdio.h> int main() { int idxI;
char string[] = "48.1658745 -654686835454.321635432435421 9.8765432e-11";
double doubleValue[3], sum = 0;
sscanf(string, "%lf %lf %lf", &doubleValue[0], &doubleValue[1], &doubleValue[2]);
for (idxI = 0;
idxI < 3;
idxI++) { doubleValue[idxI] = doubleValue[idxI] +idxI +1;
sum += doubleValue[idxI];
} sprintf(string, "%+.8lf %+.8lf %+.8lf", doubleValue[0], doubleValue[1], doubleValue[2]);
printf("The new string array is %s\n", string);
return 0;
} 
3.33.1.
#include <stdio.h>
#include <memory.h> #define TRUE 1 #define FALSE 0 #define DEFAULT_INPUTFILE "sudoku1.txt" typedef int TTable[9][9];
void ReadTable(FILE * fd, TTable T) { int i, j;
for (i = 0;
i < 9;
i++) { for (j = 0;
j < 9;
j++) fscanf(fd, "%d", &T[i][j]);
} } void PrintTable(TTable T) { int i, j;
for (i = 0;
i < 9;
i++) { for (j = 0;
j < 9;
j++) printf("%d ", T[i][j]);
printf("\n");
} } int CheckRowsColumns(TTable T) { int i, j, n, num;
for (i = 0;
i < 9;
i++) { for (j = 0;
j < 9;
j++) { n = i ? 0 : 1;
num = T[i][j];
while ((n < 9) && (T[n][j] != num)) n += (i == n + 1) ? 2 : 1;
if (n < 9) { printf("This is a wrong table!\n");
return FALSE;
} n = j ? 0 : 1;
num = T[i][j];
while ((n < 9) && (T[i][n] != num)) n += (j == n + 1) ? 2 : 1;
if (n < 9) { printf("This is a wrong table!\n");
return FALSE;
} } } } return TRUE;
int CheckOneCell(TTable T, int x, int y) { int i, j, num, err;
for (num = 1;
num <= 9;
num++) { err = TRUE;
for (i = y * 3;
i < (y + 1) * 3;
i++) { for (j = x * 3;
j < (x + 1) * 3;
j++) { if (T[i][j] == num) err = FALSE;
} } if (err) { printf("This is a wrong table!\n");
return FALSE;
} } return TRUE;
} void CheckCells(TTable T) { int i, j;
for (i = 0;
i < 3;
i++) for (j = 0;
j < 3;
j++) if (!CheckOneCell(T, i, j)) return;
printf("This table is correct!\n");
} void Check(TTable T) { if (CheckRowsColumns(T)) CheckCells(T);
} int main(int argc, char * argv[]) { TTable Table;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadTable(fd, Table);
fclose(fd);
PrintTable(Table);
Check(Table);
return 0;
} 
3.33.1. Írjon programot, amely leellenőriz egy kitöltött Sudoku táblát! A tábla értékeit olvassa be fájlból! Egy tábla akkor van helyesen kitöltve, ha minden sorban, minden oszlopban és minden kis 3x3-as kis négyzetben az 1-9 közti számjegyek mindegyike egyszer szerepel. Az ábrán egy helyesen kitöltött tábla szerepel. 9 5 8 2 7 4 6 3 1 1 4 7 5 3 6 9 2 8 2 6 3 9 8 1 4 7 5 8 3 1 4 6 9 2 5 7 4 2 5 3 1 7 8 9 6 7 9 6 8 5 2 1 4 3 3 1 4 7 2 8 5 6 9 5 8 9 6 4 3 7 1 2 6 7 2 1 9 5 3 8 4 Ábra: Sudoku tábla Az input fájl formátuma: Az input fájl 9 sort és 9 oszlopot tartalmaz. A számjegyek egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 7 4 6 8 3 1 5 9 2 9 2 3 5 7 4 8 6 1 8 1 5 2 9 6 4 7 3 1 3 4 7 5 2 6 8 9 6 9 7 3 1 8 2 5 4 5 8 2 4 6 9 1 3 7 4 7 9 6 2 8 3 1 8 3 6 8 1 4 7 9 2 5 2 5 1 9 8 3 7 4 6 Kimenet: This is a wrong table! 3.34. Amőba játék
3.34.1.
#include <stdio.h> #define FIRST_PLAYER 0 #define SECOND_PLAYER 1 #define TRUE 1 #define FALSE 0 #define SIGN1 'X' #define SIGN2 'O' #define SIZE 3 #define NUMTOWIN 3 typedef char TTable[SIZE][SIZE];
void InitTable(TTable T) { int i, j;
for (i = 0;
i < SIZE;
i++) for (j = 0;
j < SIZE;
j++) T[i][j] = ' ';
} void PrintTable(TTable T) { int i, j;
printf(" ");
for (i = 'A';
i < 'A' + SIZE;
i++) printf("%c ", i);
printf("\n");
printf(" -");
for (i = 0;
i < SIZE;
i++) printf("--");
printf("\n");
for (i = 0;
i < SIZE;
i++) { printf("%2d|", i + 1);
for (j = 0;
j < SIZE;
j++) printf("%c|", T[j][i]);
printf("\n ");
for (j = 0;
j < SIZE;
j++) printf("--");
printf("-\n");
} } int GetY(char y1, char y2) { return y2 > 0 ? (y1 - '0') * 10 + (y2 - '1') : y1 - '1' ;
} int Drawn(TTable T) { int i, j;
for (i = 0;
i < SIZE;
i++) for (j = 0;
j < SIZE;
j++) if (T[i][j] == ' ') return FALSE;
return TRUE;
} int Win(TTable T, char ch) { int i, j;
for (i = 0;
i < SIZE;
i++) { for (j = 0;
j < SIZE;
j++) { if (i <= SIZE - NUMTOWIN ) { if ((T[i][j] == ch) && (T[i+1][j] == ch) && (T[i+2][j] == ch)) return TRUE;
} if (j <= SIZE - NUMTOWIN ) { if ((T[i][j] == ch) && (T[i][j+1] == ch) && (T[i][j+2] == ch)) return TRUE;
} if ((i <= SIZE - NUMTOWIN ) && (j <= SIZE - NUMTOWIN )) { if ((T[i][j] == ch) && (T[i+1][j+1] == ch) && (T[i+2][j+2] == ch)) return TRUE;
} if ((i >= NUMTOWIN - 1 ) && (j <= SIZE - NUMTOWIN )) { if ((T[i][j] == ch) && (T[i-1][j+1] == ch) && (T[i-2][j+2] == ch)) return TRUE;
} } } return FALSE;
} int WrongCoord(TTable T, char x, char y1, char y2) { int y = GetY(y1, y2);
if ((x < 'A') || (x >= 'A' + SIZE ) || (y < 0) || (y >= SIZE)) { printf("Wrong coordinate!\n");
return TRUE;
} if (T[x - 'A'][y] != ' ') { printf("You already cannot choose this position!\n");
return TRUE;
} return FALSE;
} void Play(TTable T) { char target[5];
int player = FIRST_PLAYER;
do { if (player == FIRST_PLAYER) printf("First player\n");
else printf("Second player\n");
printf("Target: ");
do { scanf("%s", target);
} while ((target[0] != '0') && WrongCoord(T, target[0], target[1], target[2]));
if (target[0] != '0') { if (player == FIRST_PLAYER) { T[target[0] - 'A'][GetY(target[1], target[2])] = SIGN1;
if (Win(T, SIGN1)) { PrintTable(T);
printf("First player won!\n");
return;
} player = SECOND_PLAYER;
} else { T[target[0] - 'A'][GetY(target[1], target[2])] = SIGN2;
if (Win(T, SIGN2)) { PrintTable(T);
printf("Second player won!\n");
return;
} player = FIRST_PLAYER;
} PrintTable(T);
} } while ((target[0] != '0') && !Drawn(T));
printf("Game over!\n");
} int main() { TTable Table;
InitTable(Table);
} PrintTable(Table);
Play(Table);
return 0;

3.34.1. Írjon egy egyszerű amőba játékot, 3x3-as pályára! Két játékos játszhat a programmal, akik a saját jelüket helyezhetik a mezőkbe felváltva (X vagy O). Az a játékos nyeri a játszmát, akinek 3 jele lesz egy sorban, oszlopban vagy átlóban. Ha nincs több üres cella, vagy a játékosok valamelyike nyer, a játék véget ér. A programnak minden lépés után ki kell rajzolnia a játéktábla aktuális állását karakteresen! Feltételezzük, hogy mindkét játékos megfelelő pozíciót ad meg minden lépésben. Példa bemenet: A B C ------1| | | | ------2| | | | ------3| | | | ------First player Target: A1 A B C ------1|X| | | ------2| | | | ------3| | | | ------Second player Target: B1 A B C ------1|X|O| | ------2| | | | ------3| | | | ------- First player Target: A2 A B C ------1|X|O| | ------2|X| | | ------3| | | | ------Second player Target: A3 A B C ------1|X|O| | ------2|X| | | ------3|O| | | ------First player Target: B2 A B C ------1|X|O| | ------2|X|X| | ------3|O| | | ------- Second player Target: C1 A B C ------1|X|O|O| ------2|X|X| | ------3|O| | | ------First player Target: C3 A B C ------1|X|O|O| ------2|X|X| | ------3|O| |X| ------First player won! 3.35. Térkép
3.35.1. Egy fájl egy magassági térképet tartalmaz. A magasságok pozitív egész számok. Írjon programot, amely beolvassa ezt a térképet egy mátrixba, kiírja a képernyőre és kiszámítja az adott területen az alföld, dombság, hegység és magashegység arányát! A mátrix legyen dinamikus! A magassági intervallumok a következők: 0 <= magasság < 250 250 <= magasság < 500 500 <= magasság < 1500 1500 <= magasság alföld dombság hegység magashegység Az input fájl formátuma: Első sor: number1 number2 A number1 a sorok, number2 az oszlopok számát adja meg. Ezután number1 db sor következik, minden sorban number2 db, szóköz karakterrel elválasztott érték található. Példa bemenet: 5 5 200 210 220 218 230 0 1600 322 31 1000 332 320 43 1 545 2000 32 252 0 321 1320 2123 324 21 43 Kimenet: 200 210 220 218 230 0 1600 322 31 1000 332 320 1 545 2000 32 252 0 321 1320 2123 324 Lowland: 52 % Hill: 24 % Mountain: 12 % High mountain: 12 % 3.36. Inverz mátrix
3.35.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "map1.txt" #define HILL 250 #define MOUNTAIN 500 #define HIGHMOUNTAIN 1500 struct TMap { int r, c;
int ** m;
};
void ReadMap(FILE * fd, struct TMap * M) { int i, j;
fscanf(fd, "%d %d", &M->r, &M->c);
M->m = (int**)malloc(sizeof(int*) * M->r);
for (i = 0;
i < M->r;
i++) { M->m[i] = (int*)malloc(sizeof(int) * M->c);
for (j = 0;
j < M->c;
j++) fscanf(fd, "%d", &M->m[i][j]);
} } void FreeMap(struct TMap * M) { int i;
for (i = 0;
i < M->r;
i++) { free(M->m[i]);
M->m[i] = NULL;
} free(M->m);
M->m = NULL;
} void PrintMap(struct TMap * M) { int i, j;
printf("\nThe map:\n\n");
for (i = 0;
i < M->r;
i++) { for (j = 0;
j < M->c;
j++) printf("%4d ", M->m[i][j]);
printf("\n");
} } void Count(struct TMap * M) { int lowland = 0, hill = 0, mountain = 0, highmountain = 0;
int i, j, h;
double A = M->r * M->c;
for (i = 0;
i < M->r;
i++) { for (j = 0;
j < M->c;
j++) { h = M->m[i][j];
if (h < HILL) lowland++;
else if (h < MOUNTAIN) hill++;
else if (h < HIGHMOUNTAIN) mountain++;
else highmountain++;
} } printf("\nLowland: %g %%\n", lowland / A * 100.0);
printf("Hill: %g %%\n", hill / A * 100.0);
printf("Mountain: %g %%\n", mountain / A * 100.0);
printf("High mountain: %g %%\n\n", highmountain / A * 100.0);
} int main(int argc, char * argv[]) { struct TMap Map;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadMap(fd, &Map);
fclose(fd);
PrintMap(&Map);
Count(&Map);
FreeMap(&Map);
return 0;
} 
3.36.1.
#include <stdio.h>
#include <stdlib.h>
#include <memory.h> #define SIZE 3 typedef double Matrix[SIZE][SIZE];
void PrintMatrix(Matrix m) { int i, j;
printf("\n");
for (i = 0;
i < SIZE;
i++) { for (j = 0;
j < SIZE;
j++) printf("%2g ", m[i][j]);
printf("\n");
} printf("\n");
} double GetDeterminant(Matrix m) { return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] m[0][2] * m[1][1] * m[2][0] m[0][1] * m[1][0] * m[2][2] m[0][0] * m[1][2] * m[2][1];
} void MakeAdjMatrix(Matrix m) { int i, j, x1, y1, x2, y2;
Matrix m2;
for (i = 0;
i < SIZE;
i++) { for (j = 0;
j < SIZE;
j++) { x1 = j == 0;
0 y1 = i == 0;
x2 = (j != 2) + 1;
y2 = (i != 2) + 1;
m2[j][i] = (i + j) % 2 ? -1 : 1;
m2[j][i] *= (m[y1][x1] * m[y2][x2] - m[y1][x2] * m[y2][x1]);
} } memcpy(m, m2, sizeof(double) * SIZE * SIZE);
} void InvertMatrix(Matrix m) { int i, j;
double det;
det = GetDeterminant(m);
printf("Adjugate matrix: \n");
MakeAdjMatrix(m);
PrintMatrix(m);
} printf("Determinant of the matrix: %g\n", det);
if (det != 0.0) { for (i = 0;
i < SIZE;
i++) { for (j = 0;
j < SIZE;
j++) m[i][j] /= det;
} printf("Inverse matrix: \n");
PrintMatrix(m);
} else printf("We cannot invert this matrix!\n");
int main() { Matrix matrix= { {1, 2, 3}, {2, 4, 5}, {3, 5, 6} };
printf("Original matrix:\n");
PrintMatrix(matrix);
InvertMatrix(matrix);
return 0;
} 
3.36.1. Írjon programot, amely kiszámítja egy 3x3-as mátrix inverzét! A program írja ki a képernyőre a mátrix adjungáltját, determinánst és az inverz mátrixot. Az inverz mátrixot a következőképpen számíthatjuk ki: A-1 = adj(A) / det(A), ahol adj(A) az A mátrix adjungáltja, és det(A) az A mátrix determinánsa. Ha det(A) = 0, akkor A nem invertálható. = Ábra: Mátrix elemeinek az indexelése Determináns: A 2x2-es mátrix determinánsa a következő: a11*a22 - a21*a12 A 3x3-as mátrix determinánsa: a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 - a13 * a22 * a31 - a12 * a21 * a33 - a11 * a23 * a32 Adjungált: A A ⎛ A adj( ) = ⎜− ⎜ A A + ⎝ A + ahol A A A A A A A A A + A A − A − = det A A A A A A A A A − A A + A + A A A A A A ⎞ ⎟ ⎟ ⎠ ;
Példa bemenet: Original matrix: 1 2 3 2 4 5 3 5 6 Adjugate matrix: -1 3 -2 3 -3 1 -2 1 0 Determinant of the matrix: -1 Inverse matrix: 1 -3 2 -3 3 -1 2 -1 -0 3.37. Mátrixműveletek
3.37.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "matrices1.txt" struct TMatrix { int r,c;
int ** m;
};
void InitMatrix(struct TMatrix * M, int r, int c) { int i,j;
M->r = r;
M->c = c;
M->m = (int**)malloc(sizeof(int*) * r);
for (i = 0;
i < r;
i++) { M->m[i] = (int*)malloc(sizeof(int) * c);
for (j = 0;
j < c;
j++) M->m[i][j] = 0;
} } void FreeMatrix(struct TMatrix * M) { int i;
for (i = 0;
i < M->r;
i++) { free(M->m[i]);
M->m[i] = NULL;
} free(M->m);
M->m = NULL;
M->r = M-> c = 0;
} void PrintMatrix(struct TMatrix * M) { int i, j;
for (i = 0;
i < M->r;
i++) { for (j = 0;
j < M->c;
j++) printf("%3d ", M->m[i][j]);
printf("\n\n\n");
} } void ReadMatrix(FILE * fd, struct TMatrix * M) { } int i, j;
for (i = 0;
i < M->r;
i++) { for (j = 0;
j < M->c;
j++) fscanf(fd, "%d", &M->m[i][j]);
} void AddMulMatrix(struct TMatrix * A, struct TMatrix * B, struct TMatrix * C, int m) { int i, j;
for (i = 0;
i < A->r;
i++) { for (j = 0;
j < A->c;
j++) C->m[i][j] = (A->m[i][j] + B->m[i][j]) * m;
} } int main(int argc, char *argv[]) { struct TMatrix A, B, C;
int r, c;
FILE * fd = fopen( argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} fscanf(fd, "%d %d", &r, &c);
InitMatrix(&A, r, c);
InitMatrix(&B, r, c);
InitMatrix(&C, r, c);
ReadMatrix(fd, &A);
ReadMatrix(fd, &B);
fclose(fd);
printf("A : \n\n");
PrintMatrix(&A);
printf("B : \n\n");
PrintMatrix(&B);
AddMulMatrix(&A, &B, &C, 2);
printf("************************\n (A + B) * 2 = \n\n");
PrintMatrix(&C);
FreeMatrix(&A);
FreeMatrix(&B);
FreeMatrix(&C);
return 0;
} 
3.37.1. Írjon programot mátrixösszeadás és skalárral való szorzás megvalósítására! A program olvassa be fájlból két mátrixot! Adja össze a két mátrixot, és az eredményt szorozza meg 2-vel! A mátrixokat dinamikusan hozza létre! Ha A, B és C azonos méretű mátrixok, akkor Cij = Aij + Bij , ahol C az A és B mátrixok összege. Egy mátrix „d” skalárral való szorzásakor a mátrix minden elemét „d”-vel szorozzuk. Az input fájl formátuma: Első sor: Két szám, az első a sorok, a második az oszlopok száma. A többi sorban a két mátrix található, a példában látható módon. Minden sorban egy-egy mátrix-sor van, a számok szóköz karakterekkel vannak elválasztva. A mátrixok elemei egész számok. Példa bemenet: 2 3 4 3 4 3 1 5 2 4 1 1 7 3 Kimenet: A : 4 3 4 3 1 5 B : 2 4 1 1 7 3 ************************ (A + B) * 2 = 12 14 10 8 16 16 3.38. Morze kód
3.38.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define SZOKOZ "....." char * morsecodes[26] = { ".=", "=...", "=.=.", "=..", ".", "..=.", "==.", "....", "..", ".===", "=.=", ".=..", "==", "=.", "===", ".==.", "==.=", ".=.", "...", "=", "..=", "...=", ".==", "=..=", "=.==", "==.."};
void getline(char * s, int maxlen) { char ch;
int i = 0;
do { ch = getchar();
if (ch!='\n') s[i++] = ch;
} while ((i < maxlen - 1) && (ch!='\n'));
s[i] = 0;
} char * coding(char * s) { int len = 1;
int i;
char * c;
for (i = 0;
i < strlen(s);
i++) if (s[i] != ' ') len += strlen(morsecodes[ s[i] - 'A' ]);
else len += strlen(SZOKOZ);
c = (char*)malloc(sizeof(char) * len);
len = 0;
for (i = 0;
i < strlen(s);
i++) { if (s[i] != ' ') { morsecodes[ s[i] - 'A']);
strcpy(c + len, morsecodes[ s[i] - 'A' ]);
len += strlen(morsecodes[ s[i] - 'A' ]);
} else { strcpy(c + len, SZOKOZ);
len += strlen(SZOKOZ);
} } c[len] = 0;
return c;
} int main() { char message[100];
char * morse;
printf("The message: ");
getline(message, 100);
printf("Message: \"%s\" \n", message);
morse = coding(message);
printf("The coded message: \"%s\"\n", morse);
free(morse);
morse = NULL;
return 0;
} 
3.38.1. Írjon programot, ami egy üzenetet Morze kóddá alakít! Az üzenet begépelése után a program foglaljon le memóriát a kódolt üzenet számára, kódolja az üzenetet és jelenítse meg azt! Használja az alábbi sztring tömböt az egye karakterek leképezésére! A szóköz karakter kódja 5 pont. char* morsecodes[26] = { ".=", "=...", "=.=.", "=..", ".", "..=.", "==.", "....", "..", ".===", "=.=", ".=..", "==", "=.", "===", ".==.", "==.=", ".=.", "...", "=", "..=", "...=", ".==", "=..=", "=.==", "==.."};
Példa bemenet: Az üzenet: SOS I AM WRITING A TEST Üzenet: "SOS I AM WRITING A TEST" A kódolt üzenet: "...===................===......==.=...=..=.==.......=.....=....=" 3.39. Mátrix szorzása vektorral
3.39.1
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "input.txt" struct TMatrix { int r,c;
int ** m;
};
void InitMatrix(struct TMatrix * M, int r, int c) { int i,j;
M->r = r;
M->c = c;
M->m = (int**)malloc(sizeof(int*) * r);
for (i = 0;
i < r;
i++) { M->m[i] = (int*)malloc(sizeof(int) * c);
for (j = 0;
j < c;
j++) M->m[i][j] = 0;
} } void FreeMatrix(struct TMatrix * M) { int i;
for (i = 0;
i < M->r;
i++) { free(M->m[i]);
M->m[i] = NULL;
} free(M->m);
M->m = NULL;
M->r = M-> c = 0;
} void PrintMatrix(struct TMatrix * M) { int i, j;
for (i = 0;
i < M->r;
i++) { for (j = 0;
j < M->c;
j++) printf("%3d ", M->m[i][j]);
printf("\n\n\n");
} } void ReadMatrix(FILE * fd, struct TMatrix * M) { } int i, j;
for (i = 0;
i < M->r;
i++) { for (j = 0;
j < M->c;
j++) fscanf(fd, "%d", &M->m[i][j]);
} void AddMulMatrix(struct TMatrix * A, struct TMatrix * B, struct TMatrix * C, int m) { int i, j;
for (i = 0;
i < A->r;
i++) { for (j = 0;
j < A->c;
j++) C->m[i][j] = (A->m[i][j] + B->m[i][j]) * m;
} } void MulMatrixVector(struct TMatrix * M, struct TMatrix * V1, struct TMatrix * V2) { int i, j;
for (i = 0;
i < M->r;
i++) { V2->m[i][0] = 0;
for (j = 0;
j < M->c;
j++) V2->m[i][0] += M->m[i][j] * V1->m[j][0];
} } int main(int argc, char *argv[]) { struct TMatrix A, V1, V2;
int r, c;
FILE * fd = fopen( argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} fscanf(fd, "%d %d", &r, &c);
InitMatrix(&A, r, c);
InitMatrix(&V1, c, 1);
InitMatrix(&V2, r, 1);
ReadMatrix(fd, &A);
ReadMatrix(fd, &V1);
fclose(fd);
MulMatrixVector(&A, &V1, &V2);
printf("Matrix : \n\n");
PrintMatrix(&A);
printf("Vector : \n\n");
PrintMatrix(&V1);
printf("************************\n Matrix * Vector = \n\n");
PrintMatrix(&V2);
FreeMatrix(&A);
FreeMatrix(&V1);
FreeMatrix(&V2);
return 0;
} 
3.39.1. Írjon programot, amely megszoroz egy mátrixot egy vektorral! A mátrixot és a vektort fájlból olvassa be és tárolja őket dinamikus adatszerkezetekkel! Írja ki a képernyőre az eredeti mátrixot és vektort, majd a szorzatvektort! A szorzatvektor annyi értéket tartalmaz, amennyi a mátrix sorainak száma. Ha „P” a szorzatvektor, „A” a mátrix, és „V” az eredeti vektor, akkor Pi = Sum(j=1…c, Aij*Vj), ahol Aij a mátrix i-edik sorának j-edik oszlopában van, c a mátrix oszlopainak száma. Az input fájl formátuma: Első sor: num1 num2 num1: a mátrix sorainak száma num2: a mátrix oszlopainak száma, amely egyben az eredeti vektor elemeinek száma is A következő num1 db sor a mátrix sorait tartalmazza, mindegyik sorban num2 db érték található, szóköz karakterrel elválasztva. A mátrix után num2 db szám következik, az eredeti vektor elemei. Példa bemenet: 2 3 4 1 3 7 2 2 6 2 3 Kimenet: Matrix : 4 1 7 2 Vector : 6 3 2 2 3 ************************ Matrix * Vector = 3.40. Sztring tokenizáló
3.40.1.
#include <stdio.h>
#include <stdlib.h> #define MAXLEN 101 int Count(char * str) { int szokozs = 0;
int i;
for (i = 0;
str[i] != 0;
i++) szokozs += (str[i] == ' ');
return ++szokozs;
} char * GetToken(char * s, int * len) { int i = 0;
char * w;
*len = 0;
while ((s[ *len ] != 0) && (s[ *len ] != ' ')) (*len)++;
(*len)++;
w = (char*)malloc(sizeof(char) * (*len));
for (i = 0;
i < (*len) - 1;
i++) w[i] = s[i];
w[(*len) - 1] = 0;
return w;
} char ** Tokenizer(char * str, int * s) { int i;
int size = Count(str);
int len;
char ** t = (char **)malloc(size * sizeof(char*));
for (i = 0;
i < size;
i++) { t[i] = GetToken(str, &len);
str += len;
} *s = size;
return t;
} void Print(char ** t, int size) { int i;
for (i = 0;
i < size;
i++) printf("%d.: \"%s\"\n", i + 1, t[i]);
} void Free(char *** t, int size) { int i;
} char ** t2 = *t;
for (i = 0;
i < size;
i++) { free(t2[i]);
t2[i] = NULL;
} *t = NULL;
int main() { char str[MAXLEN];
char ** t = NULL;
int size;
if (gets(str) == NULL) { printf("Error!\n");
return 0;
} printf("The typed text: \"%s\"\n", str);
t = Tokenizer(str, &size);
Print(t, size);
Free(&t, size);
} return 0;

3.40.1. Írjon sztring tokenizáló programot! A felhasználó egy sztringet gépel be, amely több szóból állhat, a szavakat egy vagy több szóköz karakter választja el. Ezután a program számolja meg a sztringben lévő szavakat, foglaljon le dinamikus tömböket a szavak számára, és másolja be az egyes szavakat a lefoglalt karaktertömbökbe! Írja ki a program a képernyőre az eredeti sztringet, és az egyes szavakat! Példa bemenet: This is a simple example. The typed text: "This is a 1.: "This" 2.: "is" 3.: "a" 4.: "simple" 5.: "example." simple example." 3.41. Szavak kicserélése
3.41.1. Egy fájlban egy legfeljebb 1000 karakter hosszú sztring található. Írjon programot, amely beolvassa ezt a fájlt, majd bekér a felhasználótól két szót! A második szó nem lehet hosszabb az elsőnél. A program keresse meg az első szó minden előfordulását a szövegben, és cserélje ki a második szóra. Írja ki a képernyőre az új szöveget, és a találatok számát! Példa: The original text: "This is a very simple text that can help for you to understand the task. " Type a word: simple Type the new word: easy 1 hits The new text: "This is a very easy text that can help for you to understand the task. " 3.42. Ellenőrző összeg
3.41.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "text.txt" #define MAX_TEXT_LENGTH 1001 #define MAX_WORD_LENGTH 21 #define TRUE 1 #define FALSE 0 void Change(char * t, char * w1, char * w2) { int i = 0;
int j;
int lent = strlen(t);
int lenw = strlen(w1);
int lenw2 = strlen(w2);
char tmp;
int hits = 0;
for (i = 0;
i < lent - lenw;
i++) { if (strncmp(t + i, w1, lenw) == 0) { tmp = t[i + lenw2];
strcpy(t + i, w2);
t[i + lenw2] = tmp;
for (j = i + lenw2;
j < lent - (lenw - lenw2);
j++) t[j] = t[j + lenw - lenw2];
t[j] = 0;
lent = strlen(t);
hits++;
} } } printf("\n%d hits\n", hits);
int main(int argc, char * argv[]) { char text[MAX_TEXT_LENGTH];
char word1[MAX_WORD_LENGTH];
char word2[MAX_WORD_LENGTH];
FILE * fd = fopen(argc > 1? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} if (fgets(text, MAX_TEXT_LENGTH - 1, fd) == NULL) { perror("Error");
fclose(fd);
return 0;
} fclose(fd);
printf("\nThe original text: \"%s\"\n\n", text);
printf("Type a word: ");
scanf("%s", word1);
printf("Type the new word: ");
scanf("%s", word2);
Change(text, word1, word2);
printf("\nThe new text: \"%s\"\n\n", text);
return 0;
} 
3.4.1.
#include <stdio.h>
#include <conio.h> int main() { char string1[100], string2[100], string3[100];
int c, idxI;
printf("String input with getchar. Press enter, ctrl+z and enter to end input!\n");
idxI=0;
while((c=getchar()) != EOF) { string1[idxI]=c;
idxI++;
} string1[--idxI]=0;
printf("String input with gets: ");
gets(string2);
printf("String input with scanf: ");
scanf(„%s”, string3);
printf("\nstring1 with getchar = %s\n", string1);
printf("string2 with gets = %s\n", string2);
printf("string3 with scanf = %s\n", string3);
printf("Press any key to exit!");
c=getch();
return 0;
} 
3.4.1. Kérjen be egy-egy sztringet gets, getchar és scanf segítségével! Írja ki a sztringeket puts, putchar és printf segítségével! 

3.42.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "message.txt" #define TRUE 1 #define FALSE 0 #define MAXLEN 51 typedef unsigned char ubyte;
ubyte GetChecksum(char * msg) { unsigned short sum = 0;
int i;
for (i = 0;
msg[i] != 0;
i++) sum += (unsigned char)msg[i];
printf("\nSum of \"%s\": %X\n", msg, sum);
sum = (ubyte)sum;
sum = 0xFF - sum + 1;
printf("The checksum: %X\n", sum);
return sum;
} int Checking(char * msg, ubyte chksm) { int i;
unsigned short sum = chksm;
for (i = 0;
msg[i] != 0;
i++) sum += (unsigned char)msg[i];
sum = (ubyte)sum;
return (sum == 0);
} void ReadMessages(FILE * fd) { int count;
int i;
unsigned int chksum;
char msg[MAXLEN];
fscanf(fd, "%d\n", &count);
printf("\n");
for (i = 0;
i < count;
i++) { if (fgets(msg, MAXLEN, fd) == NULL) { printf("Error\n");
return;
} msg[strlen(msg) - 1] = 0;
fscanf(fd, "%X\n", &chksum);
printf("\"%s\" %X ===> ", msg, chksum);
if (Checking(msg, chksum)) printf("Correct!\n");
else printf("Faulty!\n");
} } int main(int argc, char * argv[]) { FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadMessages(fd);
fclose(fd);
GetChecksum("This is a simple checksum example.");
printf("\n");
return 0;
} 
3.42.1. Írjon programot, amely képes ellenőrző összeg generálására egy üzenethez, és ezen összeg alapján ellenőrizni tudja a bejövő üzeneteket! Az ellenőrző összeg kiszámítása a következőképpen történik: Adjuk össze az üzenet minden bájtját, ha az összeg nagyobb, mint 255, akkor az összegnek csak a legkisebb bájtját tekintjük. Az így kapott bájt kettes komplemense (255 - sum + 1) lesz az ellenőrző összeg. Például az „ABCD” üzenet bájtjai: 0x41, 0x42, 0x43 and 0x44, így az összeg = 0x41 + 0x42 + 0x43 + 0x44 = 0x10A. Ebből legkisebb bájt: 0xA, a kettes komplemens pedig: 0xFF - 0xA + 0x1 = 0xF6. Az ellenőrzés menete: Az üzenettel együtt az ellenőrző összeg is megérkezik egy fájlban. A programnak össze kell adnia a beérkezett üzenet minden bájtját és az ellenőrző összeget. Ha az eredmény utolsó bájtja 0, akkor a beérkezett üzenet valószínűleg nem sérült. Egy fájl több üzenetet tartalmaz, az ellenőrző összegükkel együtt. A program olvassa be ezeket, és ellenőrizze őket! Írja ki a képernyőre az üzeneteket, az ellenőrző összegeket, és azt, hogy az üzenetek hibásak vagy helyesek! Végül számolja ki a „This is a simple checksum example.” üzenet ellenőrző összegét! Az input fájl formátuma: Első sor: Az üzenetek száma A többi sor felváltva tartalmaz üzeneteket és ellenőrző összegeket. Az üzenetek soraiban több szó is szerepelhet. Az üzenet után következő sor az üzenet ellenőrző összegét tartalmazza hexadecimális formában. Példa bemenet: 2 This is the first row of the message. C2 This is the second row ov the message. 6E Kimenet: "This is the first row of the message." C2 ===> Correct! "This is the second row ov the message." 6E ===> Faulty! Sum of "This is a simple checksum example.": C6C The checksum: 94 3.43. Statisztika

3.5. Gyökök
3.43.1.-3.34.3.
#include <stdio.h>
#include <stdlib.h> #define AKTUALIS_EV 2010 int main(int argc, char** argv) { FILE * fd = fopen(argv[1], "r");
if (fd == NULL) { perror("Hiba");
return EXIT_FAILURE;
} int kiskoru = 0;
int felnott = 0;
int nyugdijas = 0;
int vh2 = 0;
int szokoevben = 0;
int eletkor;
while (!feof(fd)) { if (fscanf(fd, "%d", &eletkor)) { if (eletkor < 18) { kiskoru++;
} else { felnott++;
if (eletkor >= 62) { nyugdijas++;
} } int ev = AKTUALIS_EV - eletkor;
if (ev >= 1939 && ev <= 1945) { vh2++;
} printf("ev: %d\n", ev);
if ((ev % 400 == 0) || (ev % 4 == 0 && ev % 100 != 0)) { printf("szokoev\n");
szokoevben++;
} } } fclose(fd);
} printf("Kiskoruak: %d\n", kiskoru);
printf("Felnottek: %d\n", felnott);
printf("Nyugdijasok: %d\n", nyugdijas);
printf("Vilaghaboru alatt: %d\n", vh2);
printf("Szokoevben: %d\n", szokoevben);
return EXIT_SUCCESS;
3 3 5 2 3 
3.43.1. Egy 5000 fős település lakosainak adatait kell feldolgoznunk. Van egy fájlunk, amely a lakosok életkorát tartalmazza. Írjon programot, amely kiírja a képernyőre, hogy mennyi kiskorú, felnőtt, nyugdíjas él a teleülésen! Kiskorúnak számít az, aki még nem töltötte be a 18. életévét, egyébként a felnőttek közé soroljuk. A nyugdíjkorhatár 62 év. 
3.43.2. Bővítse ki az előző programot úgy, hogy a program kiírja, hogy hányan születtek a második világháború alatt (1939-1945). Az aktuális év 2010. 
3.43.3. Bővítse ki az előző programot úgy, hogy a program kiírja azt is, hogy hányan születtek szökőévben! Szökőévnek számítanak azok az évek, ahol az évszám osztható 4-el, de a 100-asra végződőek közül csak azok, amelyek oszthatóak 400-al. Ez alapján szökőév volt 1992, 1996, de 1900 nem, viszont 2000 igen. 3.44. Kerítés
3.44.1. Egy 400 méter kerületű telket szeretnénk körülvenni drótkerítéssel. Több köteg drótkerítésünk van, amelyek hosszát egyenként ismerjük. Írjon programot, amely 0 végjelig beolvassa az egyes kötegek hosszait, majd a végén kiírja, hogy összesen hány méternyi kerítésünk van és, ha kell-e még kerítést vennünk, akkor összesen mennyit! 3.45. Jegyek átlaga Aladár év végén szeretné kiszámolni, hogy mely tantárgyból hányasra áll. Minden tárgyból sok jegyet szerzett, ezért úgy véli, fárasztó munka lenne kézzel átlagokat számolni, ezért számítógépes segítséghez folyamodik.
3.44.1.
#include <stdio.h>
#include <stdlib.h> int main() { int koteg;
int osszeg = 0;
do { printf("Kerem a keriteskoteg hosszat: ");
scanf("%d", &koteg);
osszeg += koteg;
} while (koteg > 0);
printf("Osszesen van %d meter kerites\n", osszeg);
if (osszeg < 400) { printf("Meg kell %d meternyi kerites\n", 400 - osszeg);
} return EXIT_SUCCESS;
} 
3.45.1.
#include <stdio.h>
#include <stdlib.h> #define N 10 int main() { int i;
int osszeg = 0;
int jegy;
for (i = 0;
i < N;
i++) { printf("%d. jegy: ", i + 1);
scanf("%d", &jegy);
osszeg += jegy;
} printf("A jegyek szamtani atlaga: %g\n", (double)osszeg / N);
return EXIT_SUCCESS;
} 
3.45.1. Írjon programot Aladárnak, amely beolvas 10 jegyet, majd kiszámolja azok számtani átlagát! 
3.45.2-3.45.3.
#include <stdio.h>
#include <stdlib.h>
#include <math.h> #define N 10 typedef struct lista { struct lista * kovetkezo;
int jegy;
} lista;
int main() { lista * jegyek = NULL;
int i;
int osszeg = 0;
int jegy;
double atlag;
i = 1;
do { printf("%d. jegy: ", i++);
scanf("%d", &jegy);
osszeg += jegy;
if (jegy > 0) { lista * elem = (lista *) malloc(sizeof (lista));
elem->jegy = jegy;
if (jegyek == NULL) { elem->kovetkezo = NULL;
} else { elem->kovetkezo = jegyek;
} jegyek = elem;
} } while (jegy > 0);
atlag = (double) osszeg / (i - 2);
lista * temp = jegyek;
lista * prev;
double elteres = 0;
while (temp != NULL) { elteres += (atlag - temp->jegy) * (atlag - temp->jegy);
prev = temp;
temp = temp->kovetkezo;
free(prev);
} double szoras = sqrt(elteres / (i - 2));
printf("A jegyek szamtani atlaga: %g\n", atlag);
printf("A jegyek szorasa: %g\n", szoras);
return EXIT_SUCCESS;
} 
3.45.2. Bővítse ki az előző programot úgy, hogy 0 végjelig olvassa be a jegyeket és úgy végzi el a számolást! 
3.45.3. Fejlessze tovább a programot úgy, hogy a jegyek szórását is meghatározza! Határozza meg az egyes jegyek átlagtól való eltérésit, utána ezen eltérések négyezeteinek az átlagát, majd az így kapott eredmény gyökét! 3.46. Nyúltenyésztés
3.46.1.-3.46.2.
#include <stdio.h>
#include <stdlib.h> int main() { unsigned long long int termekeny = 0, termeketlen = 1;
unsigned long long int osszesen = termeketlen;
int honap;
int ev;
for (ev = 1;
ev <= 5;
ev++) { for (honap = 1;
honap <= 12;
honap++) { unsigned long long int nyulakUj = termekeny + termeketlen;
osszesen += nyulakUj;
termekeny = termeketlen;
termeketlen = nyulakUj;
printf("%d\n", nyulakUj);
} van\n", termekeny *= 0.1;
termeketlen *= 0.05;
printf("eladas utan %llu termekeny es %llu termeketlen nyulpar termekeny, termeketlen);
printf("Osszesen %llu adag tapra lesz szukseg\n", osszesen * 2);
} return EXIT_SUCCESS;
} 
3.46.1. Mr. Fibonacci elhatározta, hogy belevág a nyúltenyésztésbe. Az első hónapban vesz egy újszülött nyúlpárt. Minden nyúl 2 hónap után válik termékennyé. Minden hónapban minden termékeny nyúlpár egy új nyúlpárt szül. A nyulakat etetni kell, minden nyúl egy zsák nyúltápot fogyaszt el minden hónapban és egy nyúlpár se pusztul el. Írjon programot, amely meghatározza, hogy hány zsák nyúltápot kell vásárolni egy évre, ha az első hónapban 1 nyúlpár van! 
3.46.2. Bővítse ki az előző programot úgy, hogy 3 évre előre számoljon, figyelembe véve, hogy Mr. Fibonacci minden év elején eladja a termékeny nyulak 90 %-át, és a terméketlenek 95 %-át! Amennyiben az eladandó nyulak mennyisége nem egész szám, úgy ezt az értéket mindig lefele kerekítjük. Például 101 termékeny nyúl esetén 90-et adunk el. 3.47. Jegyek
3.47.1. Egy 30 fős osztályban minden tanulóról tudjuk, hogy informatikából mennyi a jegyeinek az átlaga. Írjon programot, amely billentyűzetről beolvassa a 30 átlagot, majd kiírja a képernyőre, hogy volt-e bukás idén! Az bukik meg, akinek az átlaga kevesebb, mint 1.5. 
3.47.1.
#include <stdio.h>
#include <stdlib.h> #define N 30 int main() { double jegyek[N];
int i;
for (i = 0;
i < N;
i++) { printf("A %d. atlag: ", i + 1);
scanf("%lf", &jegyek[i]);
} i = 0;
while (i < N && jegyek[i] >= 1.5) { i++;
} if (i < N) { printf("Volt bukas!\n");
} else { printf("Nem volt bukas!\n");
} return EXIT_SUCCESS;
} 
3.47.2.
#include <stdio.h>
#include <stdlib.h> int main() { double jegy;
int sorszam = 1;
do { printf("Kerem a %d. atlagot: ", sorszam++);
scanf("%lf", &jegy);
} while (jegy >= 1.5);
if (jegy == 0.0 || jegy >= 1.5) { printf("Nem volt bukas!\n");
} else { printf("Volt bukas!\n");
} return EXIT_SUCCESS;
} 
3.47.2. Módosítsa az előző programot úgy, hogy addig olvassa be az átlagokat, amíg bukott embert nem talál! Amennyiben 0-t olvasunk be, az azt jelenti, hogy vége a beolvasásnak, vagyis ez nem egy átlag. A program ez esetben is írja ki, hogy bukik-e valaki! 3.48. Marsjáró A Mars Explorer 3000-es marsjáró robot utazása során 100 méterenként feljegyzi, hogy a bolygón való leszállóhelyéhez viszonyítva milyen magasan / mélyen jár, így egy domborzati keresztmetszetet továbbít a földi irányító központba. Szeretnénk részletesen megvizsgálni a bejárt terepet. A vizsgálatra számítógépet használunk. A domborzati magasságokat egy tömbben tároljuk.
3.48.1.
#include <stdio.h>
#include <stdlib.h> #define N 100 int main() { double magassag[N];
int i;
for (i = 0;
i < N;
i++) { magassag[i] = (rand() % 1000) / 10.0;
} int minIndex = 0;
int maxIndex = 0;
for (i = 0;
i < N;
i++) { if (magassag[minIndex] > magassag[i]) { minIndex = i;
} if (magassag[maxIndex] < magassag[i]) { maxIndex = i;
} } printf("A legmagasabb pont: %g, helye: %d\n", magassag[maxIndex], maxIndex);
printf("A legalacsonyabb pont: %g, helye: %d\n", magassag[minIndex], minIndex);
return EXIT_SUCCESS;
} 
3.48.1. Írjon programot, amely a tömbben tárolt domborzati adatokból meghatározza, hogy mekkora volt a legmagasabb, illetve legalacsonyabb magasság, ahol a marsjáró járt, valamint hogy hol voltak ezek a pontok! 
3.48.2.-3.48.4.
#include <stdio.h>
#include <stdlib.h>
#include <math.h> #define N 100 double magassagLekerdez() { static int i = 0;
double res;
if (i >= 0 && i <= 3) res = 4;
else if (i >= 4 && i <= 10) res = 3;
else if (i >= 40 && i <= 60) res = 7;
else if (i >= 70 && i <= 100) res = 2;
else res = (rand() % 1000) / 10.0;
i++;
return res;
} typedef struct Siksag { int kezdet;
int veg;
int hossz;
} Siksag;
int main() { int i;
int minIndex = 0;
int maxIndex = 0;
int emelkedoIndex;
Siksag maxSiksag;
Siksag aktSiksag;
double minMagassag;
double maxMagassag;
double maxKulonbseg = 0;
double magassag;
double elozo;
maxSiksag.hossz = 1;
maxSiksag.veg = 0;
for (i = 0;
i < N;
i++) { magassag = magassagLekerdez();
if (i == 0) { minMagassag = magassag;
maxMagassag = magassag;
elozo = magassag;
} else { if (abs(elozo - magassag) > maxKulonbseg) { maxKulonbseg = abs(elozo - magassag);
emelkedoIndex = i;
} if (minMagassag > magassag) { minIndex = i;
minMagassag = magassag;
} if (maxMagassag < magassag) { maxIndex = i;
maxMagassag = magassag;
} if (elozo == magassag) { if (aktSiksag.hossz == 0) { aktSiksag.hossz = 2;
aktSiksag.kezdet = i - 1;
aktSiksag.veg = i;
} else { aktSiksag.veg = i;
aktSiksag.hossz++;
} } else { if (aktSiksag.veg == i - 1) { if (maxSiksag.hossz < aktSiksag.hossz) { maxSiksag = aktSiksag;
} aktSiksag.hossz = 0;
} } } elozo = magassag;
} if (maxSiksag.hossz < aktSiksag.hossz && aktSiksag.hossz > 1) { maxSiksag = aktSiksag;
} double maxFok = atan(maxKulonbseg / 100.0) / (M_PI / 180.0);
printf("A legmagasabb pont: %g, helye: %d\n", maxMagassag, maxIndex);
printf("A legalacsonyabb pont: %g, helye: %d\n", minMagassag, minIndex);
printf("A legmeredekebb emelkedo: %g fok, helye: %d\n", maxFok, emelkedoIndex);
printf("A leghosszabb siksag adatai:\n\tkezdete: %d\n\tvege: %d\n\thossza: %d\n", maxSiksag.kezdet, maxSiksag.veg, maxSiksag.hossz);
return EXIT_SUCCESS;
} 
3.48.2. Közeledik a marsbeli tél, ezért a marsjáró földi vezetői attól félnek, hogy azelőtt leáll, mielőtt elküldené a legújabb összegyűjtött méréseket. Ezért beállítják, hogy minden egyes mérés után küldje el a Földre az aktuális magasságát. Írjon programot, amibe a kezelő személy begépeli az aktuális kapott magasság értéket és minden új adat után kiszámolja, hogy eddig mekkora volt a legmagasabb és legalacsonyabb pont és hol voltak azok! 
3.48.3. Bővítse ki az előző programot úgy, hogy azt is nyilván tartsa a legmeredekebb lejtő és emelkedő meredekségét, valamint pozícióját! Megjegyzés: két mérési adat közötti különbség egy derékszögű háromszög egyik befogóját határozza meg, a másik befogó 100 méter. 
3.48.4. Bővítse ki az előző programot úgy, hogy a leghosszabb sík terület hosszát, valamint kezdő és vég pontjának pozícióját keresse meg! Sík területnek számít az, ahol a terep pontjai összefüggően azonos magasságúak. 3.49. Ritka vektor
3.49.1-3.49.3.
#include <stdio.h>
#include <stdlib.h> typedef struct Elem { double value;
int index;
struct Elem * next;
} Elem;
typedef struct Vector { Elem * fej;
} Vector;
void initVector(Vector * vector) { vector->fej = NULL;
} double lekerdezVector(Vector vector, int index) { Elem * tmp = vector.fej;
while (tmp && tmp->index < index) tmp = tmp->next;
if (tmp && tmp->index == index) return tmp->value;
return 0.0;
} int torolVector(Vector * vector, int pos) { Elem * prv = 0, * tmp = vector->fej;
while (tmp && tmp->index < pos) { prv = tmp;
tmp = tmp->next;
} if (tmp && tmp->index == pos) { if (prv) prv->next = tmp->next;
else vector->fej = tmp->next;
free(tmp);
return 1;
} return 0;
} void tisztitVector(Vector * vector) { Elem * tmp = vector->fej, * prv = 0;
while (tmp) { if (tmp->value == 0) { Elem * tmp2 = tmp->next;
torolVector(vector, tmp->index);
tmp = tmp2;
} else { prv = tmp;
tmp = tmp->next;
} } } void felszabaditVector(Vector * vector) { Elem * tmp1 = vector->fej;
Elem * tmp2;
while (tmp1) { tmp2 = tmp1->next;
free(tmp1);
tmp1 = tmp2;
} vector->fej = 0;
} void mutatVector(Vector vector) { int i, dim;
if ((dim = legutolsoVector(vector)) == 0) { printf("ures\n");
return;
} for (i = 0;
i <= dim;
i++) { printf("%lg", lekerdezVector(vector, i));
if (i < dim) printf(",");
} printf("\n");
} void beallitVector(Vector * vector, double value, int pos) { if (value == 0.0) return;
if (!vector->fej) { vector->fej = (Elem*) malloc(sizeof (Elem));
vector->fej->value = value;
vector->fej->index = pos;
vector->fej->next = 0;
} else { Elem * prv = NULL, * tmp = vector->fej;
while (tmp && (tmp->index < pos)) { prv = tmp;
tmp = tmp->next;
} if (tmp && tmp->index == pos) { tmp->value = value;
return;
} Elem * nm = (Elem*) malloc(sizeof (Elem));
nm->value = value;
nm->index = pos;
} } if (!tmp) { prv->next = nm;
prv->next->next = 0;
} else { if (prv) { prv->next = nm;
prv->next->next = tmp;
} else { prv = nm;
prv->next = tmp;
vector->fej = prv;
} } void rendezVector(Vector vector) { if (!vector.fej) return;
Elem * tmp1, * tmp2, * min;
double temp;
tmp1 = vector.fej;
while (tmp1->next) { min = tmp2 = tmp1;
while (tmp2) { if (tmp2->value < min->value) min = tmp2;
tmp2 = tmp2->next;
} temp = min->value;
min->value = tmp1->value;
tmp1->value = temp;
tmp1 = tmp1->next;
} } double szorozVector(Vector v1, Vector v2) { if (!v1.fej || !v2.fej) return 0.0;
double res = 0;
Elem * tmp1 = v1.fej;
while (tmp1) { Elem * tmp2 = v2.fej;
while (tmp2 && tmp2->index < tmp1->index) tmp2 = tmp2->next;
if (tmp2 && tmp2->index == tmp1->index) res += tmp1->value * tmp2->value;
tmp1 = tmp1->next;
} return res;
} void addVector(Vector * v1, Vector v2) { Elem * tmp1 = v1->fej, * tmp2;
while (tmp1) { tmp2 = v2.fej;
while (tmp2 && tmp2->index < tmp1->index) tmp2 = tmp2->next;
if (tmp2 && tmp2->index == tmp1->index) tmp1->value += tmp2->value;
tmp1 = tmp1->next;
} } tmp1 = v2.fej;
while (tmp1) { tmp2 = v1->fej;
while (tmp2 && tmp2->index < tmp1->index) tmp2 = tmp2->next;
if (!tmp2 || tmp2->index > tmp1->index) beallitVector(v1, tmp1->value, tmp1->index);
tmp1 = tmp1->next;
} tisztitVector(v1);
int meretVector(Vector vector) { Elem * tmp = vector.fej;
int count = 0;
while (tmp) { count++;
tmp = tmp->next;
} return count;
} int legutolsoVector(Vector vector) { Elem * tmp = vector.fej;
int dim = 0;
while (tmp) { dim = tmp->index;
tmp = tmp->next;
} return dim;
} int menuMutat() { int menu;
printf("Beallit: 1\n");
printf("Ertek: 2\n");
printf("Mindet torol: 3\n");
printf("Nem nullak szama: 4\n");
printf("Legutolso: 5\n");
printf("Megjelenit: 6\n");
printf("Rendez: 7\n");
printf("Hozzaad: 8\n");
printf("Szoroz: 9\n");
printf("Kilepes: 10\n");
scanf("%d", &menu);
return menu;
} int main() { Vector vector;
initVector(&vector);
Vector v2;
initVector(&v2);
beallitVector(&v2, 5, 2);
beallitVector(&v2, 1, 6);
beallitVector(&v2, 7, 10);
int menu;
do { menu = menuMutat();
if (menu == 1) { int index;
double ertek;
printf("Hanyadik elem? ");
scanf("%d", &index);
printf("Ertek? ");
scanf("%lg", &ertek);
beallitVector(&vector, ertek, index);
} if (menu == 2) { int index;
printf("Hanyadik elem? ");
scanf("%d", &index);
printf("A(z) %d. elem: %g\n\n", index, lekerdezVector(vector, index));
} if (menu == 3) { felszabaditVector(&vector);
} if (menu == 4) { printf("Nem nullak szama: %d\n\n", meretVector(vector));
} if (menu == 5) { printf("Legnagyobb nem nulla index: %d\n\n", legutolsoVector(vector));
} if (menu == 6) { mutatVector(vector);
} if (menu == 7) { rendezVector(vector);
} if (menu == 8) { addVector(&vector, v2);
} if (menu == 9) { printf("A skalaris szorzat: %lg\n", szorozVector(vector, v2));
} } while (menu != 10);
} felszabaditVector(&vector);
felszabaditVector(&v2);
return EXIT_SUCCESS;

3.49.1. Nemo kapitány alámerül a Nautilus tengeralattjáróval, hogy megvizsgálja a tenger élővilágát. Merülés közben a segédei minden tízedik méternél megszámolják, hogy mennyi halat látnak, hogy ezt felhasználhassák későbbi kutatásaikhoz. A számlálások eredményét egy vektorban tárolják el, ahol az i. komponens a 10*i méter mélyen végzett számlálás eredményét tárolja. Sajnos még nem áll rendelkezésre nagy memória kapacitású számítógép, az eredményeket lyukkártyára írják. Megfigyelték, hogy nagyon gyakran nem látnak egy halat sem, ezért úgy gondolták, oly módon tárolják az eredményeket, hogy ezt a tényt kihasználják és a ritka vektorok tárolási módszeréhez folyamodtak, így helyet takarítottak meg, és az adatok feldolgozása is gyorsabb. Írjon programot, amely egy ilyen ritka vektorokat kezel! A ritka vektorok olyan vektorok, amelyek nagyon kevés nem 0 komponenst tartalmaznak. Ezeket célszerű úgy tárolni, hogy csak a nem 0 elemeket tároljuk, azon vektoron belüli indexével. Ennek egyik módja, ha a (szám, index) párokat láncolt listában tároljuk. A vektor dimenziója nincs korlátozva. Valósítsa meg a következő műveleteket: · Beállít(index, érték): A vektor adott indexű elemét az adott értékre állítja be. Ha az érték 0, akkor az elem nem tárolódik. · Érték(index): A művelet visszaadja az adott indexű elem értékét. · Töröl: A művelet nulláza a teljes vektor tartalmát. · NemNullák: A művelet visszaadja, hogy mennyi nem 0 elem van a vektorban. · Legutolsó: A művelet visszaadja, hogy hányas indexen található a legutolsó nem 0 elem. · Megjelenít: A művelet kiírja a képernyőre a teljes vektort egészen a „Legutolsó” által meghatározott elemig. A 0-kat is meg kell jeleníteni. 
3.49.2. Előfordulhat, hogy az előző vektoron belül az elemek nem jó sorrendben követik egymást. Például lehet, hogy előbb található meg az 5-ös indexű elem a listában, mint a 3-as. Implementálja a „Rendez” műveletet, amely az indexeknek megfelelően növekvő sorrendbe rendezi a listán belüli elemeket! 
3.49.3. Bővítse ki az előző programot az összeadás és a szorzás műveletekkel! Az összeadás két ritka vektort ad össze. Ügyeljen arra, hogy a 0 elemeket ne tárolja el! A szorzás 2 ritka vektort szoroz össze skalárisan. 4. Láncolt listák feladatai 4.1. Lista két tömbbel
3.5.1
#include <stdio.h>
#include <math.h> int main() { float tomb[5];
int idxI;
} for (idxI=0;
idxI<5;
idxI++) { tomb[idxI]=sqrt(idxI);
} for (idxI=0;
idxI<5;
idxI++) { printf("%f, ", tomb[idxI]);
} return 0;

3.5.1. Írjon programot, amelyben egy 5 hosszú statikus float tömb minden elemébe a hozzátartozó index gyökét írja be! Használjon for ciklust az egyes elemek eléréséhez és az eredmény kiírásához! Az egyes értékek vesszővel legyenek elválasztva! 
3.5.2.
#include <stdio.h>
#include <math.h> int main() { float * tomb;
int idxI, size;
printf("Size of array? ");
scanf("%d", &size);
tomb = (float*) malloc(size*sizeof(float));
for (idxI = 0;
idxI < size;
idxI++) tomb[idxI] = sqrt(idxI);
for (idxI = 0;
idxI < size;
idxI++) { printf("%f", tomb[idxI]);
if(idxI+1 != size) printf(",");
else printf("\n");
} free(tomb);
return 0;
} 
3.5.2. Oldja meg, hogy az utolsó szám után ne jelenjen meg vessző a kiírásnál és hogy a tömb nagyságát szabadon lehessen meghatározni! 3.6. Tömb reprezentálása
3.6.1. A karakteres képernyőn reprezentáljon egy 4 hosszú egész tömböt! Kérje be a tömb elemeit és írja ki az értékeket '*' szimbólumokból készített négyzetekbe! Adja meg az egyes elemek indexeit és címeit! Írja ki a tömb mint mutató értékét és annak a címét! 3.2. ábra: Lehetséges képernyőkép
3.6.1.
#include <stdio.h>
#include <math.h> int main() { const int size=4;
int tomb[size];
int idxI, idxJ;
for (idxI=0;
idxI<size;
idxI++) { printf("The %d. value: ", idxI);
scanf("%d", &tomb[idxI]);
} printf("\n%20.20s", " ");
for (idxI=0;
idxI<size;
idxI++) { for (idxJ=0;
idxJ<12;
idxJ++) { printf("*");
} printf("");
} } printf("\n%20.20s", " ");
for (idxI=0;
idxI<size;
idxI++) { printf("*%10d* ", tomb[idxI]);
} printf("\n%20.20s", " ");
for (idxI=0;
idxI<size;
idxI++) { for (idxJ=0;
idxJ<12;
idxJ++) { printf("*");
} printf("");
} printf("\n%20.20s", "index: ");
for (idxI=0;
idxI<size;
idxI++) { printf("%-13d", idxI);
} printf("\n%20.20s", "address: ");
for (idxI=0;
idxI<size;
idxI++) { printf("%-#13p", &tomb[idxI]);
} printf("\n%20.20s%#p", "tomb: ", tomb);
printf("\n%20.20s%#p", „&tomb: ", &tomb);
printf("\n%20.20s%d", "tomb size: ", size);
return 0;


3.7. Magasság mérés
3.7.1. Feladat: Írjon programot, amelyben egy 10*10-es statikus, inicializált, float értékeket tartalmazó mátrix tengerszint feletti magasság adatokat reprezentál! Adja meg a szárazföld és a tenger arányát, ha a negatív magasság tengerfeneket reprezentál! Adja meg a legmagasabb pontot és adja meg a legmagasabb pontot a tengerben feltételes maximum keresés segítségével! Azt az esetet is kezelni kell, amikor nincs tenger! Számolja ki a terület átlagos magasságát! 
3.7.1.
#include <stdio.h>
#include <float.h> int main() { const int xSize=10, ySize=10;
float matrix[xSize][ySize]={ {4, 5, 6, 4, 2, 3, 4, 2, 4, 2}, {2, 2, 6, 5, 8, 7, 5, 3, 4, 2}, {4, 3, 6, 2, 6, 3, 4, 6, 7, 2}, {7, 2, 6, -2, -3, -3, -4, 6, 1, 2}, {4, 1, 6, -7, -2, -3, -2, -8, 4, 2}, {8, 1, 6, -7, -4, -3, -7, -6, -4, -2}, {4, 3, 6, 7, 3, -3, -4, -8, -2, -2}, {9, 2, 6, 6, 2, 2, -4, -8, -4, 2}, {4, 3, 6, 8, 3, 2, 4, -6, 4, 2}, {3, 3, 6, 7, 1, 3, 5, 6, 4, 2}};
int water, land, biggestIndexX, biggestIndexY, biggestWaterIndexX, biggestWaterIndexY, idxI, idxJ;
float mostShallowWater, sum, avg;
water=0;
land=0;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { if (matrix[idxI][idxJ]>0) land++;
else water++;
} } printf("The ration to land to water is = %d:%d\n", land, water);
{ biggestIndexX=0;
biggestIndexY=0;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { if (matrix[idxI][idxJ] > matrix[biggestIndexX][biggestIndexY]) } } biggestIndexX=idxI;
biggestIndexY=idxJ;
} printf("The heighest point is at row: %d, column: %d and its height is: %f\n", biggestIndexX, biggestIndexY, matrix[biggestIndexX][biggestIndexY]);
biggestWaterIndexX=-1;
biggestWaterIndexY=-1;
mostShallowWater=-FLT_MAX;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { if (matrix[idxI][idxJ] < 0 && matrix[idxI][idxJ] > mostShallowWater) { biggestWaterIndexX=idxI;
biggestWaterIndexY=idxJ;
mostShallowWater=matrix[biggestWaterIndexX][biggestWaterIndexY];
} } } if (biggestWaterIndexX == -1) { printf("There is no water so the search is meaningless.\n");
} else { printf("The most shallow water is at row: %d, column: %d and its depth is: %f\n", biggestWaterIndexX, biggestWaterIndexY, mostShallowWater);
} sum=0;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { sum+=matrix[idxI][idxJ];
} } avg=sum /(xSize*ySize);
printf("The average height is: %f\n", avg);
} return 0;

3.7.2. Határozza meg a legnagyobb szintkülönbséget a teljes területen, csak a szárazföldön, csak a tengerben! 3.8. Kockadobás
3.7.2.
#include <stdio.h>
#include <float.h> int main() { const int xSize = 10, ySize = 10;
float matrix[10][10] = { {4, 5, 6, 4, 2, 3, 4, 2, 4, 2}, {2, 2, 6, 5, 8, 7, 5, 3, 4, 2}, {4, 3, 6, 2, 6, 3, 4, 6, 7, 2}, {7, 2, 6, -2, -3, -3, -4, 6, 1, 2}, {4, 1, 6, -7, -2, -3, -2, -8, 4, 2}, {8, 1, 6, -7, -4, -3, -7, -6, -4, -2}, {4, 3, 6, 7, 3, -3, -4, -8, -2, -2}, {9, 2, 6, 6, 2, 2, -4, -8, -4, 2}, {4, 3, 6, 8, 3, 2, 4, -6, 4, 2}, {3, 3, 6, 7, 1, 3, 5, 6, 4, 2} };
int biggestWaterIndexX, biggestWaterIndexY, lowestWaterIndexX, lowestWaterIndexY;
int biggestLandIndexX, biggestLandIndexY, lowestLandIndexX, lowestLandIndexY;
int idxI, idxJ;
float highestLand=-1, lowestLand=-1, deepestWater = 1, shallowestWater = 1;
for (idxI=0;
idxI<xSize && highestLand == -1;
idxI++) { for (idxJ=0;
idxJ<ySize && highestLand == -1;
idxJ++) { if (matrix[idxI][idxJ]>0) highestLand = lowestLand = matrix[idxI][idxJ];
} } for (idxI=0;
idxI<xSize && deepestWater == 1;
idxI++) { for (idxJ=0;
idxJ<ySize && deepestWater == 1;
idxJ++) { if (matrix[idxI][idxJ]<=0) deepestWater = shallowestWater = matrix[idxI][idxJ];
} } for (idxI = 0;
idxI < xSize;
idxI++) { for (idxJ = 0;
idxJ < ySize;
idxJ++) { if (matrix[idxI][idxJ] > 0) { if (matrix[idxI][idxJ] > highestLand) highestLand = matrix[idxI][idxJ];
else if (matrix[idxI][idxJ] < lowestLand) lowestLand = matrix[idxI][idxJ];
} else { if (matrix[idxI][idxJ] < deepestWater) deepestWater = matrix[idxI][idxJ];
else if (matrix[idxI][idxJ] > shallowestWater) shallowestWater = matrix[idxI][idxJ];
} } } if(highestLand != -1) printf("The level difference on land is %f\n", highestLand lowestLand);
if (deepestWater != 1) printf("The level difference in water is %f\n", shallowestWater deepestWater);
if (highestLand != -1 && deepestWater != 1) printf("The biggest global level difference is %f\n", highestLand - deepestWater);
else printf("There's no global level difference!\n");
return 0;
} 
3.8.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { int repeatRequired, repeatAct, num, trial, idxI;
int frequency[6]={0};
printf("How much consecutive 6 do you want: ");
scanf("%d", &repeatRequired);
srand((unsigned)time(NULL));
repeatAct=0;
trial=0;
while (repeatAct!=repeatRequired) { num = (rand()%6)+1;
frequency[num-1]++;
if (num==6) repeatAct++;
else repeatAct=0;
trial++;
} printf("It needed %d random number to generate %d consecutive 6.\n\n", trial, repeatRequired);
printf("Meanwhile we generated\n");
for (idxI=0;
idxI<6;
idxI++) printf("%d pieces of %d\n", frequency[idxI], idxI+1);
return 0;
} 
3.8.1. Írjon programot, amely kockadobást szimulál véletlen számok generálásával! Kérjen be egy sorozat hosszt, x-t, és addig generáljon véletlen számokat, amíg nem jelenik meg egymás után x darab hatos! Hány dobás után kaptuk meg a kívánt eredményt? Számolja az egyes dobások gyakoriságát! 
3.8.2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { int repeatRequired, repeatAct, num, trial, idxI;
int frequency[6] = {0}, sequence[30];
long int sum = 0;
printf("How much consecutive 6 do you want: ");
scanf("%d", &repeatRequired);
srand((unsigned)time(NULL));
os for (idxI = 0;
idxI < 30;
++idxI) { repeatAct = 0;
trial = 0;
while (repeatAct!=repeatRequired) { num = (rand()%6) + 1;
if (num == 6) else repeatAct=0;
trial++;
} sequence[idxI] = trial;
ismetlesnel } for (idxI = 0;
idxI < 30;
++idxI) { sum += sequence[idxI];
} printf("It's needed on average %d random number to generate %d consecutive 6.\n\n", sum/30, repeatRequired);
return 0;
} 
3.8.2. Módosítsa úgy az előző programot, hogy egy x értékre 30-szor fusson le a program! Átlagosan hány dobás szükséges x darab egymást követő hatoshoz? 3.9. Csúsztatás
3.9.1.
#include <stdio.h> void print(float a, float b, float c) { printf("a=%f b=%f c=%f\n", a, b, c);
} void shift(float* a, float* b, float* c, int cyclic) { float temp;
} temp = *c;
*c = *b;
*b = *a;
if (cyclic) *a = temp;
else *a = 0;
int main() { float x1, x2, x3;
} printf("Provide the next number: ");
scanf("%f", &x1);
printf("Provide the next number: ");
scanf("%f", &x2);
printf("Provide the next number: ");
scanf("%f", &x3);
printf("Original: ");
print(x1, x2, x3);
shift(&x1, &x2, &x3, 1);
printf("After cyclic shift: ");
print(x1, x2, x3);
shift(&x1, &x2, &x3, 0);
printf("After non-cyclic shift: ");
print(x1, x2, x3);
return 0;

3.9.1. Írjon függvényt, amely 3 cím szerint átadott float paraméter értékét (a, b és c) elcsúsztatja a következő módon: ciklikus eltolás: a → b, b → c, c → a, nem ciklikus eltolás: a → b, b → c, 0 → a! Egy negyedik paraméter jelezze, hogy az eltolás ciklikus-e! 
3.9.2. 3 változó helyett egy 3 elemű tömbön végezze el az elcsúsztatást! 
3.9.2.
#include <stdio.h> void print(float a[], int size) { int i;
for(i = 0;
i < size;
++i) printf("a[%d]= %f ", i, a[i]);
printf("\n");
} void shift(float* a, int cyclic) { float temp;
} temp = a[2];
a[2] = a[1];
a[1] = a[0];
if (cyclic) a[0] = temp;
else a[0] = 0;
int main() { float x[3];
} printf("Provide the next number: ");
scanf("%f", &x[0]);
printf("Provide the next number: ");
scanf("%f", &x[1]);
printf("Provide the next number: ");
scanf("%f", &x[2]);
printf("Original: ");
print(x, 3);
shift(x, 1);
printf("After cyclic shift: ");
print(x, 3);
shift(x, 0);
printf("After non-cyclic shift: ");
print(x, 3);
return 0;

3.9.3. Egy plusz változó jelezze, hogy melyik irányba történik a csúsztatás! A tömb mérete legyen megadható! 3.10. Műveletek tömbökön
3.9.3.
#include <stdio.h>
#include <malloc.h> void print(float a[], int size) { int idxI;
for(idxI = 0;
idxI < size;
++idxI) printf("myArray[%d]= %f ", idxI, a[idxI]);
printf("\n");
} void shift(float* a, char direction, int cyclic, int size) { float temp = (direction=='r')?a[size-1]:a[0];
int idxI;
if(direction == 'r') { for(idxI = size-1;
idxI > 0;
--idxI) { a[idxI] = a[idxI-1];
} if (cyclic) a[0] = temp;
else a[0] = 0;
} else { for(idxI = 0;
idxI < size;
++idxI) { a[idxI] = a[idxI+1];
} } if (cyclic) a[size-1] = temp;
else a[size-1] = 0;
} int main() { float *myArray;
int size, idxI;
char direction;
printf("Array size? ");
scanf("%d", &size);
myArray = (float*) malloc(sizeof(float)*size);
for(idxI = 0;
idxI < size;
++idxI) { printf("Provide the next number: ");
scanf("%f", &myArray[idxI]);
} _flushall();
printf(„Original array: „);
print(myArray, size);
printf("In which direction do you want to shift? (l/r) ");
scanf("%c", &direction);
_flushall();
printf("After cyclic shift: ");
shift(myArray, direction, 1, size);
print(myArray, size);
} printf("After non-cyclic shift: ");
shift(myArray, direction, 0, size);
print(myArray, size);
return 0;
