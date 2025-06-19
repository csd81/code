

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
