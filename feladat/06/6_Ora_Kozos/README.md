# Feladat

- A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat.  
- A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.  
- A megadott osztály a `Jarmu` osztály, mely tárolja egy jármű sebességét és tömegét. A konstruktor mindkét értéket várja.  
- Adott még egy `Tarolo` osztály, amely legfeljebb 5 járművet tárol, mutatókkal.  
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.  
- Származtass a `Jarmu` osztályból két másik osztályt:
  - A `Repulo` osztály tároljon még egy utas létszámot.
  - A `Hajo` osztály pedig tároljon még egy teherbírás értéket.  
  - Mindkét osztály a konstruktorban várja az új értékeket is.  
- A `Jarmu` osztályban van egy `kiir` függvény, amely megjeleníti az adatokat. Ezt a függvényt fejtsd ki a gyerekosztályokban is.  
- A `Jarmu` osztály `kiir` függvényét tedd virtuálissá. Figyeld meg, milyen hatással van ez a példakód kimenetére.  
- Tedd a `Jarmu` osztály destruktorát virtuálissá.  
- A `Jarmu` osztályt tedd absztrakt osztállyá azáltal, hogy a `kiir` függvényt tisztán virtuálissá teszed.  
  (A `main` függvényben ekkor a `Jarmu` osztályhoz tartozó részeket kommentbe kell tenni, hogy a kód forduljon.)  
- Készíts másoló konstruktort a `Tarolo` osztályba.
