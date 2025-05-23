3.27.2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "codedmsg.txt" #define MAX_WORD_LEN 15 char WORD[500];
typedef char TWord[MAX_WORD_LEN];
int ReadMessage(FILE * fd, TWord ** M) { int num, i;
fscanf(fd, "%d", &num);
(*M) = (TWord*)malloc(sizeof(TWord) * num);
for (i = 0;
i < num;
i++) fscanf(fd, "%s", (*M)[i]);
return num;
} void PrintMessage(TWord * M, int num) { int i;
for (i = 0;
i < num;
i++) printf("%s ", M[i]);
printf("\n");
} void Offset(TWord * M, int num, int offs) { int i, j, len;
for (i = 0;
i < num;
i++) { len = strlen(M[i]);
for (j = 0;
j < len;
j++) { M[i][j] += offs;
if (M[i][j] > 'Z') M[i][j] -= ('Z' - 'A' + 1 );
} } } void Decoding(TWord * M, int num) { int i = 0;
int j = num;
while ((i <= 'Z' - 'A') && (j >= num)) { Offset(M, num, 1);
j = 0;
while ((j < num) && (strcmp(M[j], WORD) != 0)) j++;
} } int main(int argc, char * argv[]) { int num;
TWord * Message;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} num = ReadMessage(fd, &Message);
fclose(fd);
printf("\nKnown word: ");
scanf("%s", WORD);
printf("\nThe coded message: ");
PrintMessage(Message, num);
Decoding(Message, num);
printf("The original message: ");
PrintMessage(Message, num);
printf("\n");
free(Message);
Message = NULL;
return 0;
} WKH TXLFN IRA 
3.27.2. Legyen a tartalmazott szó, a mostani „THE” is bemenet! Ha több lehetséges visszakódolás van, akkor jelenítse meg az összest! 3.28. CD katalógus
