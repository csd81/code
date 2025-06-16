#include <cstring>
#include <iostream>
#include "tantargy.h"
using namespace egyetem;

const int TANTARGYAK = 3;

void kiir(const Tantargy& t){
    std::cout <<"Kód: " <<  t.get_kod() << ", ";
    std::cout << "JegyekSzáma: "<< t.get_db() << ", ";
    std::cout << "Jegyek: ";
    for (unsigned int i = 0; i < t.get_db(); i++){
        std::cout << t.get_jegyek()[i] <<", ";
        }
    std::cout << std::endl;
    }



Tantargy tobbJegy(const Tantargy& t, const unsigned int ujmeret){
    if (ujmeret==t.get_db())
        return t;
    else if (ujmeret < t.get_db()){
        Tantargy uj;
        uj.set_kod(t.get_kod());
        uj.set_db(ujmeret);
        uj.set_jegyek(new unsigned int[ujmeret]);

            for (unsigned int i = 0; i <uj.get_db(); i++){
                uj.set_jegy(i, t.get_jegyek()[i]);
            }
            uj.set_atlag(uj.atl());
            return uj;
        }
    else {
        Tantargy uj;
        uj.set_kod(t.get_kod());
        uj.set_db(ujmeret);
        uj.set_jegyek(new unsigned int[ujmeret]);
        for (unsigned int i = 0; i < t.get_db(); i++){
            uj.set_jegy(i, t.get_jegyek()[i]);
        }
        for (unsigned int i = t.get_db(); i < ujmeret; i++){
            uj.set_jegy(i,  5);
        }
        uj.set_atlag(uj.atl());
        return uj;
    }
}

    Tantargy tobbJegy(const Tantargy& t, const unsigned int ujmeret, const int a, const int b) {
    if (ujmeret==t.get_db())
        return t;
    else if (ujmeret < t.get_db()){
        Tantargy uj;
        uj.set_kod(t.get_kod());
        uj.set_db(ujmeret);
        uj.set_jegyek(new unsigned int[ujmeret]);
        for (unsigned int i=0; i<ujmeret; i++){
            uj.set_jegy(i,  t.get_jegyek()[i]);
        }
        uj.set_atlag(uj.atl());
        return uj;
    }
    else {Tantargy uj;
        uj.set_kod(t.get_kod());
        uj.set_db(ujmeret);
        uj.set_jegyek(new unsigned int[ujmeret]);

        for (unsigned int i=0; i<t.get_db(); i++){
            uj.set_jegy(i, t.get_jegyek()[i]);
        }
        for (unsigned int i=t.get_db(); i<uj.get_db(); i++){
            if (i % 2 == 0) uj.set_jegy(i,a);
            else uj.set_jegy(i,b);
        }
        uj.set_atlag(uj.atl());
        return uj;
    }
}

    void felszabadit(Tantargy& t) {
    if (t.get_jegyek() != nullptr) {
        delete[] t.get_jegyek();
        t.set_jegyek(nullptr);
    }

    t.set_db(0);
    t.set_atlag(0.0);
}



    int main(){

        Tantargy * tantargyak = new Tantargy[TANTARGYAK];

        for (int i=0; i<TANTARGYAK; i++){
            std::cout << "TANTARGY " << i+1 << " kodja?" << std::endl;
            std::string k;
            std::cin >> k;
            std::cout << "jegyek szama?" << std::endl;
            int d;
            std::cin >> d;

            tantargyak[i] = Tantargy(k, d);
        }

        for (int i=0; i < TANTARGYAK; i++){
            kiir(tantargyak[i]);
        }

        Tantargy legjobb = tantargyak[0];
        for (int i = 1; i < TANTARGYAK; i++){
            if (tantargyak[i].get_atlag() > legjobb.get_atlag()){
                legjobb = tantargyak[i];
            }
        }
        std::cout << "legjobb tantargy: " << std::endl;
        kiir(legjobb);
        std::cout << "atlag: " << legjobb.get_atlag() << std::endl;

        std::cout << "új méretek 1: " << std::endl;
        for (int i=0; i < TANTARGYAK; i++){
            std::cout <<  i+1 << ". tantargy uj meret?" << std::endl;
            unsigned int ujm;
            std::cin >> ujm;
           Tantargy tobb = tobbJegy(tantargyak[i], ujm);
            kiir(tobb);
            felszabadit(tobb);
        }





        std::cout << "új méretek 2: " << std::endl;
        for (int i=0; i < TANTARGYAK; i++){
            std::cout <<  i+1 << ". tantargy uj meret?" << std::endl;
            unsigned int ujm;
            std::cin >> ujm;
            Tantargy tobb2= tobbJegy(tantargyak[i], ujm, 2, 4);
            kiir(tobb2);
            felszabadit(tobb2);

        }


        for (int i = 0; i < TANTARGYAK; i++) {
            felszabadit(tantargyak[i]);
        }
        delete[] tantargyak;



        return 0;
}

