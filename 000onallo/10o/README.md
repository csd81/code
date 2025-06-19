
- Készíts egy `Szerver` osztályt, ami a játékteret valósítja meg. A szerver a karakterek tömbjét tárolja (célszerű `vector` segítségével, de nem kötelező). Mivel minden fajta karaktert egyben kell kezelni, értelemszerűen `Karakter*` mutatók tömbjét kell tárolni.

- A `Szerver` osztálynak legyen egy `betolt` metódusa, amely a `karakterek.txt` fájlból betölti a szerveren játszó játékosokat. A fájl több sort tartalmaz, minden sorban egy-egy karakter adataival. Minden karakterhez adott a neve, kasztja, szintje, valamint a kaszthoz tartozó extra adat (fegyver, pontosság, vagy mana). A bemenetet a „*” karakter zárja. A metódus töltse fel a tárolt karakterek tömbjét a megfelelő típusú karakterekkel.

- A `Szerver` osztálynak legyen egy `listaz` metódusa, amely kilistázza a játékosokat (a `Karakter` osztály `kiir` metódusát felhasználva).

- A `Szerver` osztály destruktora szabadítson fel minden lefoglalt memóriát.

- A `Szerver` osztálynak legyen egy `legtobbElet` metódusa, amely visszaadja a legtöbb élettel rendelkező karaktert (`Karakter*`-ként, értelemszerűen).

- Legyen a `Szerver` osztálynak egy `csata` metódusa, amely megkapja kettő játékos nevét (szövegek), eldönti, hogy ha ez a két játékos összecsap, akkor ki lesz a nyertes, és ennek megfelelően visszaadja a nyertes nevét (szöveg). Feltehetjük, hogy létező játékos neveket adunk meg. Ha a csata döntetlenre jönne ki, akkor az `X` szöveget adja vissza.

  - Hogy megy a csata? Mindkét játékosnak van egy életereje és egy sebzése. A csata minden körében a játékosok a sebzésüknek megfelelően csökkentik a másik játékos életét. Ha valaki élete 0-ra, vagy ez alá csökken, akkor a másik nyer. Ha egyszerre csökken 0-ra (vagy az alá) az életük, akkor döntetlen. Ha mindketten élnek még, akkor jön a következő kör. Például az egyik játékos 100 élettel és 40 sebzéssel rendelkezik, a másik 78 élettel és 48 sebzéssel. Az első kör után az első játékosnak 100-48=52 élete marad, a második játékosnak 78-40=38. A második kör után az életek 4 és -2, vagyis az első játékos nyert.

  - Értelemszerűen a játékosok tárolt adatai nem változhatnak, az „élet csökkenést” átmeneti adatokkal kell kezelni.

- Legyen a `Szerver` osztálynak egy `tornaSzimulacio` metódusa, amely több csatát is végrehajt (az előző `csata` függvényt felhasználva). A lejátszandó csatákat a `merkozesek.txt` fájl tárolja. A fájlban minden sor két nevet tartalmaz, a két játékos nevét, akik között a csatát le kell futtatni. A bemenetet a fájl vége karakter zárja. A függvény mindegyik csatát futtassa le, majd az eredményt írja ki az `eredmenyek.txt` fájlba. A kimeneten ugyanaz az adatszerkezet legyen, mint amit be is olvas, de minden sor egészüljön ki egy új adattal, ami 1, ha az első játékos nyert, 2, ha a második, és 0, ha döntetlen.
