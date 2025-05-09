# Feladat

A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat. A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.

A megadott osztály a `Szin` osztály, amely nem tárol adattagot, viszont egy absztrakt ősosztály lesz, aminek a gyerekosztályai színeket tárolnak különböző módokon. A színkomponensek kezeléséhez segítséget nyújtó táblázatok a feladat leírás után találhatóak.

> Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.

## Feladatok

- Készíts a `Szin` osztályba három **tisztán virtuális függvényt** `R`, `G`, illetve `B` néven, amelyek a szín három komponensét adják vissza `unsigned char` típusként (0–255 tartományban).
  
- Származtass a `Szin` osztályból egy `RGBSzin` osztályt, amely három `unsigned char` típusként tárolja a szín három (`r`, `g`, `b`) komponensét.  
  - A konstruktor ezeket az értékeket paraméterként várja.
  - Legyen egy paraméter nélküli konstruktor is, amely a fekete színt (`0, 0, 0`) állítja be.
  - Fejtsd ki az `R`, `G` és `B` függvényeket úgy, hogy visszaadják a tárolt értékeket.

- Származtass egy `FeketeFeher` osztályt a `Szin` osztályból, ami egy logikai értéket tárol.
  - Az érték igaz, ha a szín fekete, és hamis, ha fehér.
  - Az osztály konstruktora ezt az értéket várja.
  - Fejtsd ki az `R`, `G` és `B` függvényeket.

- Származtass egy `Szurke` osztályt a `Szin` osztályból, amely lebegőpontos értéket tárol 0 és 1 között.
  - Ez a szürke szín világosságát adja meg (0: fekete, 1: fehér).
  - Fejtsd ki az `R`, `G`, és `B` függvényeket.

- Készíts a `Szin` osztályba egy statikus `szamotHexava` függvényt:
  - Paramétere egy egész szám (0–15).
  - Visszatérési érték a megfelelő hexadecimális karakter (0–F).
  
- Készíts egy hasonló `hexatSzamma` függvényt, amely a fordított átalakítást végzi.

- Készíts egy **virtuális `printCode`** függvényt a `Szin` osztályba:
  - A függvény adja vissza a színt hexadecimális formában (pl. `#E4CB27`).

- Származtass egy `SzovegesSzin` osztályt az `RGBSzin` osztályból:
  - Tároljon egy szöveget, ami a szín megnevezése (pl. `"fekete"`, `"zold"`).
  - A konstruktora csak ezt a szöveget várja, és ennek alapján állítsa be a szín komponenseit.
  - Ha az ismeretlen szöveg, akkor fekete legyen az alapértelmezett szín.
  - A konstruktor fogadjon el hexadecimális kóddal megadott színt is (`'#'` karakterrel kezdve).
  - Írd felül a `printCode` függvényt, hogy a tárolt szöveges megnevezést adja vissza.

- Készíts egy `megegyezik` függvényt a `Szin` osztályba:
  - Paraméterként egy másik színt kap (referenciaként).
  - Igaz értékkel tér vissza, ha a komponensek megegyeznek, egyébként hamissal.

- Az `RGBSzin` osztálynak készíts egy olyan konstruktort, amely paraméterként egy tetszőleges színt vár, és a komponenseket ennek megfelelően állítja be.

---

## Segítség a színek kezeléséhez

- Az `r`, `g`, `b` értékek 0 és 255 között változnak (mint az `unsigned char`).
- Hexadecimális kód: mindig `#` karakterrel kezdődik, és 16-os számrendszerben tárolja az `r`, `g`, `b` értékeket sorrendben, mindegyikhez 2 karaktert használva.

### Színek, amiket a `SzovegesSzin` osztály felismerhet

| Név       | Értékek (R,G,B)  | Hexadecimális |
|-----------|------------------|----------------|
| fekete    | (0,0,0)          | `#000000`      |
| feher     | (255,255,255)    | `#FFFFFF`      |
| kek       | (0,0,255)        | `#0000FF`      |
| zold      | (0,255,0)        | `#00FF00`      |
| piros     | (255,0,0)        | `#FF0000`      |
| cian      | (0,255,255)      | `#00FFFF`      |
| magenta   | (255,0,255)      | `#FF00FF`      |
| sarga     | (255,255,0)      | `#FFFF00`      |

### Egyéb hexadecimális példák

| Értékek (R,G,B)   | Hexadecimális |
|-------------------|----------------|
| (120,65,234)      | `#7841EA`      |
| (6,54,15)         | `#06360F`      |
| (212,200,253)     | `#D4C8FD`      |
| (128,96,177)      | `#8060B1`      |
