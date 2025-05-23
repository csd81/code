3.42.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "message.txt" #define TRUE 1 #define FALSE 0 #define MAXLEN 51 typedef unsigned char ubyte;
ubyte GetChecksum(char * msg) { unsigned short sum = 0;
int i;
for (i = 0;
msg[i] != 0;
i++) sum += (unsigned char)msg[i];
printf("\nSum of \"%s\": %X\n", msg, sum);
sum = (ubyte)sum;
sum = 0xFF - sum + 1;
printf("The checksum: %X\n", sum);
return sum;
} int Checking(char * msg, ubyte chksm) { int i;
unsigned short sum = chksm;
for (i = 0;
msg[i] != 0;
i++) sum += (unsigned char)msg[i];
sum = (ubyte)sum;
return (sum == 0);
} void ReadMessages(FILE * fd) { int count;
int i;
unsigned int chksum;
char msg[MAXLEN];
fscanf(fd, "%d\n", &count);
printf("\n");
for (i = 0;
i < count;
i++) { if (fgets(msg, MAXLEN, fd) == NULL) { printf("Error\n");
return;
} msg[strlen(msg) - 1] = 0;
fscanf(fd, "%X\n", &chksum);
printf("\"%s\" %X ===> ", msg, chksum);
if (Checking(msg, chksum)) printf("Correct!\n");
else printf("Faulty!\n");
} } int main(int argc, char * argv[]) { FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadMessages(fd);
fclose(fd);
GetChecksum("This is a simple checksum example.");
printf("\n");
return 0;
} 
3.42.1. Írjon programot, amely képes ellenőrző összeg generálására egy üzenethez, és ezen összeg alapján ellenőrizni tudja a bejövő üzeneteket! Az ellenőrző összeg kiszámítása a következőképpen történik: Adjuk össze az üzenet minden bájtját, ha az összeg nagyobb, mint 255, akkor az összegnek csak a legkisebb bájtját tekintjük. Az így kapott bájt kettes komplemense (255 - sum + 1) lesz az ellenőrző összeg. Például az „ABCD” üzenet bájtjai: 0x41, 0x42, 0x43 and 0x44, így az összeg = 0x41 + 0x42 + 0x43 + 0x44 = 0x10A. Ebből legkisebb bájt: 0xA, a kettes komplemens pedig: 0xFF - 0xA + 0x1 = 0xF6. Az ellenőrzés menete: Az üzenettel együtt az ellenőrző összeg is megérkezik egy fájlban. A programnak össze kell adnia a beérkezett üzenet minden bájtját és az ellenőrző összeget. Ha az eredmény utolsó bájtja 0, akkor a beérkezett üzenet valószínűleg nem sérült. Egy fájl több üzenetet tartalmaz, az ellenőrző összegükkel együtt. A program olvassa be ezeket, és ellenőrizze őket! Írja ki a képernyőre az üzeneteket, az ellenőrző összegeket, és azt, hogy az üzenetek hibásak vagy helyesek! Végül számolja ki a „This is a simple checksum example.” üzenet ellenőrző összegét! Az input fájl formátuma: Első sor: Az üzenetek száma A többi sor felváltva tartalmaz üzeneteket és ellenőrző összegeket. Az üzenetek soraiban több szó is szerepelhet. Az üzenet után következő sor az üzenet ellenőrző összegét tartalmazza hexadecimális formában. Példa bemenet: 2 This is the first row of the message. C2 This is the second row ov the message. 6E Kimenet: "This is the first row of the message." C2 ===> Correct! "This is the second row ov the message." 6E ===> Faulty! Sum of "This is a simple checksum example.": C6C The checksum: 94 3.43. Statisztika

 