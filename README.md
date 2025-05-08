```bash
OS. gyak 1
---
cd, ls, mkdir, touch, cp, rm

bal, jobb nyíl: a beírt karakterek között tudunk lépegetni
fel, le nyíl: korábban kiadott parancsok között tudunk lépegetni
tab: parancsok kiegészítése/befejezése
clear: képernyő törlése

gyökér könyvtár: /, ha van alkönyvtára, vagy gyerekkönyvtára akkor /valami

speciális elérési útvonalat
. (egy pont): aktuális könytár
.. (kettő pont): egy szinttel lejebb lévő könyvtár
~ (hullámvonal): aktuális felhasználó home könytára

könyvtárak közötti mozgás: cd elérési_út
cd /: főkönyvtár
cd ..: egy könyvtárral feljebb lépünk

abszolut útvonal a gyökérkönyvtártól a teljes mappa struktúrát tartalmazza

pwd: kiíratja, hogy melyik könyvtárban tartózkodunk

ls: könyvtár tartalmának listázása

Legyakrabban használt kapcsolók:

-l: Hosszú formátumú listázás. Részletes információkat nyújt a fájlokról és könyvtárakról, beleértve a jogosultságokat, tulajdonost, csoportot, méretet, időbélyeget stb.
ls -l

-a: Minden fájlt és könyvtárat listáz, beleértve a rejtett fájlokat is (a ponttal kezdődő nevek).
ls -a

-h: Human-readable méret. Az állományok méretét emberi olvashatóságra optimalizált mértékegységekben jeleníti meg (KB, MB, GB).
ls -lh

-t: Időrendi sorrendben listáz. A legfrissebb fájlok elől jelennek meg.
ls -lt

-r: Fordított sorrendben listáz. A legrégebben létrehozott vagy módosított fájlok elől jelennek meg.
ls -lr

-R: Rekurzív listázás. Az alkönyvtárak tartalmát is listázza.
ls -R 

1: Minden fájlt vagy könyvtárat egyetlen oszlopban jelenít meg.
ls -1 (1 = egyes, nem l)
  
egybevonhatók a kapcsolók: ls -l -a == ls -la

rejtett fájl: ponttal kezdődik a fájl neve, pl .serverlogs

fontos megjegyezni: hogy .txt nem biztos, hogy egy szövegfájl, linux alatt mindegy, hogy mi a fájl neve

ls -l (hosszú listázás értelmezése)
első sor a logben elfoglalt összes sor
ezt követően a fájlok kilistáza
1. oszlop (típus, jogosultság)
2. oszlop (link számláló)
3. oszlop (tulajdonos)
4. oszlop (csoportok)
5. oszlop (fájl mérete byte-ban)
6. oszlop (módosítás dátuma/ideje)
7. oszlop (név)

Az 1. oszlop részletezve: 
1 karakter: fájl (-), mappa (d), soft link (l)
2-9 karakter: tulajdonos (u), csoport (g), mások (o) jogai
r: olvasási
w: írási
x: végrehajtási (lefuttatható a fájl, be lehet lépni a mappába)
-: adott jog nem engedélyezett

parancsok leírása: man parancs, man ls (list parancs szintaxisa)

mkdir elérési_út (könyvtár létrehozása): aktuális könyvtárba csinál egy mappát

mkdir ./os/szilva/korte
mkdir ./os/szilva/korte/barack (ha nincs meg egy köztes könyvtár, jelen esetben korte, akkor hibád dob a rendszer)

a -p kapcsoló az összes köztes könyvtárat létrehozza (mkdir -p elérési út/mappa)

space-szel elválasztva több könyvtár is létreoztható

touch fájlnév: tartalom nélküli fájl létrehozása

Fájlok másolása:
cp [kapcsoló] honnan hová

pl. 
cp ~/os/egy/ketto/file1.txt ~/os/egy/
cp ./alma.txt ./ujalma.txt (meglévő fájlból egy másolat)

ha van ilyen fájl, akkor azonnal felülírás
-i kapcsolóval ha van ilyen fájl, akkor felülírás előtt rákérdez (y/n)

cp -r kapcsolóval könyvtárakat is másolhatunk, alapesetben nem működik

shell minták használata: "*" karakter, egy joker karakter, amely jelentése bármilyen karakter bármennyiszer

cp *.txt cseresznye (aktuális könytárból a cseresznye könyvtárba másolja a txt kiterjesztésű fájlokat)

Törlés:
rm fájlnév/könyvtárnév: fájl/könyvtár törlése
rm -i: megerősítéses törlés
rm -d: üres mappa törlése
rm -r: összes almappa és fájl (rekurzív) törlése
rm -f: kérdés nélkül töröl (nem számítanak a hibaüzenezek pl. nem létezik egy fájl)Old meg bash parancsokkal:

01. 
Hozz létre egy projekt könyvtárat a home könyvtárádban. Ebben a könyvtárban hozz létre egy dokumentumok alkönyvtárat és egy kepek alkönyvtárat.
mkdir ~/projekt ~/projekt/dokumentumok ~/projekt/kepek

02. 
Hozz létre egy fontos.txt nevű fájlt a projekt/dokumentumok könyvtárban és egy kep1.jpg és kep2.jpg fájlt a projekt/kepek könyvtárban.
touch ~/projekt/dokumentumok/fontos.txt
touch ~/projekt/kepek/kep1.jpg ~/projekt/kepek/kep2.jpg

03. 
Másold le a fontos.txt fájlt a backup könyvtárba.
cp ~/projekt/dokumentumok/fontos.txt ~/backup/

04.
Másold le a kep1.jpg fájlt a projekt/kepek könyvtárból a projekt/dokumentumok könyvtárba és nevezd át dokumentum.jpg-re.
cp ~/projekt/kepek/kep1.jpg ~/projekt/dokumentumok/dokumentum.jpg

05.
Listázd ki a projekt könyvtár tartalmát.
ls ~/projekt

06.
Listázd ki a projekt könyvtár tartalmát, beleértve a rejtett fájlokat is.
ls -a ~/projekt

07.
Töröld a kep2.jpg fájlt a projekt/kepek könyvtárból.
rm ~/projekt/kepek/kep2.jpg

08.
Töröld az egész projekt könyvtárat.
rm -r ~/projekt

09.
Hozz létre egy osztalyok/matematika könyvtárat a home könyvtáradba.
mkdir -p ~/osztalyok/matematika

10.
Hozz létre egy jegyzetek/2022 könyvtárat, majd a 2022 könyvtárban hozz létre egy jegyzet.txt nevű fájlt.
mkdir -p ~/jegyzetek/2022
touch ~/jegyzetek/2022/jegyzet.txt
OS. gyak 2
---
echo, mv, cat, >, >>, ln, chmod, head, tail

Szöveg kiíratás:
echo: szöveg kiíratása a konzolba
echo szöveg
Ha több space-t írunk, akkor is csak egy spacet használ, mert a szavakat paraméterként dolgozza fel és feltételezi, hogy a space maga szóelválasztó
Megoldás: idézőjeleket kell használni
Automatikusan sort emelt, ha ezt nem akarjuk, akkor -n kapcsoló
-e escape szekveniák használata (pl. prog 1, printf: \t tabulátor, \n új sor)

Áthelyezés:
mv forrásfájl célfájl: fájlok áthelyezése
Ugyanazon mappába kell áthelyezni egy fájlt, akkor átnevezi a fájl
Ha két könyvtár eltér, akkor áthelyezés is történik
Ha célfájl létezik, akkor ezt a mv parancs felül fogja írni

Tobb fájl esetén mindegyiket a célmappába fogja átmozhatni (egyezés esetén felülírás)
mv -i: áthelyezés kérdéssel

Fájlok tartalának kiíratása:
cat fáj1, fájl2, fájl3: fájlok tartalmának kiíratása
cat *.txt: kiírja az összes txt kiterjesztésú fájl tartalmát
cat paraméter nélkül, visszadja azt amit beírunk a konzolba (Ctrl+D-vel jelezzük a bevitel végét
hosszú fájl esetén cat parancsa csak annyit mutat, amennyi kifér a képernyőre

less fájlnév: képernyőként megy a tartalomon (kilépés a q gombbal)
more fájlnév: hasonló, csak egy kicsit kevesebb tudással, mint a less (space: léptetés, q: kilépés)

Kimenet átirányítása (pl. egy fájlba)
---
A kisebb nagyobb jel segítségével egy fájlba tudjuk irányítani a parancssor kimenetét
ls -l
ls -l > list.txt
more lista.txt
Fájlnév egyezés esetén felülírja a fájlt

>> (dupla kisebb nagyobbb jel): hozzáfűzzük a fájl végéhez

cat allatok.txt >> lista.txt (a lista.txt végére fűzi az állatok.txt fájlt)
cat > newfile.txt: tartalom létrehozása, ennél jobb megoldás egy szerkesztő használata pl. nano, vim

nano file.dat

Bemenet átirányítása (pl. egy fájlba)
---
./pelda < bemenet.txt a példa fájlnak hozzáadjuk bemenetként a bemenet.txt fájl

c kód futtatása esetén telepíteni kell a gcc-t 
sudo apt-get update
sudo apt-get install gcc

Fájlok linkelése
---

Soft link
Egy olyan speciális fájl, amely egy másik fájl elérési útját tartalmazza
Egy link mutathat fájlra vagy könyvtárra is. Ez egyenértékű azzal, mint ha a másik fájlra hivatkoznánk kivéve (átnevezés, törlés stb.)
Például egy gyakran használt fájlt amely nem a home könyvtáramban van, arra érdemes lehet készíteni egy hivatkozást

ln -s (soft link) létező fájl [célkönyvtár vagy célfájl]

Pl.:
ln -s banan.txt bananlink
ls -l bananlink
lrwxrwxrwx 1 balazs balazs 9 Feb 22 13:31 bananlink -> banan.txt

Emlékeztető: az ls -l paranccsal látható a hivatkozás, hogy hova mutat.

Ha törlöm az eredeti fájt, akkor a link meghíváskor kiírja, hogy nincs ilyen fájl.

Hard link
Az eredeti tartalomhoz két fájlt hozunk létre.
ln létező fájl hivatkozással új fájl jön létre.

ls -l esetén regular fájlként lesz kilistázva, de a linkszámláláló nőtt

Ha egy állományt törlök, akkor a másik megmaradt, a link 2-ről 1-re változik
Könyvtárra hard linket nem lehet létrehozni, továbbá ha több fájlrendszer van, akkor a fájlrendszerek között csak soft linket lehet használni

Jogosultsások módosítása
---

Kinek:
u: user (tulajdonos)
g: group (csoport)
o: others (mások)
a: all (mindenki)

Mit:
r: read (olvasási jog)
w: write (írási jog)
x: execure (vágrehajtási/belépési jog)
+: megad, -: elvesz

-rw-r--r-- 1 balazs balazs   274 Apr  1  2021  zh01.sh

chmod modosítás fájlok neve
chmod o+w szoveg.txt (jogosultság hozzáadása)
chmod o-w szoveg.txt (jogosultság elvétele)

Oktális számok
x: 1-esk
w: 2-esek
r: 4-esek
-: 0-sok

chmod 644 szoveg.txt

senki semmilyen jogosultság: 000
mindenkinek minden jogosultság: 777

Kitekintő:
chown ujtulaj fájlnév/elérés: új tulajdonos létrehozása
chgrp ujcsoport fájlnév/elérés: új csoport létrehozása
kombinálva: chown jozsef:security server.log (sudo használatára van szükség)    

Fájl eleje és vége
---
head -n szám fájlnév: fájl első szám sorát íratja ki
Ha nincs annyi sor, mint amennyit kérünk, nincs hiba
tail -n szám fájlnév: fájl utolsó szám sorát íratja ki

Példák:
Két fájl utolsó 3 sorának kilistázása:
tail -n 3 file1.txt file2.txt 

Összes .txt fájl első két sorának kilistázása
head -n 2 *.txt

Kitekintés:
tail -f tail miután kiírt x sort, nem tér vissza, hanem folyamatosan nézi, hogy kerülnek-e újabb sorok a fájlba, és azokat kiíratja, pl. log fájlok folyamatos bővüléseOld meg bash parancsokkal:

01.
Hozz létre egy új könyvtárat "gyakorlas" néven a home könyvtáradban.
mkdir ~/gyakorlas

02.
Hozz létre egy "szoveg.txt" nevű szöveges fájlt a "gyakorlas" könyvtárban, és írj bele egy tetszőleges szöveget az echo parancs segítségével.
echo "Ez egy példa szöveg." > ~/gyakorlas/szoveg.txt

03. Bővítsd ki a szoveg.txt fájlt a Nano szerkesztő segítségével a következő sorokkal:

Ej, mi a kő! tyúkanyó, kend
A szobában lakik itt bent?
Lám, csak jó az isten, jót ád,
Hogy fölvitte a kend dolgát!
 
Itt szaladgál föl és alá,
Még a ládára is fölszáll,
Eszébe jut, kotkodácsol,
S nem verik ki a szobából.

nano szoveg.txt
ctrl+x
yes
enter

04.
Hozz létre egy másolatot a "szoveg.txt" fájlról a "gyakorlas" könyvtárban, és nevezd át "masolat.txt"-re.
cp ~/gyakorlas/szoveg.txt ~/gyakorlas/masolat.txt

05.
Fűzd hozzá a "szoveg.txt" fájl tartalmát a "masolat.txt" fájlhoz.
cat ~/gyakorlas/szoveg.txt >> ~/gyakorlas/masolat.txt

06. 
Helyezd át a szoveg.txt-t a projekt könyvtárba és nevezd át dokumentumok.txt-re.
mv ~/gyakorlas/szoveg.txt ~/projekt/dokumentum.txt

07.
Módosítsd a "masolat.txt" fájl jogosultságait úgy, hogy csak a tulajdonos olvashassa és írhasa.
chmod 600 ~/gyakorlas/masolat.txt

08.
Listázd ki a "gyakorlas" könyvtár tartalmát, beleértve a rejtett fájlokat is.
ls -a ~/gyakorlas

09.
Írd ki a "masolat.txt" fájl első 3 sorát a konzolra.
head -n 3 ~/gyakorlas/masolat.txt

10.
Írd ki a "masolat.txt" fájl utolsó 4 sorát a konzolra.
tail -n 4 ~/gyakorlas/masolat.txt

11.
Hozz létre egy eredeti.txt fájlt a home könyvtáradban a következő tartalommal: "Jul  6 06:33:44 user1 ubuntu: dear cj"
echo "Jul  6 06:33:44 user1 ubuntu: dear cj" > eredeti.txt

12.
Készíts az eredeti.txt fájlról egy soft linket soft_link.txt néven.
ln -s eredeti.txt soft_link.txt

13.
Ellenőrizd a linket. Honnan látszik, hogy elkészült a soft link?
ls -l

14.
Készíts az eredeti.txt fájlról egy hard linket hard_link.txt néven.
ln eredeti.txt hard_link.txt

15.
Ellenőrizd a linket. Honnan látszik, hogy elkészült a hard link?
ls -lOS. gyak 3
---
pipe(|), wc, cut, sort, ps, fg, kill, find

Programok összefűzése a pipe paranccsal segítségével
Programokat amelyekak konzolra írnak és konzolról olvasnak összefűzzük (pipeolás)
ls -l | tail -n 5: részletes listát átadja a tailnek, amely kilistázza az utolsó 5 sort 
cat olvassel.txt | head -n 5: az olvassel.txt első 5 sorát adja vissza

Több fájl esetén kiíratja a nevét, amelyet -q kapcsoló el lehet tüntetni

cat fájl1.txt fájl2.txt | head -n 2: a fájl1.txt és fájl2.txt a cat által egyesített megjelenítésének első két sorát iratja ki

Pipe több parancsot is egybe lehet fűzni
Írassuk ki egy fájl 2. sorát

cat sorok.txt - jelenítse meg mindet
cat sorok.txt | head -n 2 - jelenítse meg az első kettőt
cat sorok.txt | head -n 2 | tail -n 1 - jelenítse meg az első kettőből az utolsót
 
Írassuk ki egy fájl utolsó előtti sorát
 
cat sorok.txt - jelenítse meg mindet
cat sorok.txt | tail -n 2 - jelenítse meg az utolsó kettőt
cat sorok.txt | tail -n 2 | head -n 1 | jelenítse meg az utolsó kettőből az elsőt

Sorok, szavak, karakterek száma:
wc parancs
wc -l: sorok száma
wc -w: szavak száma
wc -c: karakterek száma

wc -l allatok.txt
cat allatok.txt | wc -l

Az előbbiek kombinálhatók is
wc -wl: a szavakat és a sorokat is számolja meg
wc minden kiír

Pipe esetén használható, pl. számolja meg hány bejegyzés van az adott könyvtárban

ls -1 | wc -l: a bejegyzések kiíratása egy oszlopba, majd sorok számának összeszámolása
wc -l *.txt: az összes bejegyzés sorok száma, össz. száma

Cut (mezők vágása)
---
Adatott sorokból melyik mezőt adja vissza
cut -c kezdő-vég karakterek
cut -c 2-5 fájl.txt, a sorokból kivágja a 2-5 közötti karaktereket
cut -c 3 fájl.txt, csak a 3. karakterek

Példa, 1-3 karakter kivágása:
cat sorok.txt | cut -c 1-3

Mező vágása, egy elhatároló (tab, ' ', ';' stb) alapján. 
Ha az elhatároló egy tabulátor, akkor nem kell a -d kapcsoló.
cat sorok.txt | cut -f 2 (második oszlop kivágása -f kapcsoló segítségével)
cat sorok.txt | cut -d ';' -f 1 (első oszlop kivágása, egy olyan struktúrában, amelyeket ";"-al vannak elválasztva)

sort (rendezés)
pl. cat nevek.txt | sort (abc sorrend)

sort -r (csökkenő sorrend)
pl. cat nevek.txt | sort -r 

sort -k:  melyik mező szerint rendezzen
pl. ls -l | sort -k 6 (dátum növekvő)

sort -n: numerikus sorrendezés
pl. ls -l | sort -n -k 5 (méret alapján numberikusan rendezzen)

sort -t (helykitöltő alapú rendezés)
sort -t ';' -k 2 fájl.txt (";" helykitöltő alapján rendezzen, a második adattag alapján)

Példa:
Jelenítse meg a könyvtárában a legnagyobb fájl adatait:
ls -l | sort -k 5 | tail -n 1
Jelenítse meg a könyvtárában a legkisebb fájl adatait:
ls -l | sort -k 5 | head -n 2 | tail -n 1

sort -u: egyező sorok elrejtése
pl. cat telefonszamok.txt | sort -u

Folyamatok:
A /proc alatt egy virtuális fájlrendszer található, ahol a futó folyamatokól tudhatunk meg információkat
pl. cat /proc/cpuinfo (a gép CPU adatainak lekérdezése)

ps: saját folyamataimat mutatja
Összes felhasználó összes folyamata bővített formátumban:
ps aux (a - összes, u - felhasználók, x - bővített formátum)

Folyamat leállítása: kill

pl.
nano lorem.txt
új terminálablak indítása
ps aux (kilistázom a folyamatokat)
Ezt követően kiválasztom a leállítandó folyamat PID-ját, és ezt adom meg a kill parancs paraméterének
kill 1322

ps f (gyerek folyamatok kilistáza)

killall folyamatnév: összes meghatározott nevű folyamat leállítása

Futó folyamatok listázáta: jobs
Futó folyamat háttérbe helyezése:
nano lorem.txt & (háttérben fusson), vagy futás közben ctrl + z 
ezt követően kiírja a rendszer, hogy
[1] - 1 jobs
234567 - Process id

Első (1) job előtérbe helyezése:
fg 1 (első jobot)

Felfüggesztett folyamat leállítás:
kill pid (process id)
kill -9 %1 (-9/SIGKILL %job id)

Keresés: find parancs
A find segítségével egy adott könyvtárban egy adott állományt/állományokat keresünk
Fontos, hogy alapesetben rekurzív, lemegy a legalsó gyerekig
Lehet, név, típus, vagy méret és egyéb tulajdonságok alapján

find könyvtár kapcsolók tulajdonságok/jellegek

-name: névre keresés
-regexp: reguláris kifejezés
-type f, -type d: fájl/könyvtár
-size 50k/-50k/+50k: a méret 50 kB/50 kB alatt/50 kB felett 
-exec: a megtalált fájlokon egy parancsot hajt végre, a "{}" helyére a fájl teljes elérési útvonalát helyettesíti be.
-execdir: a megtalált fájlokon egy parancsot hajt végre, de a parancsot a fájl szülőkönyvtárában hajtja végre, így a "{}" helyére csak a fájlnév kerül.
-maxdepth: könyvtármélység meghatározása (0 a szülő, 1 az első gyerek mélység)
-group: csoport definiálása

Példák (a "." az aktuális mappa helye, átírható tetszőleges struktúrára):

find . -name hudemely.txt

find . -type f -name "*.txt" (fontos: a reguláris kifejezéseket idézőjel közé kell tenni)

find . -type f -name "*.txt" -exec ls -l "{}" \; {ide hellyetesítődik be amit a find talál}

Összes könytár információ kilistázásaa
find . -type d -exec ls -ld "{}" \; (ls -ld: könyvtár információk kilistázása hosszú formátumban)

Összes txt fájl első két sorának kiíratása
find . -type f -name "*.txt" -exec head -n 2 "{}" \;   

Hány sorból állnak a .txt kiterjesztésű fájlok
find . -type f -name "*.txt" -exec wc -l "{}" \;

A txt fájloknak összesen hány soruk van
find . -type f -name "*.txt" -exec cat "{}" \; | wc -l

A txt fájloknak összes sorát rendezzük és lapozhatóvá tegyük
find . -type f -name "*.txt" -exec cat "{}" \; | sort | more

A sysadmins tuljdonossal rendelkező "backup" kifejezést tartalmazó mappák darabszámának visszaadása
find . -type d -name "*backup*" -group sysadmins | wc -l

A user felhasználó ".io" végű 50 MB-nál nagyobb fájljainak keresése max. 2 mélységig
find . -maxdepth 2 -type f -name '*.io' -user user -size +50M

Maximum egy gyerek mélységig megtalálható ".txt" végű fájlokról készítsen biztonsági másolatot úgy, hogy lássa el őket egy ".bak" vegződéssel a backup mappába 
find . -maxdepth 1 -type f -name "*.txt" -execdir cp "{}" ./backup/"{}".bak \;Old meg bash parancsokkal:

01.
Hozz létre egy "dokumentumok" nevű könyvtárat, majd benne egy "fontos.txt" fájlt, amelynek az első három sorába írd bele a következő adatokat az echo parancs segítségével:

Kovács;Lajos;Baja;6500
Nagy;László;Székesfehérvár;8000
Tamási;Péter;Veszprém;8200

mkdir dokumentumok
echo -e "Kovács;Lajos;Baja;6500\nNagy;László;Székesfehérvár;8000\nTamási;Péter;Veszprém;8200" > dokumentumok/fontos.txt

02.
Készíts egy "projekt" nevű könyvtárat, majd benne egy "adatok.txt" és "kimenet.txt" fájlt! A "kimenet.txt" üres legyen az "adatok.txt" pedig a következőket tartalmazza:

Kovacs Tamas    Szeged  6000    06-30-3874656
Szanto Katalatin        Szekesfehervar  8000    06-20-2398763
Nagy Lilla      Veszprem        8200    06-70-8574923
Toth Tihamer    Budapest        1118    06-20-4987327
Vince Iren      Balatonalmadi   8220    06-70-3977428
Nagy Zsofi      Szeged  6000    06-70-8574923
Zold Peter      Ajka    8400    06-20-2345976
Pal Peter       Veszprem        8200    06-88-1234567

mkdir projekt
nano projekt/adatok.txt
másolás, beillesztés, mentés
touch projekt/kimenet.txt

03.
Listázd ki a "dokumentumok" könyvtár tartalmát, majd jelenítsd meg az utolsó három sort!

ls -l dokumentumok | tail -n 3

04.
Írasd ki egyszerre a "dokumentumok/fontos.txt" és "projekt/adatok.txt" fájlok tartalmának első négy sorát!

cat dokumentumok/fontos.txt projekt/adatok.txt | head -n 4

05.
Vágd ki a "projekt/adatok.txt" fájl tartalmának második és harmadik karakterét!

cat projekt/adatok.txt | cut -c 2-3

06.
Rendezd sorrendbe az "dokumentumok/fontos.txt" sorait az első mező alapján növekvő sorrendben!

cat dokumentumok/fontos.txt | sort -k 1

07.
Listázd ki az összes .txt fájlt a "projekt" könyvtárban, majd számold meg őket!

ls -1 projekt/*.txt | wc -l

08.
Vágd ki az "dokumentumok/fontos.txt" fájlban található sorok második mezőjét, amelyeket a ";" karakter választ el!

cat dokumentumok/fontos.txt | cut -d';' -f2

09.
Hozz létre három fájlt a "projekt" könyvtárban: "file1.txt", "file2.txt", "file3.txt". Minden fájl a következőt tartalmazza:

1. sor: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ac justo vel nisi vestibulum aliquet.
2. sor: Suspendisse potenti. Fusce eget tincidunt risus, ac vehicula nulla. Quisque auctor justo nec ante ullamcorper, at sodales justo tempor.
3. sor: Integer ac justo vel orci consequat vulputate. In hac habitasse platea dictumst. Proin quis urna vel turpis dictum scelerisque.
4. sor: Etiam at vestibulum velit. Sed vel justo vel ipsum vehicula bibendum. Nulla facilisi.
5. sor: Vivamus fringilla mi vitae augue auctor, in scelerisque libero tristique. Nunc euismod, libero nec varius luctus, erat velit vulputate odio.

nano file1.txt
cp file1.txt file2.txt
cp file1.txt file3.txt

10.
Hozz létre egy "backup" nevű könyvtárat, majd másold át az "projekt" könyvtár összes .txt fájlját!

mkdir backup
cp projekt/*.txt backup/

11.
Keress meg minden .txt fájlt kizárólag a "dokumentumok" könyvtárban.

find dokumentumok -maxdepth 1 -type f -name "*.txt"

12.
Keress meg minden .txt fájlt rekurzívan a "projekt" könyvtárban, és írd ki a nevüket sorban!

find projekt -type f -name "*.txt" -exec ls -1 "{}" \;

13.
Keress meg minden .txt fájlt a "dokumentumok" könyvtárban, majd írd ki az első három sorát mindegyiknek!

find dokumentumok -type f -name "*.txt" -exec head -n 3 "{}" \;

14.
Keress meg minden .txt fájlt a "backup" könyvtárban, majd másold át az összeset a "projekt" könyvtárba .old kiterjesztéssel!

find backup -type f -name "*.txt" -execdir cp "{}" projekt/"{}".old \;

15.
Keress meg minden .jpg fájlt a "~" könyvtárban, ne rekurzívan, amelyek mérete kisebb mint 50 KB!

find ~ -maxdepth 1 -type f -name "*.jpg" -size -50kOS. gyak 4
---
bash script futtatása, értékadás, kiíratás, argomentumok (paraméterek), változóba olvasás, elagázás, teszt utasítások, többszörös elágazás

A tanult parancsokat tudjuk összefűzni egy programmá.
Fordítóra nincs szükség, a shell magát a forráskódot értelmezi.
A programok elyan szöveges fájlok, amelyek futtathatók lesznek.
Kiterjesztés .sh, de bármi lehet.

Shell script létrehozása
---
1. nano helloworld.sh
2.
#!/bin/bash <- kötelező sor a shell script útvonala
echo "Hello World"
3. chmod u+x helloworld.sh
4. ./helloworld.sh <-relatív útvonal (vagy abszolult útvonal)
(Ez azért van így, hogy meg lehessen különböztetni a parancsoktól a scriptet)

A változók tipusnélküliek, tartalmazhatnak szöveget és számot is
A változókat nem kell deklarálni.

Értékadás
---
numbers=10
salary=$numbers (numbers változó értékét adom át a salary változónak)
text=hello
longtext="A fizetesem   $salary alma"

Kiíratás
---
echo $salary
10

echo $longtext
# A szóközöket csak paraméter elválasztásnak tekinti
A fizetesem 10 alma

echo "$longtext"
# Visszadja a teljes formázott stringet
A fizetesem    10 alma

echo '$longtext'
# Tartalom szószerinti kiíratása
A fizetesem $salary alma

Változónév elkülönítés zárójelezéssel:

A shell a helloworld nevű változót keresi:
$helloworld
A shell a hello nevű változót keresi a world-öt pedig stringként kezeli:
${hello}world

Parancssori argomentumok
./elso.sh arg1 arg2 (az arg1 a $1-ben, az arg2 a $2 tárolódik)

Hello World kiíratása argomentumokkal
#!/bin/bash
echo "$1" "$2"!

Az első argomentum hozzáfűzése egy fájlhoz
#!/bin/bash
echo "$1">"$2"

Az első argomentum másolása a másik argomentum mappájába
#!/bin/bash
cp "$1" "$2"

Szöveg bekérése
----
A read parancs segítségével szöveg bekérése a shell scriptbe
A read egy sort olvas be
read változo1 változo2
read x y z (ha csak egy szó szó van akkor az y, z változó üres lesz)

Példa (login.sh)
#!/bin/bash
echo "Kerem, adja meg a nevet:"
read name
echo "Kerem, adja meg a jelszavat:"
read -s password # beírt karakterek elrejtése
echo "Kedves ${name}, most már belephet!"

Elágazás (if)
---
if; then; fi

Rövid alak, a blokkok elválasztása ";"-vel
if ls sorok.txt; then echo "Van ilyen fajl"; else echo "Nincs ilyen fajl"; fi

Hosszú alak, nem minden sorban egy új blokk
if ls sorok.txt
	then echo "Van ilyen fajl"
	else echo "Nincs ilyen fajl"
fi

Vegyes alak, eliffel
if [ feltétel1 ]; then
    # első feltétel igaz
elif [ feltétel2 ]; then
    # második feltétel igaz
else
    # egyik feltétel sem igaz
fi

Az if utasítással használható a test utasítása, amely segítségével különböző tulajdonságokat tudunk megvizsgálni
test -e: exist, létezik-e
test -f: file, fájl-e az adott bejegyzés
test -d: directory, könyvtár-e az adott bejegyzés
test -s: üres-e vagy sem az adott bejegyzés

pl. Létezik-e sorok.txt
if test -e ~/dokumentumok/sorok.txt
	then echo "Van ilyen fajl"
	else echo "Nincs ilyen fajl"
fi

test utasításnak van egy rövidített formája a szögletes zárójel: []
Fontos, hogy miden elemet szóközzel kell elválasztani pl. [ "$1" -gt "$2" ]

Egész számok (integer) összehasonlítása
-eq egyenlő
if [ "$a" -eq "$b" ]
-ne nem egyenlő
if [ "$a" -ne "$b" ]
-gt nagyobb
if [ "$a" -gt "$b" ]
-ge nagyobb vagy egyenlő
if [ "$a" -ge "$b" ]
-lt kisebb
if [ "$a" -lt "$b" ]
-le kisebb vagy egyenlő
if [ "$a" -le "$b" ]

Egész számok összehasonlítása C szintaxisban. Csak dupla zárójellel működik!
kisebb ( < )
(("$a" < "$b"))
kisebb vagy egyenlő ( <= )
(("$a" <= "$b"))
nagyobb ( > )
(("$a" > "$b"))
nagyobb vagy egyenlő ( >= )
(("$a" >= "$b"))

Szövegek (string) összehasonlítása
= Egyenlő
== Az egyenlőség operátor (==) másként viselkedik a dupla zárójeles teszten belül, mint az egyszerű zárójelben.

A dupla zárójel ([[ ... ]]) a bash shell speciális szerkezete, amelyet általában a feltételes kifejezésekhez használunk. A dupla zárójelben a bash kevésbé érzékeny a speciális karakterekre, mint például a <, >, &&, ||, amelyek az egyszerű zárójelben ([ ... ]) általában problémákat okozhatnak. Mivel a dupla zárójelben a bash sokkal rugalmasabban értelmezi ezeket a karaktereket, így általában nem szükséges a karakterek escape-je.

[[ $a == z* ]]   # Igaz, ha $a "z"-vel kezdődik (mintaillesztés).
[[ $a == "z*" ]] # Igaz, ha $a megyezik z*-al (szó szerinti egyezés).
[ "$a" == z* ] # Igaz, ha $a "z"-vel kezdődik (mintaillesztés).
[ "$a" == "z*" ] # Igaz, ha $a megyezik "z*"-al (szó szerinti egyezés).

!= nem egyenlő
if [ "$a" != "$b" ]

< kisebb, mint (ASCII ábécé sorrend alapján)
if [[ $a < $b ]] # Nem kell zárójel, ha a változó nem tartalmaz speciális karaktereket
if [ "$a" \< "$b" ] # "\" mondja meg a bash-nek, hogy a "<" jelet szószerint értelmezze

> nagyobb, mint (ASCII ábécé sorrend alapján)
if [[ "$a" > "$b" ]]
if [ "$a" \> "$b" ]

-z üres string, a hossza zéró
if [ -z "$s" ]

-n nem nulla
if [ -n "$s" ]

Példa nagyobb.sh (paraméteres)
Döntsük el, hogy az első paraméterben megadott szám-e a nagyobb-e, mint a második paraméterben megadott szám.

#!/bin/bash

if [ "$1" -gt "$2" ] #if (("$1" > "$2"))
    then
        echo "Az elso szam a nagyobb."
    else
        if [ "$1" -eq "$2" ] #if (("$1" == "$2"))
            then
                echo "A ket szam egyenlo."
            else
                echo "A masodik szam a nagyobb."
        fi
fi

Többszörös elágazás (case)
---
case: többszörös elágazás
A case után egy kifejezés, ezt követi egy in kulszó, majd a minta1, minta2

Példa szamkivalaszto.sh
#!/bin/bash

echo "Kerem, valasszon egy szamot 1 és 3 kozott:"
read number

case $number in
  1)
    echo "Elso szamot valasztotta."
    ;;
  2)
    echo "Masodik szamot valasztotta."
    ;;
  3)
    echo "Harmadik szamot valasztotta."
    ;;
  *)
    echo "Hibas szamot valasztott."
    ;;
esac

expr (expresson parancs)
---
Aritmetikai és logikai kifejezések értékelésére szolgál

sum=$(expr 5 + 3) # összeadás
difference=$(expr 10 - 4) # kivonás
product=$(expr 4 * 6) # szorzás
quotient=$(expr 24 / 4) # osztás
remainder=$(expr 27 % 5) # maradékos osztás

C-szintaxisban:
sum=$((5 + 3))
difference=$((10 - 4))
product=$((4 * 6))
quotient=$((24 / 4))
remainder=$((27 % 5))

Példa osszeado.sh

#!/bin/bash
a=5
b=3
c=$(expr $a + $b)
echo "Az eredmeny: $c"Old meg bash szkriptekkel:

1. Készíts egy bash scriptet, amely beolvassa a felhasználó nevét és üdvözli azt egy személyre szabott üzenettel!

#!/bin/bash

echo "Kerem, adja meg a nevet:"
read name
echo "Udvozoljuk, $name!"

2. Írj egy bash scriptet, amely a parancssori argumentumok között megadott két számot összeadja, majd az eredményt kiírja a képernyőre!

#!/bin/bash

sum=$(($1 + $2))
echo "A ket szam osszege: $sum"

3. Hozz létre egy bash scriptet, amely a felhasználótól bekér egy fájlnevet, majd ellenőrzi, hogy a megadott fájl létezik-e a dokumentumok mappában! Ha igen, írja ki "A fájl létezik.", ha nem, akkor írja ki "A fájl nem létezik."!

#!/bin/bash

echo "Kérem, adjon meg egy fájlnevet:"
read filename

if [ -e ~/dokumentumok/$filename ]
then
    echo "A fájl létezik."
else
    echo "A fájl nem létezik."
fi

4. Írj egy bash scriptet, amely két számot olvas be a felhasználótól, és meghatározza, hogy melyik a nagyobb, vagy ha egyenlőek, akkor erről tájékoztatja a felhasználót!

#!/bin/bash

echo "Kérem, adjon meg két számot:"
read num1
read num2

if [ "$num1" -gt "$num2" ]
then
    echo "$num1 nagyobb, mint $num2."
elif [ "$num1" -eq "$num2" ]
then
    echo "A két szám egyenlő."
else
    echo "$num2 nagyobb, mint $num1."
fi

5. Írj egy bash scriptet, amely egy megadott fájlt másol egy másik megadott mappába!

#!/bin/bash

echo "Kérem, adja meg a forrásfájl nevét:"
read source_file

echo "Kérem, adja meg a célkönyvtár nevét:"
read destination_dir

cp "$source_file" "$destination_dir"
echo "A fájl másolása sikeres volt."

6. Írj egy bash scriptet, amely ellenőrzi, hogy egy adott fájl létezik-e, és ha igen, akkor megvizsgálja, hogy az üres-e vagy sem! Ha az adott fájl nem létezik, írja ki a "A fájl nem található." üzenetet!

#!/bin/bash

echo "Kérem, adjon meg egy fájl nevét:"
read filename

if [ -e "$filename" ]; then
    if [ -s "$filename" ]; then
        echo "A fájl létezik és nem üres."
    else
        echo "A fájl létezik, de üres."
    fi
else
    echo "A fájl nem található."
fi

7. Készíts egy bash scriptet, amely bekéri a felhasználótól egy könyvtár nevét, majd kiírja a könyvtárban található összes fájl és alkönyvtár nevét!

#!/bin/bash

echo "Kérem, adjon meg egy könyvtár nevét:"
read directory

echo "A könyvtár tartalma:"
ls -a $directory

8. Készíts egy bash scriptet, amely bekéri a felhasználótól két számot, majd összeadja azokat és az eredményt kiírja egy fájlba!

#!/bin/bash

echo "Kérem, adjon meg két számot:"
read num1
read num2

sum=$(($num1 + $num2))
echo "Az összeg: $sum" > sum.txt
echo "Az összeg ki lett írva a sum.txt fájlba."

9. Írj egy bash scriptet, amely eldönti, hogy a megadott szám páros vagy páratlan!

#!/bin/bash

echo "Kérem, adjon meg egy számot:"
read num

if [ $(($num % 2)) -eq 0 ]; then
    echo "$num páros szám."
else
    echo "$num páratlan szám."
fi

10. Írj egy bash scriptet, amely a felhasználótól bekér egy számot, majd megállapítja, hogy az adott szám pozitív, negatív vagy nulla!

#!/bin/bash

echo "Kérem, adjon meg egy számot:"
read num

if [ $num -gt 0 ]; then
    echo "A szám pozitív."
elif [ $num -lt 0 ]; then
    echo "A szám negatív."
else
    echo "A szám nulla."
fiOS. gyak 5
---
backtick, for ciklus, while ciklus, tömb, speciális változók, elérési utak vágása, függvények, csere a sed segítségével

Parancsbehelyettesítés
---
Szintaxis: $(command) vagy `command`
` = altgr+7

