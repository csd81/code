 
# EpicToolbox – Tarolo Osztály

## Feladatleírás

Ebben a projektben egy `Tarolo` nevű osztályt kell megvalósítani, amely egész számokat tárol előre meg nem határozott mennyiségben. Az osztály különböző konstruktorokat és metódusokat tartalmaz, amelyekkel az adatok kezelhetők, kiírhatók, módosíthatók és összehasonlíthatók.

---

## Követelmények

### Általános

* A `Tarolo` osztály az `EpicToolbox` névtérben helyezkedjen el.
* Elképzelhető, hogy a specifikációban nem szereplő, de szükséges kiegészítő metódusokat is implementálni kell a megoldás során.

---

## Osztály: Tarolo

### Konstruktorok

1. **Paraméteres konstruktor**

   * Bemenet: egy egész szám (db)
   * Művelet: létrehoz egy tömböt `db` mérettel, feltöltve 1-től kezdődő értékekkel (1, 2, 3, …).

2. **Alapértelmezett konstruktor**

   * Művelet: bekéri a felhasználótól a méretet, majd a tömb elemeit is beolvassa.

### Destruktor

* Felszabadítja a dinamikusan lefoglalt tömböt.

---

## Metódusok

### kiir()

* Megjeleníti az eltárolt számokat egy sorban.

### hozzaad(int)

* Új értéket fűz a tömb végére.
* A tömb méretét eggyel megnöveli.

### atlag()

* Visszaadja a tárolt számok átlagát.

### tartomany()

* Kiszámítja és visszaadja a legnagyobb és legkisebb érték közti különbséget.

### rendez(bool)

* Rendezést végez.

  * Ha a paraméter értéke **true**, akkor növekvő sorrendbe.
  * Ha **false**, akkor csökkenő sorrendbe rendezi a tömb elemeit.

### hozzafuz(const Tarolo &)

* Egy másik `Tarolo` objektum elemeit fűzi hozzá az aktuális tároló végére, sorrendet megtartva.

### darabLeker()

* Visszaadja az aktuálisan eltárolt értékek számát (szükséges a `kisebbTarolo` függvényhez).

---

## Globális függvények

### kisebbTarolo(const Tarolo &, const Tarolo &)

* Összehasonlít két `Tarolo` objektumot.
* Visszatérési érték:

  * `1`, ha a második objektumnak van kevesebb eleme
  * `-1`, ha az elsőnek van kevesebb eleme
  * `0`, ha megegyezik a méretük

---

## main.cpp

* Hozz létre két `Tarolo` objektumot a két konstruktorral.
* Töltsd fel őket értékekkel.
* Írasd ki az értékeket `kiir()` használatával.
* Hívd meg és jelenítsd meg a következő függvények eredményét:

  * `kisebbTarolo(...)`
  * `tartomany()`
  * `rendez(...)`
  * `hozzafuz(...)`

---

## Megjegyzések

* Használj dinamikus memóriakezelést (`new[]`, `delete[]`) helyesen.
* Törekedj az objektumorientált szemléletmódra és hatékony implementációra.

 
