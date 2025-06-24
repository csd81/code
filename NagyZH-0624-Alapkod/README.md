 

- Alkalmazni kell a megoldás során a tanult objektum-orientáltsági elveket (ősosztály-gyerekosztályok, virtuális metódusok, egységbe zárás stb).
- A bemeneti fájlokat (`in-castle-infantry.json`, `in-castle-cavalry.json`, `in-castle-machinery.json`, `in-army-1.txt`, `in-army-2.txt`, `in-army-3.txt`, `in-army-4.txt`) teszteléskor a megfelelő helyre kell másolni.
- Feltehetjük, hogy a bemenő/teszt adatok helyesek, érvényesek (kivéve, ha a feladat mást nem állít).
- A megoldás teljes forráskódját egyetlen ZIP fájlba csomagolva kell feltölteni.

## A feladat leírása

A `main`-ben és ebben a leírásban szereplő osztályok és metódusok igény szerint átnevezhetők, az itteni nevek csak példák.

Egy várból hadseregek felállítását kell menedzselni. A sereg katonai egységekből áll, ami háromféle lehet:
- gyalogság (*infantry*),
- lovasság (*cavalry*),
- gépek (*machinery*).

Minden egységnek (egységtípusnak) van egy neve, ami egyben szöveges azonosító, és ismert továbbá a felszerelés költsége (*equip cost*, egész).  
- A gyalogságnál ismert a fegyvernem (*weapon*, szöveg), és hogy nehézfegyverzetű-e (*heavy*, logikai).  
- A lovasság esetén ismert a menetsebesség (*speed*, km/nap, egész).  
- A gépek esetén ismert a gép legénységének a létszáma (*crew*, egész).

A `Castle` osztály reprezentálja a várat, ahol az elérhető egységtípusokat tároljuk. A `load` metódus három fájlnevet kap, ami rendre a gyalogság, a lovasság és a gépek felsorolását tartalmazza JSON formátumban. Ezeket egy közös tárolóba kell beolvasni.

Innentől kezdve (az előbb említett beolvasást leszámítva) a teljes pontszámhoz a `Castle` és `Army` osztályok nem hivatkozhatnak a konkrét gyerekosztályokra, csak az ősosztályra. Vagyis, a gyerekosztályok szerinti esetszétválasztásokat ajánlott virtuális metódusokkal megoldani.

A `Castle` osztályhoz legyen egy `printAll` metódus, ami a standard kimenetre kiírja a beolvasott egységeket.  
Legyen továbbá `<<` operátor is, ami tetszőleges kimeneti folyamra írja ki ugyanazt.

Az `Army` osztály reprezentál egy sereget, ami a várból elérhető katonai egységekből áll.  
Tároljuk, hogy milyen katonai egységek vannak benne, és azokból mennyi fő/darab.  
A `Castle` osztály `readArmy` metódusa paraméterben egy szövegfájl nevét kapja meg, és innen olvassa be a sereg adatait.  
Soronként egy katonai egység neve és egy darabszám van, hogy hány olyan egység van a seregben.  
A nevek whitespace-mentesek, nem ismétlődnek egy sereg leírásán belül, és a darabszámok mindig pozitívak.  
A `readArmy` adja vissza a megfelelően feltöltött `Army` objektumot.

Az `Army` osztály rendelkezzen az alábbi metódusokkal:

### `display`
Kiírja a katonai egységek neveit a létszámmal/darabszámmal együtt.  
A katonai egységek sorrendje a seregen belül nem fontos, de a 0 létszámú/darabszámú egységek ne jelenjenek meg.

### `getSpeed`
Visszaadja a sereg menetsebességét. Ez a leglassabb katonai egység menetsebességével egyenlő.  
- könnyűgyalogság: 30  
- nehézgyalogság: 25  
- gépek: 35  
- lovas egységeknél: egyedi adat

### `soldierCount`
Visszaadja a katonák számát.  
Minden gyalogos és lovas egység 1 katonát jelent, és minden gép annyit, amennyi a gép személyzete.

### `horseCount`
Visszaadja a lovak számát.  
Minden lovasnak egy lova van, a gépeket összepakolt állapotban pedig egyenként két ló húzza.

### `dailyCost`
Visszaadja a sereg egynapi ellátmányának árát. Ez nem azonos a felszerelés költségével.  
- Minden katona ellátmányának ára: 25 (egész)  
- Minden lóé: 10  
A katonák ellátmányának ára (25) a programban legyen globálisan átállítható az `Army::setSalary` statikus metódussal.

### `totalMissionCost`
Paraméterben megkapja egy szövetséges vár távolságát km-ben, és hogy hány napig kell azt védeni (egészek).  
Adja vissza, hogy ez összesen mennyibe kerül a vár urának.

Számításba kell venni:
- az oda- és visszautat (menetsebesség alapján számolva: minden hátralévő km = 1 nap)
- a védekezési időtartamot
- naponta fizetni kell a teljes sereg ellátmányát
- plusz egyszeri felszerelés költség (minden egység szorozva a darabszámával)

---

## Pontozás

| Részfeladat                                              | Pont |
|----------------------------------------------------------|------|
| Katonai egységek osztályai, kapcsolatok, adatszerkezet   | 8    |
| `Castle` osztály, `load` metódus                         | 6    |
| `Castle`: `printAll` metódus                             | 6    |
| `Castle`: `<<` operátor                                  | 2    |
| `Army` osztály, `readArmy`, `display` metódus            | 6    |
| `speed`, `soldierCount`, `horseCount` metódusok          | 4    |
| `dailyCost`, globálisan állítható ellátmány              | 3    |
| `totalMissionCost` metódus                               | 5    |
| **Összesen**                                             | **40** |
