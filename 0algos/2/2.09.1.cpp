2.9.1.
#include <stdio.h> int main() { const int size=5;
double array[]={3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
int idxI, points=0;
char choice;
printf("How do you think the %%g will display the next numbers? Regular or 
normal?\n");
for (idxI=0;
idxI<size;
idxI++) { printf("\n%15.10lf ", array[idxI]);
_flushall();
printf("Decide and press enter to continue!");
scanf("%c", &choice);
printf("result: %g\n", array[idxI]);
printf("Was you selection correct? (y)es, (n)o:");
_flushall();
scanf("%c", &choice);
if (choice=='y') { points++;
} } } printf("You have %d of %d points.", points, size);
return 0;

2.9.1. Írjon programot, amely öt darab tömbben tárolt float típusú 
számról kérdezi meg, hogy azt a printf %g-el történő kiírásakor 
hagyományos (f) vagy normál (e) alakban jeleníti meg! A számot jelenítsük 
meg először %f-el! Írjuk ki a felhasználónak, hogy tippeljen, jelenítsük 
meg a választ %g-el, kérdezzük meg, hogy helyes volt-e a tipp! Számoljuk a 
helyes válaszokat! 
