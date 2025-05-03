Feladat 

• A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat (**main** függvény és **Datum** osztály). 
A megoldás során ezekhez a kódokhoz nem kell nyúlni (kivéve ha a feladat kéri), de a 
teszteléshez a main függvényben a nem használt kódokat ki lehet kommentezni. 

• Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra. 

• Készíts egy **Hatarido** osztályt, ami tárolja egy szoftver nevét (egy szöveg, ami akár szóközöket is 
tartalmazhat), és a különböző verzióihoz tartozó kitűzött határidőket. Három verzióhoz tárolunk 
határidőt  (Datum típus): **alpha, beta,** és **végső**,  de  nem  biztos  hogy  mindegyik  határidőt 
meghatároztuk  (tipp:  dinamikusan foglalva kezeljük az időpontokat, három mutatót  tárolva).  A 
konstruktor csak a szoftver nevét várja. 

• Legyen  a  névhez  és  az  időpontokhoz lekérdező  és  beállító  függvény 
(**getNev, setNev,  getAlphaDatum, setAlphaDatum, getBetaDatum, setBetaDatum, getVegsoDatum, setVegsoDatum**). 

• Legyen a  **Hatarido** osztályban egy statikus adattag is, ami az aktuális dátumot tárolja (ez mindig 
létezik, nem kell mutató). Az értéke kezdetben legyen a mai nap. Legyen hozzá beállító és lekérő 
függvény (**setAktualisDatum, getAktualisDatum**). 

• A  **Hatarido**  osztályban  legyen  egy  lejart  metódus,  amely  a  kimenetre  kiírja  az  összes  olyan 
határidőt, ami lejárt (a határidő  előbb  van,  mint  az  aktuális  dátum).  Célszerű a **Datum**  osztályt 
kiegészíteni egy metódussal, ami összehasonlít kettő dátumot. 

• A bejegyzett határidőket lehessen  törölni  is  egy  **hataridoTorol**  metódus  segítségével,  amely 
megkapja paraméterben hogy melyik határidőt törölje. 

• Készíts másoló konstruktort a **Hatarido** osztályhoz

----
A feladat lényege egy `Hatarido` nevű C++ osztály létrehozása, amely szoftververziókhoz tartozó határidőket kezel, a következő követelményekkel:

---

### 🧱 **Osztálystruktúra: `Hatarido`**

#### 🧾 **Adattagok**

* `string nev` – a szoftver neve
* `Datum* alpha` – `Datum` típusú pointer, lehet `nullptr`
* `Datum* beta`
* `Datum* vegso`
* `static Datum aktualisDatum` – statikus, minden példányra közös

#### 📦 **Konstruktor**

* Csak a szoftver nevét kapja meg
* A három dátum pointer legyen `nullptr` alapból

#### 🔧 **Függvények**

* `string getNev() const`
* `void setNev(const string&)`
* `Datum* getAlphaDatum() const`, stb. mindhárom dátumhoz getter/setter
* `static void setAktualisDatum(const Datum&)`
* `static Datum getAktualisDatum()`
* `void lejart() const` – kiírja azokat a dátumokat, amik az `aktualisDatum` előtt vannak
* `void hataridoTorol(string tipus)` – pl. `"alpha"` string alapján törli a megfelelő határidőt (`delete` és `nullptr`)
* Másoló konstruktor, amely mély másolatot készít a három dátumról

#### ➕ **Datum osztály bővítés**

* `bool kisebbMint(const Datum& masik) const` – dátum összehasonlítás

---

### 💡 Megjegyzések

* A memóriakezelés fontos: minden dinamikusan foglalt `Datum`-ot megfelelően kell törölni.
* A `lejart()` függvényben használható pl. `alpha != nullptr && alpha->kisebbMint(aktualisDatum)`.

---

Szeretnéd, hogy készítsek ehhez egy teljes `Hatarido.h` és `Hatarido.cpp` implementációt, vagy egy példát a másoló konstruktorra és a `lejart()` metódusra?


Here's an ASCII class diagram for the `Hatarido` class based on the assignment specifications:

```
+--------------------------------------------------+
|                    Hatarido                      |
+--------------------------------------------------+
| - nev: std::string                               |
| - alpha: Datum*                                  |
| - beta: Datum*                                   |
| - vegso: Datum*                                  |
| - static aktualisDatum: Datum                    |
+--------------------------------------------------+
| + Hatarido(nev: std::string)                     |
| + Hatarido(const Hatarido& other)                |
| + ~Hatarido()                                    |
|                                                  |
| + getNev(): std::string                          |
| + setNev(n: const std::string&)                  |
| + getAlphaDatum(): Datum*                        |
| + setAlphaDatum(d: Datum*)                       |
| + getBetaDatum(): Datum*                         |
| + setBetaDatum(d: Datum*)                        |
| + getVegsoDatum(): Datum*                        |
| + setVegsoDatum(d: Datum*)                       |
|                                                  |
| + static getAktualisDatum(): Datum               |
| + static setAktualisDatum(d: const Datum&)       |
|                                                  |
| + lejart(): void                                 |
| + hataridoTorol(tipus: std::string): void        |
+--------------------------------------------------+
```

Let me know if you'd like a similar diagram for the `Datum` class or a UML version.
