// 3.24. Egyszerű sztringfordító
// 3.24.1. Írjon programot, amely beolvas egy fájlból utasításokat és 
// végrehajtja a benne foglaltakat! Az utasítások három integer típusú 
// változót használhatnak: A, B, C. A script elején a változók értéke 0. A 
// lehetséges utasítások a következők: GET Op: Op lehet egy változó (A, B, 
// or C), ez a parancs beolvas egy tízes számrendszerbeli számot a 
// billentyűzetről, és az Op-ban tárolja. WRITE Op: Op értékét a 
// képernyőre írja. ADD Op1 Op2: Hozzáadja Op2-t Op1-hez, azaz Op1 = Op1 + 
// Op2. SUB Op1 Op2: Kivonja Op2-t Op1-ből, azaz Op1 = Op1 - Op2. MUL Op1 Op2: 
// Megszorozza Op1-et Op2-vel, azaz Op1 = Op1 * Op2. DIV Op1 Op2: Elosztja Op1-et 
// Op2-vel, azaz Op1 = Op1 / Op2. STOP: Ez a parancs a script végét jelzi. 
// Minden sorban csak egy parancs szerepel. Ha a sor # karakterrel kezdődik, azt 
// a sort megjegyzésnek tekintjük. Ezeknek a soroknak a végét is egy # 
// karakter jelzi. Az első # után egy szóköz karakter következik. A program 
// írja ki ezeket a sorokat a képernyőre, a # karakterek kivételével! 
// Például ha a sor a következő „# This is a comment! #”, a program a 
// következőt írja ki: „This is a comment!” Példa bemenet: # Type A: # GET 
// A # Type B: # GET B ADD A B # The sum: # WRITE A STOP Kimenet: Type A: 1 Type 
// B: 2 The sum: 3 
// 3.24.1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "script.txt" #define 
MAX_COMMAND_LEN 10 #define MAX_OPERAND_LEN 5 #define STOP_CMD "STOP" #define 
GET_CMD "GET" #define ADD_CMD "ADD" #define SUB_CMD "SUB" #define MUL_CMD "MUL" 
#define DIV_CMD "DIV" #define WRITE_CMD "WRITE" void Get(FILE * fd, int * N) { 
char Op[MAX_OPERAND_LEN];
fscanf(fd, "%s", Op);
scanf("%d", N + (Op[0] - 'A'));
} void WriteComment(FILE * fd) { char ch;
fscanf(fd, "%c", &ch);
do { fscanf(fd, "%c", &ch);
if (ch != '#') printf("%c", ch);
} while (ch != '#');
} void Add(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] += N[ ch2 - 'A' ];
} void Sub(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] -= N[ ch2 - 'A' ];
} void Mul(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] *= N[ ch2 - 'A' ];
} void Div(FILE * fd, int * N) { char Op1[MAX_OPERAND_LEN];
char Op2[MAX_OPERAND_LEN];
} char ch1, ch2;
fscanf(fd, "%s %s", Op1, Op2);
ch1 = Op1[0];
ch2 = Op2[0];
N[ ch1 - 'A' ] /= N[ ch2 - 'A' ];
void Write(FILE * fd, int * N) { char Op[MAX_OPERAND_LEN];
fscanf(fd, "%s", Op);
printf("%d\n", N[ Op[0] - 'A' ]);
} void Run(FILE * fd) { int Numbers[3];
Numbers[0] = Numbers[1] = Numbers[2] = 0;
char Command[MAX_COMMAND_LEN];
do { fscanf(fd, "%s", Command);
if (strcmp(Command, "#") == 0) WriteComment(fd);
if (strcmp(Command, GET_CMD) == 0) Get(fd, Numbers);
if (strcmp(Command, ADD_CMD) == 0) Add(fd, Numbers);
if (strcmp(Command, SUB_CMD) == 0) Sub(fd, Numbers);
if (strcmp(Command, MUL_CMD) == 0) Mul(fd, Numbers);
if (strcmp(Command, DIV_CMD) == 0) Div(fd, Numbers);
} if (strcmp(Command, WRITE_CMD) == 0) Write(fd, Numbers);
} while (strcmp(Command, STOP_CMD) != 0);
int main(int argv, char * argc[]) { FILE * fd = fopen(argv > 1 ? argc[1] : 
DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} Run(fd);
fclose(fd);
return 0;
} 
