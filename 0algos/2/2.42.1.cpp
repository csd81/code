2.42.1.
#include <stdio.h>
#include <sys/timeb.h>
#include <time.h> int main() { struct _timeb timebuffer;
char* timeline;
int start, act;
_ftime(&timebuffer);
start = timebuffer.time;
do { _ftime(&timebuffer);
timeline = ctime(&timebuffer.time);
act = timebuffer.time;
printf("\n%.8s.%hu", &timeline[11], timebuffer.millitm);
} while (act-start < 10);
return 0;
} 
2.42.1. Írjon programot, amely 10 másodpercen keresztül folytonosan kiírja az aktuális időt ezredmásodperc pontossággal! Használja az _ftime és ctime függvényeket! 2.43. Tippelés

