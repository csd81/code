
# Színkezelő Projekt 

## 📚 Feladat

A feladat célja egy színkezelő osztályhierarchia létrehozása, ahol a `Szin` absztrakt ősosztályból különböző típusú színeket reprezentáló osztályokat származtatunk.

A projekt kódjai a mellékelt `main()` függvényből tesztelhetők.

---

## 🏗 Osztályok

### 🟢 Szin (absztrakt ősosztály)

* Nem tartalmaz adattagot
* 3 tisztán virtuális metódus:

  * `R()`: piros komponens (0..255)
  * `G()`: zöld komponens (0..255)
  * `B()`: kék komponens (0..255)
* Egyéb metódusok:

  * `szamotHexava(i)` — int → hexa karakter (0..15 → '0'..'F')
  * `hexatSzamma(c)` — hexa karakter → int (0..15)
  * `printCode()` — hexaszínkód (pl. "#E4CB27")
  * `megegyezik(sz)` — két szín megegyezik-e komponensenként

---

### 🟠 RGBSzin (Szin leszármazott)

* Tárolt adattagok: `unsigned char r, g, b`
* Konstruktorok:

  * `RGBSzin(r, g, b)` — beállítja a komponenseket
  * `RGBSzin()` — fekete szín
  * `RGBSzin(const Szin &sz)` — másik szín komponenseit másolja
* `R()`, `G()`, `B()` metódusok: komponensenkénti visszaadás

---

### ⚫⚪ FeketeFeher (Szin leszármazott)

* Tárol egy logikai értéket:

  * `true` → fekete
  * `false` → fehér
* Konstruktor:

  * `FeketeFeher(bool fekete)`
* `R()`, `G()`, `B()` → 0 vagy 255 ennek megfelelően

---

### ⚪⚫ Szurke (Szin leszármazott)

* Tárolt adattag: `double vilagos` (0..1)
* Konstruktor:

  * `Szurke(double vilagos)`
* `R()`, `G()`, `B()` → vilagos \* 255 (mindhárom komponens ugyanaz)

---

### 🟣 SzovegesSzin (RGBSzin leszármazott)

* Tárolt adattag: `string szoveg`
* Konstruktor:

  * `SzovegesSzin(const string &sz)`

    * Ismert színek:

      * `"fekete"` → (0,0,0)
      * `"feher"` → (255,255,255)
      * `"kek"` → (0,0,255)
      * `"zold"` → (0,255,0)
      * `"piros"` → (255,0,0)
      * `"cian"` → (0,255,255)
      * `"magenta"` → (255,0,255)
      * `"sarga"` → (255,255,0)
    * Hexaszín formátum: `"#RRGGBB"`
    * Ismeretlen színnév → fekete
* `printCode()` → a szöveget adja vissza (nem hexakód!)

---

## ⚙️ Használat — tesztelés

A `main.cpp` tartalmaz teszteseteket a következőkre:

* RGBSzin konstruktora, destruktora
* FeketeFeher tesztelése
* Szurke tesztelése
* SzovegesSzin tesztelése névvel és hexakóddal
* printCode() helyes működése
* megegyezik() metódus működése
* RGBSzin másoló konstruktor működése

---

## 🛠 Memóriakezelés

* Minden `new` után megfelelő `delete` hívások történnek → nincs memóriafolyás.

---

## 💻 Hexaszínek konverziója

Példák:

| R, G, B érték | Hexakód |
| ------------- | ------- |
| (120,65,234)  | #7841EA |
| (6,54,15)     | #06360F |
| (212,200,253) | #D4C8FD |
| (128,96,177)  | #8060B1 |

---

## ✅ Követelményellenőrzés

| Követelmény                                 | Megvalósítva |
| ------------------------------------------- | ------------ |
| Szin osztály tisztán virtuális metódusokkal | ✅            |
| RGBSzin adattagok, konstruktorok, metódusok | ✅            |
| FeketeFeher logikai alapon működő szín      | ✅            |
| Szurke világosság alapján                   | ✅            |
| SzovegesSzin színnevek és hexakód           | ✅            |
| szamotHexava, hexatSzamma                   | ✅            |
| printCode() mindenhol                       | ✅            |
| megegyezik()                                | ✅            |
| RGBSzin másoló konstruktor                  | ✅            |
| Memóriafelszabadítás                        | ✅            |

---

## 📋 Összefoglalás

Ez a projekt gyakoroltatja:

* **absztrakt osztályok** használatát (Szin)
* **polimorfizmust** (R(), G(), B(), printCode())
* **öröklődést** és **konstruktorláncot**
* **statikus segédfüggvények** kezelését
* **szövegfeldolgozást** hexaszínek konvertálásához
* **memóriakezelést (new/delete)**

