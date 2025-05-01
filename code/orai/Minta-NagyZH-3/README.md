Here’s a plain English outline of the objectives for the "Minta NagyZH – 2024" programming task:

---

### Main Goal:
Build a C++ program to manage and apply **coupons** to **shopping purchases** using object-oriented programming.

---

### Key Tasks:

1. **Use Object-Oriented Design:**
   - Build classes for different types of coupons and manage them properly.

2. **Coupon Types:**
   - **Single-use coupon**: usable only once.
   - **Multi-use coupon**: can be used multiple times, has a usage count.
   - **Monthly coupon**: only works during a specific month (e.g., May 2024).

3. **Coupon Class Hierarchy:**
   - Create a base class `Coupon` and use inheritance for the different types.

4. **Wallet Class:**
   - Stores multiple coupons.
   - Can add coupons manually or load them from a JSON file.
   - Can count how many coupons exist (with an option to count only valid ones).
   - Can export coupon counts (valid and invalid) into a JSON file.

5. **Purchase Class:**
   - Loads purchase items from a JSON file.
   - Stores product names, unit prices, quantities, and units.
   - Has a method to **print** all details.
   - Calculates **total cost** before coupons.
   - Applies coupons from a `Wallet` and calculates **discounted total** (without going below 0).

6. **Main Program Setup:**
   - Create a `Wallet` with:
     - One single-use 1000 Ft coupon
     - One 2000 Ft coupon usable 5 times
     - One 3000 Ft monthly coupon valid for May 2024

7. **Date Handling:**
   - The current date should be set to 2024-05-01, but should also be changeable globally.

8. **Submission Rules:**
   - Submit the full source code in one `.zip` file.
   - Place the test input files (`purchases.json`, `coupons-1.json`, `coupons-2.json`) in the `build` directory for testing.

---

Would you like help designing the class structure or starting the code?




Let's begin the **line-by-line explanation** of your project, starting with the file `main.cpp`.

---

### 🔹 File: `main.cpp`

```cpp
#include <iostream>
using namespace std;
```
- These lines include the standard C++ I/O library and bring the standard namespace into scope so you can use `cout`, `endl`, etc., without `std::`.

---

```cpp
// sajat include-ok (az osztalyok szabadon atnevezhetok!)
#include "wallet.h"
#include "csingle.h"
#include "cmulti.h"
#include "cmonthly.h"
#include "purchase.h"
```
- These are project-specific header files. They include:
  - `wallet.h`: manages a collection of coupons.
  - `csingle.h`: defines single-use coupons.
  - `cmulti.h`: defines multi-use coupons.
  - `cmonthly.h`: defines coupons valid in a given month.
  - `purchase.h`: handles purchase data and applying coupons.

---

```cpp
using SingleCoupon = CSingle;
using MultiCoupon = CMulti;
using MonthlyCoupon = CMonthly;
```
- These `using` statements create aliases so you can use easier names (`SingleCoupon` instead of `CSingle`, etc.).

---

```cpp
int main()
{
    cout << "main() eleje!" << endl << endl;
```
- The main function begins, printing a startup message.

---

```cpp
    Wallet wallet;
```
- Creates a `Wallet` object to store coupons.

---

```cpp
    // itt kell a Wallet-et feltolteni a harom kuponnal:
    wallet.addCoupon(new SingleCoupon(1000));
    wallet.addCoupon(new MultiCoupon(2000,5));
    wallet.addCoupon(new MonthlyCoupon(3000,2024,5));
```
- Adds three different coupons to the wallet:
  - A 1000 Ft **single-use** coupon.
  - A 2000 Ft **multi-use** coupon usable 5 times.
  - A 3000 Ft **monthly** coupon valid for **May 2024**.

---

```cpp
    cout << "---Vasarlasok, print()" << endl;
    Purchase purchase("purchases.json");
    purchase.print();
    cout << endl;
```
- Creates a `Purchase` object from the JSON file `purchases.json` and prints the items.

---

```cpp
    cout << "---Vegosszeg lekerdezese (alap)" << endl;
    cout << "sum == " << purchase.getTotal() << endl; // 15831
```
- Displays the **total price without coupons**.

---

