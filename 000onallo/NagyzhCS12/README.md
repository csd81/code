
# Feladat

- A feladat elkezdéséhez a mellékelt projekt tartalmaz `main` függvényt. A teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni, de módosítani azokat nem szabad.
- A feladathoz csak azokat a függvényeket készítsd el, amiket a feladat kér, illetve ami ezen felül feltétlenül szükséges a helyes működéshez.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
- A nem forduló kód 0 pont.
- A feladatban a fájlrendszeren található fájlokhoz kell egy egyszerű osztályszerkezetet elkészíteni.

## 1. `Fajl` osztály

Készíts egy `Fajl` osztályt, amely a fájlok általános adatait tárolja:
- fájl neve (szöveg),
- mérete (egész),
- fontossága (egész).

### Követelmények:

- Konstruktor várja az adatokat.
- Legyenek a következő get függvények:
  - `getNev`
  - `getMeret`
  - `getFontos`
- Legyen setter a fontosságra:
  - `setFontos`
- Legyen egy **tisztán virtuális** `adatok()` függvény, amely kiírja a fájl adatait a szabályok szerint.  
  *(2 + 1 pont)*


## 2. `SzovegesFajl` osztály

Származtass egy `SzovegesFajl` osztályt a `Fajl`-ból, amely új adatként tárolja a szöveges fájl tartalmát (szöveg).

### Követelmények:

- Konstruktor várja az új adatot is.
- Legyen `getTartalom` getter.  
  *(3 pont)*

### a) `adatok()` függvény:

- Ha a fontosság legalább 5: jelenjen meg minden adat (név, méret, tartalom).
- Különben csak a fájlnév.  
  *(2 pont)*

### b) `+=` operátor:

- Jobb oldalán egy szöveg.
- Azt fűzze hozzá a tartalomhoz.  
  *(2 pont)*

### c) Statikus adattag:

- Tárolja az elérési útvonalat.
- Kezdetben üres szöveg.
- Legyen:
  - `setUtvonal`
  - `getUtvonal`  
  *(3 pont)*

### d) `adatok()` módosítása:

- A fájlnév elé tegye az elérési útvonalat és `'/'` jelet.
- Ha az útvonal üres, akkor nem kell `'/'`.  
  *(2 pont)*

---


## 3. `KepFajl` osztály

Származtass egy `KepFajl` osztályt a `Fajl`-ból, amely új adatként tárolja:
- kép szélessége (egész),
- magassága (egész).

### Követelmények:

- Konstruktor várja az új adatokat.
- Legyen:
  - `getSzelesseg`
  - `getMagassag`  
  *(3 pont)*

### a) `adatok()` függvény:

- A fájl neve és fontossága mindig jelenjen meg.
- A fájlméret, szélesség, magasság: csak ha a méret legalább 10000.  
  *(2 pont)*

### b) `*` operátor (egyetlen operandus):

- Visszaadja a kép pixeleinek számát.  
  *(2 pont)*

------>

## 4. `Mappa` osztály

Kezeljen tetszőleges mennyiségű fájlt. A fájlokat úgy tárolja, hogy **mindig pontosan annyi hely legyen**, amennyi kell.

### Követelmények:

- Létre kell hozni a megfelelő adattagokat.  
  *(3 pont)*

### a) `getDarab()` függvény:

- Visszaadja a fájlok számát.  
  *(1 pont)*

### b) `<<` operátor:

- Lehetővé teszi új fájl hozzáadását a `main`-ben látható módon.  
  *(4 pont)*

### c) Destruktor:

- Szabadítsa fel a tárolt fájlokat.  
  *(1 pont)*

### d) `tartalom()` függvény:

- Megjeleníti a tömb tartalmát, az egyes fájlok saját `adatok()` függvényét használva.  
  *(2 pont)*

### e) `>` operátor:

- Két mappa esetén igaz, ha a bal oldali mappában a fájlok összmérete nagyobb, mint a jobb oldali mappáé.  
  *(3 pont)*

### f) `[]` operátor:

- Megkap egy fájlnevet (szöveg).
- Igazzal tér vissza, ha van ilyen nevű fájl.
- Különben hamissal.  
  *(4 pont)*
