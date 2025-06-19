
# Asszociatív tároló 

## Cél

A feladatban egy általános **asszociatív tárolót** kell megvalósítani.
Az asszociatív tároló **kulcs-érték párokat** tárol, ahol a kulcs egyértelműen azonosítja a hozzá tartozó értéket.
Egy kulcs **csak egyszer** szerepelhet.

A programban a következő elemeket kellett megvalósítani:

---

## KulcsErtekPar

* Sablonos **struktúra**.

* Két sablonparaméter: `KulcsTipus`, `ErtekTipus`.
* Adattagok: `kulcs` és `ertek` — **publikus** adattagok.
* Konstruktorok:

  * **paraméter nélküli** konstruktor
  * **paraméteres** konstruktor, ami a két adattagot beállítja

---

## Asszociativ osztály

* Sablonos osztály, két sablonparaméter: `KulcsTipus`, `ErtekTipus`.
* Tárolás:

  * Dinamikus tömb: `KulcsErtekPar<KulcsTipus,ErtekTipus>[]`.
  * A tömb mérete **dinamikusan változik** (újrafoglalás történik).
* Destruktor: **felszabadítja** a dinamikus tömböt.

### Függvények

#### meret()

* Visszaadja a tárolt kulcs-érték párok számát.

#### keres() *(privát segédfüggvény)*

* Paraméter: kulcs.
* Visszaadja, hogy a kulcs melyik indexen van a tömbben.
* Ha nincs, visszaadja a tömb méretét (mint „nincs” jelzés).

#### beallit()

* Paraméterek: kulcs, érték.
* Ha a kulcs **már szerepel**, frissíti az értéket.
* Ha még **nem szerepel**, hozzáadja az új kulcs-érték párt.

#### kulcsByIndex(index)

* Visszaadja az adott indexen lévő kulcsot.

#### ertekByIndex(index)

* Visszaadja az adott indexen lévő értéket.

#### vane(kulcs)

* Megmondja, hogy szerepel-e a kulcs.

#### ertek(kulcs)

* Visszaadja a kulcshoz tartozó értéket.
* Ha nincs ilyen kulcs: **dummy érték** (paraméter nélküli konstruktorral létrehozva).

#### ertekVagyDefault(kulcs, defErtek)

* Ha a kulcs megtalálható: visszaadja az értéket.
* Ha nincs: a megadott `defErtek` alapértelmezett értéket adja vissza.

#### torol(kulcs)

* Kitörli a kulcs-érték párt, ha létezik.
* Ha nincs ilyen kulcs, nem csinál semmit.

#### operator[](kulcs)

* Visszaadja az értéket **referenciaként**.
* Ha nincs ilyen kulcs:

  * **létrehoz egy új kulcs-érték párt**, dummy értékkel.
  * visszatér az új értékre mutató referenciával.

---

## Main.cpp tesztek

A main.cpp tartalmazza az összes szükséges **tesztesetet**:

* KulcsErtekPar:

  * paraméter nélküli és paraméteres konstruktor kipróbálása
* Asszociativ osztály:

  * konstruktor, meret()
  * beallit(), kulcsByIndex(), ertekByIndex()
  * beallit() → meglévő kulcs értékének frissítése
  * vane() → kulcs jelen van-e
  * ertek() → érték lekérése
  * ertekVagyDefault()
  * torol() → kulcs törlése
  * operator\[] → referenciaként lekérés, új kulcs felvétele is

---

## Ellenőrzési lista

| Funkció                          | Megvalósítva |
| -------------------------------- | ------------ |
| KulcsErtekPar sablonos struktúra | Igen         |
| KulcsErtekPar konstruktorok      | Igen         |
| Asszociativ osztály              | Igen         |
| meret()                          | Igen         |
| keres() (privát)                 | Igen         |
| beallit()                        | Igen         |
| kulcsByIndex()                   | Igen         |
| ertekByIndex()                   | Igen         |
| vane()                           | Igen         |
| ertek()                          | Igen         |
| ertekVagyDefault()               | Igen         |
| torol()                          | Igen         |
| operator\[]                      | Igen         |

---

## Összefoglalás

A feladat eredményeképp létrejött egy **általános asszociatív tároló**, amely a specifikációban megadott összes követelményt teljesíti.

A megoldás:

* általános típusokra működik (`KulcsTipus`, `ErtekTipus`);
* dinamikusan kezeli a memóriát;
* minden szükséges lekérdezési és módosítási műveletet támogat.

A main.cpp programban lefutó tesztek teljeskörűen ellenőrzik a működést.

