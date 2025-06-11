

# Dobóverseny Projekt

## Feladatleírás

A feladat egy **dobóverseny** adatait tároló és feldolgozó program elkészítése.

* A verseny adatainak kezeléséhez a `Probalkozas` és `Verseny` osztályokat kell elkészíteni.
* A programban **std::vector** és **fájlkezelés** eszközöket is használni kell.

---

## Alapkiindulás

* A mellékelt **verseny1.txt** szöveges fájlt a projekt **build könyvtárába** kell másolni.

* Az írt kimeneti fájlok is ugyanebben a könyvtárban fognak megjelenni.

* Minden olyan függvény, amely **lehet const**, legyen is az.

---

## Probalkozas osztály

### Tárolt adatok

* versenyző neve (`string`)
* dobott távolság (`double`)
* dobás érvényes volt-e (`bool`)

### Követelmény

* Legyen benne **paraméter nélküli konstruktor**:

  * név: `"ismeretlen"`
  * távolság: `0`
  * érvényesség: `false`

### Cél

* Szükséges a `vector<Probalkozas>` teljeskörű működéséhez.

---

## Main.cpp követelmények

### Előkészületek

A `main` függvény elején, jelölt helyen:

1. Hozz létre egy **3 elemes** `vector<Probalkozas>` tárolót.
2. Írasd ki a tartalmát `kiirProbalkozasVektor` függvénnyel.
3. Írd át a 3 elem értékét tetszőleges `Probalkozas` adatokra.
4. Méretezd át a tárolót **5 eleműre**.
5. Ismét írasd ki a tartalmát.

---

## Verseny osztály

### Adattagok

* megnevezés (`string`)
* `vector<Probalkozas>` — a próbálkozásokat tároló vektor

### Kötelező függvények

#### Konstruktor

* Paraméter: fájl elérési út (`string`)
* A fájl elején:

  * verseny megnevezése
  * majd soronként az egyes próbálkozások adatai:

    * név (string, whitespace nélkül)
    * dobás távolság (double)
    * érvényesség (bool)

#### kiir() függvények

1. Első verzió:

   * kiírja a verseny nevét + a próbálkozásokat `std::cout`-ra.

2. Második verzió:

   * paraméterként kap egy tetszőleges **kimeneti folyamot** (ostream).
   * oda írja a kiírást.

3. Harmadik verzió:

   * paraméter: fájl elérési útja (string).
   * az adott nevű fájlba írja a kiírást (felülírja annak tartalmát).

#### uj() függvény

* Paraméterek:

  * versenyző neve (string)
  * dobás távolság (double)
  * érvényesség (bool)
* Művelet: új `Probalkozas` beszúrása a vektor végére.

#### ervenyesDobasok() függvény

* Visszatérési érték: `vector<double>`.
* Tartalma: az **összes érvényes dobott távolság**.

#### nevSzerint() függvény

* Paraméterek:

  * versenyző neve (string)
  * referenciaként kapott `vector<Probalkozas>`.
* Művelet:

  * **törli** a kapott vektor tartalmát.
  * feltölti az adott versenyzőhöz tartozó próbálkozásokkal.

---

## Main.cpp további feladatok

* A `main` függvény **megadott helyén**:

  * kérdezd le az **érvényes dobásokat** → írd ki.
  * kérdezd le egy versenyző próbálkozásait `nevSzerint` → írd ki.

---

## Speciális megjegyzések

* A versenyző neve és a verseny megnevezése **nem tartalmaz whitespace-t**.
* A bemeneti fájlból való beolvasás a fájl végéig történik.

---

## Összegzés

### Implementálandó osztályok és függvények:

| Osztály / függvény | Követelmény                                |
| ------------------ | ------------------------------------------ |
| Probalkozas        | paraméter nélküli konstruktor              |
| Probalkozas        | getter függvények                          |
| Verseny            | konstruktor fájlból                        |
| Verseny            | kiir() — 3 verzió                          |
| Verseny            | uj()                                       |
| Verseny            | ervenyesDobasok()                          |
| Verseny            | nevSzerint()                               |
| Main.cpp           | vector<Probalkozas> kezelése (resize stb.) |
| Main.cpp           | kiirProbalkozasVektor használat            |
| Main.cpp           | ervenyesDobasok és nevSzerint tesztelés    |

