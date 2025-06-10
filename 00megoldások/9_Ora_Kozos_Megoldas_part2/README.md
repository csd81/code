# Feladatleírás - Sablonos Tomb osztály

## 1. rész

A feladat teszteléséhez a mellékelt projekt tartalmaz egy `main` függvényt.

### Követelmények:

- Készíts egy sablonos `Tomb` osztályt, amely egy statikus tömböt valósít meg objektum-orientált formában.
  - 2 sablon-paramétere van:
    - Az első egy típus, hogy milyen típusú adatokat tároljon a tömb.
    - A második egy egész szám, hogy hány eleme legyen a tömbnek.
  - Az osztály tároljon egy megfelelő típusú és méretű tömböt (statikus tömbként, nem kell dinamikus memóriafoglalás).
  - Feltételezhetjük, hogy a tárolt típusnak van paraméter nélkül hívható konstruktora.

### Implementálandó függvények:

- `meret`: visszaadja a tömb méretét.
- `beallit`: megkap egy indexet és egy értéket, és beállítja a tömb adott indexű elemét a kapott értékre (érvénytelen indexre ne csináljon semmit).
- `leker`: megkap egy indexet, és visszaadja a tömb adott indexű elemét (pontosabban egy másolatot), az index helyességét nem kell ellenőrizni.
- `elem`: megkap egy indexet, és visszaadja a tömb adott indexű elemét referenciaként (ezáltal a függvényen keresztül akár módosítható is lesz), az index helyességét nem kell ellenőrizni.
  - Az `elem` függvényhez készíts egy konstans verziót is, ami konstans referenciát ad vissza.
  - Ha már mennek az operátorok, akkor elkészíthető a `[]` operátor is két verzióban, ugyanezzel a funkcionalitással.

---

## 2. rész

Az első részben elkészített kód folytatása. Ebben a részben közös ősosztályt készítünk az azonos típusú tömböknek.

### Követelmények:

- Készíts egy sablonos `TombAlap` osztályt, aminek az egyetlen sablon paramétere a tárolt adat típusa lesz.
- Az osztálynak adattagja nem lesz, csak egy interfészként szolgál az azonos típusú tömbök kezelésére.
- A `meret`, `beallit`, `leker`, és `elem` függvények mind legyenek tisztán virtuális függvények az osztályban.
  - Ha van `[]` operátor, azt szintén meg lehet csinálni tisztán virtuálisnak. De még jobb, ha nem virtuális, hanem meghívja a virtuális `elem` függvényt, ami ugyanazt csinálja.

### Módosítások:

- A `Tomb` osztályt módosítsd úgy, hogy származzon abból a `TombAlap` osztályból, ami ugyanazzal a sablonparaméterrel rendelkezik (típus), függetlenül a tömb méretétől.

### További követelmény:

- Készíts a `main.cpp`-be egy `tombKiir` függvényt, melynek sablon paramétere egy típus legyen, a függvény paramétere pedig egy mutató egy ilyen típusú elemeket tároló `TombAlap`-ra. A függvény jelenítse meg a tömb elemeit.
- A `tombKiir` függvényből készíts egy másik verziót, ami referenciaként kapja a paramétert, és nem mutatóként.
