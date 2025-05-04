# Feladat leírása

A feladat teszteléséhez a mellékelt projekt tartalmaz egy `main` függvényt, valamint egy `Esemeny` osztályt. Az `Esemeny` osztály egy esemény (rendezvény) adatait tárolja:

- név (szöveg),
- dátum (szöveg),
- kezdési idő (egész szám),
- befejezési idő (egész szám),
- résztvevők száma (egész szám).

Feltesszük, hogy minden esemény egész órakor kezdődik és ér véget. Az osztályhoz tartozik:

- paraméter nélküli konstruktor,
- valamint egy olyan konstruktor, ami minden adatot vár,
- minden adathoz van setter és getter.

## Teendők

- Töltsd le, és add a projekthez a `json.hpp` fájlt.
- Készíts egy `Helyszin` osztályt, ami egy rendezvény szervező helyszín adatait tárolja. Az osztályban:
  - tárolja a helyszín nevét és címét (szövegek),
  - valamint az itt rendezett eseményeket (célszerű `vector` használatával, de lehet dinamikus tömb is).
  - Konstruktor nem szükséges.

## `Helyszin` osztály metódusai

- `betolt(fajlnev: string)`:  
  Ez a metódus egy fájl nevét kapja paraméterként. A fájl JSON formátumú, és tartalmazza az összes adatot (név, cím, események tömbje). A metódus olvassa be a fájlt, és töltse fel az osztály adatait.

- `kiir()`:  
  Ez a metódus megjeleníti az osztály adatait a standard kimenetre a megadott minta alapján.

- `esemenyHosszKiir(fajlnev: string)`:  
  Ez a metódus egy fájl nevet kap paraméterként. A metódus a kapott fájlba JSON formátumban listázza ki, hogy melyik esemény milyen hosszú (hány órán keresztül tart).  
  A JSON fájl tartalma egy tömb legyen, melynek minden eleme egy esemény nevét és hosszát tartalmazza.
