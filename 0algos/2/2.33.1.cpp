
2.33.1.
#include <stdio.h> const int maxStudentNumber=100;
const int maxCodeLength=6;
typedef struct { int sNum;
char sCode[maxStudentNumber][maxCodeLength+1];
float sPoints[maxStudentNumber];
} Class;
void printClass(Class *myClass, char comments[4][3][40]) { int idxI;
printf("%+10s%#20p%#20p%#20p\n", "address: ", myClass, myClass>sCode, myClass->sPoints);
printf("%+10s%20d%20c%20.1f\n", "value: ", myClass->sNum, myClass>sCode[0][0], myClass->sPoints[0]);
for (idxI=0;
idxI<4;
idxI++) { printf("%10s%20s%20s%20s\n", "", comments[idxI][0], comments[idxI][1], comments[idxI][2]);
} } int main() { Class myCl[2]={ {3, {"AA34", "BE3E", "CLY56"}, {16.4, 23.2, 40.0}}, {2, {"NMA444", "SE63"}, {13.2, 50.0}}, };
char myComments[4][3][40]= { {"myCl[0] "}, {"myCl[0].sNum", "myCl[0].sCode", "myCl[0].sPoints"}, {"", "myCl[0].sCode[0]", "myCl[0].sPoints[0]"}, {"", "myCl[0].sCode[0][0]"} };
printClass(&myCl[0], myComments);
printf("\n\n");
myComments[0][0][5] = '1';
myComments[1][0][5] = '1';
myComments[1][1][5] = '1';
myComments[1][2][5] = '1';
myComments[2][1][5] = '1';
myComments[2][2][5] = '1';
myComments[3][1][5] = '1';
printClass(&myCl[1], myComments);
return 0;
} 
2.33.1. Írjon programot, amelyben szemlélteti a karakteres képernyőn a struktúrák elhelyezkedését a memóriában! Hozzon létre egy osztály típusú struktúrát: hallgatók száma, hallgatók Neptun kódjai (statikus sztring tömb), hallgatók pontszámai (statikus lebegőpontos tömb)! Írjon függvényt, amely megjelenti a paraméterként átadott struktúra adattagjainak a címeit és értékeit (a tömb típusú mezőknek csak az első elemét kell megjeleníteni)! Írja ki azt is, hogy milyen más módon tud az adott címre hivatkozni! Ezt az információt is paraméterként adja át a kiíró függvénynek! Hozzon létre kételemű tömböt osztály típusú struktúrákból! Inicializálja a tömböt és hívja meg mindkét elemre a kiíró függvényt! 2.3. ábra: Lehetséges képernyőkép 2.34. Bitmezők
