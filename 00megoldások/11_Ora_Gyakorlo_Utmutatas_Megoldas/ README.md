 
# Vasúti járműkezelő rendszer



## Feladatleírás

A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat.
A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.

---

## Követelmények

### Vehicle osztály

* Készíts egy absztrakt `Vehicle` osztályt, amely vasúti járműveket reprezentál.
* A járműveknek legyen:

  * egy azonosítója (`string`),
  * egy tömege (`int`),
  * egy sebessége (`int`),
  * egy tisztán virtuális `getType` metódus, ami visszaadja a típusát (`string`).
* Az osztálynak legyen egy konstruktora, amely a típuson kívül minden más tulajdonságot megkap paraméterben és beállítja azokat.
* Legyen virtuális destruktor.
* Szükséges getterek: `getId`, `getMass`.

### Származtatott osztályok

#### Engine

* A `mozdonyt` reprezentálja.
* Legyen egy plusz tulajdonsága, amely a mozdony által elvontatható tömeget adja meg (`int`).
* A típus szövege: `"ENGINE"`.

#### FreightCar

* A `tehervagonokat` írja le.
* Legyen egy plusz tulajdonsága, amely a tehervagonban szállítható termékek mennyiségét adja meg (`int`).
* A típus szövege: `"FreightCar"`.

#### PassengerCar

* A `személykocsikat` írja le.
* Legyen egy plusz tulajdonsága, amely a szállítható utasok számát adja meg (`int`, `getPassengerCount`).
* A típus szövege: `"PassengerCar"`.

### print metódus

* Készíts a `Vehicle` osztályba egy tisztán virtuális `print` metódust.
* A metódus:

  * Ne legyen visszatérési értéke.
  * Ne várjon semmit paraméterben.
  * Az egyes járművek tulajdonságait írja ki a standard kimenetre.
* Valósítsd meg a `print` metódust a gyerekosztályokban.

---

## TrainManager osztály

* Hozz létre egy `TrainManager` osztályt, amely a vasúti járműveink kezelését valósítja meg.
* Az osztály:

  * Egy vektorban (`vector<Vehicle*>`) tárolja a járműveinket, amiket egyenként dinamikusan kell foglalnunk.
  * A tároló kezdetben üres.

### Metódusok

#### addVehicle

* Paraméterben egy járművet vár (`Vehicle*`) és hozzáadja a tárolóhoz.

#### printAll

* Kiírja a járművek adatait.
* Ehhez használja a járművek `print` metódusát.

---

## TrainSet osztály

* Készíts egy `TrainSet` osztályt, amely egy szerelvényt reprezentál.
* A szerelvény:

  * Járművekből áll, ezeket egy vektorban tároljuk (`vector<Vehicle*>`).
* Az osztálynak legyen egy konstruktora, amely a járművek vektorát várja paraméterben — ezek lesznek a szerelvény járművei.

### Metódusok

#### getEngine

* Visszatér a szerelvényben lévő mozdonnyal (`Engine*`).
* Ha nincs, vagy egynél több mozdony van, akkor `nullptr`.

#### engineCanTow

* Azon tér vissza, hogy a szerelvény mozdonya el tudja-e vontatni a vagonokat a tömegük alapján.
* Feltételezhetjük, hogy egy mozdony van.
* A mozdony saját tömegét nem kell beleszámolni.

#### isValid

* Visszaadja, hogy a szerelvény érvényes-e.
* Akkor teljesül, ha:

  * pontosan egy mozdony van,
  * legalább egy vagon,
  * és a mozdony el tudja vontatni a vagonokat.

#### printAll

* Kiírja a járműveket abban a szerelvényben.

---

## TrainManager bővítése

### Szerelvények tárolása

* Módosítsd a `TrainManager` osztályt úgy, hogy szerelvényeket is tudjon tárolni tetszőleges mennyiségben (`vector<TrainSet*>`).

### coupleSet

* Paraméterben várja a járművek vektorát.
* Ezekből összeállít egy szerelvényt és eltárolja azt.
* Csak érvényes szerelvényt lehet eltárolni, különben a szerelvényt azonnal törölni is kell.
* Megjegyzés: az egyszerűség kedvéért a felhasznált járműveket nem kell kitörölni a járművek tárolójából (minden vagon és mozdony többször is felhasználható).

### printSets

* Kiírja a tárolt szerelvények adatait.
* Ehhez a `TrainSet` osztályban is ajánlott csinálni egy `printAll` metódust.

### searchSet

* Paraméterben egy mozdony azonosítóját kapja meg (`string`).
* Ez alapján visszaadja a szerelvényt (`TrainSet*`).
* Ha nem találja a szerelvényt, akkor `nullptr`.

### decoupleSet

* Egy szerelvényt vár paraméterben (`TrainSet*`).
* Eltávolítja azt a szerelvények közül.

### removeVehicle

* Egy járművet vár paraméterben.
* Eltávolítja azt a tároltak közül (a szerelvényekben lévőkkel nem kell foglalkozni).

---

## Megjegyzés

> A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat.
> A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.

