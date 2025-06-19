
# Feladat

- A feladat elkezdéséhez a mellékelt projekt tartalmaz `main` függvényt. A teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni, de módosítani azokat nem szabad.
- A feladathoz csak azokat a függvényeket készítsd el, amiket a feladat kér, illetve ami ezen felül feltétlenül szükséges a helyes működéshez.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
- A nem forduló kód 0 pont.
- A feladatban felhasználói felületen található megjelenítő elemekhez kell egy egyszerű osztályszerkezetet elkészíteni.

## 1) `AdatMegjelenito` osztály

Készíts egy `AdatMegjelenito` osztályt, amely egy megjelenítő elem általános adatait tárolja:

- szín (szövegként),
- és hogy látható-e (logikai érték).

A konstruktor várja az adatokat, és legyen hozzájuk:
- getter: `getSzin`, `getLathato`
- setter a logikai értékhez: `setLathato` 

### a) 
Készíts az osztályhoz egy **tisztán virtuális** `megjelenit` függvényt, amely majd a gyerekosztályokban kiírja a megfelelő adatokat. 

---

## 2) `Szoveg` osztály

Származtass egy `Szoveg` osztályt az `AdatMegjelenito`-ből, amely új adatként tárolja:

- a megjelenítendő szöveget (`szoveg`)
- és annak betűméretét (egész)

A konstruktor várjon minden adatot, és legyen hozzájuk getter:

- `getSzoveg`
- `getBetumeret` 

### a)
Fejtsd ki az ősosztály `megjelenit` függvényét, ami:

- jelenítse meg az eltárolt szöveget,
- annak betűméretét
- és színét, **feltéve** hogy az ősosztály szerint látható.

Ha nem látható, akkor **ne írjon ki semmit**, csak legyen egy hosszú áthúzás (`"----------------------"`). 


### b)
Készíts az osztályhoz egy `=` operátort, amelynek:

- bal oldalán az osztály,
- a jobb oldalán egy **szöveg** áll.

Az operátor módosítsa a tárolt szöveget a jobb oldalon lévőre. 

---

## 3) `SzamLista` osztály

Származtass egy `SzamLista` osztályt az `AdatMegjelenito`-ből, amely új adatként **kettő számot tárol** (egészek), amik az alsó és felső határ lesznek.

A konstruktor várjon minden adatot, és legyen hozzájuk getter:

- `getAlso`
- `getFelso` 



### a)
Fejtsd ki az ősosztály `megjelenit` függvényét, hogy jelenítse meg a számok listáját:

- minden egész számot az alsó határtól a felső határig,
- **egyesével** haladva.

Ha az ősosztály szerint **nem látható** a megjelenítés, akkor csak a **kettő határ jelenjen meg**, a köztes értékek ne. 


### b)
Készíts az osztályhoz egy `*` operátort (**egy operandusú verzió**), amely:

- visszaadja a kettő eltárolt egész szám különbségét. 


### c)
Az osztályban legyen egy **statikus adattag**, ami a megjelenített számok **lépésközét** tárolja (egész).

- Kezdetben az értéke legyen `1`.
- Készítsd el hozzá a `setLepeskoz`, `getLepeskoz` függvényeket. 



### d)
A `megjelenit` függvény működését módosítsd úgy, hogy:

- a megjelenített számok ne egyesével növekedjenek,
- hanem a megadott **lépésközzel**. 

---

## 4) `AdatHalmaz` osztály

Készíts egy `AdatHalmaz` osztályt, amely **tetszőleges mennyiségű megjelenítőt** kezel.

- Az elemeket úgy kell tárolni, hogy **mindig pontosan annyi hely legyen a tömbben, amennyi kell**.
- Hozd létre az ennek megfelelő adattagokat. 

### a)
A `getMeret` függvénnyel legyen lekérdezhető a tárolt elemek száma. 

### b)
Az osztályhoz a `<<` operátorral lehessen egy újabb megjelenítendő elemet hozzáadni, a `main`-ben látható módon. 

### c)
Az osztály destruktora szabadítsa fel a tárolt megjelenítőket. 

### d)
Készíts az osztályhoz egy `kiir` függvényt, amely:

- megjelenít **minden eltárolt elemet**, természetesen azok megjelenítési szabályait használva. 


### e)
Készíts az osztályhoz egy `<` operátort, aminek mindkét oldala egy ilyen `AdatHalmaz`.

- A függvény térjen vissza **igazzal**, ha a **bal oldaliban kevesebb** a látható elem, mint a jobb oldaliban, egyébként pedig **hamissal**. 



### f)
Készíts az osztályhoz egy `~` operátort (**egy operandusú**), ami:

- mindegyik eltárolt elem láthatóságát az **eredetivel ellentétesre** állítja. 






 
