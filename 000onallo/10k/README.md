 
### 🧾 `esemenyHosszKiir(kimenetiFajl)`

 

 
  
  { "esemeny": "unnepi vacsora", "hossz": 3 },
  { "esemeny": "szerepjatek est", "hossz": 7 },
 
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
 

