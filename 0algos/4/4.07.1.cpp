// c++11
4.7.1. Kérjünk be egy tetszőleges egész számot (n), majd egy listába tegyük be 2-től n-ig a természetes számokat! Vegyünk ki minden nem prím számot a listából! Ötlet: a lista első eleme (2) prím, minden olyan számot törlünk, amely osztható ezzel a számmal (az első iterációban 2 kivételével az összes páros szám törlődik). A megmaradt elemek közül a következő ismét prím, töröljük ennek is minden többszörösét. Ezt ismételjük addig, amíg a lista végére nem érünk, ekkor írjuk ki a listát! 4.8. Halmazműveletek

 
#include <stdio.h>
#include <stdlib.h> struct PrimeArray { int current_number;
struct PrimeArray* next;
};
void UploadPrimeArray(struct PrimeArray*, int);
void ListPrimeArray(struct PrimeArray);
void RemoveNotPrimes(struct PrimeArray*);
void FreePrimeArray(struct PrimeArray*);
int main() { int MAX_NUMBER;
struct PrimeArray my_prime_array;
printf("Pleas enter a number, the orignal list will be generated from 2 to this number.\n");
scanf("%d", &MAX_NUMBER);
printf("The original list:\n");
UploadPrimeArray(&my_prime_array, MAX_NUMBER);
ListPrimeArray(my_prime_array);
RemoveNotPrimes(&my_prime_array);
printf("\n\nThe list, after removing not primes:\n");
ListPrimeArray(my_prime_array);
FreePrimeArray(&my_prime_array);
return 0;
} void UploadPrimeArray(struct PrimeArray* first, int max_number) { int i;
struct PrimeArray* actual;
actual = first;
actual->current_number = 2;
actual->next = NULL;
for (i = 3;
i <= max_number;
++i) { actual->next = (struct PrimeArray*)malloc(sizeof(struct PrimeArray));
actual = actual->next;
actual->current_number = i;
actual->next = NULL;
} } void ListPrimeArray(struct PrimeArray first) { int i = 1;
struct PrimeArray* actual = &first;
while (actual) { printf("%3d.element: %3d\n", i++, actual->current_number);
actual = actual->next;
} } void RemoveNotPrimes(struct PrimeArray* first) { struct PrimeArray* actual, *prev, *next;
while (first->next) { actual = first->next;
prev = first;
next = actual->next;
while (actual->next) { if ((actual->current_number % first->current_number) == 0) { free(actual);
actual = next;
next = actual->next;
prev->next = actual;
} else { prev = actual;
actual = actual->next;
next = actual->next;
} } printf("\nInner steps (%%%d)\n", first->current_number);
ListPrimeArray(*first);
first = first->next;
} } void FreePrimeArray(struct PrimeArray* first) { fel struct PrimeArray* actual = first->next;
while (actual) { first = actual->next;
free(actual);
actual = first;
} } 
