
# ♟️ Sakkfigura Projekt

## 📋 Feladatleírás

A feladatban egy `Figura` osztály hierarchiát kell megvalósítani, amely a különböző sakkfigurák (bástya, király, futó, vezér, huszár) pozícióját és lépéslogikáját modellezi.

A mellékelt projekt tartalmaz kezdeti kódokat — ezekhez bizonyos feladatoknál hozzá kell nyúlni.
A `main.cpp` fájlban a teszteléshez a nem használt kódokat ki lehet kommentezni.

---

## 🗂️ Alaposztály: `Figura`

A `Figura` osztály egy sakkfigura adatait tárolja:

* az oszlop és a sor, ahol a figura van
  → egy darab szöveg, két karakterrel, pl.: `"A5"` vagy `"G2"`

A pozíciót a konstruktorban kapja meg.

### Memória kezelés

* Ügyelj arra, hogy minden lefoglalt memória felszabadításra kerüljön!

### Függvények

#### `static bool ervenyes(const string &pos)`

* Megkap egy pozíciót szövegként
* Megmondja, hogy a pozíció **érvényes-e**
* Érvényes pozíció:

  * két karakterből áll
  * első karakter nagybetű (`'A'` - `'H'`)
  * második karakter számjegy (`'1'` - `'8'`)

#### `virtual bool lephet(const string &pos) const = 0`

* Tisztán virtuális függvény
* Megmondja, hogy a figura léphet-e a megadott **érvényes** pozícióra
  *(A pozíció érvényességét feltételezzük.)*

#### `bool odalep(const string &pos)`

* Megkap egy pozíciót
* Ha a pozíció érvényes **ÉS** a figura léphet oda:

  * a figura pozícióját átállítja ide
  * `true`-val tér vissza
* Ha nem: `false`

#### `virtual char jeloles() const = 0`

* Tisztán virtuális függvény
* Visszaadja a figurához tartozó **egy karakteres jelölést**:

  * bástya → `'B'`
  * király → `'K'`
  * futó → `'F'`
  * vezér → `'V'`
  * huszár → `'H'`

---

## ♜ Bástya (`Bastya` osztály)

* A **Figura** osztályból származik.

### Lépéslogika:

* vízszintesen vagy függőlegesen bármennyit léphet
* **nem maradhat helyben**

### Függvények:

* `bool lephet(const string &pos) const`
* `char jeloles() const` → `'B'`

---

## ♚ Király (`Kiraly` osztály)

* A **Figura** osztályból származik.

### Lépéslogika:

* bármilyen irányba **egy mezőt** léphet (összesen 8 lehetőség)
* **nem maradhat helyben**

### Függvények:

* `bool lephet(const string &pos) const`
* `char jeloles() const` → `'K'`

---

## ♝ Futó (`Futo` osztály)

* A **Figura** osztályból származik.

### Lépéslogika:

* **átlósan** bármennyit léphet
* **nem maradhat helyben**

### Függvények:

* `bool lephet(const string &pos) const`
* `char jeloles() const` → `'F'`

---

## ♛ Vezér (`Vezer` osztály)

* A **Figura** osztályból származik.

### Lépéslogika:

* tud **bástya**- és **futó**-módon is lépni:

  * vízszintesen, függőlegesen vagy átlósan bármennyit léphet
* **nem maradhat helyben**

### Függvények:

* `bool lephet(const string &pos) const`
* `char jeloles() const` → `'V'`

---

## ♞ Huszár (`Huszar` osztály)

* A **Figura** osztályból származik.

### Lépéslogika:

* **"L" alakban** léphet:

  * 2 mezőt az egyik irányba, 1 mezőt a másik irányba
* **nem maradhat helyben**

### Függvények:

* `bool lephet(const string &pos) const`
* `char jeloles() const` → `'H'`

---

## 🧪 Tesztelés

* A `main.cpp` fájl végén lévő kód teszteli az osztályokat.
* Az alábbi osztályokat ellenőrzi:

  * `Figura` (ervenyes, odalep, jeloles)
  * `Bastya`
  * `Kiraly`
  * `Futo`
  * `Vezer`
  * `Huszar`

**A gyaloggal nem kell foglalkozni, mert az több egyéb dologtól is függ!**

---

## ⚠️ Fontos technikai követelmények

✅ Memória helyes kezelése

✅ Konstans függvények helyes használata

✅ Virtuális metódusok / öröklés helyes használata

✅ Teljes funkcionalitás implementálása

✅ `main.cpp`-ben az összes lépés tesztelése

