 

# Egyetem – Tantárgy Jegyek Kezelése

## Feladatleírás

A feladat célja egy program készítése, amely három tantárgy eredményeit tárolja és elemzi. A tantárgyakhoz tartozó jegyek dinamikusan foglalt tömbben vannak, és különféle műveletek hajthatók végre rajtuk.

---

## Követelmények

### Általános

* Dolgozz **referenciákkal** és **konstansokkal**, ahol lehetséges.
* A struktúra és minden függvény a `egyetem` **névtérben** helyezkedjen el.
* Gondoskodj a `main()`-ben való használhatóságról a megfelelő `using` deklarációval.

---

## Adatszerkezet

### Tantárgy Struktúra

* `kod` – tantárgy kódja (`std::string`, szóköz nélküli)
* `db` – jegyek száma (`unsigned int`)
* `jegyek` – `unsigned int*`, dinamikus tömb

---

## Funkcionalitások

### 1. Tantárgyak létrehozása és beolvasása

* A program **fixen 3 tantárgy** eredményeit tárolja.
* Minden tantárgyhoz:

  * Kérd be a **jegyek számát**.
  * Foglalj helyet a dinamikus **jegytömbnek**.
  * Olvasd be a **jegyeket**.

### 2. Megjelenítés

* Készíts egy függvényt, amely egy tantárgy **összes adatát kiírja**.
* Ezzel jelenítsd meg a **három tantárgy** adatait.

### 3. Jegyátlag számítás

* Készíts egy függvényt, amely egy tantárgyat kap, és visszaadja a **jegyek átlagát**.

### 4. Legjobb átlag keresése

* Használd az előző függvényt, és **keresd meg** azt a tantárgyat, amelyiknél a legnagyobb az átlag.
* Jelenítsd meg az adott tantárgy **adatait**.

### 5. Jegyek tömbjének újraméretezése

* Készíts egy függvényt, amely:

  * megkap egy tantárgyat és egy új méretet (`unsigned int`)
  * **újrafoglalja** a jegytömböt a megadott méretre
  * ha csökken a méret → utolsó jegyek elvesznek
  * ha nő a méret → új értékek mind **5-ösök**

* Minden tantárgyhoz kérj be egy számot (új méret), és hívd meg ezt a függvényt.

### 6. Alternatív verzió: két váltakozó értékkel

* Készíts a fenti függvényből egy **második verziót**, amely további két paramétert vár (pl. `2` és `4`)
* Ha a tömb mérete nő:

  * az új jegyek **felváltva**: `2, 4, 2, 4, ...`

### 7. Memória felszabadítás

* Készíts egy függvényt, amely megkap egy tantárgyat, és **felszabadítja a tömböt**.
* A program végén hívd meg ezt a függvényt minden tantárgyra.

---

## Megjegyzés

* Használj `new` és `delete[]` műveleteket helyesen.
* Tartsd be a konstans referenciahasználatot, ahol indokolt.

 