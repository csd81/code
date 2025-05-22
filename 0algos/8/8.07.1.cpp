// 8.7.1. James nagyon feledékeny, ezért emlékeztetőket szokott írni magának. Egy emlékeztető egy dátumot tartalmaz (év, hónap, nap), egy időpontot (órát), és egy emlékeztető kulcsszót. Az emlékeztetők összekeveredtek, ezért programot kell írni azok rendezésére. Az emlékeztetőket fájlból olvassa be! Írja ki a képernyőre a rendezett emlékeztetősorozatot! Tárolja az emlékeztetőket struktúrában, illetve dinamikus tömbökben! Az input fájl formátuma: Első sor: az emlékeztetők száma. A további sorok az emlékeztetőket tárolják a következő formátumban: Év Hónap Nap Óra Kulcsszó Az év, hónap, nap és óra értékei pozitív egészek. A szó maximális hossza 20 karakter. A sorokban az adatok szóköz karakterekkel vannak elválasztva. Példa bemenet: 2 2008 11 20 12 Bank 2008 10 16 16 Dentist Kimenet: Year: 2008 Month: 10 Day: 16 Hour: 16 Dentist Year: 2008 Month: 11 Day: 20 Hour: 12 Bank 

// 8.7.1.
#include <stdio.h>
#include <stdlib.h>
#include <memory.h> #define DEFAULT_INPUTFILE "memo1.txt" #define MAX_MEMO_LEN 21 #define TRUE 1 #define FALSE (!TRUE) struct TMemo { int Year;
int Month;
int Day;
int Hour;
char m[MAX_MEMO_LEN];
};
int ReadMemos(FILE * fd, struct TMemo ** M) { int c, i;
struct TMemo * mptr;
fscanf(fd, "%d", &c);
(*M) = mptr = (struct TMemo*)malloc(sizeof(struct TMemo) * c);
for (i = 0;
i < c;
i++) { fscanf(fd,"%d %d %d %d", &mptr->Year, &mptr->Month, &mptr->Day, &mptr->Hour);
fscanf(fd, "%s", mptr->m);
mptr++;
} return c;
} void PrintMemos(struct TMemo * M, int c) { int i;
for (i = 0;
i < c;
i++) { printf("Year: %d\nMonth: %d\nDay: %d\nHour: %d\n\t %s\n\n", M->Year, M->Month, M->Day, M->Hour, M->m);
M++;
} } int Greater(struct TMemo * A, struct TMemo * B) { if (A->Year != B->Year) { return (A->Year > B->Year);
} else { if (A->Month != B->Month) { return (A->Month > B->Month);
} else { if (A->Day != B->Day) { return (A->Day > B->Day);
} else { if (A->Hour > B->Hour) return (A->Hour > B->Hour);
} } } return FALSE;
} void Sort(struct TMemo * M, int c) { int i, j, mini;
struct TMemo tmp;
for (i = 0;
i < c - 1;
i++) { mini = i;
for (j = i;
j < c;
j++) { if (Greater( M + mini, M + j)) mini = j;
} memcpy(&tmp, M + mini, sizeof(struct TMemo));
memcpy(M + mini, M + i, sizeof(struct TMemo));
memcpy(M + i, &tmp, sizeof(struct TMemo));
} } int main(int argc, char * argv[]) { struct TMemo * Memos;
int MCount = 0;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} } MCount = ReadMemos(fd, &Memos);
fclose(fd);
Sort(Memos, MCount);
PrintMemos(Memos, MCount);
free(Memos);
Memos = NULL;
return 0;




