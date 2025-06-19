Here is a `README.md` generated verbatim from the provided PDF:

```markdown
# Nagy ZH – Gyorsétterem Kínálat Kezelése

## FONTOS INFÓK

- A feladat során alkalmazd a megtanult objektum-orientáltsági elveket!
- A fájlokat egy zip-be csomagolva kell feltölteni.

---

## Feladat Leírása

A feladatban egy új gyorsétterem kínálatát kezeljük. Három fajta ételt készítenek:

- pizzát
- hamburgert
- kebabot

### Általános:

Minden ételnek van egy **neve** (szöveg), ami alapján hivatkozhatunk rá.

#### Pizzához:

- feltétek (szövegek)

#### Hamburgerhez:

- húspogácsa típusa: `marha`, `csirke`, `vegetáriánus`
- mérete: gramm (egész szám)
- van-e benne bacon vagy sajt (logikai értékek)

#### Kebabhoz:

- szósz típusa: `édes`, `csípős`, `fokhagymás`
- van-e benne hagyma, paradicsom, feta sajt (logikai értékek)

### Osztálystruktúra:

- Ősosztály: `Food`
- Pizza: `Pizza` osztály
- Étterem étlapja: `FoodBar` osztály

#### `FoodBar` osztály:

- Tárolja az összes ételt.
- Etlapot JSON fájlban tárolja.
- Konstruktor: kapja meg a fájl nevét és töltse be.
- `printAll()` metódus: kilistázza az étlapot.
  - Tipp: célszerű virtuális függvény
- Etlapban jelenjen meg az ételek **ára** is:

---

### Ár Szabályok

#### Pizza:
- Alapár: 2000 Ft
- Minden feltét: +300 Ft

#### Hamburger:
- Alapár: 500 Ft
- Pogácsa:
  - marha: 10 Ft/g
  - csirke: 6 Ft/g
  - vegetáriánus: 7 Ft/g
- Bacon és sajt: +100-100 Ft, ha van

#### Kebab:
- Alapár: 1800 Ft
- Hozzáadott elemek:
  - hagyma: +150 Ft
  - paradicsom: +100 Ft
  - feta sajt: +250 Ft
- Szósz típusa nem befolyásolja az árat

---

### `Order` osztály

- Egy rendelést valósít meg
- `static loadOrder(string filename)` metódus:
  - Betölti a rendelést JSON-ből
  - Minden elem:
    - étel neve
    - típusa
    - mennyisége (egész)
- Egyedi összeállítás nincs, csak az étlapon szereplő ételekből lehet választani.

### `FoodBar::processOrder(Order)` metódus

- Kilistázza a rendelt tételek részleteit (mintaszerűen)
- Megjeleníti az összesített árat

---

### Prémium feltétek (csak pizza esetén)

- Tároljuk statikusan a prémium feltéteket
- `addPremiumTopping(string)` – hozzáadás
- `clearPremiumToppings()` – kiürítés
- Prémium feltét ára: **500 Ft**, nem 300 Ft

---

### Operátor túlterhelés

- `operator<<` az `Order` osztályhoz
- Tetszőleges ostream-re írja ki a rendelés tartalmát
- Részletes adatok és ár nélkül

---

## Pontozás

| Részfeladat                                     | Pont |
|-------------------------------------------------|------|
| 1. Ételek adatszerkezete                        | 4    |
| 2. `FoodBar` osztály, konstruktor, JSON betöltés| 8    |
| 3. `printAll` metódus                           | 3    |
| 4. `printAll` árakkal együtt                    | 5    |
| 5. `Order` osztály, `loadOrder` metódus         | 5    |
| 6. `processOrder` metódus                       | 5    |
| 7. Prémium feltétek kezelése                    | 4    |
| 8. Prémium feltétek ára beleszámítva            | 2    |
| 9. `operator<<` rendelésekhez                   | 4    |

---
```

Let me know if you want this as a downloadable file or want a version in Hungarian or English only.
