#include <iostream>
#include "akcio.h"
#include "karakter.h"
#include "mohokarakter.h"
#include "valogatos.h"
#include "jatekosok.h"

using namespace std;

int main()
{

    // Akcio teszt: konstruktor, getterek
    cout << endl << "Akcio teszt: konstruktor, getterek" << endl;
    Akcio a1("mozgas", 6, 4); // mozgas típusú, 6 az értéke, 3-as nehézségű
    cout << a1.getTipus() << " " << a1.getErtek() << " " << a1.getNehezseg() << endl; // mozgas 6 4
    Akcio a2("tamadas", 10, 7);
    cout << a2.getTipus() << " " << a2.getErtek() << " " << a2.getNehezseg() << endl; // tamadas 10 7

    // Akcio teszt: * operátor
    cout << endl << "Akcio teszt: operator *" << endl;
    cout << *a1 << endl; // 1.5
    cout << *a2 << endl; // 1.42857

    // A Karakter osztály absztrakt, ahhoz nem tartozik teszt kód.

    // Mohokarakter teszt: konstruktor, getter, vegrehajt
    cout << endl << "Mohokarakter teszt: konstruktor, getter, vegrehajt" << endl;
    Mohokarakter m1("Moho1", 50, 5); // Moho1 a neve, 50 a pontszáma, 5 a megkapott nehézség.
    cout << m1.getNev() << " " << m1.getPont() << " " << m1.getNehezseg() << endl; // Moho1 50 5
    m1.vegrehajt(a1); // Ezt végrehajtja, mert legalább 5 pont, és a nehézség is belefér.
    cout << m1.getNev() << " " << m1.getPont() << " " << m1.getNehezseg() << endl; // Moho1 56 5
    m1.vegrehajt(a2); // Ezt nem hajtja végre, mert túl nehéz.
    cout << m1.getNev() << " " << m1.getPont() << " " << m1.getNehezseg() << endl; // Moho1 56 5
    Karakter *k1=new Mohokarakter("Moho2", 35, 8);
    cout << k1->getNev() << " " << k1->getPont() << endl; // Moho2 35
    k1->vegrehajt(a1); // Ezt végrehajtja.
    cout << k1->getNev() << " " << k1->getPont() << endl; // Moho2 41
    k1->vegrehajt(a2); // Ezt is végrehajtja.
    cout << k1->getNev() << " " << k1->getPont() << endl; // Moho2 51
    delete k1;

    // Mohokarakter teszt: getDarab
    cout << endl << "Mohokarakter teszt: getDarab" << endl;
    cout << Mohokarakter::getDarab() << endl; // 1
    Mohokarakter *m2=new Mohokarakter(m1);
    cout << Mohokarakter::getDarab() << endl; // 2
    delete m2;
    cout << Mohokarakter::getDarab() << endl; // 1

    // Valogatos teszt: konstruktor, getter, vegrehajt
    cout << endl << "Valogatos teszt: konstruktor, getter, vegrehajt" << endl;
    Valogatos v1("Valogat1", 60, "mozgas"); // Valogat1 a neve, 60 a pontszáma, mozgas a választott típus.
    cout << v1.getNev() << " " << v1.getPont() << " " << v1.getTipus() << endl; // Valogat1 60 mozgas
    v1.vegrehajt(a1); // Ezt végrehajtja, mert megfelelő a típusa.
    cout << v1.getNev() << " " << v1.getPont() << " " << v1.getTipus() << endl; // Valogat1 66 mozgas
    v1.vegrehajt(a2); // Ezt nem hajtja végre, mert más a típusa.
    cout << v1.getNev() << " " << v1.getPont() << " " << v1.getTipus() << endl; // Valogat1 66 mozgas
    Karakter *k2=new Valogatos("Valogat2", 25, "tamadas");
    cout << k2->getNev() << " " << k2->getPont() << endl; // Valogat2 25
    k2->vegrehajt(a1); // Ezt nem hajtja végre.
    cout << k2->getNev() << " " << k2->getPont() << endl; // Valogat2 25
    k2->vegrehajt(a2); // Ezt végrehajtja.
    cout << k2->getNev() << " " << k2->getPont() << endl; // Valogat2 35
    delete k2;

    // Jatekosok teszt: konstruktor, getDarab
    cout << endl << "Jatekosok teszt: konstruktor, getDarab" << endl;
    Jatekosok j1(4); // Max 4 karaktert tárolhat, de még nincs egy sem.
    cout << j1.getDarab() << endl; // 0

    // Jatekosok teszt: << opertátor (hozzáadáshoz)
    cout << endl << "Jatekosok teszt: operator << (hozzaadas)" << endl;
    j1<<new Mohokarakter("Moho3", 40, 5);
    j1<<new Valogatos("Valogat3", 30, "mozgas");
    j1<<new Mohokarakter("Moho4", 70, 6);
    j1<<new Valogatos("Valogat4", 80, "tamadas");
    cout << j1.getDarab() << endl; // 4
    j1<<new Valogatos("Valogat5", 80, "tamadas"); // Ez már nem fér el benne, de memóriaszemet nem szabad hagyni.
    cout << j1.getDarab() << endl; // 4

    // Jatekosok teszt: [] opertátor
    cout << endl << "Jatekosok teszt: operator []" << endl;
    Karakter *tmp=j1[1];
    if (tmp) cout << tmp->getNev() << " " << tmp->getPont() << endl; // Valogat3 30
    else cout << "Nincs ilyen karakter" << endl;
    Jatekosok j2(6);
    j2<<new Mohokarakter("Moho5", 70, 8);
    j2<<new Valogatos("Valogat6", 80, "tamadas");
    tmp=j2[1];
    if (tmp) cout << tmp->getNev() << " " << tmp->getPont() << endl; // Valogat6 80
    else cout << "Nincs ilyen karakter" << endl;
    tmp=j2[2]; // Bár elférne 6 karakter is, még nincs annyi, így ezen a helyen sincs valós karakter.
    if (tmp) cout << tmp->getNev() << " " << tmp->getPont() << endl;
    else cout << "Nincs ilyen karakter" << endl; // Nincs ilyen karakter

    // Jatekosok teszt: += opertátor
    cout << endl << "Jatekosok teszt: operator +=" << endl;
    int sikeres = (j1+=a1); // A 0, 1, és 2 helyen lévőknek megfelel, az utolsónak nem.
    cout << sikeres << endl; // 3
    sikeres = (j1+=a2); // Ez csak az utolsónak felel meg.
    cout << sikeres << endl; // 1

    // Jatekosok teszt: << opertátor (kiíráshoz)
    cout << endl << "Jatekosok teszt: operator << (kiiras)" << endl;
    Jatekosok j3(7);
    j3<<new Mohokarakter("Moho6", 40, 5);
    j3<<new Valogatos("Valogat7", 30, "mozgas");
    j3<<new Mohokarakter("Moho7", 70, 6);
    j3<<new Valogatos("Valogat8", 80, "tamadas");
    cout << j3 << endl;
    // Max darab: 7, jelenlegi: 4
    // Nev: Moho6, pont: 40 (Mohokarakter)
    // Nev: Valogat7, pont: 30 (Valogatos)
    // Nev: Moho7, pont: 70 (Mohokarakter)
    // Nev: Valogat8, pont: 80 (Valogatos)




	return 0;
}
