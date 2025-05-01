This C++ project manages **deadlines** using two classes:

---

### ✅ `Datum` – Represents a Date
Defined in `datum.h` and implemented in `datum.cpp`.

- **Attributes:** `ev` (year), `honap` (month), `nap` (day).
- **Usage:** Constructed as `Datum(2025, 5, 1)`, with simple getters and setters.

---

### ✅ `Hatarido` – Represents a Deadline
Defined in `hatarido.h` and implemented in `hatarido.cpp`.

- **Attributes:**
  - `nev`: the name of the deadline.
  - `alphaDatum`, `betaDatum`, `vegsoDatum`: pointers to `Datum`, dynamically allocated.
  - `aktualisDatum`: static `Datum`, shared across all instances, tracks current date.

- **Functions:**
  - Set and get individual dates (`alpha`, `beta`, `vegso`).
  - Set and get the static `aktualisDatum`.
  - Constructor initializes name, sets all date pointers to `nullptr`.
  - Destructor safely deletes any allocated dates.

---

### ✅ `main.cpp` – Demonstrates Usage

1. Creates two `Hatarido` objects (`h1`, `h2`) with different names.
2. Sets dates using either direct construction or user input.
3. Displays deadlines via the `hataridotKiir` function.
4. Demonstrates reading and updating the shared current date (`aktualisDatum`).

---

### 🔍 Key Concepts:
- **Dynamic memory management**: Dates are stored as pointers and dynamically allocated (`new Datum(...)`) and deleted in the destructor.
- **Safe pointer use**: Ensures dates are created only once; overwriting avoids memory leaks.
- **Encapsulation**: Direct access to internals is avoided—everything is handled via setters/getters.

--------------------------



Let’s go through the `Datum` class **header (`datum.h`)** and **implementation (`datum.cpp`)** line by line:

---

### 📄 `datum.h` – Class Declaration

```cpp
#ifndef DATUM_H
#define DATUM_H
```
- Header guard: prevents multiple inclusion of the same header file.

```cpp
class Datum
{
    unsigned int ev, honap, nap;
```
- Defines the class `Datum`.
- It has **three private attributes**:
  - `ev` = year
  - `honap` = month
  - `nap` = day

---

#### Public interface:

```cpp
public:
    Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap);
```
- **Constructor**: initializes the date with given year, month, and day.

```cpp
    unsigned int getEv() const;
    void setEv(unsigned int value);
```
- Getter and setter for the **year**.

```cpp
    unsigned int getHonap() const;
    void setHonap(unsigned int value);
```
- Getter and setter for the **month**.

```cpp
    unsigned int getNap() const;
    void setNap(unsigned int value);
```
- Getter and setter for the **day**.

```cpp
};
#endif // DATUM_H
```
- Closes the class definition and header guard.

---

### ⚙️ `datum.cpp` – Class Implementation

```cpp
#include "datum.h"
```
- Includes the class declaration.

```cpp
Datum::Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap):
    ev(_ev),
    honap(_honap),
    nap(_nap)
{
}
```
- The **constructor** initializes the private members using an initializer list.

```cpp
unsigned int Datum::getEv() const
{
    return ev;
}
```
- Returns the year.

```cpp
void Datum::setEv(unsigned int value)
{
    ev = value;
}
```
- Sets the year.

```cpp
unsigned int Datum::getHonap() const
{
    return honap;
}
```
- Returns the month.

```cpp
void Datum::setHonap(unsigned int value)
{
    honap = value;
}
```
- Sets the month.

```cpp
unsigned int Datum::getNap() const
{
    return nap;
}
```
- Returns the day.

```cpp
void Datum::setNap(unsigned int value)
{
    nap = value;
}
```
- Sets the day.

---

### ✅ Summary

