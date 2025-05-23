3.28.2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "cds.txt" #define MAX_WORD_LENGTH 16 #define TRUE 1 #define FALSE 0 typedef char TWord[MAX_WORD_LENGTH];
struct TCD { int Num;
TWord Name;
TWord * P;
};
void ReadCD(FILE * fd, struct TCD * A) { int i;
fscanf(fd, "%s", A->Name);
fscanf(fd, "%d", &A->Num);
printf("%s:\n", A->Name);
A->P = (TWord *)malloc(sizeof(TWord) * A->Num);
for (i = 0;
i < A->Num;
i++) { fscanf(fd, "%s", A->P[i]);
printf("\t%s\n", A->P[i]);
} } int ReadCDs(FILE * fd, struct TCD ** A) { int num, i;
fscanf(fd, "%d", &num);
(*A) = (struct TCD * )malloc(sizeof(struct TCD) * num);
for (i = 0;
i < num;
i++) ReadCD(fd, (*A) + i);
return num;
} int spec_strcmp(const char* s1, const char* s2) { int l1=strlen(s1), l2=strlen(s2);
int l=l1<l2?l1:l2,i;
for (i=0;i<l;i++) { if (s1[i]!='?' && s1[i]!=s2[i] && s1[i]!='*') { return -1;
} } return 0;
} void Search(struct TCD * A, char * S, int num) { int i = 0;
int j;
int success = FALSE;
while ((i < num) && (!success)) { j = 0;
while ((j < A[i].Num) && (spec_strcmp(A[i].P[j], S) != 0)) j++;
success = j < A[i].Num;
i++;
} if (success) printf("The %s is here: %s\n", S, A[i - 1].Name);
else printf("%s does not exists!\n", S);
} void FreeCDs(struct TCD * A, int num) { int i;
for (i = 0;
i < num;
i++) { free(A[i].P);
A[i].P = NULL;
} } int main(int argc, char * argv[]) { int CDNum;
struct TCD * CDs;
TWord Word;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} CDNum = ReadCDs(fd, &CDs);
fclose(fd);
printf("Program name: ");
scanf("%s", Word);
Search(CDs, Word, CDNum);
FreeCDs(CDs, CDNum);
free(CDs);
CDs = NULL;
return 0;
} 2 2007/11 2 BurningStudio RadioRama 2005/4 3 Doc2PDF Apollo Stellarium 
3.28.2. Írja át úgy az előző programot, hogy lehessen a keresésnél egy ? vagy egy * karaktert használni! A ? egy tetszőleges karakter helyett állhat, a * pedig a sztring végén lehet és azt jelezi, hogy még valamennyi karakter hátra van. Ha egy minta több program nevére is illeszkedik, akkor jelenítse meg mindet! 3.29. Leltár
