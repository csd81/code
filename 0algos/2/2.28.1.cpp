
2.28.1.
#include <stdio.h> int main() { int data=42, *pData=&data, **ppData=&pData, 
***pppData=&ppData;
int idxI;
printf("%10s %#p %#p %#p %#p \n", "address: ", &pppData, &ppData, &pData, 
&data);
printf("%10s ", "");
for (idxI=0;
idxI<4;
idxI++) printf("-----------");
printf("\n%10s |%#p| |%#p| |%#p| |%10d| \n", "value:", pppData, ppData, pData, 
data);
printf("%10s ", "");
for (idxI=0;
idxI<4;
idxI++) printf("-----------");
printf("\n%10s %-15s%-15s%-15s%-15s", "variable:", "pppData", "ppData", 
"pData", "data");
printf("\n%10s %-15s%-15s%-15s%-15s", "", "", "*pppData", "*ppData", "*pData");
printf("\n%10s %-15s%-15s%-15s%-15s", "", "", "", "**pppData", "**ppData");
printf("\n%10s %-15s%-15s%-15s%-15s", "", "", "", "", "***pppData");
return 0;
} 
2.28.1. Írjon programot, amely a konzolos képernyőn szemléltet egy int*** 
mutatót és az általa mutatott értékeket! Írja ki a jelenlévő változók 
címét, értékét és hogy milyen alternatív módon lehet hivatkozni a 
változókra! 2.2. ábra: Lehetséges képernyőkép
