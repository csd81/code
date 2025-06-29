<!--
---

## Pontozás

| Részfeladat                                | Pont |
|--------------------------------------------|------|
| 1. Utazások adatszerkezete                 | 4    |
| 2. `TravelAgency` osztály, `loadTrips`, JSON betöltés | 8    |
| 3. `printData` metódus                     | 4    |
| 4. `listTripsBetween` metódus              | 4    |
| 5. Promóciós helyszín kezelése             | 2    |
| 6. `promotedTravels` metódus               | 4    |
| 7. `FilterBase<T>` osztály                 | 2    |
| 8. `filterTrips` metódus                   | 4    |
| 9. `MaxTimeFrom` osztály                   | 4    |
| 10. `listTripsBetween` metódus egy átszállással | 4    |



# Feladat – Nagyzh – FONTOS INFÓK

- A feladat során alkalmazd a megtanult objektum-orientáltsági elveket!
- A fájlokat egy zip-be csomagolva kell feltölteni.

---

## A feladat leírása

A feladatban egy utazási iroda által biztosított utazási lehetőségeket kezeljük. Az iroda képes busz, vonat, illetve repülő utakat foglalni az ügyfelei számára.  
Minden utazáshoz tudjuk:

- melyik városból melyik városba megy (szövegek),
- milyen hosszú az út (percben, egész),
- mennyibe kerül (Ft, egész).

Az egyszerűség kedvéért dátumokat és menetrendet most nem kezelünk.

**Busz út esetén**:
- tervezett pihenők száma és össz ideje (egészek, az út hosszában ez is benne van).
**Vonat út esetén**:
- megállók száma (egész).

**Repülő út esetén**:
- osztály (szöveg).

Az ősosztály neve legyen `Trip`.

---

### TravelAgency osztály

Az utazási irodát a `TravelAgency` osztály valósítsa meg, mely tárolja az iroda által használható utazási opciókat.

- Legyen benne egy `loadTrips` metódus, amely paraméterben egy JSON fájl nevét kapja, és onnan betölti az utazási opciókat.

- Legyen az utazásokban egy **virtuális `printData` metódus**, amely kilistázza az adataikat. Minden osztályban megfelelően legyen kifejtve.


- A `TravelAgency` osztályban legyen egy `listTripsBetween` metódus, amely paraméterben megkap egy kiindulási és egy érkezési várost, és kilistáz minden utazási opciót a kettő között (a megfelelő irányban).

---

### Promóciós helyszínek kezelése

Az utazási irodák szövetsége minden hónapban kijelöl egy **promóciós helyszínt**, és az oda foglalt utakhoz kedvezményt ad.

- A `TravelAgency` osztályban legyen egy **statikus városnév** eltárolva, amely az iroda aktuális promóciós helyszínét adja meg.
- A `getPromotedLocation` és `setPromotedLocation` metódusokon keresztül lehessen lekérdezni és beállítani.
- Kezdetben legyen üres, ami azt jelenti, hogy nincs kijelölt város.
- Legyen egy `promotedTravels` metódus, amely kilistáz minden olyan utat, amely az aktuális promóciós helyszínre megy.

---

### Szűrés

- Legyen egy `FilterBase<T>` nevű sablonos osztály, mely rendelkezik egy tisztán virtuális  
  `bool match(const T &value) const` metódussal.
- Az osztály célja, hogy logikai visszatérési értékű szűrési feltételt lehessen készíteni tetszőleges típusú adatokhoz.
 
- A `TravelAgency` osztályban legyen egy `filterTrips` metódus, amely egy paraméterben egy szűrési feltételt kap (ezzel az ősosztállyal jelölve), ami kilistáz minden olyan utazási lehetőséget, amely a feltételeknek megfelel.

**TIPP**:  
Mivel a függvénnyel az utazási lehetőségeket szűrjük, ami tetszőleges lehet, a feltételt **ősosztály mutatóra (`Trip*`)** adjuk meg.

---

### MaxTimeFrom osztály

- Legyen egy `MaxTimeFrom` osztály, ami eltárol egy kiindulási várost, valamint egy maximális utazási időt (az adatokat konstruktorban várva).
- Az osztály a `FilterBase<T>` osztályból származzon úgy, hogy ezt alkalmazva szűrésnek (az előző feladat `filterTrips` metódusában) azon utazások jelenjenek meg, amelyek:
  - a megadott kiinduló városból indulnak,
  - és nem hosszabbak, mint a megadott maximális utazási idő.

**TIPP**:  
A `match` függvény pontos formátumát célszerű a `main.cpp`-beli tesztkódból másolni, mert elég kötött módon kell létrehozni.

--->

### Átszállásos utak

A `listTripsBetween` metódust módosítsd úgy, hogy amennyiben nem talál közvetlen utat a két város között:
- jelezze ezt,
- majd keressen meg és listázzon ki minden **1 átszállásos** utat.

Ha ilyet sem talál, nem kell tovább keresni.

void TravelAgency::listTripsBetween(const string &from, const string &to)
{

    for (auto t: trips){
       if (t->getSource()==from && t->getDest()==to)
            t->printData();
    }
}
--->
