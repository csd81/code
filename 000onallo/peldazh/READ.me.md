 

**a)** Készíts az osztályhoz `<<` operátort, amelynek segítségével új karaktert lehet hozzáadni a tárolóhoz (paraméterként mutatót vár).  
Ha a karakterek száma már elérte a maximumot, akkor ne adja hozzá az újat (memóriaszemét ekkor se legyen!).  


**b)** Készíts `[]` operátort az osztályhoz, amely paraméterként egy egész indexet vár, és visszaadja a belső tömb ennyiedik helyén lévő mutatót.  
Ha az index érvénytelen (kicímez a tömbből, vagy csak nem tárolunk még ennyit), akkor `null` mutatóval térjen vissza.  


**c)** Készíts `+=` operátort az osztályhoz, melynek bal oldalán egy `Jatekosok` objektum van, a jobb oldalán egy `Akcio`.  
Az operátor minden eltárolt karakternek adja át az akciót végrehajtásra.  
Az operátor számolja meg, hogy hány karakter hajtotta végre az akciót, és ezzel az egész értékkel térjen vissza.  


**d)** Készíts az osztályhoz `<<` operátort, amivel tetszőleges kimeneti folyamra meg lehet jeleníteni az adatait.  
A kimeneten szerepeljen a tárolt karakterek maximális és tényleges száma, valamint a karakterek adatai.  
A gyerekosztályokban tárolt adatokat nem kell megjeleníteni, viszont minden karakternél írd ki hogy melyik típusba tartozik (`Mohokarakter`, vagy `Valogatos`).  
