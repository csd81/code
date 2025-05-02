# Feladat: `Szamok` osztály készítése

# Feladat

Készíts egy `Szamok` osztályt, amely lebegőpontos számok tömbjét tárolja. Az osztály legyen a `Tarolo` névtérben.

## Követelmények

- A tárolt tömb mérete nem ismert előre. Az osztály konstruktora kapja meg a méretet paraméterként, és foglaljon dinamikusan helyet a tömbnek.
- A konstruktor második paramétere egy alapértelmezett érték legyen (`0`). Létrehozáskor a tömb minden eleme ezt az értéket vegye fel.
- A `Szamok` osztály destruktora szabadítsa fel a konstruktor által lefoglalt memóriát.

## Osztálymetódusok

- `darabLeker()`  
  Visszaadja az eltárolt értékek számát.

- `ertekBeallit(index, ertek)`  
  - Beállítja a megadott indexű tömbértéket a megadott értékre.  
  - Ha az index érvénytelen, a függvény nem csinál semmit.

- `ertekLeker(index)`  
  - Visszaadja a megadott indexű értéket.  
  - Ha az index érvénytelen, a függvény `-10⁸` értékkel tér vissza.

## main.cpp elvárások

- **Ne** használj `using namespace` utasítást a `Tarolo` névtérre!
- Készíts egy `kiir` függvényt, amely paraméterként kap egy `Szamok` objektumot, és megjeleníti a tömb elemeit egy sorban, vesszővel elválasztva.
- A `main` függvényben:
  - Hozz létre két `Szamok` objektumot.
  - Töltsd fel őket értékekkel.
  - Jelenítsd meg őket a `kiir` függvénnyel.


## Követelmények

* **Osztály neve:** `Szamok`
* **Névtér:** `Tarolo`
* **Adattag:** lebegőpontos számok tömbje

### Konstruktor

* Paraméterezett konstruktor:

  * **1. paraméter:** tömb mérete
  * **2. paraméter (alapértelmezett):** kezdeti érték, amivel a tömb elemeit feltöltjük (alapértelmezés: `0`)
* A konstruktor foglaljon helyet a tömbnek dinamikusan.

### Destruktor

* Szabadítsa fel a konstruktor által lefoglalt memóriát.

### Függvények az osztályban

* `darabLeker()`:
  Visszaadja az eltárolt értékek számát.

* `ertekBeallit(index, ertek)`:

  * Beállítja a megadott indexű tömbértéket a megadott `ertek`-re.
  * Ha az index érvénytelen, a függvény nem csinál semmit.

* `ertekLeker(index)`:

  * Visszaadja a tömb adott helyén lévő értéket.
  * Ha az index érvénytelen, `-10⁸` értékkel tér vissza.

## `main.cpp` követelmények

* **Fontos:** Ne használj `using namespace` utasítást a `Tarolo` névtérre!
* Készíts egy `kiir` nevű függvényt, amely:

  * Paraméterként kap egy `Szamok` objektumot.
  * Megjeleníti a tömb elemeit egy sorban, vesszővel elválasztva.

### `main()` függvény

* Hozz létre két `Szamok` objektumot.
* Töltsd fel őket értékekkel.
* Jelenítsd meg azokat a `kiir` függvénnyel.

 ```bash
 +--------------------------+
|     Tarolo::Szamok      |
+--------------------------+
| - double* tomb          |
| - int meret             |
+--------------------------+
| + Szamok(m: int,        |
|         kezdo: double)  |
| + ~Szamok()             |
| + int darabLeker()      |
| + void ertekBeallit(    |
|       index: int,       |
|       ertek: double)    |
| + double ertekLeker(    |
|         index: int)     |
+--------------------------+
```

| Visibility | Name             | Type / Parameters                  | Description                     |
|------------|------------------|------------------------------------|---------------------------------|
| *Private*  | `tomb`           | `double*`                          | Pointer to the array            |
| *Private*  | `meret`          | `int`                              | Size of the array               |
| *Public*   | `Szamok`         | `(int m, double kezdo = 0)`        | Constructor                     |
| *Public*   | `~Szamok`        | `()`                               | Destructor                      |
| *Public*   | `darabLeker`     | `() -> int`                        | Returns the number of elements |
| *Public*   | `ertekBeallit`   | `(int index, double ertek)`        | Sets value at index             |
| *Public*   | `ertekLeker`     | `(int index) -> double`            | Gets value or -10⁸ if invalid  |
