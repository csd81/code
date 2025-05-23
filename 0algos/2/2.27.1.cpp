
2.27.1
#include <stdio.h> int main() { int data=42, code=666, temp;
int *realAddress=&data, *changedAddress=0, *tryAddress;
changedAddress = realAddress - code;
printf("The 1st key: %p\n", changedAddress);
printf("Press 1 if the other person arrived: ");
scanf("%d", &temp);
printf("The 2nd key: %d\n", code);
changedAddress = NULL;
code = 0;
printf("To retrieve the data provide the 1st key: ");
scanf("%p", &changedAddress);
printf("Provide the 2nd key: ");
scanf("%d", &code);
tryAddress = changedAddress + code;
} if (tryAddress==realAddress) printf("Access granted, the data is: %d\n", 
*tryAddress);
else printf("Access denied!\n");
return 0;

2.27.1. Írjon programot, amely egy titkos adatnak (változónak) a címét egy 
mutatóba és egy egészbe kódolja úgy, hogy a mutató és az egész összege 
a változó címét eredményezi! A program adja meg a két adatot két 
embernek egyenként. Később kérje be a mutatót és az egészet és ha őket 
összeadva visszakapjuk a változó címét, akkor írja ki a változó 
értékét. 2.28. Többszörös indirekció
