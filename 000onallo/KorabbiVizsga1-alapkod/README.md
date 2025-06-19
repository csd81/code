<!-- 

# Feladat – NagyZH

- A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat. A megadott `main.cpp` fájlt módosítani nem lehet, de segít a tesztelésben.
- A feladatban egy számítógépes alkatrészeket áruló bolt kezdetleges rendszerét kell elkészíteni.
- A megoldás során figyelj a tanult elvekre (konstans, referencia, memóriakezelés).
- Az 1a és 1b feladatok kötelezőek, de a többi között is lehet ráépülés.

## A feladatok:

### 1. Absztrakt ősosztály

a. Készíts egy `Alkatresz` osztályt, amely az absztrakt ősosztály lesz az alkatrészek tárolásához.  
Ne felejtsd el a megfelelő destruktort sem.  
Az osztály tárolja az alkatrész gyártóját és típusát (szövegek), amelyeket a konstruktor ilyen sorrendben meg is kap.  
Mindkettőhöz legyen getter (`getGyarto`, `getTipus`). **(3 pont)**

b. Az osztályban legyen 1 tisztán virtuális függvény `ar` metódus, amely paramétert nem vár, nem módosítja a belső adatokat, és visszatér az alkatrész árával (egész). **(1 pont)**

c. Az osztályban legyen egy virtuális `kiir` metódus, amely a standard kimenetre kiírja az alkatrész gyártóját, típusát, valamint az árát, sortöréssel a végén (lásd `minta-stdout.txt`). Az adatokon nem módosít. **(2 pont)**

### 2. `Processzor` osztály

Származtass az `Alkatresz` osztályból egy `Processzor` osztályt.  
Új adatként tárolja a processzor órajelét és a magok számát (egészek).  
Legyen hozzájuk getter is (`getOrajel`, `getMagok`).  
A konstruktor paraméterben várja az ősosztály két adatát, és a két új adatot is.  
Az `ar` metódus adja vissza a processzor árát: `órajel * 11 + magok * 16000`. **(2 pont)**

### 3. `Memoria` osztály

Származtass az `Alkatresz` osztályból egy `Memoria` osztályt.  
Új adatként tárolja a memória kapacitását és sebességét (egészek).  
Legyen hozzájuk getter is (`getKapacitas`, `getSebesseg`).  
A konstruktor paraméterben várja az ősosztály két adatát, és a két új adatot is.  
A kapacitás és sebesség elhagyható, ekkor `kapacitas=16`, `sebesseg=3200`.  
Az `ar` metódus: `kapacitás * 800 + sebesség * 7`. **(2 pont)**

### 4. `EgyebAlkatresz` osztály

a. Származtass az `Alkatresz` osztályból egy `EgyebAlkatresz` osztályt.  
Tárolja a leírást (szöveg) és az árat.  
Legyen getter a leíráshoz (`getLeiras`).  
Konstruktorban kapja az ősosztály két adatát és a két új adatot is.  
Az `ar` metódus visszaadja a tárolt árat. **(2 pont)**

b. Írja felül az `kiir` metódust úgy, hogy a leírás is megjelenjen. **(2 pont)**

### 5. Operátorok az `Alkatresz` osztályhoz

a. `<` operátor: bal oldalon alkatrész, jobb oldalon egész szám (ár), akkor `true`, ha az alkatrész ára kisebb. **(2 pont)**

b. `<<` operátor: tetszőleges kimeneti folyamra kiírható. Formátuma megegyezik `kiir`-rel, sortörés nélkül. **(3 pont)**

c. `!` operátor: visszaadja a gyártót és típust egy szövegként: `gyártó + ' ' + típus`. **(2 pont)**

### 6. Statikus adattag az `Alkatresz` osztályhoz

a. Statikus egész változó: értékhatár, kezdetben `450000`.  
Legyen getter/setter: `getErtekhatar`, `setErtekhatar`. **(2 pont)**

b. `teljesAr` metódus:

- ha ár < értékhatár → ár
- ha értékhatár < ár ≤ 2× értékhatár → ár + 14000
- ha ár > 2× értékhatár → ár + 32000 **(2 pont)**

### 7. `Csomag` osztály

a. Tároljon tetszőleges mennyiségű alkatrészt (gyerekosztályok).  
Konstruktor kapja meg a darabszámot, ekkor fix méretű tömböt hoz létre.  
A konstruktor nem kap más paramétert, ősosztály adatai legyenek üres szövegek.  
Destruktor felszabadítja a tömböt, de az egyes objektumokat nem.  
`darabszam` metódus adja vissza a tárolt objektumok számát.  
Az `ar` metódus kezdetben `0`. **(3 pont)**

b. `beallit` metódus: egy alkatrészt (pointer) kap, hozzáadja a csomaghoz.  
Figyelni kell, hányat adtunk hozzá, ne lépje túl. Ha tele van, ne csináljon semmit. **(4 pont)**

c. `ar` metódus: visszaadja az összár 90%-át. **(2 pont)**
-->
### 8. `Kupon` sablonosztály

a. Egy sablon paraméterrel rendelkező osztály.  
Egyetlen adattag: kedvezmény (egész), konstruktorban megkapja, getter: `getKedvezmeny`. **(2 pont)**

b. `alkalmaz` metódus: paraméterként kap egy `Alkatresz*`.  
Ha a típus megegyezik a sablon paraméterrel (`dynamic_cast` segítségével), akkor vonja le a kedvezményt, különben térjen vissza az eredeti árral.  
Feltételezhetjük, hogy a sablonparaméter az `Alkatresz` egyik gyerekosztálya. 