The `Datum` class is a simple **immutable-style data container** for a calendar date, offering:
- A constructor to initialize date values.
- Getters and setters for each date component.
- No validation (e.g., it doesn't check if February 30 is valid).

Would you like to add features like:
- Date validation?
- Comparison operators (`<`, `==`, etc.)?
- A `toString()` method for formatted output?



Let’s now explain the `Hatarido` class in both the **header (`hatarido.h`)** and the **implementation (`hatarido.cpp`)** line by line.

---

## 📄 `hatarido.h` – Header File

```cpp
#ifndef HATARIDO_H
#define HATARIDO_H
```
- Header guard to prevent multiple inclusions.

```cpp
#include <string>
#include "datum.h"

using namespace std;
```
- Includes the `<string>` library and the `Datum` class.
- Allows use of `string` without prefixing `std::`.

---

### ✅ Class Declaration

```cpp
class Hatarido
{
    string nev;
    Datum *alphaDatum;
    Datum *betaDatum;
    Datum *vegsoDatum;

    static Datum aktualisDatum;
```

- **`nev`**: the name of the deadline.
- **`alphaDatum`, `betaDatum`, `vegsoDatum`**:
  - Three optional deadline dates, stored as pointers to `Datum`.
  - They can be `nullptr` if unset.
- **`aktualisDatum`**: a **static** shared date, common to all instances (like a global current date).

---

### 📦 Public Methods

```cpp
public:
    Hatarido(const string &_nev);
    ~Hatarido();
```
- **Constructor**: initializes the object with a name.
- **Destructor**: frees allocated memory for the date pointers.

---

### Getters and Setters

```cpp
    string getNev() const;
    void setNev(const string &newNev);
```
- Gets or sets the name.

```cpp
    Datum *getAlphaDatum() const;
    void setAlphaDatum(const Datum &d);
```
- Gets or sets the **alpha** date.

```cpp
    Datum *getBetaDatum() const;
    void setBetaDatum(const Datum &d);
```
- Gets or sets the **beta** date.

```cpp
    Datum *getVegsoDatum() const;
    void setVegsoDatum(const Datum &d);
```
- Gets or sets the **final** (vegso) date.

---

### Static Methods for Shared Date

```cpp
    static Datum getAktualisDatum();
    static void setAktualisDatum(const Datum &d);
```
- Get or set the **shared current date** (`aktualisDatum`) for all deadlines.

```cpp
};
#endif // HATARIDO_H
```
- End of class and header guard.

---

## ⚙️ `hatarido.cpp` – Implementation File

```cpp
#include "hatarido.h"
```
- Includes the class definition.

---

### 📌 Static Member Definition

```cpp
Datum Hatarido::aktualisDatum(2025,2,28);
```
- Initializes the shared current date to February 28, 2025.

---

### 🎛️ Getters and Setters

```cpp
string Hatarido::getNev() const { return nev; }
void Hatarido::setNev(const string &newNev) { nev = newNev; }
```
- Manage the deadline's name.

```cpp
Datum *Hatarido::getAlphaDatum() const { return alphaDatum; }
```
- Returns the pointer to the alpha date.

```cpp
void Hatarido::setAlphaDatum(const Datum &d)
{
    if (alphaDatum) *alphaDatum = d;
    else alphaDatum = new Datum(d);
}
```
- If `alphaDatum` exists, update its value.
- If not, allocate a new `Datum`.

This logic avoids memory leaks while supporting dynamic behavior.

(Same logic is used for `betaDatum` and `vegsoDatum`.)

```cpp
Datum *Hatarido::getBetaDatum() const { return betaDatum; }
void Hatarido::setBetaDatum(const Datum &d)
{
    if (betaDatum) *betaDatum = d;
    else betaDatum = new Datum(d);
}

Datum *Hatarido::getVegsoDatum() const { return vegsoDatum; }
void Hatarido::setVegsoDatum(const Datum &d)
{
    if (vegsoDatum) *vegsoDatum = d;
    else vegsoDatum = new Datum(d);
}
```

---

### 🔁 Static Date Accessors

```cpp
Datum Hatarido::getAktualisDatum() { return aktualisDatum; }
void Hatarido::setAktualisDatum(const Datum &d) { aktualisDatum = d; }
```
- Set or retrieve the shared `aktualisDatum`.

---

### 🛠️ Constructor and Destructor

```cpp
Hatarido::Hatarido(const string &_nev):
    nev(_nev),
    alphaDatum(nullptr),
    betaDatum(nullptr),
    vegsoDatum(nullptr)
{}
```
- Initializes the name and sets all date pointers to `nullptr`.

```cpp
Hatarido::~Hatarido()
{
    delete alphaDatum;
    delete betaDatum;
    delete vegsoDatum;
}
```
- Cleans up any dynamically allocated `Datum` objects to avoid memory leaks.

---

### ✅ Summary

The `Hatarido` class:
- Manages **three optional deadlines** (`alpha`, `beta`, `vegso`) using dynamic memory.
- Shares a **static current date** across all instances.
- Uses clean memory management in constructor and destructor.
- Lacks some features mentioned in `main.cpp` like:
  - Copy constructor
  - `lejart()` method
  - `hataridoTorol(string)` method

Would you like help implementing any of those missing methods?





Let's go line by line through the first ~60 lines of `main.cpp` to understand everything clearly:

---

```cpp
#include <iostream>
#include <fstream>
#include "datum.h"
#include "hatarido.h"
```
- Includes standard I/O and file handling libraries.
- Includes the custom headers `datum.h` and `hatarido.h` for working with the `Datum` and `Hatarido` classes.

```cpp
using namespace std;
```
- Avoids the need to prefix `std::` before things like `cout`, `string`, etc.

---

### Function: `datumKiir`
```cpp
void datumKiir(const Datum *d)
{
    if (d==0) cout << "Nem letezo datum" << endl;
    else cout << d->getEv() << "." << d->getHonap() << "." << d->getNap() << endl;
}
```
- A helper function that prints a date.
- If the pointer is `nullptr`, it prints "Nem letezo datum" (Hungarian: "Nonexistent date").
- Otherwise, it prints the date in the format `YYYY.MM.DD`.

---

### Function: `hataridotKiir`
```cpp
void hataridotKiir(const Hatarido &h)
{
    cout << h.getNev() << ": " << endl;
    cout << "  alpha: ";
    datumKiir(h.getAlphaDatum());
    cout << "  beta: ";
    datumKiir(h.getBetaDatum());
    cout << "  vegso: ";
    datumKiir(h.getVegsoDatum());
}
```
- Takes a `Hatarido` object and prints:
  - Its name.
  - Its `alpha`, `beta`, and `vegso` dates using the `datumKiir` function.

---

### Function: `main`
```cpp
int main()
{
```
Start of the program execution.

```cpp
// Létrehozás és név beállítás
Hatarido h1("Elso tarolo osztaly");
```
- Creates the first `Hatarido` object `h1` with the name "Első tároló osztály".

```cpp
cout << "Kerek egy masik nevet: ";
string nev;
getline(cin, nev); // Teljes sor bekérése
Hatarido h2(nev);
```
- Asks the user for a second name.
- Reads a full line (can include spaces).
- Creates a second `Hatarido` object `h2` with that name.

```cpp
cout << h1.getNev() << endl;
cout << h2.getNev() << endl;
```
- Prints the names of both deadlines.

```cpp
h1.setNev("Atallitott nev");
cout << h1.getNev() << endl;
cout << h2.getNev() << endl;
```
- Renames `h1` and prints both names again to show that `h2` remains unchanged.

---

### Date Handling
```cpp
cout << endl;
h1.setAlphaDatum(Datum(2017, 3, 6));
```
- Sets `h1`’s alpha deadline to March 6, 2017.

```cpp
cout << "Kerek egy datumot (ev, honap, nap): ";
unsigned int e, h, n;
cin >> e >> h >> n;
h1.setVegsoDatum(Datum(e,h,n));
```
- Asks the user for a date.
- Sets `h1`’s final (`vegso`) deadline.

```cpp
cout << "Kerek meg egy datumot (ev, honap, nap): ";
cin >> e >> h >> n;
Datum d(e,h,n);
h2.setBetaDatum(d);
```
- Asks the user for another date.
- Creates a `Datum` object and sets it as the `beta` deadline of `h2`.

```cpp
hataridotKiir(h1);
hataridotKiir(h2);
```
- Prints both deadline objects with their dates.

---

### Static Date (`aktualisDatum`)
```cpp
Datum aktualis = Hatarido::getAktualisDatum();
cout << "Aktualis datum: " << aktualis.getEv() << "." << aktualis.getHonap() << "." << aktualis.getNap() << endl;
```
- Gets and prints the shared (static) current date stored in the class.

---

There are also commented-out blocks later to:
- Check if deadlines are expired.
- Modify dates.
- Copy objects.
- Delete specific deadlines.

Would you like me to continue explaining the remaining lines, including the commented-out blocks?

----

Let's now explain the rest of the `main.cpp` file line by line:

---

### 📆 Continuing with `aktualisDatum` (shared date)
```cpp
// cout << "Kerem az uj aktualis datumot (ev, honap, nap): ";
// cin >> e >> h >> n;
```
- These lines are commented out.
- They would normally ask the user for a new current date (`aktualisDatum`).

```cpp
Hatarido::setAktualisDatum(Datum(e,h,n));
```
- Updates the shared static `aktualisDatum` with the last entered values of `e`, `h`, `n`.

```cpp
aktualis = Hatarido::getAktualisDatum();
cout << "Aktualis datum: " << aktualis.getEv() << "." << aktualis.getHonap() << "." << aktualis.getNap() << endl;
```
- Re-fetches and prints the updated static date.

---

### ⏰ Checking if a deadline has passed (commented out)
```cpp
// cout << h1.getNev() << " lejart?" << endl;
// h1.lejart();
// cout << h2.getNev() << " lejart?" << endl;
// h2.lejart();
```
- These lines are commented out.
- Intended to check whether deadlines have expired using a hypothetical `lejart()` method (not implemented in current `Hatarido` class).

---

### 🧹 Date deletion and reset (commented out)
```cpp
// cout << endl;
// h1.setVegsoDatum(Datum(2000,1,1));
```
- Would set `h1`'s final date to 2000.01.01.

```cpp
// h1.hataridoTorol("alpha"); // Ezt kitörli
// h1.hataridoTorol("beta");  // Itt nincs dátum tárolva
// h1.hataridoTorol("gamma"); // Ilyen meg nincs is
```
- Intended to delete specific dates by name from `h1`.
- This method `hataridoTorol` is referenced but not present in the current implementation.

```cpp
// hataridotKiir(h1);
```
- Would reprint `h1` after modifications.

---

### 🧬 Object copying (commented out)
```cpp
// cout << endl;
// Hatarido uj(h1);
```
- Intended to create a copy of `h1` using a copy constructor (which is also not implemented in the current `Hatarido` class).

```cpp
// hataridotKiir(h1);
// hataridotKiir(uj);
```
- Would print both original and copied `Hatarido` objects.

```cpp
// uj.setNev("UJ");
// uj.setBetaDatum(Datum(1996,8,9));
```
- Modifies the name and `beta` date of the copy, `uj`.

```cpp
// hataridotKiir(h1);
// hataridotKiir(uj);
```
- Shows that changes to the copy do not affect the original, assuming deep copy logic is implemented.

---

### Program ends
```cpp
return 0;
}
```
- Ends the `main()` function and terminates the program normally.

---

### Summary of Missing Features Referenced in Comments
- `lejart()` → would check if a deadline is past `aktualisDatum`.
- `hataridoTorol(string)` → would delete one of the stored date pointers.
- Copy constructor → `Hatarido uj(h1)` assumes deep copy capability.

Would you like help implementing any of these missing features (e.g. `lejart()` or `copy constructor`)?

-----
Here are the **key takeaways** from this C++ project:

---

### ✅ **1. Object-Oriented Design**
- Two main classes:
  - `Datum`: encapsulates a date.
  - `Hatarido`: represents a deadline with multiple optional dates.
- Follows **encapsulation** with getters/setters.
- Demonstrates **composition**: `Hatarido` contains `Datum` objects via pointers.

---

### ✅ **2. Dynamic Memory Management**
- Uses `new` to allocate `Datum` objects inside `Hatarido`.
- Checks if a pointer is already allocated before assigning a new value.
- Properly **deletes allocated memory** in the destructor to avoid memory leaks.

---

### ✅ **3. Static Members and Methods**
- `aktualisDatum` is shared among all `Hatarido` instances.
- Useful for tracking system-wide concepts like "current date".
- Demonstrates how to use and define `static` members in C++.

---

### ✅ **4. Input/Output Handling**
- Uses both `cin` and `getline()` to handle user input safely.
- Prints formatted output using `cout`.

---

### ✅ **5. Separation of Interface and Implementation**
- Headers (`.h`) define structure and public API.
- Source files (`.cpp`) contain implementation logic.
- Encourages **modular, maintainable code**.

---

### ✅ **6. Real-World Concepts**
- Models deadlines and expiration in a realistic and extendable way.
- Could be easily extended to include:
  - Date validation
  - Deadline comparison (`lejart()`)
  - Date removal by name (`hataridoTorol`)
  - Copy constructor and assignment operator

---

### 🧠 Bonus: What You Can Learn or Practice

| Concept                     | Practiced in Code? |
|----------------------------|--------------------|
| Class Design               | ✅                 |
| Pointers and Memory        | ✅                 |
| Static Members             | ✅                 |
| Encapsulation              | ✅                 |
| Copy Semantics             | ❌ (not yet)       |
| Input Validation           | ❌ (could be added)|
| Operator Overloading       | ❌ (could be added)|
| Exception Handling         | ❌ (not used)      |

---

Would you like a list of suggested improvements or new features you could implement next?