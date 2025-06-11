
# 10. Óra – Rendezvények kezelése JSON-ból

Ez a projekt események (rendezvények) adatainak kezelésére szolgál, JSON fájlból történő betöltéssel.  
A program célja egy `Helyszin` nevű osztály használata, amely eseményeket kezel és különféle műveleteket végez az adatokkal.

---

## 🧪 Tesztelés

A mellékelt projekt tartalmaz egy `main` függvényt, valamint egy `Esemeny` osztályt.

---

## 📦 Esemeny osztály

Az `Esemeny` osztály egy esemény (rendezvény) adatait tárolja:

- név *(string)*
- dátum *(string)*
- kezdési idő *(int)*
- befejezési idő *(int)*
- résztvevők száma *(int)*

> Feltesszük, hogy minden esemény **egész órakor** kezdődik és ér véget.

### 🛠 Konstruktorok

- Paraméter nélküli konstruktor
- Paraméteres konstruktor: minden adatot megkap

### 🔁 Metódusok

Minden adathoz getter és setter:

- `getNev()` / `setNev(...)`
- `getDatum()` / `setDatum(...)`
- `getKezdete()` / `setKezdete(...)`
- `getVege()` / `setVege(...)`
- `getResztvevokSzama()` / `setResztvevokSzama(...)`

---

## 🧭 Helyszin osztály

A `Helyszin` osztály egy rendezvényhelyszín adatait kezeli:

- helyszín neve *(string)*
- címe *(string)*
- események listája *(std::vector<Esemeny>)*

> Konstruktor nem szükséges.

### 📥 `betolt(jsonFajl)`

- Paraméter: JSON fájl neve
- Beolvassa a fájlt, amely tartalmazza:
  - a helyszín nevét
  - címét
  - események tömbjét
- Feltölti az osztály adattagjait

### 📤 `kiir()`

- Az osztály összes adatát kiírja a képernyőre
- Mintához hasonló megjelenítés:

```
Helyszin: Varosi rendezveny kozpont (3214, Valami Varos, xy utca 10)
Esemenyek:
szinhazi eloadas: 2023.06.20. 19:00 - 22:00 (140 fo)
unnepi vacsora: 2023.05.19. 20:00 - 23:00 (80 fo)
szerepjatek est: 2023.07.28. 16:00 - 23:00 (25 fo)
...

```

### 🧾 `esemenyHosszKiir(kimenetiFajl)`

- Paraméter: kimeneti fájl neve
- JSON formátumban listázza ki az események **időtartamát (órában)**
- A fájl formátuma:

```json
[
  { "esemeny": "szinhazi eloadas", "hossz": 3 },
  { "esemeny": "unnepi vacsora", "hossz": 3 },
  { "esemeny": "szerepjatek est", "hossz": 7 },
  ...
]
````

---

## 🧰 Függőségek

A projekthez szükséges a [nlohmann/json](https://github.com/nlohmann/json) könyvtár (json.hpp).

---

## 🔄 Futási példa (`main.cpp`)

```cpp
Helyszin h;
h.betolt("kozpont.json");
h.kiir();
h.esemenyHosszKiir("kimenet.json");
```

---

## 📝 Példafájl – `kozpont.json`

```json
{
  "nev": "Varosi rendezveny kozpont",
  "cim": "3214, Valami Varos, xy utca 10",
  "esemenyek": [
    {
      "nev": "szinhazi eloadas",
      "datum": "2023.06.20.",
      "kezdete": 19,
      "vege": 22,
      "resztvevok": 140
    },
    {
      "nev": "unnepi vacsora",
      "datum": "2023.05.19.",
      "kezdete": 20,
      "vege": 23,
      "resztvevok": 80
    }
  ]
}
```

---

## 📌 Összefoglalás

A projekt célja, hogy objektum-orientált módon kezeljük rendezvények adatait:

* JSON fájlból történő beolvasás
* Események kiírása
* Időtartam kiszámítása JSON formátumban

```
Szükséges fájlok:
- esemeny.h / .cpp
- helyszin.h / .cpp
- main.cpp
- json.hpp
```
 


