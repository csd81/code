This C++ code demonstrates **basic object-oriented programming concepts** including **class definition, inheritance, encapsulation, and polymorphism**. It involves two classes: `Szemely` (Person) and `Hallgato` (Student), where `Hallgato` inherits from `Szemely`.

---

### ✅ `Szemely.h` Header File Explanation

```cpp
#ifndef SZEMELY_H
#define SZEMELY_H
```
These are **include guards**. They prevent the header file from being included more than once during compilation.

```cpp
#include <string>
using namespace std;
```
Includes the string class and brings everything from the `std` namespace into the global scope.

```cpp
class Szemely
{
    string vnev, knev;
    unsigned int eletkor;
public:
    Szemely(const string &v, const string &k, unsigned int kor);
    const string &getVezetekNev() const;
    const string &getKeresztNev() const;
    string teljesNev() const;
    unsigned int getEletkor() const;
    void kiir() const;
    bool fiatalabb(const Szemely &masik) const;
};
```
This defines a class `Szemely` with:

- **private member variables**:
  - `vnev` = last name
  - `knev` = first name
  - `eletkor` = age
- **public methods**:
  - Constructor
  - Getters for names and age
  - `teljesNev()` returns full name
  - `kiir()` prints the person’s info
  - `fiatalabb()` compares age with another `Szemely`

---

### ✅ `szemely.cpp` Implementation

```cpp
Szemely::Szemely(...) : vnev(v), knev(k), eletkor(kor) {}
```
**Constructor** with member initializer list.

```cpp
string Szemely::teljesNev() const
{
    return vnev + " " + knev;
}
```
Returns a **temporary string** containing the full name.

```cpp
void Szemely::kiir() const
{
    cout << vnev << " " << knev << ": " << eletkor << endl;
}
```
Prints the full data of the person.

```cpp
bool Szemely::fiatalabb(const Szemely &masik) const
{
    return this->eletkor < masik.eletkor;
}
```
Compares if the person is **younger** than another.

---

### ✅ `Hallgato.h` Header File

```cpp
#ifndef HALLGATO_H
#define HALLGATO_H

#include "szemely.h"
```
Includes `Szemely` because `Hallgato` inherits from it.

```cpp
class Hallgato : public Szemely
{
    string neptunKod;
    unsigned felevekSzama;
public:
    Hallgato(...);     // constructor
    void kiir() const; // overrides kiir
    bool furcsa() const;
};
```
Adds new data:
- `neptunKod` = unique student code
- `felevekSzama` = number of completed semesters

Also:
- Custom `kiir()` printing student data
- `furcsa()` checks if the student is "strange" (younger than expected)

---

### ✅ `hallgato.cpp` Implementation

```cpp
Hallgato::Hallgato(...) : Szemely(...), neptunKod(...), felevekSzama(...) {}
```
Constructor uses base class initializer + its own fields.

```cpp
void Hallgato::kiir() const
{
    Szemely::kiir();
    cout << neptunKod << " " << felevekSzama << endl;
}
```
Calls base class `kiir()`, then prints student info.

```cpp
bool Hallgato::furcsa() const
{
    return getEletkor() < 18 + 2 * felevekSzama;
}
```
Returns true if the student’s age is less than expected: age < 18 + (2 × semesters)

---

### ✅ `main.cpp` Usage

```cpp
Szemely sz1("Kiss", "Jozsef", 32);
Szemely sz2("Nagy", "Maria", 20);
sz1.kiir();
sz2.kiir();
```
Creates and prints two people.

```cpp
Hallgato h1("Teszt", "Anna", 21, "ABCDEF");
Hallgato h2("Hegeszt", "Elek", 19, "XYZXYZ", 5);
h1.kiir();
h2.kiir();
```
Creates two students and prints them.

```cpp
cout << h1.furcsa() << endl;
```
Tests the custom logic for whether the student is "strange".

```cpp
sz1.fiatalabb(sz2) ...
```
Compares age between people and students.

```cpp
Szemely m1(sz1);
Szemely m2 = sz2;
```
Tests copy construction and assignment.

---

### 🧠 Summary of Concepts

- `#ifndef` ... `#define`: include guards
- Class with constructor and const methods
- Inheritance: `Hallgato` from `Szemely`
- Method overriding and calling base methods
- Encapsulation and data hiding
- Composition of behavior using helper functions like `teljesNev()`, `fiatalabb()`


-----

Here are the **key takeaways** from the code:

---

### 🔑 **Key Concepts**

#### ✅ 1. **Include Guards**
- `#ifndef`, `#define`, `#endif` prevent multiple inclusions of a header file.
  
#### ✅ 2. **Class Definition**
- `Szemely` represents a person with `vnev` (last name), `knev` (first name), and `eletkor` (age).
- `Hallgato` (student) **inherits** from `Szemely` and adds `neptunKod` and `felevekSzama`.

#### ✅ 3. **Constructor Initialization Lists**
- Member variables are initialized directly in the constructor using `:` syntax.

#### ✅ 4. **Const Methods**
- `const` after method declarations means they do not modify the object.
- Good practice for getters like `getEletkor()` or `getKeresztNev()`.

#### ✅ 5. **Method Overriding**
- `Hallgato::kiir()` **overrides** `Szemely::kiir()` and also calls it.

#### ✅ 6. **Encapsulation**
- Member variables are private by default.
- Access and modification are done through public methods (getters).

#### ✅ 7. **Inheritance**
- `Hallgato` reuses and extends functionality from `Szemely`.

#### ✅ 8. **Object Comparison**
- `fiatalabb()` method lets you compare two `Szemely` or derived objects by age.

#### ✅ 9. **Custom Logic**
- `furcsa()` uses a formula to determine if a student's age is unusual for their number of semesters.

#### ✅ 10. **Code Reuse**
- `Szemely::kiir()` is reused in `Hallgato::kiir()` via `Szemely::kiir();`.

---

Would you like a set of flashcards or practice questions based on this code?