
// 3.12.2. Készítsen statisztikát egy szövegben lévő szavak és mondatok 
számáról! 3.13. Kódolt beszéd
3.12.2.
#include <stdio.h>
#include <string.h> int main() { char text[80];
char nextChar;
int textSize, sentence, word, idxI;
} printf("Text= ");
gets(text);
textSize = strlen(text);
if (text[0] == '\0') sentence = word = 0;
else { sentence = 0;
word = 1;
} for (idxI = 0;
idxI < textSize;
idxI++) { nextChar = text[idxI];
switch (nextChar) { case ' ': word++;
break;
case '.': case '!': case '?': sentence++;
break;
} } printf("Vowel statistics:\n");
printf("Word: %d\n", word);
printf("Sentence: %d\n", sentence);
return 0;

