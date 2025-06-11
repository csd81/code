 

# Számítógépes játék karakterkezelő rendszer
 

---

## Feladatleírás

A feladat teszteléséhez a mellékelt projekt tartalmaz egy `main` függvényt.
Minden más osztályt a feladat során kell megírni.

A feladat során egy számítógépes játék karaktereit kell kezelni, akiket három kasztra lehet osztani:

* harcos
* íjász
* mágus

---

## Követelmények

### Karakter osztály

* Készíts egy `Karakter` osztályt, ami egy absztrakt ősosztály lesz a különböző típusú karakterekhez.
* Az osztály tárolja:

  * a karakter nevét (szöveg)
  * a karakter szintjét (egész)
* Mindkét adatot a konstruktor várja.
* Legyen hozzájuk getter:

  * `getNev`
  * `getSzint`

#### Tisztán virtuális metódusok

A `Karakter` osztálynak három tisztán virtuális metódusa legyen:

* `eletero`: a karakter életerejét adja majd vissza egész számként, az adatokon nem módosít
* `sebzes`: a karakter sebzését adja majd vissza egész számként, az adatokon nem módosít
* `kiir`: megjeleníti majd a karakter adatait, és nem módosít rajtuk

---

### Harcos osztály

* Származtass a `Karakter` osztályból egy `Harcos` osztályt, ami a harcos típusú karaktert valósítja meg.
* Extra adatként a használt fegyver típusát tárolja (szöveg).
* A konstruktor mindhárom adatot várja: név, szint, fegyver.

#### Metódusok

* `eletero`: a harcos életereje alapból **12**, és ez minden egyes szintért **6**-tal növekszik
* `sebzes`: a harcos sebzése alapból **5**, és ez minden egyes szintért **2**-vel növekszik
* `kiir`: megjeleníti az adatokat a minta szerint

---

### Íjász osztály

* Származtass a `Karakter` osztályból egy `Ijasz` osztályt, ami az íjász típusú karaktert valósítja meg.
* Extra adatként a célzás pontosságát tárolja (egész).
* A konstruktor mindhárom adatot várja: név, szint, pontosság.

#### Metódusok

* `eletero`: az íjász életereje alapból **10**, és ez minden egyes szintért **3**-mal növekszik
* `sebzes`: az íjász sebzése alapból **3**, és ez minden egyes szintért **2**-vel növekszik

  * ha a karakter pontossága **legalább 90**, akkor a sebzés **duplázódik**
* `kiir`: megjeleníti az adatokat a minta szerint

---

### Mágus osztály

* Származtass a `Karakter` osztályból egy `Magus` osztályt, ami a mágus típusú karaktert valósítja meg.
* Extra adatként a varázsláshoz rendelkezésre álló **mana** mennyiségét tárolja (egész).
* A konstruktor mindhárom adatot várja: név, szint, mana.

#### Metódusok

* `eletero`: a mágus életereje alapból **8**, és ez minden egyes szintért **3**-mal növekszik, plusz **1 extra életet kap minden 5. manáért** (törtrész nincs)
* `sebzes`: a mágus sebzése alapból **4**, és ez minden egyes szintért **2**-vel növekszik, plusz **3 extra sebzést kap minden 10. manáért** (törtrész nincs)
* `kiir`: megjeleníti az adatokat a minta szerint

---

### Szerver osztály

* Készíts egy `Szerver` osztályt, ami a játékteret valósítja meg.
* A szerver a karakterek tömbjét tárolja (**célszerű `vector` segítségével, de nem kötelező**).
* Mivel minden fajta karaktert egyben kell kezelni, értelemszerűen **`Karakter` mutatók** tömbjét kell tárolni.

#### Destruktor

* A `Szerver` osztály **destruktora szabadítson fel minden lefoglalt memóriát**.

#### betolt()

* A `Szerver` osztálynak legyen egy `betolt` metódusa, amely a `karakterek.txt` fájlból betölti a szerveren játszó játékosokat.
* A fájl több sort tartalmaz, minden sorban egy-egy karakter adataival.
* Minden karakterhez adott:

  * neve
  * kasztja
  * szintje
  * valamint a kaszthoz tartozó extra adat (fegyver, pontosság, vagy mana)
* A bemenetet a `"*"` karakter zárja.

#### listaz()

* A `Szerver` osztálynak legyen egy `listaz` metódusa, amely **kilistázza a játékosokat** (a `Karakter` osztály `kiir` metódusát felhasználva).

#### legtobbElet()

* A `Szerver` osztálynak legyen egy `legtobbElet` metódusa, amely visszaadja a legtöbb élettel rendelkező karaktert (`Karakter*` mutatóként).

#### csata(nev1, nev2)

* Legyen a `Szerver` osztálynak egy `csata` metódusa, amely megkapja **kettő játékos nevét** (szövegek).
* Eldönti, hogy ha ez a két játékos összecsap, akkor **ki lesz a nyertes**.
* Visszaadja a nyertes nevét (szöveg).
  Ha a csata **döntetlen**, akkor az `"X"` szöveget adja vissza.

##### Csata menete

* Mindkét játékosnak van egy életereje és egy sebzése.
* A csata minden körében a játékosok a sebzésüknek megfelelően csökkentik a másik játékos életét.
* Ha valaki élete **0-ra, vagy ez alá** csökken, akkor a másik nyer.
* Ha egyszerre csökken 0-ra (vagy az alá) az életük, akkor **döntetlen**.
* Ha mindketten élnek még, akkor jön a következő kör.
* **Fontos:** a játékosok tárolt adatai nem változhatnak — az "élet csökkenést" **átmeneti adatokkal** kell kezelni.

#### tornaSzimulacio()

* Legyen a `Szerver` osztálynak egy `tornaSzimulacio` metódusa, amely több csatát is végrehajt (az előző `csata` függvényt felhasználva).
* A lejátszandó csatákat a `merkozesek.txt` fájl tárolja.
* A fájlban minden sor két nevet tartalmaz, a két játékos nevét, akik között a csatát le kell futtatni.
* A bemenetet a fájl vége karakter zárja.
* A függvény mindegyik csatát futtassa le, majd az eredményt írja ki az `eredmenyek.txt` fájlba.

##### Kimenet

* A kimeneten ugyanaz az adatszerkezet legyen, mint amit be is olvas.
* Minden sor egészüljön ki egy új adattal:

  * `1`, ha az első játékos nyert
  * `2`, ha a második
  * `0`, ha döntetlen

---

**Forrás:** 10\_Ora\_Onallo\_TXT.pdf
