 <!--

# Szemely és Hallgato Osztályok

## Feladatleírás

A projekt célja egy **örökléses osztályhierarchia** megvalósítása a `Szemely` és `Hallgato` osztályok segítségével.
A `Szemely` osztály alapvető személyes adatokat kezel, a `Hallgato` osztály pedig további hallgatói adatokat tárol és kiegészítő funkciókat valósít meg.

---

## Projektindítás

* A projekt már tartalmaz előkészített kódokat (`main` függvény és `Szemely` osztály).
* A megoldás során ezekhez a kódokhoz **hozzá kell nyúlni**, ha szükséges.
* A teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.

---

## Osztályok

### Szemely Osztály

* Tárolt adatok:

  * Vezetéknév (`string`)
  * Keresztnév (`string`)
  * Életkor (`unsigned int`)
* Függvények:

  * `kiir()` → kiírja a személy adatait.
  * `fiatalabb(const Szemely&)` → visszaadja, hogy az aktuális objektum **fiatalabb-e** a paraméterben kapott személynél.

### Hallgato Osztály

* **Származtatott osztály**, azaz öröklődik a `Szemely`-ből.
* További tárolt adatok:

  * Neptun-kód (`string`)
  * Befejezett félévek száma (`unsigned int`), **alapértelmezett érték: 1**
  -->
* Függvények:

  * **Getter minden adathoz**, setter csak a `felevek` mezőhöz.
  * `kiir()` → **felülírja** az ősosztály `kiir()` függvényét, felhasználva az ősosztály megvalósítását is.
  * `furcsa()` → visszaadja, hogy a hallgató **fiatalabb-e**, mint ahogy a féléveinek száma sugallja.
    (Egy hallgató jellemzően legalább **18 éves**, amikor az első félévét kezdi.)

---

## Memóriakezelés

* Ügyelj rá, hogy minden **lefoglalt memória megfelelően felszabadításra** kerüljön.

---

## Összefoglalás

A projektben implementálandó fő komponensek:

| Komponens             | Követelmény                                   |
| --------------------- | --------------------------------------------- |
| `Szemely` osztály     | Alapvető adatok és metódusok                  |
| `Hallgato` osztály    | Öröklés, bővített adatok, speciális metódusok |
| `furcsa()` metódus    | Speciális logika a kor-félév arányra          |
| `fiatalabb()` metódus | Összehasonlító logika                         |

 