```cpp
    cout << "---Vegosszeg lekerdezese (kuponok hasznalata)" << endl;
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 9831
```
- Applies coupons and prints the **discounted total**.
- The next lines repeat this to show how coupon state changes after each use:
```cpp
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
```
- You can see the total increasing as coupons become invalid or are used up.

---

```cpp
    cout << "---Datum atallitasa, havi kuponok" << endl;
```
- Starts testing how date affects **monthly coupons**.

```cpp
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
    MonthlyCoupon::setCurrentDate(2023,12,31);
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 15831
    MonthlyCoupon::setCurrentDate(2024,5,1);
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
```
- The monthly coupon only works in May 2024, so the total jumps back up when it's not valid.

---

```cpp
    cout << "---loadCoupons(), countCoupons(), exportCounts()" << endl;
```
- Demonstrates reading additional coupons from a file, counting, and exporting stats.

```cpp
    wallet.loadCoupons("coupons-1.json");
    wallet.exportCounts("export-example-A.json");
```
- Loads coupons from `coupons-1.json` and writes counts to `export-example-A.json`.

---

```cpp
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 2
    cout << wallet.countCoupons<SingleCoupon>() << endl; // 3
```
- Counts valid and all **single-use** coupons.

---

```cpp
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 4091
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 0
```
- Applies more coupons and shows how the valid count drops to zero.

---

```cpp
    cout << ">>> Beolvasas: coupons2.json ." << endl;
    wallet.loadCoupons("coupons-2.json");
```
- Loads another set of coupons.

---

```cpp
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 2
    cout << wallet.countCoupons<MultiCoupon>(true) << endl; // 6
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 1141
```
- Uses some of the newly loaded coupons.

---

```cpp
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 0
    cout << wallet.countCoupons<MultiCoupon>(true) << endl; // 6
    cout << wallet.countCoupons<MultiCoupon>(false) << endl; // 7
```
- Shows valid vs total for **multi-use** coupons.

---

```cpp
    wallet.exportCounts("export-example-B.json");
    cout << endl;

    cout << "main() vege!" << endl;
    return 0;
}
```
- Exports updated stats and ends the program.

---

Would you like me to continue with a line-by-line breakdown of another file (e.g., `wallet.cpp` or `purchase.cpp`)?



Great! Let's go through **`wallet.cpp`** line by line.

---

### 🔹 File: `wallet.cpp`

```cpp
#include "wallet.h"
```
- Includes the corresponding header that declares the `Wallet` class.

---

```cpp
#include "csingle.h"
#include "cmulti.h"
#include "cmonthly.h"
```
- Includes the definitions for the three coupon types so the wallet can create them when reading from JSON.

---

```cpp
#include <fstream>
#include <nlohmann/json.hpp>
```
- `fstream`: used for reading/writing files.
- `nlohmann/json`: a popular JSON library for C++ that makes it easy to work with JSON.

---

```cpp
using json = nlohmann::json;
```
- Simplifies usage of the JSON type by making `json` an alias for `nlohmann::json`.

---

```cpp
Wallet::~Wallet()
{
    for (Coupon* c : coupons) {
        delete c;
    }
}
```
- **Destructor**: deletes all dynamically allocated `Coupon` objects to avoid memory leaks.

---

```cpp
void Wallet::addCoupon(Coupon* c)
{
    coupons.push_back(c);
}
```
- Adds a new `Coupon` pointer to the `coupons` vector.

---

```cpp
void Wallet::loadCoupons(const string& fname)
{
    ifstream f(fname);
    json j;
    f >> j;
```
- Opens a file with the given filename (`fname`), reads JSON content into the `j` object.

---

```cpp
    for (auto& elem : j) {
        string type = elem["type"];
```
- Iterates through all coupon objects in the JSON array and reads the `"type"` field (e.g., "single", "multi", "monthly").

---

```cpp
        if (type == "single") {
            addCoupon(new CSingle(elem["value"]));
        } else if (type == "multi") {
            addCoupon(new CMulti(elem["value"], elem["count"]));
        } else if (type == "monthly") {
            addCoupon(new CMonthly(elem["value"], elem["year"], elem["month"]));
        }
    }
}
```
- Depending on the type:
  - Creates a `CSingle`, `CMulti`, or `CMonthly` coupon using JSON values.
  - Adds it to the wallet.

