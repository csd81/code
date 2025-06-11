
# 📘 Vektor Osztály Projekt

## Feladatleírás

A feladatban egy `Vektor` osztályt kell megvalósítani, amely egy matematikai vektort ábrázol.

Az osztály:

* tárolja a vektor méretét (`darab`),
* illetve a megfelelő mennyiségű lebegőpontos számot tároló dinamikus tömböt.

A konstruktor paraméterként a vektor méretét kapja meg.

**Fontos:** minden lefoglalt memória felszabadításáról gondoskodni kell a destruktorban!

---

## Implementálandó operátorok

### Alapműveletek

* (a) `+`
  Két vektor összeadása.
  Visszatérési érték: új vektor.

* (b) `+=`
  Egy másik vektor hozzáadása a jelenlegihez.
  Visszatérési érték: a módosított vektor.

* (c) `+`
  Egy szám és egy vektor összeadása, ahol a szám a bal oldalon áll.
  Visszatérési érték: új vektor, amely az eredeti vektor elemeit a számmal megnövelve tartalmazza.

* `=`
  Másik vektor értékeinek átmásolása a jelen vektorba.

* `--` prefix és postfix
  Minden vektor elem csökkentése eggyel.

* `<<`
  A vektor elemeinek kiírása a megadott kimeneti folyamra.

---

### Kiegészítő műveletek

Implementáld a következő operátorokat is, a (c) pontban leírt elvek szerint:

* `-`, `/`, `*`
  Két vektor közötti kivonás, osztás, szorzás.

* `-=`, `/=`, `*=`
  Ugyanezek in-place változatai.

* Szám és vektor műveletek, ahol a szám a bal oldalon van:
  `-`, `/`, `*`

* Szám és vektor műveletek, ahol a szám a jobb oldalon van:
  `+`, `-`, `/`, `*`

---

### Egyéb speciális operátorok

* `++` prefix és postfix
  Minden vektor elem növelése eggyel.

* `[]`
  Egy adott indexű elem referenciaként való elérése és módosítása.

* `[] const`
  Egy adott indexű elem konstans referenciaként való elérése.

* `^`
  Két vektor skaláris szorzata (dot product).

* `*` (unáris)
  A vektor hossza.

* `~` (unáris)
  A normalizált vektor (hossz = 1).

* `==`
  Két vektor egyenlőségének ellenőrzése (azonos elemszám és azonos elemek).

* `!=`
  Két vektor egyenlőtlensége.

* `<`
  Két vektor összehasonlítása:
  igaz, ha a két vektor azonos elemszámú, és minden elem bal oldalon < jobb oldali elem.

---

## Megjegyzés

* A feladat elkezdéséhez mellékelt projekt tartalmaz kódokat.
* A megoldás során bizonyos esetekben módosítani kell ezeket a kódokat.
* A `main()` függvényben a teszteléshez a nem használt kódokat ki lehet kommentezni.

---

## Fontos technikai követelmények

✅ Memória helyes kezelése (lefoglalt memória felszabadítása)
✅ Konstans függvények megfelelő használata
✅ Hatékony és tiszta C++ kód írása
✅ Minden operátorra kiterjedő teljes funkcionalitás
✅ `main.cpp` fájlban tesztelni kell az összes operátort!

---

## Tesztelés

A `main.cpp` fájlban minden operátorra külön blokkban kell tesztkódot írni.
Például:

* `Vektor teszt: operator +`
* `Vektor teszt: operator +=`
* `Vektor teszt: operator + számmal balról`
* stb.

