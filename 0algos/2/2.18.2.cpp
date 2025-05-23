
2.18.2.
#include <stdio.h>
#include <ctype.h> int main() { char roman[30];
int arabian = 0, size, idxI;
printf("Roman number: ");
scanf("%s", roman);
size = strlen(roman);
for (idxI = 0;
idxI < size;
idxI++) { roman[idxI] = toupper(roman[idxI]);
} for (idxI = 0;
idxI < size;
idxI++) { switch (roman[idxI]) { case 'I': if (roman[idxI + 1] == 'X') { 
arabian += 9;
idxI += 1;
} else { if (roman[idxI + 1] == 'V') { arabian += 4;
idxI += 1;
} else { arabian += 1;
} } break;
case 'V': arabian += 5;
break;
case 'X': if (roman[idxI + 1] == 'C') { arabian += 90;
idxI += 1;
} else { if (roman[idxI + 1] == 'L') { arabian += 40;
idxI += 1;
} else { arabian += 10;
} } break;
case 'L': arabian += 50;
break;
case 'C': if (roman[idxI + 1] == 'M') { arabian += 900;
idxI += 1;
} else { if (roman[idxI + 1] == 'D') { arabian += 400;
idxI += 1;
} else { arabian += 100;
} } break;
case 'D': arabian += 500;
break;
case 'M': arabian += 1000;
break;
} } } printf("%d\n", arabian);
return 0;

2.18.2. Ne csak egy darab számjegyet, hanem egy több karakterből álló 
számot alakítson át! 