---

```cpp
void Wallet::exportCounts(const string& fname) const
{
    json j;
```
- Prepares a new JSON object `j` for writing the coupon count results.

---

```cpp
    j["single"]["valid"] = countCoupons<CSingle>(true);
    j["single"]["invalid"] = countCoupons<CSingle>(false) - j["single"]["valid"];
```
- Counts **valid** and **invalid** single-use coupons and stores them in the JSON.

---

```cpp
    j["multi"]["valid"] = countCoupons<CMulti>(true);
    j["multi"]["invalid"] = countCoupons<CMulti>(false) - j["multi"]["valid"];
```
- Same for multi-use coupons.

---

```cpp
    j["monthly"]["valid"] = countCoupons<CMonthly>(true);
    j["monthly"]["invalid"] = countCoupons<CMonthly>(false) - j["monthly"]["valid"];
```
- Same for monthly coupons.

---

```cpp
    ofstream f(fname);
    f << j.dump(4);
}
```
- Opens the output file and writes the JSON object with **indentation of 4 spaces**.

---

Would you like to continue with `coupon.cpp` or one of the coupon-type files like `csingle.cpp` next?



Perfect — let’s now go through **`coupon.cpp`** line by line.

---

### 🔹 File: `coupon.cpp`

```cpp
#include "coupon.h"
```
- Includes the header file `coupon.h`, where the base class `Coupon` is declared.

---

```cpp
Coupon::Coupon(int value) : value(value)
{
}
```
- **Constructor** of the `Coupon` base class.
- It takes an `int value` (discount value in Forints) and uses an **initializer list** to set the `value` member.

---

```cpp
int Coupon::getValue() const
{
    return value;
}
```
- A **getter method** to retrieve the coupon's value.
- Marked `const` because it does not modify the object.

---

```cpp
ostream& operator<<(ostream& os, const Coupon& c)
{
    return c.print(os);
}
```
- **Overloads the `<<` operator** so you can write `cout << myCoupon;`.
- It calls the virtual `print` method on the coupon, allowing each subclass to define its own print format.

---

```cpp
Coupon::~Coupon() {}
```
- A **virtual destructor** definition for the base class.
- Important for safely deleting derived class objects through a base class pointer (i.e., `delete Coupon*`).

---

This file is simple, as it provides the foundation for all coupon types. It defines:
- how coupons store their value,
- how to get that value,
- how to print them (via polymorphism),
- and includes a virtual destructor for safe cleanup.

---

Would you like to go over `csingle.cpp`, `cmulti.cpp`, or `cmonthly.cpp` next?


Let’s now continue with **`csingle.cpp`** — the implementation of the **single-use coupon**.

---

### 🔹 File: `csingle.cpp`

```cpp
#include "csingle.h"
```
- Includes the header that defines the `CSingle` class (a single-use coupon).

---

```cpp
CSingle::CSingle(int value) : Coupon(value), used(false)
{
}
```
- **Constructor** for `CSingle`.
- Calls the base class `Coupon(value)` to set the coupon’s value.
- Initializes `used` to `false`, meaning the coupon hasn’t been used yet.

---

```cpp
bool CSingle::isValid() const
{
    return !used;
}
```
- Returns `true` if the coupon **has not been used**.
- Otherwise, returns `false`.

---

```cpp
int CSingle::apply()
{
    used = true;
    return getValue();
}
```
- Applies the coupon:
  - Sets `used` to `true`.
  - Returns the coupon’s value (via `getValue()` from the base class).
- This simulates the coupon being spent.

---

```cpp
ostream& CSingle::print(ostream& os) const
{
    return os << "CSingle(" << getValue() << ") " << (isValid() ? "valid" : "invalid");
}
```
- **Custom print** method:
  - Prints `CSingle(<value>) valid` or `CSingle(<value>) invalid`.
  - Used by the overloaded `<<` operator in `coupon.cpp`.

---

This file encapsulates the logic of a coupon that can **only be used once**. It:
- Tracks if it’s been used,
- Can be applied once,
- Reports validity,
- Prints itself clearly.

---