Példa:
A text változó értéke a list.txt első sora
text=$(cat ~/os/docs/list.txt | head -n 1)

For ciklus (elsődlegesen listák bejárására)
---
Alap szintaxis:

for változó in [LISTA]
do
  [UTASÍTÁSOK]
done

1. Szintaxis stringek esetén:
for element in Hydrogen Helium Lithium Beryllium
do
  echo "Element: $element"
done

2. Szintaxis egy meghatározott intervallum (0-tól 3-ig számok) esetén:
for i in {0..3}
do
  echo "Number: $i"
done

3. Szintaxis egy meghatározott intervallumon rögzített lépésközzel csökkenő módon:
for value in {10..0..2}
do
echo $value
done

4. C szintaxis használata esetén:
for ((num = 1; num <= 5; num++))
do
echo $num
done

5. Szintaxis fájlok bejárása:
for file in ~/docs/*
do
  echo "Processing $file file..."
  cat "$file"
done

Használható még a break utasítás (azonnal hagyja el a ciklust) és a continue utasítás (azonnal lépjen a következő iterációba) is.

While ciklus (elsődlegesen teszt utasítások feltételeinek vizsgálatára, valamint fájlok soronkénti feldolgozására)
---
Alap szintaxis:
while [teszt utasítás/parancs/feltétel]
do
<utasítások>
done

1. Szintaxis teszt utasítás használata esetén:

Írjon egy basch scriptet while ciklus segítségével, amelyben a 1-től 10-ig íratjuk ki a számokat.

#!/bin/bash

counter=1
while [ $counter -le 10 ]
do
echo $counter
counter=$(( $counter + 1 )) #vagy (( counter++ ))
done

Ez egy egyszerű while ciklus, amelyben a counter változó kezdeti értéke 1. Test utasítás segítségével minden iterációban megvizsgáljuk, hogy a counter változó kisebb vagy egyenlő-e mint 10. A ciklusban az echo utasítás kiírja az adott számot a standard kimenetre, majd növeli az counter értékét egyel.

2. Szintaxis egy fájl sorainak beolvasására:

Írjon egy bash scriptet, amelyben beolvassuk soronként a sample.txt fájl tartalmát. Ha az aktuális sor tartalmazza az "ERROR" szót, akkor írassuk ki a képernyőre. 

#!/bin/bash

# Fájl neve
file="sample.txt"

# Olvassuk be a fájl tartalmát egy soronként
while read line
do
  # Ha az aktuális sor tartalmazza az "ERROR" szót,
  # akkor írjuk ki a sort a képernyőre
  if [[ "$line" == *"ERROR"* ]]
	then
		echo "$line"
  fi
done < "$file"

A fenti script egy sample.txt nevű fájlt olvas be, majd ha megtalálja az aktuális sorban az "ERROR" szót, akkor azt kiírja a képernyőre. A while read line sor olvassa be a fájl sorait, a if elagásban lévő test utasítás pedig ellenőrzi, hogy tartalmaz-e az aktuális sor "ERROR" szót. Ha igen, akkor a echo paranccsal kiírjuk az adott sort a képernyőre.

Tömb
---
Tömb definiálása:
number=(1 2 3 4 5 6)
fruits=("apple" "banana" "orange")

Adott elem elérése:
echo ${fruits[0]}  # apple

Tömb elemeinek kiíratása:
echo "${fruits[*]}" # "*" - összes elem visszaadása szóközökkel elválasztva

Tömb elemeinek soronkénti kiíratása:
for fruit in "${fruits[@]}" # "@" - összes elem a tömbben
do
    echo $fruit # elemek kiíratása soronként
done

Tömb elemeinek bejárása:
for ((i=0; i<${#fruits[@]}; i++)) # a "#" a fruits tömb teljes hosszát adja vissza
do
    echo "Index $i: ${fruits[i]}"
done

Új elem beszúrása a tömb végére 1. módszer:
fruits+=("kiwi")

Új elem beszúrása a tömb végére 2. módszer:

# Eredeti tömb
my_array=("banana" "orange")

# Az új tömb hozzáfűzése az eredeti tömbhöz
my_array=("${my_array[@]}" "apple")

Új elem beszúrása a tömb elejére 1. módszer:
# Eredeti tömb
my_array=("banana" "orange")

# Az új tömb hozzáfűzése az eredeti tömbhöz
my_array=("apple" "${my_array[@]}")

Új elem beszúrása a tömb elejére 2. módszer:
# A tömbben lévő elemek azonosítóit egyel jobbra elcsúsztatom
for ((i=${#fruits[@]}; i>0; i--))
do
    fruits[$i]=${fruits[$i-1]}
done

# Beszúrom az új elemet az első helyre
fruits[0]="pear"

Új elem beszúrása egy tetszőleges helyre:
my_array=("${my_array[@]:0:1}" "$new_element" "${my_array[@]:1}")
# Jelentés:
# "${my_array[@]:0:1}" - az eredeti tömb 0. indexétől 1 hosszúságú vágásig (ez az eredeti tömb 0. indexű eleme)
# "$new_element" - új elem
# "${my_array[@]:1}") - az eredeti tömb 1. indexe és az ezt követő elemek

Elem törlése:
unset fruits[1]  # banana elem törlése

Speciális változók
---

#!/bin/bash
echo "A script neve: $0"
echo "Az első argumentum: $1"
echo "Az argumentumok száma: $#"
echo "Az összes argumentum: $@"

Listában lévő argomentumok kiíratása:
#!/bin/bash

Argomentumok kiíratása
for argument in "$@"
do
	echo "$argument"
done

Az aktuális argomentumot kivágjuk az aktuális argomentumlistából és a többit pedig egyel előrébb csúsztatjuk:

while [ $# -ne 0 ] # C-szintaxis (($# != 0))
do
	echo $1
	shift
	# A argomentumlista csúsztatása az első iteráció után argomentum esetén: $1 kivágba, $2 -> $1, $3 -> $2)
	# shift szám esetén egy meghatározott szám szerint lép az argomentum listán
done

Elérési utak, elemek vágása
---
basename: az utolsó elemet hagyja meg
dirname: az utolsó elemet vágja ki

basename ./os/allatok.txt
allatok.txt

dirname ./os/allatok.txt
./os/allatok

Shell parancsok előfuttatása: $(parancs)

find . -type f -name "hudemely.txt"
./mellyen/mellyebben/legmellyebben/legeslegmellyebben/hudemely.txt

Fájlnév kivágása:
basename $(find . -type f -name "hudemely.txt")
hudemely.txt

Elérési út kivágása:
dirname $(find . -type f -name "hudemely.txt")
./mellyen/mellyebben/legmellyebben/legeslegmellyebben/

Függvények
---
Lehetőségek van a bash-ban is függvényeket írni.

A függvény saját paramétereit tudja elérni $1 $2 stb. változókkal, azonban a shell script változóit már nem, így azokat egy globális változóba kell tennünk, vagy át kell adnunk paraméterként.

Példa. Írjon egy olyan bash scriptetben, amely bekér egy nevet, majd ezt a nevet a hello függvénynek átadva kiíratja egy köszönéssel.

#!/bin/bash

# függvény definíció
hello() {
  echo "Szia, $1!"
}

# A fő program
echo "Kerem adja meg a nevet:"
read name

# függvény meghívása
hello $name

A fő programban bekérünk egy nevet a felhasználótól (read name), majd meghívjuk a hello függvényt ezzel a névvel (hello $name). A függvény meghívásakor a $name változó értéke átadódik a $1 paraméternek, majd végül kiíratásra kerül a köszönést követően.

sed (stream editor, elsődlegesen cserére használjuk)
---
Számos funkcióval rendelkező eszköz a szövegfeldolgozásra. Főként a szövegfájlokban végzett keresésre és helyettesítésre használják.

Szintaxis:
sed 's/hello/goodbye/' file.txt # A file.txt-ben az első előfordulását cseréli a "hello" szövegnek "goodbye" szövegre.

sed 's/mit/mire/; s/mit/mire/; s/mit/mire/;' file.txt # A file.txt-ben az első három előfordulás esetén cseréli a "hello" szöveget "goodbye" szövegre.

sed 's/mit/mire/g' file.txt # A file.txt-ben minden "mit" szöveget "mire" szövegre cserél.

sed -i 's/mit/mire/g' file.txt # Az -i kapcsolóval közvetlen a fájlban is elvégzi a cserét

sed 's/apple/& pie/g' file.txt # Az & reprezentálja az eredeti találatot. Ebben a példában megtartja az eredetit (apple) és kiegészíti a pie-jal.

sed 's/[a-z]/\U&/g' file.txt # Minden kisbetűt nagybetűre cserél. [a-z] reprezentálja a kisbetűket, a \U azt jelenti, hogy a találatot nagybetűsítjük.

sed 's/[A-Z]/\L&/g' file.txt # Minden nagybetűt kisbetűre cserél. [A-Z] reprezentálja a nagybetűket, a \L azt jelenti, hogy a találatot kisbetűsítjük.

sed 's/a//g' file.txt # Összes "a" betű törlése.

echo AAAAAAlmafaaaaa | sed 's/\([Aa]\)\1*/\1/g' # "A" duplikátumok törlése
# Magyarázat
# \([Aa]\) - Egy regexp csoport, amely tartalmazza az "A" és "a" betűket
# \1* - Sorszámozom az előző mintát, amely nullaszor vagy többször előfordulhat
# \1 - Visszahivatkozok az eredeti sorszámra

