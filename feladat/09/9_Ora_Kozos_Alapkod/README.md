# Feladat – Sablonos Tömb Osztály

## 1. rész

A feladat teszteléséhez a mellékelt projekt tartalmaz egy `main` függvényt.

### Feladat: `Tomb` osztály

Készíts egy sablonos `Tomb` osztályt, amely egy statikus tömböt valósít meg objektum-orientált formában. Az osztály a következő módon működik:

- Két sablonparamétere van:
  - Az első egy típus, amely meghatározza a tárolt adatok típusát.
  - A második egy egész szám, amely megadja a tömb méretét.

- Az osztály:
  - Tároljon egy megfelelő típusú és méretű **statikus tömböt** (nem szükséges dinamikus memóriafoglalás).
  - Feltételezhető, hogy a tárolt típusnak van paraméter nélküli konstruktora.

### Függvények

Készítsd el az osztályhoz az alábbi tagfüggvényeket:

- `meret()` – visszaadja a tömb méretét.
- `beallit(index, ertek)` – beállítja a tömb adott indexű elemét a megadott értékre. Érvénytelen index esetén ne csináljon semmit.
- `leker(index)` – visszaadja a tömb adott indexű elemének másolatát (az index helyességét nem kell ellenőrizni).
- `elem(index)` – visszaadja a tömb adott indexű elemét **referenciaként**, így az módosítható. Az index helyességét nem kell ellenőrizni.
  - Készíts egy **konstans verziót** is, amely konstans referenciát ad vissza.
- Ha már mennek az operátorok, akkor implementáld a `[]` operátort is **két verzióban**, ugyanezzel a funkcionalitással.

---

## 2. rész

Az első részben elkészített kód folytatása. Ebben a részben **közös ősosztályt** készítünk az azonos típusú tömböknek.

### Feladat: `TombAlap` osztály

- Készíts egy sablonos `TombAlap` osztályt, amelynek egyetlen sablonparamétere a tárolt adat típusa.
- Az osztálynak **nem lesz adattagja**, interfészként szolgál az azonos típusú tömbök kezelésére.

### Függvények

A következő függvények legyenek **tisztán virtuálisak** az osztályban:

- `meret()`
- `beallit(index, ertek)`
- `leker(index)`
- `elem(index)`
  - A `[]` operátor is lehet tisztán virtuális, de **jobb megoldás**, ha **nem virtuális**, hanem meghívja a `elem()` függvényt, ami ugyanazt csinálja.

### A `Tomb` osztály módosítása

- Származzon a megfelelő típusú `TombAlap` osztályból.
- A sablonparaméterek közül csak a **típust** örökölje (a méret ne számítson az ősosztály szempontjából).

---

## `main.cpp` kiegészítése

- Készíts egy `tombKiir` nevű sablonfüggvényt:
  - Sablonparamétere egy típus.
  - Paramétere egy mutató egy ilyen típusú elemeket tároló `TombAlap` példányra.
  - A függvény jelenítse meg a tömb elemeit.

- Készíts egy másik verziót is:
  - Ez **referenciaként** kapja a `TombAlap` példányt, nem mutatóként.
