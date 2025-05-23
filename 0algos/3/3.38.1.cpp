3.38.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define SZOKOZ "....." char * morsecodes[26] = { ".=", "=...", "=.=.", "=..", ".", "..=.", "==.", "....", "..", ".===", "=.=", ".=..", "==", "=.", "===", ".==.", "==.=", ".=.", "...", "=", "..=", "...=", ".==", "=..=", "=.==", "==.."};
void getline(char * s, int maxlen) { char ch;
int i = 0;
do { ch = getchar();
if (ch!='\n') s[i++] = ch;
} while ((i < maxlen - 1) && (ch!='\n'));
s[i] = 0;
} char * coding(char * s) { int len = 1;
int i;
char * c;
for (i = 0;
i < strlen(s);
i++) if (s[i] != ' ') len += strlen(morsecodes[ s[i] - 'A' ]);
else len += strlen(SZOKOZ);
c = (char*)malloc(sizeof(char) * len);
len = 0;
for (i = 0;
i < strlen(s);
i++) { if (s[i] != ' ') { morsecodes[ s[i] - 'A']);
strcpy(c + len, morsecodes[ s[i] - 'A' ]);
len += strlen(morsecodes[ s[i] - 'A' ]);
} else { strcpy(c + len, SZOKOZ);
len += strlen(SZOKOZ);
} } c[len] = 0;
return c;
} int main() { char message[100];
char * morse;
printf("The message: ");
getline(message, 100);
printf("Message: \"%s\" \n", message);
morse = coding(message);
printf("The coded message: \"%s\"\n", morse);
free(morse);
morse = NULL;
return 0;
} 
3.38.1. Írjon programot, ami egy üzenetet Morze kóddá alakít! Az üzenet begépelése után a program foglaljon le memóriát a kódolt üzenet számára, kódolja az üzenetet és jelenítse meg azt! Használja az alábbi sztring tömböt az egye karakterek leképezésére! A szóköz karakter kódja 5 pont. char* morsecodes[26] = { ".=", "=...", "=.=.", "=..", ".", "..=.", "==.", "....", "..", ".===", "=.=", ".=..", "==", "=.", "===", ".==.", "==.=", ".=.", "...", "=", "..=", "...=", ".==", "=..=", "=.==", "==.."};
Példa bemenet: Az üzenet: SOS I AM WRITING A TEST Üzenet: "SOS I AM WRITING A TEST" A kódolt üzenet: "...===................===......==.=...=..=.==.......=.....=....=" 3.39. Mátrix szorzása vektorral
