2.7.1. Hozzon létre egy olyan main függvényt, amelyben 3 különböző típusú, 'a' nevű változó szerepel! Az egyes változók típusai: const float, char [200], unsigned long int. Ugyanolyan nevű változókat egy függvényben belül úgy tud létrehozni, hogy a változó definiálások különböző blokkokban vannak. Egy negyedik változóba kérje be, melyik blokkba menjen be a program, írassa ki az ott lévő a változó értékét! 2.8. Formázott kimenet
2.7.1.
#include <iostream> using namespace std;
int main () { int direction;
cout << "Choose a direction: (1) const float, (2) char [200], (3) unsigned long int" << endl;
cin >> direction;
} if (direction==1) { const float a=12.345;
cout << "a=" << a << endl;
} if (direction==2) { char a[200]=„test123”;
cout << "a=" << a << endl;
} if (direction==3) { unsigned long int a=98765;
cout << "a=" << a << endl;
} if (direction<1 || direction>3) { cout << "The direction value is incorrect" << endl;
} return 0;