Példa. Cserélje le a hello összes "l" betűjét "L" betűre.

echo "hello" | sed 's/l/L/g'Old meg bash szkriptekkel:

1. Készíts egy bash scriptet, amely összeszámolja a kiindulási könyvtárban lévő összes .txt fájl sorait, amelyet egy változóban tárol el. Írja ki végül az összes sor értékét.

#!/bin/bash

total_lines=$(cat *.txt | wc -l)
echo "Az összes .txt fájlban összesen $total_lines sor található."

2. Írj egy bash szkriptet, ami kiírja a 0-tól 10 a számokat kettesével.
#!/bin/bash

for i in {0..10..2}
do
    echo $i
done  

3. Írj egy bash szkriptet, ami egy tömbben tárolja néhány kedvenc gyümölcsödet, majd kiírja az összes elemet külön sorba.
#!/bin/bash

fruits=("alma" "korte" "szolo" "narancs")
for fruit in "${fruits[@]}"
do
    echo $fruit
done

4. Írj egy bash szkriptet, amely az "Ellenseges kemhalozat felkutatasa es semlegesítése" szövegben minden "e" karaktert "X" karakterre cserél. Írassa ki az eredményt.

#!/bin/bash
modified_text=$(echo "Ellenseges kemhalozat felkutatasa es semlegesítese" | sed 's/e/X/g')

