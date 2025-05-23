3.41.1. Egy fájlban egy legfeljebb 1000 karakter hosszú sztring található. Írjon programot, amely beolvassa ezt a fájlt, majd bekér a felhasználótól két szót! A második szó nem lehet hosszabb az elsőnél. A program keresse meg az első szó minden előfordulását a szövegben, és cserélje ki a második szóra. Írja ki a képernyőre az új szöveget, és a találatok számát! Példa: The original text: "This is a very simple text that can help for you to understand the task. " Type a word: simple Type the new word: easy 1 hits The new text: "This is a very easy text that can help for you to understand the task. " 3.42. Ellenőrző összeg
3.41.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "text.txt" #define MAX_TEXT_LENGTH 1001 #define MAX_WORD_LENGTH 21 #define TRUE 1 #define FALSE 0 void Change(char * t, char * w1, char * w2) { int i = 0;
int j;
int lent = strlen(t);
int lenw = strlen(w1);
int lenw2 = strlen(w2);
char tmp;
int hits = 0;
for (i = 0;
i < lent - lenw;
i++) { if (strncmp(t + i, w1, lenw) == 0) { tmp = t[i + lenw2];
strcpy(t + i, w2);
t[i + lenw2] = tmp;
for (j = i + lenw2;
j < lent - (lenw - lenw2);
j++) t[j] = t[j + lenw - lenw2];
t[j] = 0;
lent = strlen(t);
hits++;
} } } printf("\n%d hits\n", hits);
int main(int argc, char * argv[]) { char text[MAX_TEXT_LENGTH];
char word1[MAX_WORD_LENGTH];
char word2[MAX_WORD_LENGTH];
FILE * fd = fopen(argc > 1? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} if (fgets(text, MAX_TEXT_LENGTH - 1, fd) == NULL) { perror("Error");
fclose(fd);
return 0;
} fclose(fd);
printf("\nThe original text: \"%s\"\n\n", text);
printf("Type a word: ");
scanf("%s", word1);
printf("Type the new word: ");
scanf("%s", word2);
Change(text, word1, word2);
printf("\nThe new text: \"%s\"\n\n", text);
return 0;
} 
