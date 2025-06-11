 
# Halmaz osztály feladat

## Általános leírás

- A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat. A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.
- A megadott kód most nem tartalmaz osztályt, csak `main` függvényt.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.

## Feladatok

### Alap osztály

- Hozz létre egy `Halmaz` osztályt, amely `double` értékeket tárol egy átméreteződő tömbben, mely mindig pontosan akkora, amennyi számot tárol.
- Az osztály számok halmazát kezeli majd.
- Az osztály konstruktora nem vár paramétert.

### Átméretezés

- Az operátoroknak különböző méretű halmazokra is működniük kell, így a megfelelő átméretezésre figyelni kell.

### Függvények és operátorok

#### `meret()` függvény

- Készíts a `Halmaz` osztályba egy `meret` függvényt, amely visszaadja a halmaz méretét (eltárolt elemek számát).

#### `<<` operátor (hozzáadás)

- Definiálj egy `<<` operátort, amellyel elemeket lehet hozzáadni.
- Működése:

```cpp
Halmaz h;
h << 8.5 << 5 << 4 << 12.33; // Minden elemet hozzáad a h halmazhoz, balról jobbra haladva.
````

* A halmazban minden elem csak egyszer szerepelhet.
* A belső tömbben az elemek mindig növekvő sorrendben szerepeljenek (a helyét keresd meg a rendezett elemek között).

#### `>>` operátor (eltávolítás)

* Definiálj egy `>>` operátort, amivel a halmazból ki lehet venni elemeket.
* Működése:

```cpp
h >> 6.123 >> 4 >> 12.33; // Minden elemet kiszed a h halmazból, balról jobbra haladva.
```

* A halmazban nem létező elemet figyelmen kívül kell hagyni.

#### `<<` operátor (kiírás)

* Definiálj egy `<<` operátort, amivel a halmaz elemeit lehet kiírni bármilyen kimeneti folyamra.
* Új sor ne legyen a kiírás végén.
* Példa:

```cpp
Halmaz h;
h << 8.5 << 5 << 4 << 12.33;
cout << h << endl;
```

* Kimenet:

```
{4, 5, 8.5, 12.33}
```

#### Másoló konstruktor és destruktor

* Készíts a `Halmaz` osztályhoz másoló konstruktort és destruktort.

#### `=` operátor

* Definiáld az `=` operátort, amivel egy halmazt másolni lehet.

#### `[]` operátor

* Definiálj egy `[]` operátort, ami a paraméterben kapott számra visszaadja, hogy az a halmaznak eleme-e vagy nem.

#### `&` operátor

* Definiálj egy `&` operátort, amely két halmazra elvégzi a metszet műveletet, és visszatér az eredménnyel.

#### `|` operátor

* Definiálj egy `|` operátort, amely két halmazra elvégzi az unió műveletet, és visszatér az eredménnyel.

#### `-` operátor (halmazkivonás)

* Definiálj egy `-` operátort, amely két halmazra elvégzi a halmazkivonás (bal oldali halmazból kivonja a jobb oldali halmazt) műveletet, és visszatér az eredménnyel.

#### `^` operátor (kölcsönös kizárás)

* Definiálj egy `^` operátort, amely két halmazra elvégzi a kölcsönös kizárás műveletet, és visszatér az eredménnyel.

#### Módosító operátorok

* Definiáld az előző operátorok azon verzióját, amelyek a bal oldali halmazt módosítják, és nem újat készítenek: `&=`, `|=`, `-=`, `^=`.

#### `+` operátor (hozzáadás számmal)

* Definiálj egy `+` operátort, amelynek bal oldalán a halmaz van, jobb oldalán egy lebegőpontos szám.
* Eredménye egy új halmaz, amely az eredeti halmazhoz hozzáadja a számot.

#### `-` operátor (kivonás számmal)

* Definiálj egy `-` operátort, amelynek bal oldalán a halmaz van, jobb oldalán egy lebegőpontos szám.
* Eredménye egy új halmaz, amely az eredeti halmazból kivonja a számot.

#### `<` és `<=` operátorok

* Definiálj egy `<` operátort, amely két halmazt hasonlít össze, és akkor tér vissza igaz értékkel, ha a bal oldali halmaz valódi részhalmaza a jobb oldalinak.
* Definiáld a `<=` operátort is, amely megengedi az egyenlőséget is.

#### `>` és `>=` operátorok

* Definiálj egy `>` operátort, amely két halmazt hasonlít össze, és akkor tér vissza igaz értékkel, ha a jobb oldali halmaz valódi részhalmaza a bal oldalinak.
* Definiáld a `>=` operátort is, amely megengedi az egyenlőséget is.

#### `==` és `!=` operátorok

* Definiáld az `==` operátort, amely két halmazt hasonlít össze, és akkor tér vissza igazzal, ha a két halmaz megegyezik.
* Definiáld a `!=` operátort is, ami pont az ellenkezőjét csinálja.

#### `legnagyobb()` függvény

* Készíts a `Halmaz` osztályba egy `legnagyobb` függvényt, amely visszaadja a halmazban tárolt legnagyobb elemet.

#### `legkisebb()` függvény

* Készíts a `Halmaz` osztályba egy `legkisebb` függvényt, amely visszaadja a halmazban tárolt legkisebb elemet.

#### `torol()` függvény

* Készíts a `Halmaz` osztályba egy `torol` függvényt, amely kitöröl minden elemet a halmazból.

