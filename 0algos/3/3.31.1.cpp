3.31.1. A könyvtárak nyilvántartást vezetnek a kikölcsönzött könyvekről. Ez tartalmazza a könyvek szerzőjét, címét, illetve a kölcsönzés lejáratának idejét. Tételezzük fel, hogy az aktuális dátum 2008. december 15. Írjon programot, amely beolvassa a kikölcsönzött könyvek listáját egy fájlból, és kilistázza azoknak a könyveknek az adatait, amelyek kölcsönzési ideje már lejárt! Használjon dinamikus tömböket és struktúrákat az adatok tárolására! Az input fájl formátuma: Első sor: A könyvek száma. A többi sor: Szerző Rövid_cím Év Hónap Nap A szerző neve és a könyv címe is egy-egy szó csak. Az év, hónap, nap a lejárat idejét jelölik. Példa bemenet: 3 Asimov Foundation 2009 1 20 Herbert Dune 2008 12 1 Dancs Terror 2008 11 30 Kimenet: Title: Herbert Author: Dune Expiraton: 2008 12 1 Title: Dancs Author: Terror Expiraton: 2008 11 30 3.32. Szótár
3.31.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "lib1.txt" #define MAXLEN 20 #define YEAR 2008 #define MONTH 12 #define DAY 15 #define TRUE 1 #define FALSE 0 struct TBook { char title[MAXLEN];
char author[MAXLEN];
int year, month, day;
};
int ReadBooks(FILE * fd, struct TBook ** Books) { int num, i;
struct TBook * B;
fscanf(fd, "%d", &num);
(*Books) = B = (struct TBook*)malloc(sizeof(struct TBook) * num);
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s %d %d %d", B->title, B->author, &B->year, &B>month, &B->day);
B++;
} return num;
} int Later(int y, int m, int d) { if (y < YEAR) return TRUE;
else if (y == YEAR) { if (m < MONTH) return TRUE;
else if (m == MONTH) { if (d < DAY) return TRUE;
} } return FALSE;
} void PrintBooks(struct TBook * B, int num) { int i;
printf("\n");
for (i = 0;
i < num;
i++) { } } if (Later(B[i].year, B[i].month, B[i].day)) printf("Title: %s\nAuthor: %s\nExpiraton: %d %d %d\n\n", B[i].title, B[i].author, B[i].year, B[i].month, B[i].day);
int main(int argc, char * argv[]) { int booknum;
struct TBook * Books;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} booknum = ReadBooks(fd, &Books);
fclose(fd);
PrintBooks(Books, booknum);
free(Books);
Books = NULL;
return 0;
} 
