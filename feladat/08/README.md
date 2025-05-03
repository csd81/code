# Feladat – Vektor Osztály Bővítése

A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat. A megoldás során bizonyos esetekben ezekhez a kódokhoz is hozzá kell nyúlni. A `main` függvényben a nem használt kódokat kommentbe lehet tenni a teszteléshez.

## Alapinformációk

A megadott osztály a `Vektor` osztály, amely egy matematikai vektort ábrázol. Az osztály:

- Tárolja a vektor méretét.
- Tárol egy lebegőpontos számokat tartalmazó tömböt.
- A konstruktor a méretet várja paraméterül, és ennek megfelelően inicializálja a tömböt.

🛑 **Fontos:** Ügyelj arra, hogy minden lefoglalt memória megfelelően felszabadításra kerüljön.

---

## Feladatok

### 1. Alapműveletek

- **(a)** Készíts a `Vektor` osztályhoz egy `+` operátort, amely két vektort ad össze. Az eredmény egy új vektor legyen.
- **(b)** Készíts egy `+=` operátort, amely egy másik vektort ad hozzá az aktuálishoz. Visszatérési értéke a módosított objektum.
- **(c)** Készíts egy `+` operátort, amely egy lebegőpontos számot és egy vektort ad össze úgy, hogy a szám a bal oldalon van. Visszatérési értéke egy új vektor, amely minden komponensében megnő a szám értékével.
- Készíts egy `=` operátort, amely egy másik vektor értékeit másolja az aktuális objektumba.
- Készíts prefix és postfix `--` operátort, amelyek minden elemet csökkentenek eggyel.
- Készíts `<<` operátort, amely a vektor elemeit írja ki az output stream-re.

---

### 2. További operátorok

- Készítsd el a következő matematikai operátorokat:
  - `-`, `/`, `*`
  - `-=`, `/=`, `*=`

  Ezek működjenek az (a), (b), (c) példák szerint.

#### Megjegyzés:
A (c)-hez hasonló esetekben figyelni kell a sorrendre:
- Ha szám van a **bal oldalon**, és a vektor a **jobb oldalon**, az operátorok pl.: `szám - vektor`, `szám / vektor` esetén másképp viselkednek, mint a fordított sorrendben.

- Készítsd el a `+`, `-`, `/`, `*` operátorokat is, amelyeknél a **szám van a jobb oldalon** (pl.: `vektor + szám`).

---

### 3. Indexelés

- Készíts `[]` operátort, amely:
  - Egy egész számot vár paraméterül.
  - Visszaadja a megfelelő indexű elemet **referenciaként** (így az módosítható is).

- Készíts egy **konstans** verziót is, amely **konstans referenciát** ad vissza.

---

### 4. Speciális operátorok

- `^` operátor: két vektor **skaláris szorzata**.
- Unáris `*` operátor: a vektor **hosszát** adja vissza.
- Unáris `~` operátor: a vektor **normalizált** formáját adja vissza.
- `==` operátor: visszatér **igazzal**, ha a két vektor megegyezik (ugyanannyi elem, ugyanazok az értékek, sorrendben).
- `!=` operátor: az előző ellentéte.
- `<` operátor: visszatér **igazzal**, ha a két vektor azonos méretű, és minden elem **szigorúan kisebb** a másik megfelelő eleménél.

📌 Példa:  
- `(2,3,4)` < `(4,7,6)` ✅  
- `(2,3,4)` < `(3,3,5)` ❌ (mert 3 < 3 nem igaz)
