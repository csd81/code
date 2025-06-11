 

# Szamok Osztály – Projektleírás

## Feladatleírás

A feladat célja egy `Szamok` osztály elkészítése, amely lebegőpontos számok tömbjét tárolja és kezeli.

---

## Követelmények

### Névtér

* A `Szamok` osztály a `Tarolo` névtérben helyezkedjen el.
* A `main.cpp`-ben **ne** használj `using namespace Tarolo` utasítást.

---

## Osztály: Szamok

### Adattagok

* **Lebegőpontos számok** dinamikusan foglalt tömbje
* A tömb méretét a konstruktor paraméterben kapja meg.
* A konstruktor második paramétere egy alapérték, amelyet minden elem felvesz (alapértelmezett érték: `0`).

### Konstruktor

* Paraméterek:

  * `méret` (unsigned int)
  * `alapérték` (float, alapértelmezett: 0)
* A konstruktor foglalja le a szükséges memóriát.

### Destruktor

* Szabadítsa fel az előzőleg lefoglalt memóriát.

### Függvények

#### darabLeker

* Adja vissza az eltárolt értékek számát.

#### ertekBeallit

* Paraméterek:

  * index
  * új érték
* Beállítja a tömb adott helyén lévő értéket.
* **Érvénytelen index** esetén a függvény **ne csináljon semmit**.

#### ertekLeker

* Paraméter:

  * index
* Visszaadja a tömb adott helyén lévő számot.
* **Érvénytelen index** esetén a függvény **-10^8** értékkel tér vissza.

---

## Main.cpp követelmények

### Kiir függvény

* Készíts egy `kiir` függvényt, amely paraméterben kap egy `Szamok` objektumot.
* Jelenítse meg a tárolt értékeket **egy sorban, vesszővel elválasztva**.

### Main függvény

* Hozz létre **két `Szamok` objektumot**.
* Töltsd fel őket értékekkel.
* Jelenítsd meg az értékeket a **kiir függvény** segítségével.

---

## Megjegyzések

* Dolgozz gondosan a dinamikus memóriakezeléssel (`new` és `delete`).
* Ne használj `using namespace Tarolo` a `main`-ben.