Would you like to continue with `cmulti.cpp` (multi-use coupons) next?



Here are the **key takeaways** from the files we've reviewed (`main.cpp`, `wallet.cpp`, `coupon.cpp`, `csingle.cpp`):

---

### 🧠 **Object-Oriented Design**
- The system is designed using **inheritance**:
  - `Coupon` is the **base class**.
  - `CSingle`, `CMulti`, and `CMonthly` are **derived classes** with specific behaviors.

---

### 🛒 **Coupon Behavior**
- **Single-use coupon (`CSingle`)**:
  - Has a `used` flag.
  - Can only be applied once.
  - After use, becomes invalid.

- **Polymorphism** is used:
  - `apply()` and `isValid()` are virtual and overridden in each derived class.
  - `print()` is also virtual for formatted output.

---

### 📦 **Wallet Functionality**
- `Wallet` stores a list of `Coupon*`.
- Supports:
  - Adding coupons.
  - Loading from JSON files (`loadCoupons`).
  - Counting valid/invalid coupons by type (`countCoupons<T>()`).
  - Exporting statistics to a JSON file (`exportCounts()`).
- Automatically deallocates memory in its destructor (`~Wallet`).

---

### 🧾 **Purchase Logic**
- `Purchase` loads items from a JSON file.
- Has methods to:
  - Print items.
  - Calculate total price.
  - Apply all valid coupons from a `Wallet`, adjusting totals and invalidating used coupons.

---

### 🧪 **Main Program**
- Demonstrates:
  - Coupon creation and usage.
  - Date-dependent validation (monthly coupons).
  - Dynamic coupon loading from files.
  - Tracking and exporting usage statistics.

---

Would you like a diagram showing the class hierarchy and responsibilities?


Here's an **ASCII diagram** showing the **class hierarchy and relationships** in your coupon system:

```
                     +------------------+
                     |     Coupon       |  <-- Base class (abstract/interface)
                     +------------------+
                     | - value: int     |
                     +------------------+
                     | + getValue()     |
                     | + isValid()      | <-- virtual
                     | + apply()        | <-- virtual
                     | + print()        | <-- virtual
                     +------------------+
                             ▲
        +--------------------+--------------------+
        |                    |                    |
+----------------+  +----------------+  +---------------------+
|   CSingle       |  |    CMulti      |  |     CMonthly        |
+----------------+  +----------------+  +---------------------+
| - used: bool    |  | - count: int   |  | - year: int         |
|                 |  |                |  | - month: int        |
|                 |  |                |  | (static current date|
|                 |  |                |  |  shared among all)  |
+----------------+  +----------------+  +---------------------+

                 Coupon subclasses implement:
                   - isValid()
                   - apply()
                   - print()
```

And the **usage relationships**:

```
+------------------------+
|        Wallet          |
+------------------------+
| - coupons: vector<Coupon*> |
+------------------------+
| + addCoupon()          |
| + loadCoupons()        |
| + countCoupons<T>()    |
| + exportCounts()       |
+------------------------+

         uses and manages →
                [ Coupon* ]
```

```
+------------------------+
|       Purchase         |
+------------------------+
| - items: vector<Item>  |
+------------------------+
| + getTotal()           |
| + print()              |
| + useCoupons(Wallet&)  |
+------------------------+
```

Would you like a similar ASCII diagram for file structure or data flow?





Here's an **ASCII diagram of the data flow** in your coupon application — from loading data, applying coupons, to output/export:

```
                           +--------------------+
                           |  JSON Input Files  |
                           | (purchases.json,   |
                           |  coupons-1.json,   |
                           |  coupons-2.json)   |
                           +---------+----------+
                                     |
                                     v
                           +--------------------+
                           |      Purchase      |
                           | - loads items      |
                           |   from JSON        |
                           +--------------------+
                                     |
                    ----------------+------------------
                    |                                  |
                    v                                  v
        +------------------------+       +--------------------------+
        |     getTotal()         |       |     useCoupons(Wallet&)  |
        | → calculates total     |       | → applies valid coupons  |
        |   based on items       |       | → updates coupon state   |
        +------------------------+       +--------------------------+

                                     ▲
                                     |
                            +--------+---------+
                            |      Wallet       |
                            | - loadCoupons()   |
                            | - countCoupons<T> |
                            | - exportCounts()  |
                            +-------------------+
                                     |
              +----------------------+---------------------+
              |                      |                     |
              v                      v                     v
       [ CSingle ]            [ CMulti ]           [ CMonthly ]
       (used once)        (used N times)       (valid in month)

                                     |
                                     v
                            +--------------------+
                            |  JSON Output File  |
                            | (export-example-*.json) |
                            | ← exportCounts()   |
                            +--------------------+

```

