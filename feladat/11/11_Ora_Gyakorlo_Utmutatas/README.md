# Gyakorló feladat – Tervezés  
## Vasúti járműkezelő rendszer (tervezés)

A vállalatunk egy vasúti járműkezelő rendszert kíván fejleszteni.  
A rendszer célja, hogy lehetővé tegye a különböző típusú vasúti járművek (mozdonyok, személyszállító kocsik, tehervagonok stb.) kezelését és nyomon követését.

---

## Vasúti járműtípusok

A vasúti járműveknek különböző típusai lehetnek:
- **Mozdonyok**
- **Személyszállító vagonok**
- **Tehervagonok**

### Közös nyilvántartott adatok minden járműnél:
- Azonosító
- Tömeg
- Engedélyezett maximális sebesség

### Típus-specifikus adatok:
- **Személyvagonok**:
  - Kapacitás (hány utast tud elszállítani)
- **Tehervagonok**:
  - Maximálisan szállítható áruk tömege
- **Mozdonyok**:
  - Maximálisan elvontatható szerelvény tömege (a mozdony saját tömege nem számít bele)

---

## Funkcionális követelmények

A rendszernek képesnek kell lennie a következő műveletek elvégzésére:

### 1. Új jármű felvitele
- Új járművek rögzítése a nyilvántartásban

### 2. Jármű selejtezése
- Létező jármű eltávolítása a rendszerből

### 3. Szerelvény összeállítása
- Minden szerelvény:
  - Pontosan **1 mozdonyból**
  - Legalább **1 vagonból** áll
- Csak akkor hozható létre, **ha a mozdony képes elvontatni a vagonokat** (az **üres** vagonok tömege számít)
- Sikeres szerelvénylétrehozás esetén visszajelzés szükséges

### 4. Szerelvény felbontása
- Létező szerelvény szétbontása

### 5. Szerelvények tulajdonságainak megjelenítése
- A szerelvény minden járművének tulajdonságát listázni kell

---


# Gyakorló feladat – Útmutatás  
## Vasúti járműkezelő rendszer (útmutatás)

A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat. A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.

---

## Feladatok

### 1. Vehicle osztály
- Készíts egy **absztrakt `Vehicle` osztályt**, amely vasúti járműveket reprezentál.
- Adattagok:
  - `id` (string)
  - `mass` (int)
  - `speed` (int)
- Legyen egy **tiszta virtuális `getType()` metódus**, ami visszaadja a típusát (string).
- Legyen egy **konstruktor**, amely a típuson kívül minden más tulajdonságot beállít.
- Legyen **virtuális destruktor**.
- Későbbi feladatokhoz **getterek** is kellenek: `getId`, `getMass`.

### 2. Származtatott osztályok
Származtass a `Vehicle` osztályból három alosztályt:

- **`Engine`**
  - Reprezentálja a mozdonyt.
  - Plusz adattag: `towingCapacity` (int)
  - `getType()` visszatérési értéke: `"ENGINE"`

- **`FreightCar`**
  - Tehervagonokat írja le.
  - Plusz adattag: `freightCapacity` (int)
  - `getType()` visszatérési értéke: `"FreightCar"`

- **`PassengerCar`**
  - Személykocsikat írja le.
  - Plusz adattag: `passengerCount` (int)
  - `getType()` visszatérési értéke: `"PassengerCar"`
  - Getter: `getPassengerCount()`

### 3. `print()` metódus
- A `Vehicle` osztályba kerüljön egy **tiszta virtuális `print()` metódus**, amely nem tér vissza és nem vár paramétert.
- A metódus a jármű tulajdonságait írja ki a standard kimenetre.
- A `print()` metódust **valósítsd meg az összes gyermekosztályban**.

---

## 4. TrainManager osztály
- Valósítsd meg a `TrainManager` osztályt, amely a vasúti járműveket kezeli.
- Adattag: `vehicles` – `vector<Vehicle*>` (dinamikusan foglalt járművek, kezdetben üres)

### Metódusok:
- `addVehicle(Vehicle*)`: hozzáadja a járművet a tárolóhoz.
- `printAll()`: kiírja az összes jármű adatait (`print()` használatával).

---

## 5. TrainSet osztály
- A `TrainSet` osztály egy szerelvényt reprezentál.
- Adattag: `vehicles` – `vector<Vehicle*>` (a szerelvény járművei)
- Konstruktor: a járművek vektorát kapja meg paraméterként.

### Metódusok:
- `getEngine()`: visszaadja a mozdonyt (`Engine*`), ha pontosan egy van, egyébként `nullptr`.
- `engineCanTow()`: visszaadja, hogy a mozdony el tudja-e vontatni a vagonokat (a saját tömege nélkül).
- `isValid()`: visszaadja, hogy a szerelvény érvényes-e (pontosan egy mozdony, legalább egy vagon, és vontathatóság rendben van).

---

## 6. TrainManager bővítése szerelvényekkel
- A `TrainManager` tároljon szerelvényeket is: `vector<TrainSet*>`

### Új metódusok:
- `coupleSet(vector<Vehicle*>)`:
  - Létrehoz egy szerelvényt a megadott járművekből.
  - Csak érvényes szerelvényt tárol el, különben azonnal törli.

- `printSets()`:
  - Kiírja a tárolt szerelvények adatait.
  - Ehhez a `TrainSet` osztályban javasolt egy `printAll()` metódus, ami kiírja a szerelvény járműveit.

- `searchSet(string engineId)`:
  - Keres egy szerelvényt a mozdony azonosítója alapján, visszaadja (`TrainSet*`), vagy `nullptr` ha nem találja.

- `decoupleSet(TrainSet*)`:
  - Eltávolítja a megadott szerelvényt.

- `removeVehicle(Vehicle*)`:
  - Eltávolítja a járművet a tárolóból.
  - A szerelvényekben lévő példányokat nem kell kezelni.


