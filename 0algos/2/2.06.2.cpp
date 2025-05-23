2.6.2.
#include <stdio.h> int main() { const float a=3.14;
char dir;
printf("const float a=%f\n", a);
printf("Select direction! (1/2)\n");
scanf("%c", &dir);
if (a=='1') { char a[200]= "Maroknyi szekely porlik, mint a szikla";
printf("string a=%s\n", a);
} else { unsigned long int a=456789;
printf("unsigned long int a=%lu\n", a);
} return 0;
} 
2.6.2. Kérje be majd írassa ki egy autó tulajdonságait! A tulajdonságok a 
következőek: márka - char[200], végsebesség - float, regisztrációs szám 
- hexa, tömeg double, típus név - char[300], utas szám - int, műholdas 
navigáció - char. 2.7. Blokkon belüli változók