echo "Módosított szöveg: $modified_text"

5. Írj egy bash szkriptet, amely argomentumban megkap egy fájlnevet. Először ellenőrizze, hogy a megadott fájl létezik-e. Ezt követően írassa ki a kapott fájl utolsó előtti sorát.

#!/bin/bash

if [ ! -f "$1" ]
then
    echo "Hiba: A megadott fájl nem létezik."
    exit 1
fi

second_last_line=$(tail -n 2 "$1" | head -n 1)
echo "A(z) '$1' fájl utolsó előtti sora: $second_last_line"

6. Írjon egy bash szkriptet, amely bekér három darab számot. A számok közül keresse meg a legnagyobbat, majd írassa ki.

#!/bin/bash

echo "Kérem az első számot:"
read szam1

echo "Kérem a második számot:"
read szam2

echo "Kérem a harmadik számot:"
read szam3

if [ $szam1 -gt $szam2 ] && [ $szam1 -gt $szam3 ]; then
    echo "$szam1 a legnagyobb."
elif [ $szam2 -gt $szam1 ] && [ $szam2 -gt $szam3 ]; then
    echo "$szam2 a legnagyobb."
elif [ $szam3 -gt $szam1 ] && [ $szam3 -gt $szam2 ]; then
    echo "$szam3 a legnagyobb."
