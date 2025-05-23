
2.40.3. Készítsen beolvasó programot! Jelezze ki az XML fájl szintaktikai hibáit! Például hibás tag, nyitó tag párja hiányzik vagy fordítva, két tag pár keresztben van. 2.41. Stopper
2.40.3. <Person> <Name>Jani</Name> <Age>22</Age> <Car> <ID>0</ID> <price>50.000000</price> </Car> <Car> <ID>2</ID> <price>12.369000<price> </Car> <Car> <ID>21</ID> <price>0.569000</price> </Car> </Person> <Person> <Name>Evi</Name> <Age>36</Age> <Car> <ID>6</ID> <price>21.000000</price> </Car> <Car> <ID>1<ID> <price>15.400000</price> </Car> </Person> <Person> <Name>Zotya</Name> <Age>25</Age> <Car> <ID>3</ID> <price>5.700000</price> </Car> </Person>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> int main() { char data[200][200];
char tag[50], newtag[50];
int idxI, idxJ, idxK, rows = 0, TagIdx = 0, Found = 0,Error=0;
FILE * fd = fopen("file.xml", "r");
if (!fd) { printf("file.xml is not found");
exit(1);
} while (!feof(fd)) { fscanf(fd, "%s", data[rows]);
rows++;
} for (idxI = 0;
idxI < rows;
idxI++) { idxJ = 0;
TagIdx = 0;
Found = 0;
if (data[idxI][idxJ] == '<' && data[idxI][idxJ + 1] != '/') { do { tag[TagIdx] = data[idxI][idxJ];
TagIdx++;
idxJ++;
} while (data[idxI][TagIdx - 1] != '>');
tag[TagIdx] = '\0';
newtag[strlen(tag) + 1] = '\0';
for (idxK = strlen(tag);
idxK > 0;
idxK--) { if (idxK != 1) { newtag[idxK] = tag[idxK - 1];
} else newtag[idxK] = '/';
} newtag[0] = tag[0];
if (strlen(data[idxI]) > strlen(tag)) { if (strstr(data[idxI], newtag)) { Found = 1;
data[idxK][0] = '\0';
} else { printf("Error at line: %d.\n\tNo close TAG for %s.\n", idxI + 1, tag);
Error=1;
} } else { for (idxK = idxI+1;
idxK < rows;
idxK++) { if (!strcmp(tag, data[idxK]) && !Found) { printf("At line %d.\n\tNo closeTAG for %s.\n", idxI+1,tag);
Error=1;
idxK=rows;
} else if (strstr(data[idxK], newtag) && !Found) { Found = 1;
data[idxK][0] = '\0';
} } } } } } if(!Error){ printf("No errors detected!\n");
} return 0;
