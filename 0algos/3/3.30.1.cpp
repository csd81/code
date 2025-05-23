3.30.1. A könyvtárakban a könyvek az Egyetemes Tizedes Osztályozás (ETO, angolul UDC) szerint vannak osztályozva. Minden könyvnek van egy ETO száma, amit a könyv témája határoz meg. Az ETO szám első számjegye a fő témát határozza meg: 0. Általános művek, bibliográfia, könyvtárügy. 1. Filozófia, pszichológia, logika, etika. 2. Vallás, egyházak, teológia. 3. Társadalomtudományok, közigazgatás, jog, oktatás. 4. Nem használt 5. Matematika, természettudományok, fizika, kémia. 6. Alkalmazott tudományok, műszaki tudományok, orvostudományok. 7. Művészetek, játék, sport, szórakozás. 8. Nyelvészet, irodalom 9. Régészet, földrajz, életrajz, történelem Például egy 543-as ETO számú könyvről tudjuk, hogy matematikával, vagy természettudományokkal foglalkozik. A többi számjegy a program szempontjából nem fontos. A „lib1.txt” fájlban könyvek adatai szerepelnek. A fájl tartalmazza a szerző nevét, a könyv címét, a kiadási évet és a könyv ETO számát. Írjon programot, amely beolvassa ezt a fájlt, listázza az egyes könyveket, végül összesítést ad, hogy hány könyv található a könyvtárban egy-egy a témában! Használjon dinamikus tömböket és struktúrákat az adatok tárolására! Az input fájl formátuma: Első sor: A könyvek száma. A többi sor formátuma: Szerző Rövid_Cím Kiadási év ETO (szóköz karakterekkel elválasztva). A szerző neve és a könyv címe maximum 20 karakterből áll, mindkettő egy-egy szó csak. Az ETO szám 3 karakterből áll. Példa bemenet: 3 Asimov Foundation 1980 820 Herbert Dune 1990 820 Dancs Terror 2001 512 Kimenet: Author: Asimov Title: Foundation Year of edition: 1980 UDC: 820 Language, Linguistics, Literature Author: Herbert Title: Dune Year of edition: 1990 UDC: 820 Language, Linguistics, Literature Author: Dancs Title: Terror Year of edition: 2001 UDC: 512 Matematika and natural sciences ************************************** Generalities: 0 books Philosophy, Psychology: 0 books Religion, Theology: 0 books Social sciences: 0 books vacant: 0 books Matematika and natural sciences: 1 books Applied sciences, Medicine, Technology: 0 books Arts, Recreation, Entertainment, Sport: 0 books Language, Linguistics, Literature: 2 books Geography, Biography, History: 0 books 3.31. Kikölcsönzött könyvek
3.30.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "lib1.txt" #define MAXLEN 21 #define MAXUDC 4 char * UDCClasses[10] = { "Generalities", "Philosophy, Psychology", "Religion, Theology", "Social sciences", "vacant", "Mathematics and natural sciences", "Applied sciences, Medicine, Technology", "Arts, Recreation, Entertainment, Sport" , "Language, Linguistics, Literature", "Geography, Biography, History"};
struct TBook { char title[MAXLEN];
char author[MAXLEN];
int edition;
char UDC[MAXUDC];
};
int ReadBooks(FILE * fd, struct TBook ** Books) { int num, i;
struct TBook * B;
fscanf(fd, "%d", &num);
(*Books) = B = (struct TBook*)malloc(sizeof(struct TBook) * num);
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s %d %s", B->title, B->author, &B->edition, B->UDC);
B++;
} return num;
} void CountBooks(struct TBook * B, int num) { int i;
int types[10];
for (i = 0;
i < 10;
i++) types[i] = 0;
printf("\n\n");
for (i = 0;
i < num;
i++) { printf("Author: %s\n Title: %s\nYear of edition: %d\nUDC: %s %s\n\n", B[i]. author, B[i].title, B[i].edition, B[i].UDC, UDCClasses[ B[i].UDC[0] - '0' ]);
types[ B[i].UDC[0] - '0' ]++;
} printf("\n**************************************\n\n");
for (i = 0;
i < 10;
i++) printf("%s: %d books\n", UDCClasses[i], types[i]);
printf("\n\n");
} int main(int argc, char * argv[]) { int booknum;
struct TBook * Books;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} booknum = ReadBooks(fd, &Books);
fclose(fd);
CountBooks(Books, booknum);
free(Books);
Books = NULL;
return 0;
} 
