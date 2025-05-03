# 5. óra, közös feladat

## `std::vector` és fájlkezelés

A feladat egy dobóverseny adatait tárolni.

Adott a `Probalkozas` osztály, ami egy versenyző egy dobásának adatait tárolja:  
- versenyző neve (`string`),  
- dobott távolság (`double`),  
- illetve, hogy a dobás érvényes volt-e (`bool`).  

Ilyen próbálkozásokból egyszerre többet kell majd tárolni a `Verseny` osztályban.

> A teszteléshez a mellékelt `verseny1.txt` szöveges fájlt a projekt build könyvtárába kell másolni.  
> Ugyanebben a build könyvtárban fognak megjelenni a program által megírt kimeneti fájlok is.

> Amelyik függvény lehet `const`, az legyen is az.

---

## Előkészületek

1. Legyen a `Probalkozas` osztályban paraméter nélküli konstruktor.  
   A név `"ismeretlen"`, a távolság `0`, az érvényesség `false` legyen.  
   *(Szükséges később a `vector<Probalkozas>` teljeskörű működéséhez.)*

2. A `main` függvény elején, a jelölt helyen hajtsd végre az alábbi műveleteket:
   - Hozz létre egy kezdetben három elemet tartalmazó `vector<Probalkozas>` tárolót.
   - Írasd ki a tartalmát a `main` elején lévő `kiirProbalkozasVektor` függvény meghívásával.
   - Írd át a tároló három elemét tetszőleges adattartalmú, egyéb `Probalkozas`-okra.
   - Méretezd át a tárolót öt eleműre.
   - Ismét írasd ki a tartalmát.

---

## `Verseny` osztály

3. Legyen egy `Verseny` osztály az alábbi két adattaggal:  
   - `megnevezés` (`string`)  
   - a próbálkozásokat tároló vektor (`vector<Probalkozas>`)

4. A `Verseny` osztálynak legyen konstruktora, ami egy paramétert várjon:  
   egy fájl elérési útját (`string`), amiből az objektum adatait fel kell tölteni.  
   A fájl elején a verseny megnevezése van, majd az egyes próbálkozások adatai  
   a fent megadott sorrendben a fájl végéig.  
   *Sem a megnevezés, sem a versenyzők neve nem tartalmaz whitespace-t.*

5. Legyen a `Verseny` osztályban egy `kiir` függvény, ami kiírja:
   - egy sorba a verseny megnevezését,  
   - ezután soronként az egyes próbálkozások adatait,  
   - mindent szóközzel elválasztva.

6. Legyen a `kiir` függvénynek egy olyan második változata,  
   ami egyetlen paraméterben egy tetszőleges kimeneti folyamot kap,  
   és oda végzi el a kiírást.  
   *(Tipp: az eredeti `kiir` függvény átalakításával is megoldható.)*

7. Legyen a `kiir` függvénynek egy olyan harmadik változata,  
   ami egyetlen paraméterben egy fájl elérési útját kapja meg (`string`),  
   és az adott nevű fájlba végzi el a kiírást, annak tartalmát felülírva.

8. Legyen a `Verseny` osztályban egy `uj` függvény,  
   ami három paraméterben egy új próbálkozás adatait kapja meg.  
   Szúrja be a próbálkozást a tároló vektor végére.

9. Legyen a `Verseny` osztályban egy `ervenyesDobasok` függvény,  
   ami egy `vector<double>` formájában visszaadja az összes érvényesen dobott távolságot.

10. A `main` függvényben a megadott helyen kérdezd le az `v` változóban tárolt `Verseny`-ből  
    az érvényes dobásokat az előző függvénnyel, majd írd is ki azokat.

11. Legyen a `Verseny` osztályban egy `nevSzerint` függvény,  
    ami két paraméterben megkapja egy versenyző nevét (`string`),  
    és sima referenciaként egy `vector<Probalkozas>` tárolót.  
    Törölje a kapott tároló tartalmát, majd töltse fel a versenyen  
    az adott nevű versenyzőhöz tartozó próbálkozásokkal.
