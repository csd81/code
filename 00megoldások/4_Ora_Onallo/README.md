 

# DatumLista Projekt

## Feladatleírás

A projekt célja egy **DatumLista** osztály elkészítése, amely `Datum` típusú dátumokat tárol, kezeli, valamint speciális műveleteket valósít meg a dátumokkal.
A `Datum` és `DatumLista` osztályok a **Naptar névtérben** helyezkednek el.

---

## Alapkiindulás

* A mellékelt projekt már tartalmaz kódokat:

  * `main.cpp`
  * `Datum` osztály
* Bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni.
* A `main` függvényben a nem használt kódokat ki lehet kommentezni.

---

## Követelmények

### Általános

* Ügyelj rá, hogy **minden lefoglalt memória megfelelően felszabadításra kerüljön**.

### Névtér

* A meglévő `Datum` osztály, valamint a készítendő `DatumLista` osztály legyenek a **Naptar** névtérben.

---

## Osztályok

### Datum Osztály

* Tárolt adatok:

  * év
  * hónap
  * nap
* Kötelező metódusok:

  * **Alapértelmezett konstruktor** is legyen (mert a `DatumLista` osztályban szükség van rá).
  * Getter és setter függvények a fenti adatokhoz.

### DatumLista Osztály

#### Tárolt adatok

* Dinamikusan foglalt tömb `Datum` típusból.
* Dátumok darabszáma → konstruktorban paraméterként kapja meg.
* **Megjegyzés** (szöveg, akár szóközökkel) → konstruktorban paraméterként kapja meg.
* **Statikus adattag** → a tömb maximális méretét tárolja.

  * Alapértéke: **6**.

#### Kötelező metódusok

* **Konstruktor** → dátumok száma + megjegyzés

* **Destruktor** → memória felszabadítása

* **Másoló konstruktor** → helyes memóriakezeléssel

* Getter és setter metódusok:

  * `setMegjegyzes`, `getMegjegyzes`
  * `setDatum`, `getDatum`

    * **setDatum** esetén az indexet ellenőrizni kell.
    * **getDatum** esetén nem kell az indexet ellenőrizni.
  * `getDarab` → dátumok darabszáma

* `hozzaad` metódus:

  * Paraméter: egy `Datum`.
  * A dátumot hozzáadja a tárolóhoz.
  * A tömb méretét csak akkor növeli, ha az új méret **nem haladja meg** a `maxDarab` értékét.

* `legkorabbi` metódus:

  * Visszaadja a tárolt dátumok közül a **legkorábbit**.
  * Feltételezhetjük, hogy van legalább egy dátum az osztályban.

* Statikus adattag kezelés:

  * `getMaxDarab`
  * `setMaxDarab`

  **Megjegyzés:** ha a `setMaxDarab` metódussal a maximumot utólag **kisebbre állítjuk**, mint az aktuális elemszám, ezzel most **nem kell foglalkozni** (nem kell törölni az elemeket).

---

## Main.cpp követelmények

* A `main`-ben a fenti metódusok használatával tesztelni kell az osztályok működését.
* A `main` függvény felépítése a mellékelt minta szerint:

  * Létrehozás
  * Megjegyzés beállítása
  * Dátumok bekérése és beállítása
  * Másolat készítése
  * Dátumok hozzáadása
  * Legkorábbi dátum lekérdezése
  * Statikus `maxDarab` tesztelése (set, get)

---

## Memóriakezelés

* Minden **dinamikusan foglalt memória** felszabadítása kötelező:

  * `DatumLista` destruktora oldja meg.
