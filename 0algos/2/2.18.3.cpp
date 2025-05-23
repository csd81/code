
2.18.3.
#include <stdio.h> int main() { char roman[20];
int arabian, idxI = 0;
printf("Arabianian number(1-4999): ");
scanf("%d", &arabian);
while (arabian > 0) { while ((arabian - 1000) >= 0) { roman[idxI++] = 'M';
arabian -= 1000;
} while ((arabian - 900) >= 0) { roman[idxI++] = 'C';
roman[idxI++] = 'M';
arabian -= 900;
} while ((arabian - 500) >= 0) { roman[idxI++] = 'D';
arabian -= 500;
} while ((arabian - 400) >= 0) { roman[idxI++] = 'C';
roman[idxI++] = 'D';
arabian -= 400;
} while ((arabian - 100) >= 0) { roman[idxI++] = 'C';
arabian -= 100;
} while ((arabian - 90) >= 0) { roman[idxI++] = 'X';
roman[idxI++] = 'C';
arabian -= 90;
} while ((arabian - 50) >= 0) { roman[idxI++] = 'L';
arabian -= 50;
} while ((arabian - 40) >= 0) { roman[idxI++] = 'X';
roman[idxI++] = 'L';
arabian -= 40;
} while ((arabian - 10) >= 0) { roman[idxI++] = 'X';
arabian -= 10;
} while ((arabian - 9) >= 0) { roman[idxI++] = 'I';
roman[idxI++] = 'X';
arabian -= 9;
} while ((arabian - 5) >= 0) { roman[idxI++] = 'V';
arabian -= 5;
} while ((arabian - 4) >= 0) { roman[idxI++] = 'I';
roman[idxI++] = 'V';
arabian -= 4;
} while ((arabian - 1) >= 0) { roman[idxI++] = 'I';
arabian -= 1;
} } roman[idxI++] = '\0';
printf("%s\n", roman);
return 0;
} 
2.18.3. Valósítsa meg a visszafele történő konverziót! 2.19. Háromszög
