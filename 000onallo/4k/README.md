 

* Ügyelj arra, hogy **minden lefoglalt memória** megfelelően felszabadításra kerüljön.

* Készíts egy `Hatarido` osztályt, ami:

  * tárolja a **szoftver nevét** (string, akár szóközöket is tartalmazhat),
  * tárolja a különböző verziókhoz tartozó kitűzött határidőket:

    * `alpha`, `beta`, és `végső` verzióhoz.
    * Típus: `Datum`
    * Nem biztos, hogy mindegyik határidőt meghatároztuk → **dinamikus tárolás**, 3 mutatóval.
  * A konstruktor csak a **szoftver nevét** várja.

## Kötelező metódusok

### Név és határidők beállítása / lekérdezése

* `getNev`, `setNev`
* `getAlphaDatum`, `setAlphaDatum`
* `getBetaDatum`, `setBetaDatum`
* `getVegsoDatum`, `setVegsoDatum`

### Aktuális dátum

* A `Hatarido` osztályban legyen egy **statikus adattag**, ami az **aktuális dátumot** tárolja.

  * Ez az adattag mindig létezik, nem kell mutató.
  * Kezdeti értéke: **mai nap**.
  * Legyen hozzá:

    * `setAktualisDatum`
    * `getAktualisDatum`

### Lejárat ellenőrzése

* A `Hatarido` osztályban legyen egy `lejart` metódus, amely:

  * a kimenetre kiírja az összes olyan határidőt, ami **lejárt** (azaz a határidő **előbb van**, mint az aktuális dátum).
  * Célszerű a `Datum` osztályt kiegészíteni egy metódussal, ami **összehasonlít két dátumot**.

### Határidő törlése


* A bejegyzett határidőket lehessen törölni egy `hataridoTorol` metódus segítségével, amely:

  * paraméterben megkapja, hogy **melyik határidőt törölje**.

### Másoló konstruktor

* Készíts **másoló konstruktort** a `Hatarido` osztályhoz.

---

## Megjegyzések

* A `Datum` osztályhoz adj hozzá egy `kisebbMint` metódust, amely **összehasonlít két dátumot**.
* A dinamikusan foglalt memóriákat (határidő mutatók) gondosan kezeld, a másoló konstruktorban is!

 
