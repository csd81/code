
# Doboz Program – Feladatleírás

## Áttekintés

A program célja, hogy téglatest alakú dobozokat kezeljen, adataikat tárolja, és különböző műveleteket végezzen rajtuk: például felszín, térfogat számítása, új dobozok hozzáadása, beleférés ellenőrzése, forgatás stb.

---

## Követelmények

### Általános

* Használj **referenciákat** és **konstansokat**, ahol csak lehet.
* A **struktúra** és a szükséges függvények kerüljenek a `doboz` **névtérbe**.
* Gondoskodj a megfelelő `using` deklarációkról, hogy a `main()`-ben a kód működjön.

---

## Adatszerkezet

* **Struktúra**:

  * `nev` : `std::string` (szóköz nélküli)
  * `szelesseg`, `magassag`, `hosszusag` : `unsigned int`

---

## Funkcionalitások

### 1. Dinamikus tárolás

* Kérdezd le, **hány doboz** adatát tárolja a program.
* **Foglalj helyet** ennyi doboz számára.
* Olvasd be a dobozok adatait.

### 2. Megjelenítés

* Készíts egy függvényt, amely **kiírja a dobozok adatait** egy tömbből.

### 3. Felszín és térfogat

* Készíts egy függvényt, amely megkap egy dobozt, és kiírja:

  * a **felszínét**
  * a **térfogatát**

### 4. Tömb bővítése

* Készíts egy függvényt, amely:

  * megkapja a dobozok tömbjét és egy `int` értéket.
  * újrafoglalja a tömböt, **megnöveli a méretét** a megadott számmal.
* Kérj be egy számot, és **növeld meg a tömb méretét** a függvény segítségével.
* Olvasd be az **új elemeket**, majd írasd ki a **teljes tömb** tartalmát.

### 5. Beleférés ellenőrzése

* Készíts egy függvényt, amely:

  * megkap **két dobozt**
  * visszaadja, hogy **bármelyik doboz belefér-e** a másikba (elforgatás **nélkül**)
* Készíts egy **másik verziót**, amely:

  * megkap **egy dobozt** és 3 különálló méretet
  * visszaadja, hogy **belefér-e** az adott helyre (elforgatás **nélkül**)

### 6. Doboz forgatása

* Készíts egy függvényt, amely:

  * megkap egy dobozt
  * **elforgatja**: szélesség ⇄ magasság ⇄ hosszúság

### 7. Memória felszabadítása

* **Szabadítsd fel** a lefoglalt memóriát a program végén.

---

## Tippek

* Használj `new` / `delete` műveleteket helyesen.
* Tartsd meg az **eredeti sorrendet** a kiírásoknál.
* A függvényeket külön fájlba is szervezheted (`.cpp` + `.h`).

 