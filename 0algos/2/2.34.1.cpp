
2.34.1.
#include <stdio.h> const int maxStudentNumber=100;
const int maxCodeLength=6;
typedef struct { char name[100];
unsigned int sex :1;
unsigned int grownUp :1;
unsigned int zodiac :6;
10 - Aquarious unsigned int religion :3;
- Hinduism, 4 - Budhism, 5 - other unsigned int bloodType :2;
unsigned int RH :1;
} Person;
void readPerson(Person *myPerson) { int dummy;
printf("name=");
scanf("%s", myPerson->name);
printf("sex: 0 - female, 1 - male ");
scanf("%d", &dummy);
myPerson->sex=dummy;
printf("grown up: 0 - no, 1 - yes ");
scanf("%d", &dummy);
myPerson->grownUp=dummy;
printf("zodiac: 0 - Aries, 1 - Taurus, 2 - Gemini, 3 - Cancer, 4 Leo, 5 - 
Virgo, \ 6 - Libra, 7 - Scorpio, 8 - Sagittarius, 9 - Capricorn, 10 Aquarious, 
11 - Pisces ");
scanf("%d", &dummy);
myPerson->zodiac=dummy;
printf("religion: 0 - Judaism, 1 - Christian, 2 - Islam, 3 Hinduism, \ 4 - 
Budhism, 5 - other ");
scanf("%d", &dummy);
myPerson->religion=dummy;
printf("bloodType: 0 - 0, 1 - A, 2 - B, 3 - AB ");
scanf("%d", &dummy);
myPerson->bloodType=dummy;
} printf("RH: 0 - -, 1 - + ");
scanf("%d", &dummy);
myPerson->RH=dummy;
void printPerson(Person *myPerson) { printf("person={name=%s, sex=", 
myPerson->name);
switch (myPerson->sex) { case 0: printf("female, ");
break;
case 1: printf("male, ");
break;
} printf("grown up=");
switch (myPerson->grownUp) { case 0: printf("no, ");
break;
case 1: printf("yes, ");
break;
} printf("zodiac=");
switch (myPerson->zodiac) { case 0: printf("Aries, ");
break;
case 1: printf("Taurus, ");
break;
case 2: printf("Gemini, ");
break;
case 3: printf("Cancer, ");
break;
case 4: printf("Leo, ");
break;
case 5: printf("Virgo, ");
break;
case 6: printf("Libra, ");
break;
case 7: printf("Scorpio, ");
break;
case 8: printf("Sagittarius, ");
break;
case 9: printf("Capricorn, ");
break;
case 10: printf("Aquarious, ");
break;
case 11: printf("Pisces, ");
break;
} printf("religion=");
switch (myPerson->religion) { case 0: printf("Judaism, ");
break;
case 1: printf("Christian, ");
break;
case 2: printf("Islam, ");
break;
case 3: printf("Hinduism, ");
break;
case 4: printf("Budhism, ");
break;
case 5: printf("other, ");
break;
} printf("bloodType=");
switch (myPerson->bloodType) { case 0: printf("0, ");
break;
case 1: printf("A, ");
break;
case 2: printf("B, ");
break;
case 3: printf("AB, ");
break;
} printf("RH=");
switch (myPerson->RH) { case 0: printf("-} ");
break;
case 1: printf("+} ");
break;
} printf("structure size in bytes = %d\n", sizeof(*myPerson));
} int main() { Person me;
readPerson(&me);
printf("\n");
printPerson(&me);
return 0;
} 
2.34.1. Írjon programot egyén adatainak a tárolásához! Az ember típus 
mezői a név (statikus tömb), nem, nagykorú-e, csillagjegye, vallása (5 
nagy vallás vagy egyéb), élő személy-e, vércsoport, RH csoport! 
Használjon megfelelő hosszú bitmezőket! Írjon bekérő és kiíró 
függvényt, a kiíró függvénynél ne számokat, hanem azok jelentéseit 
írja ki! Határozza meg a struktúra méretét! 
