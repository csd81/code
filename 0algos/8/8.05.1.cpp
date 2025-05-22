
8.5.1.
#include <stdio.h>
#include <malloc.h> typedef struct { int ID;
char name[50];
float price;
} headphone;
void exchange(headphone** a, int i, int j) { headphone *temp=a[i];
a[i]=a[j];
a[j]=temp;
} void downheap(headphone** a, int size, int parent) { int left=2*parent+1, right=2*parent+2, maxChild=left;
if (left>=size) return;
if (right<size && a[right]->ID > a[left]->ID) maxChild=right;
maxChild if (a[parent]->ID >= a[maxChild]->ID) return;
else { exchange(a, parent, maxChild);
downheap(a, size, maxChild);
subtree } } void buildheap(headphone** a, int n) { int v;
for (v=n/2-1;
v>=0;
v--) downheap(a, n, v);
} void heapsort(headphone** a, int n) { buildheap(a, n);
while (n>1) { n--;
exchange(a, 0, n);
array downheap(a, n, 0);
} } void printHeadphone(headphone* node) { if (!node) return;
printf("[ID: %3d, ", node->ID);
printf("name: %10s, ", node->name);
printf("price: %6.2f]", node->price);
} void printArray(headphone** array, int size) { int idxI=0;
for (;idxI<size;idxI++) { printHeadphone(array[idxI]);
printf("\n");
} } int main() { headphone b={23, "Genius", 2710}, c={7, "MS", 3250}, d={63, "Verano", 1160}, e={11, "LG", 6980}, f={9, "Samsung", 2370}, g={42, "Ele", 1260}, h={12, "Azona", 1230};
headphone* a[]={&b, &c, &d, &e, &f, &g, &h};
int size = sizeof (a) / sizeof(headphone*);
printf("Unordered heap:\n");
printArray(a, size);
heapsort(a, size);
printf("\nOrdered heap:\n");
printArray(a, size);
return 0;
} 
8.5.1. Valósítsa meg a kupacrendezést! A kupac legyen tömbbel reprezentálva! Minden tömbelem mutasson egy fejhallgató típusú struktúrára, amelynek az adattagjai: azonosító - egész, név - sztring, ár - lebegőpontos. Írja meg a következő függvényeket: egy fejhallgató adatainak kiírása, kupac kiírása (minden fejhallgató külön sorba, az azonos mezők egy oszlopban legyenek), a mutató tömb két elemének felcserélése, felszivárog, kupacépítés, kupacrendezés! 8.6. Szavak rendezése