### 🔄 Summary:
- **Input**: JSON files for purchases and coupons.
- **Processing**:
  - `Purchase` calculates totals and applies coupons.
  - `Wallet` manages coupon validity and counts.
- **Output**:
  - Printed totals and stats.
  - Exported coupon counts to JSON.

Would you like a walk-through of how a `useCoupons` call processes the coupons?



Here’s a **clear step-by-step walk-through** of what happens when you call `purchase.useCoupons(wallet)` in the code:

---

### 🔄 How `useCoupons()` Works

#### 🔹 File: `purchase.cpp`

```cpp
int Purchase::useCoupons(Wallet &wallet) const
{
    int sum = getTotal();
    sum -= wallet.useAllAndGetTotalDiscount();
    return sum;
}
```

### ➤ Step-by-Step Breakdown:

1. **Get the total price of the purchase:**
   ```cpp
   int sum = getTotal();
   ```
   This calls `getTotal()`, which sums the price of all purchase items.

2. **Ask the wallet to apply all valid coupons:**
   ```cpp
   sum -= wallet.useAllAndGetTotalDiscount();
   ```
   - The `wallet` goes through all its stored coupons.
   - For each **valid coupon**, it:
     - Applies it (marks it as used).
     - Adds its value to the total discount.

3. **Return the discounted result:**
   ```cpp
   return sum;
   ```

---

### 🔹 File: `wallet.cpp`

```cpp
int Wallet::useAllAndGetTotalDiscount()
{
    int totalDiscount = 0;
    for (size_t i = 0; i < coupons.size(); i++)
    {
        if (coupons[i]->isValid())
        {
            coupons[i]->use();
            totalDiscount += coupons[i]->getValue();
        }
    }
    return totalDiscount;
}
```

### ➤ Step-by-Step Breakdown:

1. **Initialize total discount to zero:**
   ```cpp
   int totalDiscount = 0;
   ```

2. **Loop through all stored coupons:**
   ```cpp
   for (...) {
       if (coupons[i]->isValid()) {
           ...
       }
   }
   ```

3. **If a coupon is valid:**
   - Mark it as **used** (`use()`).
   - Add its value to `totalDiscount`.

4. **Return the total discount.**

---

### ✅ Example Flow:

Let’s say the total price is `15831 Ft`, and the wallet has:

