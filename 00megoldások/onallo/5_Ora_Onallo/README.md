# 2D pontok és tárolók kezelése

---

## Cél

A feladat célja különböző típusú 2D pontokból álló halmazok kezelése, pontokkal műveletek végzése, fájlból beolvasás és fájlba írás, valamint speciális származtatott osztályok (Útvonal, Háromszög, Téglalap, Sokszög) implementálása.

---

## Osztályok és specifikáció

---

### 1–5. Pont osztály

Adattagok:

* x, y koordináta (double)
* statikus M korlát (double, kezdetben 106)

Követelmények:

1. Paraméter nélküli konstruktor → origó (0,0)
2. Statikus M, setM(), getM()
3. Koordináták M ellenőrzése konstruktorban → figyelmeztetés + koordináták kiírása
4. Másoló konstruktor is figyeli az M korlátot
5. Warnings.log fájlba is kerül az M korlát túllépése (std::ios::app)

Egyéb:

* getX(), getY() getterek
* kiir() ostream-re
* tavolsag(p1,p2) — statikus metódus

---

### 6–12. Halmaz osztály

Adattagok:

* megnevezes (string)
* vector<Pont> pontok

Követelmények:

6. Konstruktor: megnevezés
7. Konstruktor: megnevezés + elemszám → default origó pontok
8. hozzaad(Pont)
9. hozzaad(x, y) függvénytúlterhelés
10. kiir(): megnevezés, elemszám, pontok
11. beolvas(fajl): pontok beolvasása fájlból
12. fajlbair(fajl): pontok mentése fájlba, beolvasható formátumban

---

### 13–16. Utvonal osztály (Halmazból származtatva)

Adattagok:

* bool irany (kezdetben true)

Követelmények:

13. Konstruktor: megnevezés → "PATH", pontok üresek
14. megfordit() → irany változó ellentettjére állítása
15. kiir(): ha irany == false → pontok fordított sorrendben
16. hossz() → szomszédos pontok távolságainak összege

---

### 17–19. Haromszog osztály (Halmazból származtatva)

Követelmények:

17. Konstruktor: 3 Pont → "TRIANGLE"
18. getA(), getB(), getC()
19. alak():

* "hegyesszogu", ha D < -1e-8
* "derekszogu", ha -1e-8 ≤ D ≤ 1e-8
* "tompaszogu", ha D > 1e-8
  (D = z² - (v² + w²), z a leghosszabb oldal)

---

### 20–22. Teglalap osztály (Halmazból származtatva)

Követelmények:

20. Konstruktor: (xmin, xmax, ymin, ymax) → "RECTANGLE", 4 csúcs
21. terulet() → téglalap területe
22. tartalmaz(Pont) → pont belül van-e (kerületen is igen)

---

### 23–25. Sokszog osztály (Halmazból származtatva)

Követelmények:

23. Konstruktor: megnevezést vár → tetszőleges számú pont
24. kerulet(): pontok közti távolságok összege + első–utolsó között is
25. bennfoglalo(): minimális Teglalap, ami tartalmazza a Sokszöget

---

## További megjegyzések

* Memóriakezelés: nincs dinamikus memóriafoglalás → RAII biztosított
* warnings.log kezelése: std::ios::app módban, nem töröljük a fájl tartalmát
* Fájlok:

  * beolvasásnál az első sorban pontok száma, utána x y koordináták

---

## Követelményellenőrzés

| Specifikáció pont | Megvalósítva |
| ----------------- | ------------ |
| Pont (1–5)        | Igen         |
| Halmaz (6–12)     | Igen         |
| Utvonal (13–16)   | Igen         |
| Haromszog (17–19) | Igen         |
| Teglalap (20–22)  | Igen         |
| Sokszog (23–25)   | Igen         |

---

## Összefoglalás

Ez a projekt gyakoroltatja:

* absztrakt gondolkodás → Halmaz mint általános tároló
* származtatás → Utvonal, Haromszog, Teglalap, Sokszog
* statikus adattagok → M a Pontban
* statikus metódusok → tavolsag
* fájlkezelés → beolvasás, kiírás
* polimorfizmus (kiir() felüldefiniálása)
* figyelmeztetések naplózása (warnings.log)