else
    echo "Egyenlőség van."
fi

7. Írjon olyan bash scriptet, amely a standard inputról bekér egy számot, ezt a számot hozzáfűzi az aktuális mappában lévő azon fájlokhoz, amelyek neve tartalmazza az "vizsga" szót.

#!/bin/bash
echo "Adjon meg egy szamot"
read number
for file in ./*vizsga*
do
	echo ${number} >> ${file}
done

8. Írjon olyan bash scriptet, amely az aktuális könyvtárban létrehoz egy alma.txt nevű fájlt, amelynek a tartalma az aktuális mappában található fájlok száma.

#!/bin/bash
find . -maxdepth 1 -type f | wc -l > alma.txt

9. Írjon egy bash szkriptet, amely egy bejelentkezési funkciót valósít meg. Ha felhasználói névként az admin2, jelszóként pedig a secret szerepel, akkor írja ki a program, hogy a bejelentkezés sikeres, ellenkező esetben azt, hogy sikertelen a bejelentkezés.

#!/bin/bash
# Type your Login Information
read -p 'Felhasznaloi nev: ' username
read -sp 'Jelszo: ' password

if (( $username == "admin2" && $password == "secret" ))
then
     echo -e "\nSikeres bejelentkezés"
else
     echo -e "\nSikertelen bejelentkezés"
fi

10. Írjon egy bash szkriptet, amely egy egyszerű játékot valósít meg. A játék, kérjen be egy számot és ha az a szám a 10 vagy az 20, akkor írja ki, hogy megnyerted a játékot, különben pedig azt, hogy elvesztetted a játékot.
#!/bin/bash

echo "Gondoltam egy számra! Próbáld meg kitalálni!"

read szam

if [ "$szam" -eq 10 ] || [ "$szam" -eq 20 ]
then
  echo "Gratulalok, nyertel!"
else
  echo "Sajnalom, nem nyertel!"
fi

11. Írjon egy bash szkriptet, amely paraméterként nevsor.txt fájl tartalmát soronként kiíratja.

#!/bin/bash
filename=$1
while read line
do
echo $line
done < $filename

12. Írjon olyan bash scriptet, amelynek tetszőleges számú paramétert megadhatunk. Írja ki a megadott paramétereket egymás alá, mindegyiket új sorba!

#!/bin/bash

for input in "$@"; do
    echo "$input"
done

13. Írjon olyan bash scriptet, amely paraméterként egy fájlt vár. Ha a fájl nem létezik, írja ki, hogy: "Nem megvalosithato.", majd lépjen ki. Ha létezik a fájl, akkor Írja ki a felhasználónak a fájl sorainak és szavainak a szorzatát!

#!/bin/bash

if [ -f $1 ]
then
        line=$(cat $1 | wc -l)
        echo "Sorok: $line"
        word=$(cat $1 | wc -w)
        echo "Szavak: $word"
        echo "Összesen: $((line * word))"
else
        echo "Nem megvalosithato."
fi

14. Írj egy bash szkriptet, ami átmásolja az összes .txt kiterjesztésű fájlt egy új mappába, amelynek neve "txt_files". A szkript először ellenőrizze, hogy létezik-e az adott mappa, ha nem, hakkor hozza létre.

#!/bin/bash

if [ ! -d "txt_files" ]
then
    mkdir txt_files
fi

cp *.txt txt_files/

15. Írj egy bash szkriptet, amely kiírja az aktuális könyvtárban található legkisebb és legnagyobb méretű fájl nevét.

#!/bin/bash

# Legkisebb méretű fájl neve
smallest_file=$(ls -l | sort -n -k5 | head -n 2 | tail -n 1 | cut -d ' ' -f 9)

# Legnagyobb méretű fájl neve
largest_file=$(ls -l | sort -nr -k5 | head -n 2 | tail -n 1 | cut -d ' ' -f 9)

echo "A legkisebb méretű fájl neve: $smallest_file"
echo "A legnagyobb méretű fájl neve: $largest_file"
OS. gyak 6
---
Reguláris kifejezések, a grep használata

A reguláris kifejezések olyan karakterláncok, amelyek segítségével könnyen és hatékonyan lehet keresni az adatok között. Olyan esetekre ad megoldást, amikor nem tudjuk megnevezni a karakterláncot, hanem csak a karakterláncot leíró "szabályokat" tudjunk megmondani.

Példa: Telefonszámok

Lehetséges formátumok
06704564453
+3670569678

Formátumok eltérő mintákat követnek
###########
+##########

Megoldás: reguláris kifejezések használata
Létre kell hoznunk egy olyan mintát, amely az összes telefonszám formátumra tud biztosítani egyezést
^(\+36|06)(20|30|70)[0-9]{7}$ - Ez a formátum mind a két telefonszám formátumot azonosítani tudja

Példák:

abc - egyezés az "abc" kifejezésre
[hjkl] - egyezés a h, j, k vagy l karakterekre
07-?131 – egyezés "07131" vagy a "07-131" kifejezésekre
item[1-3] – egyezés az "item1", az "item2" vagy az "item3" kifejezésekre
codes* - egyezés a "code", a "codes", a "codess", a "codeesss" stb. kifejezésekre

Reguláris kifejezés részei
--
1. Normál karakterek
abc - illeszkedés az "abc" kifejezésre

2. Kvantifikátorok (mennyiségjelzők)
repeating* – illeszkedés "repeatin", "repeating", " repeatingggg" stb. kifejezésekre
Megjegyzés: A * kifejezés az előtte lévő "g" karakterre vonatkozik, amennyiből állhat 0 vagy bármennyi darab a kifejezés végén.

ab{1,3} – illeszkedés az "ab", az "abb", vagy az "abbb" kifejezésekkel
Megjegyzés: A {1,3} zárójeles érték az előtte lévő "b" karakterre vonatkozik, amelyből lehet, 1, 2 vagy 3 darab.

Karakter osztályok
[hjkl] – illeszkedés a "h", a "j", a "k" és az "l" karakterekre
\d – illeszkedés egy számjegy karakterre 0 és 9 között
. – illeszkedés bármilyen karakterre

Kvantifikátorok (mennyiségjelzők)
a? - 0 vagy 1 darab "a" karakter
a* - 0 vagy több darab "a" karakter
a+ - 1 vagy több darab "a" karakter
a{3} - pontosan 3 darab "a" karakter
a{3,} - 3 vagy több darab "a" karakter
a{3,6} - 3 és 6 között "a" karakter

Karakter osztályok
[abc] - a vagy b vagy c
[^abc] - bármi ami nem a vagy b vagy c
[a-z] - kisbetű
[^A-Za-z] - minden ami nem betű
\s - szóköz
\d - számjegy
\b - szóhatár (egy különálló szó keresésére)
. - bármilyen tetszőleges karakter

Speciális szekvenciák
$ - A string vége
^ - A string eleje
| - Vagy operátor
() - Zárójelek a csoportosításhoz

Az előző telefonszámos példa:
06704564453
+36205696789

^(\+36|06)(20|30|70)[0-9]{7}$

^ - a string eleje
(\+36|06) - előhívó lehet +36 vagy 06
(20|30|70) - körzetszám lehet 20, 30, vagy 70
[0-9]{7} - 7 db számjegy (0-9)
$ - string vége

Mi van akkor, ha kell illesztés vezetékes telefonszámra és mobil telefonszámra is?

^(06|\+36)((20|30|50)\d{7}|(\d{6}))$

A kifejezés az alábbiak szerint működik:

^ jelöli az illeszkedés kezdetét.
(06|\+36) a telefonszám előtagját illeszti, ami lehet "06" vagy "+36".
((20|30|50)\d{7}|\d{6}) a telefonszámot illeszti, ami attól függően, hogy a körzetszám 20, 30 vagy 50-e, 7 vagy 6 jegyű lehet. Az első zárójelben az illesztendő körzetszámok találhatók, a második zárójelben pedig a telefonszám 7 vagy 6 jegyűsége van meghatározva. A cső szimbólum a "vagy" műveletet jelenti.
$ jelöli az illeszkedés végét.

Példák az illeszkedő telefonszámokra:

+3612345678
0612345678
+36301234567
06301234567
+36501234567
06123456

Használat
- grep "keresett minta" myfile.txt
- alapesetben a minta pontos előfordulását keresi
- a keresés case sensitive

Opciók
-i: a keresés nem case sensitive
-v: a minta ne forduljon elő
-n: ne írja ki az illeszkedő sor számát
-E: kibővített (egrep) üzemmód
-o: csak az egyezést adja vissza nem az egész sort
-q: csendes üzemmód, csak visszatérési értékkel jelzi, hogy van-e találat

Működés
---
Amikor megadunk egy mintát, akkor a minta pontos előfordulását kerestük a fájlban.
A grep soronkénti feldolgozást végez
Ha van találat 0 a visszatérési értéke, ha nem talál, akkor 1 lesz a visszatérési értéke

Literal match 1:1-ben meg kell egyezni a mintának az adott sor mintjával

Regexp: Mintha kódolást vagy rövidítést szeretnénk használni

grep "az" myfile.txt - soronként megnézzük, hogy szerepel-e az "az" kifejezés

^ sor eleji egyezőség
grep "^Az " myfile.txt - kiír minden "Az" névelővel kezdődő sort

$ sor végi egyezőség
grep "\.$" myfile.txt - kiír minden "pontra" végződő sort

. a tetszőleges karakter
grep "..len" myfile.txt kiírja, hogy közvetlen de nem írja ki, hogy élen, mert ott csak egy karakter van

[] karaktercsoport illesztés
grep " [ea]z " myfile.txt vagy e vagy a betű (ez, az szó)

- intervallum illesztés
grep "^[A-Z]" myfile.txt kiír minden nagybetűvel kezdődő sort

* ismétlődés nulla vagy tetszőleges darabszámmal
grep "([A-Za-z ]*)" myfile.txt visszaad minden olyan sort, amelyben a zárójel között tetszőleges karakterek állnak

\ escépezés: speciális karakterek illesztése

Azért fontos, mert például a . karakter a reguláris kifejezésekben bármilyen karaktert jelent, kivéve az újsor karaktert (\n). Ez azt jelenti, hogy ha keresni akarunk pontosan egy pontot, akkor a \ karakterrel kell az előző karaktert "escapelnünk", hogy mentesítsük a speciális jelentés elől.

Pl. Kijelentő mondatok keresése a file.txt-ben.

grep "^(A |Az )?[A-Z][a-zA-Z]*\.$" file.txt

Ez a reguláris kifejezés keresni fog minden olyan sort a file.txt fájlban, amely:

^ - A sor elején kezdődik
(A |Az )? - Az opció megjelenik nullaszor vagy egyszer, amely megegyezik az A vagy Az névelővel, utána egy szóközzel
[A-Z] - Egy nagybetűvel kezdődik
[a-zA-Z]* - További betűk követik, de csak betűk lehetnek, kisbetűk és nagybetűk egyaránt
\. - Ponttal végződik
$ - A sor végén ér véget

grep -E kapcsoló vagy egrep: kibővített szabályrendszer
---
(): csoportosítás
grep -E "()" myfile.txt egy csoport megadása

|: vagy kapcsolat
grep -E "( ez | az )" myfile.txt vagy " ez " vagy " az "

*, +, ?: többszöri illesztés (1x, 2, többször, valahányszor)

grep -E "\([A-Za-z]*\)" sorok.txt: 0 vagy tetszőleges számú előfordulás
grep -E "\([A-Za-z]?\)" sorok.txt: 0 vagy 1 előfordulás
grep -E "\([A-Za-z]+\)" sorok.txt: 1 vagy több előfordulás
grep -E "\([A-Za-z]{2}\)" sorok.txt: 2 előfordulás
grep -E "\([A-Za-z]{1,2}\)" sorok.txt: 1 vagy 2 előfordulás
grep -E " [a-z]{4} " sorok.txt: 4 betűs szavak kiíratása

Szóhatárok szűrése
---
A \b szóhatár egy speciális karakter a reguláris kifejezésekben (regexekben), amely a szóhatárt jelöli. A szóhatár azt jelzi, hogy a keresett minta csak akkor egyezik meg, ha az előtte vagy utána levő karakter nem betűkarakter (pl. szóköz, tabulátor, írásjelek stb.), vagy a sor eleje vagy vége. Ez hasznos lehet, ha pontosan meghatározott szavakat vagy szóösszetételeket szeretnénk keresni a szövegben.

Például, ha megszeretnénk találni az "apple" szót egy szövegfájlban, de csak akkor, ha ez a szó önállóan áll egy sorban (tehát nem része más szónak vagy szóösszetételnek), akkor ezt a \b szóhatárral érhetjük el:

grep "\bapple\b" myfile.txt

Ez a parancs az "apple" szót csak akkor találja meg, ha az egy önálló szóként szerepel a sorban, és nem része más szónak, például "pineapple"-nek.

--
Fájlbeolvasás (ismétlés)

while read line
do
# echo $line | grep ... (ciklusmag)
done < file.txtOld meg reguláris kifejezésekkel:

1. Adott egy gyumolcs.txt szöveges állomány, amelyben minden sor egy szó vagy mondat. Írj egy reguláris kifejezést, amely csak azokat a sorokat adja vissza, amelyek "apple", "banana" vagy "orange" szavakat tartalmaznak!

Példa adatok
I like apples.
I hate tomatoes.
Bananas are my favorite fruit.
Oranges are rich in vitamin C.
I eat an apple a day.
I don't like bananas.

grep -E "( apple | banana | orange )" gyumolcs.txt
grep -E "(\bapple\b|\bbanana\b|\borange\b)" gyumolcs.txt

2. Adott egy nevek.txt szöveges fájl, amely tartalmazza az emberek nevét és életkorát, minden sorban egy személy. Írj egy reguláris kifejezést, amely csak azokat a sorokat adja vissza, amelyekben az életkor 18 és 25 év között van!

Példa adatok:
Anna, 20
Bela, 30
Csilla, 22
David, 16
Eszter, 27

grep -E "(1[89]|2[0-5])" nevek.txt

3. Adott egy emailcimek.txt szöveges állomány, amelyben minden sor egy e-mail címet tartalmaz. Írj egy reguláris kifejezést, amely csak azokat a sorokat adja vissza, amelyek gmail.com vagy yahoo.com e-mail címeket tartalmaznak!

Példa adatok:
johndoe@gmail.com
janedoe@yahoo.com
mike.smith@outlook.com
sarahjones@gmail.com
peterparker@yahoo.com
bobdoe@gmail.com

grep -E "(@gmail\.com|@yahoo\.com)$" emailcimek.txt

4. Adott egy ipcimek.txt szöveges állomány, amelyben minden sor egy IP-címet tartalmaz. Írj egy reguláris kifejezést, amely csak azokat a sorokat adja vissza, amelyek 192.168.x.x vagy 10.x.x.x IP-címeket tartalmaznak!

Példa adatok:
192.168.1.1
192.168.2.1
10.0.0.1
10.0.0.2
192.168.1.10
172.16.0.1

grep -E "^(192\.168\.|10\.)" ipcimek.txt

5. Adott egy evszamok.txt szöveges állomány, amelyben minden sor egy dátumot tartalmaz a következő formátumban: "éééé-hh-nn". Írj egy reguláris kifejezést, amely csak azokat a sorokat adja vissza, amelyek 2022. év április hónapban történt eseményekre utalnak!

Példa adatok:
2022-03-29
2022-04-01
2022-04-12
2022-05-15
2022-04-30
2021-04-15

grep -E '^2022-04-' evszamok.txt

6. Bash script. Adott egy adatok.txt szöveges állomány, amelyben minden sor egy e-mail cím. Írj egy reguláris kifejezést, amely csak azokat a sorokat adja vissza, amelyek domain névként "example.com"-ot használnak, és az e-mail cím felhasználói neve legalább 5 karakter hosszú!

Példa adatok:
john@example.com
jane@example.com
joe@example.com
mary@example.com
jack@example.org
alice@example.com

grep -E "^.{5,}@example\.com$" adatok.txt

7. Adott egy fontos.txt szöveges állomány, amelyben minden sor egy URL címet tartalmaz. Írj egy reguláris kifejezést, amely csak azokat a sorokat adja vissza, amelyek "http://" vagy "https://" protokollal kezdődnek, és ".com" vagy ".hu" végződéssel rendelkeznek!

Példa adatok:
http://example.com
https://openai.org
https://stackoverflow.com
http://google.hu
https://github.com

grep -E '^(http:\/\/|https:\/\/).*\.(com|hu)$' fontos.txt

8. Írj egy bash scriptet a grep és reguláris kifejezések használatával, amely beolvassa az allomasok.txt fájl tartalmát egy ciklus segítségével, majd egymás alá írassa ki a városok neveit.

Példa adatok:
Budapest, Moricz Zsigmond korter: 5 busz, 7 villamos, 2 metro all meg.
Szeged, Dom ter: 1 villamos, 3 busz, 2 trolibusz indul el.
Debrecen, Nagyerdei korut: 4 busz, 1 villamos, 1 metro halad el.
Pecs, Szechenyi ter: 2 trolibusz, 6 busz érkezik.
Gyor, Baross Gabor ter: 3 trolibusz, 4 villamos, 1 busz all meg.
Szekesfehervar, Bory-var: 2 busz, 1 trolibusz, 1 villamos indul el

#!/bin/bash

while read line
do
  city=$(echo "$line" | grep -oE "^[A-Z][a-z]+")
  echo "$city"
done < allomasok.txt

---
#!/bin/bash

while read line
do
  city=$(echo "$line" | grep -oE "^[^,]+")
  echo "$city"
done < allomasok.txt

9. Írj egy bash scriptet a grep és reguláris kifejezések használatával, amely beolvassa az allomasok.txt fájl tartalmát egy ciklus segítségével, majd egymás alá írassa ki a vilamosok számát. 

Példakimenet:
7 villamos
4 villamos
2 villamos

Példa adatok:
Budapest, Moricz Zsigmond korter: 5 busz, 7 villamos, 2 metro all meg.
Szeged, Dom ter: 1 villamos, 3 busz, 2 trolibusz indul el.
Debrecen, Nagyerdei korut: 4 busz, 1 villamos, 1 metro halad el.
Pecs, Szechenyi ter: 2 trolibusz, 6 busz érkezik.
Gyor, Baross Gabor ter: 3 trolibusz, 4 villamos, 1 busz all meg.
Szekesfehervar, Bory-var: 2 busz, 1 trolibusz, 1 villamos indul el

#!/bin/bash

# beolvassuk a fájlt és kiírjuk a villamosok számát
while read line
do
    tram_count=$(echo $line | grep -oE "[0-9]+ villamos")
        if [ -n "$tram_count" ]
                then
                        echo $tram_count
        fi
done < allomasok.txt

10. Írj egy bash scriptet a grep és reguláris kifejezések használatával, amely beolvassa az allomasok.txt fájl tartalmát egy ciklus segítségével, majd összeadja a buszok számát, amelyet végül kiírat.

Példa adatok:
Budapest, Moricz Zsigmond korter: 5 busz, 7 villamos, 2 metro all meg.
Szeged, Dom ter: 1 villamos, 3 busz, 2 trolibusz indul el.
Debrecen, Nagyerdei korut: 4 busz, 1 villamos, 1 metro halad el.
Pecs, Szechenyi ter: 2 trolibusz, 6 busz érkezik.
Gyor, Baross Gabor ter: 3 trolibusz, 4 villamos, 1 busz all meg.
Szekesfehervar, Bory-var: 2 busz, 1 trolibusz, 1 villamos indul el

#!/bin/bash

bus_count=0

while read line
do
        bus_number=$(echo "$line" | grep -oE "\b[0-9]+ busz\b" | grep -oE "[0-9]+")
        if [ -n "$bus_number" ]
                then
                        ((bus_count+=bus_number))
        fi
done < allomasok.txt

echo "A varosokban levo osszes busz szama: $bus_count"1. Belső tördelődésnél a folyamatok nem használják ki a rendelkezésre bocsátott partíciót.
Igaz/Hamis

2. Fix partíciós rendszereknél szükség lehet a szabad területek tömörítésére.
Igaz/Hamis

3. A FIFO lapcsere stratégia gyakran használt lapot is kitehet.
Igaz/Hamis

4. A demand paging (igény szerinti lapozás) esetén ritkán van laphiba.
Igaz/Hamis

5. A háttértárak foglalt területeinek nyilvántartására használt indexelt tárolás jó, mert gyors és közvetlen hozzáférést is lehetővé tesz.
Igaz/Hamis

6. Ami a memóriában a (szektor, blokk, szegmens, lap), az a háttértáron a (szektor, blokk, szegmens, lap).

7. Mik a skálázhatósággal kapcsolatos követelmények? Válasszon ki egyet vagy többet:
a. A rendszert egy központi helyről lehessen felügyelni.
b. Növekvő terhelésnél a rendszer ne törjön le hirtelen.
c. A rendszer növekedésével ne kelljen az architektúrát megáltoztatni.
d. Minden felhasználó egységesen lássa az összes csomópontot, munkája szempontjából mindegy legyen, hogy melyikre lép be.
e. További csomópontok üzembe állításánál a teljesítmény ne romoljon.

8. Az elosztott állományoknál használt helyi átmeneti tárakon végzett műveleteknél mit jelent az átmeneti tár konzisztenciája? Válasszon ki egyet:
a. A helyi tár tartalma érvénytelen.
b. A távoli tár tartalma érvénytelen.
c. A helyi tár tartalma és a távoli tár tartalma különböző.

9. Az elosztott állományoknál használt távoli eljárás hívás során a kommunikáció. Válasszon ki egyet:
a. szimmetrikus
b. asszimetrikus

10. Az elosztott állománykezelésnél hasznát távoli eljáráshívás során az adatok a helyi csomópontba másolódnak.
Igaz/Hamis
```