- A `SingleCoupon(1000)`
- A `MultiCoupon(2000, 5)` ← valid 5 times
- A `MonthlyCoupon(3000)` for May 2024 (and today's date is valid)

#### 1st use:
- All 3 are valid:
  - `1000 + 2000 + 3000 = 6000` discount
  - New total: `15831 - 6000 = 9831`

#### 2nd use:
- Single is now invalid
- Multi has 4 uses left
- Monthly still valid
  - `2000 + 3000 = 5000` discount
  - New total: `15831 - 5000 = 10831`

…and so on, coupons become exhausted one by one.

---

Let me know if you’d like this visualized in ASCII or explained with a coupon state chart!


Here is an **ASCII coupon state chart** showing how the state of each coupon type evolves across multiple calls to `useCoupons(wallet)`:

---

### 🧾 Initial Wallet State (Before Any Use)
```
+--------------+---------+------------------+
| Coupon Type  | Value   | Status           |
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Valid            |
| MultiCoupon  | 2000 Ft | Uses left: 5     |
| MonthlyCoupon| 3000 Ft | Valid (May 2024) |
+--------------+---------+------------------+
```

---

### 🧮 After 1st useCoupons() call
```
Discount applied: 1000 + 2000 + 3000 = 6000 Ft
```
```
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Invalid (used)   |
| MultiCoupon  | 2000 Ft | Uses left: 4     |
| MonthlyCoupon| 3000 Ft | Valid            |
+--------------+---------+------------------+
```

---

### 🧮 After 2nd useCoupons() call
```
Discount applied: 2000 + 3000 = 5000 Ft
```
```
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Invalid          |
| MultiCoupon  | 2000 Ft | Uses left: 3     |
| MonthlyCoupon| 3000 Ft | Valid            |
+--------------+---------+------------------+
```

---

### 🧮 After 3rd useCoupons() call
```
Discount applied: 2000 + 3000 = 5000 Ft
```
```
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Invalid          |
| MultiCoupon  | 2000 Ft | Uses left: 2     |
| MonthlyCoupon| 3000 Ft | Valid            |
+--------------+---------+------------------+
```

---

### 🧮 After 4th useCoupons() call
```
Discount applied: 2000 + 3000 = 5000 Ft
```
```
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Invalid          |
| MultiCoupon  | 2000 Ft | Uses left: 1     |
| MonthlyCoupon| 3000 Ft | Valid            |
+--------------+---------+------------------+
```

---

### 🧮 After 5th useCoupons() call
```
Discount applied: 2000 + 3000 = 5000 Ft
```
```
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Invalid          |
| MultiCoupon  | 2000 Ft | Uses left: 0     | ← Now invalid
| MonthlyCoupon| 3000 Ft | Valid            |
+--------------+---------+------------------+
```

---

### 🧮 After 6th useCoupons() call
```
Discount applied: 3000 Ft
```
```
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Invalid          |
| MultiCoupon  | 2000 Ft | Invalid          |
| MonthlyCoupon| 3000 Ft | Valid            |
+--------------+---------+------------------+
```

---

### 🧮 If Date Changes (e.g., to June 2024)
```
MonthlyCoupon becomes invalid → Discount applied: 0 Ft
```
```
+--------------+---------+------------------+
| SingleCoupon | 1000 Ft | Invalid          |
| MultiCoupon  | 2000 Ft | Invalid          |
| MonthlyCoupon| 3000 Ft | Invalid (wrong month) |
+--------------+---------+------------------+
```

---

Let me know if you'd like the same style chart for loading from a JSON file (`loadCoupons`) or counting/exporting coupon status!


Here’s an **ASCII Call Graph** (function-level) of your program — showing how the main functions call each other and interact across files:

---

### 🔧 Function-Level ASCII Call Graph

```
main()
│
├── wallet.addCoupon()             ← adds initial coupons manually
│
├── purchase.print()              ← displays purchase items
│
├── purchase.getTotal()          ← calculates full price
│
├── purchase.useCoupons(wallet)
│   └── getTotal()                     ← get base total
│   └── wallet.useAllAndGetTotalDiscount()
│       ├── coupon->isValid()             ← virtual, resolves to actual type
│       ├── coupon->use()                 ← virtual (e.g., mark used, reduce count)
│       └── coupon->getValue()            ← virtual (get value)
│
├── MonthlyCoupon::setCurrentDate()  ← change static date
│
├── wallet.loadCoupons(filename)
│   └── JSON parsing
│   └── addCoupon(new CSingle/CMulti/CMonthly(...))
│
├── wallet.countCoupons<T>(validOnly)
│   └── dynamic_cast<T*> on each coupon
│   └── coupon->isValid() if validOnly is true
│
├── wallet.exportCounts(filename)
│   ├── countCoupons<CSingle>()
│   ├── countCoupons<CMulti>()
│   ├── countCoupons<CMonthly>()
│   └── JSON write
│
└── std::cout << coupon            ← calls coupon->print() via operator<<
```

---

### 🎯 Explanation

- `main()` orchestrates everything — adding coupons, loading JSON, calling `print()`, applying discounts, exporting results.
- `useCoupons()` is the central coupon application path, relying on `Wallet` and polymorphism (`isValid()`, `use()`, `getValue()`).
- File I/O (`loadCoupons` and `exportCounts`) work through the `Wallet` class.
- `countCoupons<T>` uses **templates** and **runtime type checking** to filter coupon types and validity.

---

Let me know if you'd like a similar graph for class-to-class dependencies or template usage!