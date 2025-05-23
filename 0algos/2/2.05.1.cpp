2.5.1. Egymásba ágyazott ciklusok segítségével határozza meg, hogy hány 
üres iteráció tesz ki egy másodpercet, ha a ciklusváltozó egész, illetve 
ha lebegőpontos! Minden ciklus 1000 lépést tegyen meg! Hány egymásba 
ágyazott ciklus kell, hogy a végrehajtási idő 5-10 másodperc legyen? 
2.5.1.
#include <stdio.h> int main() { int idxA, idxB, idxC, size=1000;
for(idxA = 0;
idxA < size;
idxA++) { for(idxB = 1;
idxB < size;
idxB++) { for(idxC = 1;
idxC < size;
idxC++) { } } } return 0;
} 