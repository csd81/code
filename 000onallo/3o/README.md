 
# Rendezveny és Szamsor Projekt

## Feladatleírás

A projekt célja egy dinamikus tömböt kezelő `Szamsor` osztály és abból származtatott `Rendezveny` osztály elkészítése, valamint kiegészítő funkciók implementálása.

---

## Kiindulás

* A projekt már tartalmaz előkészített kódokat (`main` függvény, `Szamsor` és `Szemely` osztály).
* Bizonyos feladatoknál a meglévő kódokhoz is hozzá kell nyúlni.
* A `main` függvényben a nem használt kódokat ki lehet kommentezni.

---

## Osztályok

### Szamsor Osztály

* **Típus**: Dinamikusan foglalt tömb egész számokból
* **Méret**: A konstruktorban megadott méret
* **Funkciók**:

  * Alapvető függvények a tömb kezeléséhez
* **Memóriakezelés**:

  * Ügyelj rá, hogy a lefoglalt memória felszabadításra kerüljön.

### Rendezveny Osztály

* **Származtatás**: `Szamsor` osztályból
* **Specifikum**:

  * A dinamikus tömb **7 méretű** (egy-egy szám a hét minden napjához)
  * Tartalmaz egy `Szemely*` típusú mutatót, amely a **kiemelt vendéget** tárolja (opcionális).
* **Funkciók**:

  * **kiir()** – kiírja az összes adatot.
  * **másoló konstruktor** – helyes memóriakezeléssel.
  * **legjobbNap()** – kiírja, hogy a rendezvény **hanyadik napján** volt a legnagyobb a létszám.
  * **Kiemelt vendég kezelése**:

    * Kiemelt vendéget lehessen beállítani és lekérdezni.

---

## Main.cpp követelmények

### kisebbAtlag függvény

* Paraméterben két `Szamsor` objektumot kap.
* Kiszámítja és kiírja:

  * az első, vagy a második paraméterben eltárolt számok **átlaga nagyobb-e**, vagy **azonosak**.

---

## Memóriakezelés

* Minden dinamikusan foglalt memóriát megfelelően szabadíts fel.

---

## Összefoglalás

| Komponens            | Követelmény                                                                             |
| -------------------- | --------------------------------------------------------------------------------------- |
| `Szamsor` osztály    | Dinamikus tömb, alapműveletek                                                           |
| `Rendezveny` osztály | Származtatás, fix méretű tömb, kiemelt vendég, kiir(), másoló konstruktor, legjobbNap() |
| `kisebbAtlag`        | Átlag-összehasonlítás `main.cpp`-ben                                                    |
 