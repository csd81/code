#include <iostream>
#include <string>
using namespace std;

namespace egyetem{
struct Tantargy {
    std::string kod;
    unsigned jegyekSzama;
    unsigned* jegyek;
};


void beolvas(Tantargy& t){
    cout << "kod: "; cin >> t.kod;
    cout << "szam: "; cin >> t.jegyekSzama;

    t.jegyek = new unsigned[t.jegyekSzama];
    for(unsigned i=0; i<t.jegyekSzama; i++){
        cout << " " << (i+1) << ". jegy: ";
        cin >> t.jegyek[i];
    }
}

void kiir(Tantargy& t){
    std::cout << "\nTargy kodja: " << t.kod << '\n';
    std::cout << "Jegyek szama: " << t.jegyekSzama << '\n';
    std::cout << "Jegyek: ";
    for(unsigned i=0; i<t.jegyekSzama; i++){
        cout << t.jegyek[i] << " ";
    }
    cout << "\n";
}

void felszabadit(Tantargy& t){
    delete[] t.jegyek;
    t.jegyek = nullptr;
}

double atlag(const Tantargy& t){
    if (t.jegyekSzama ==0) return 0.0;
    unsigned osszeg = 0;
    for (unsigned  i = 0; i<t.jegyekSzama; ++i){
        osszeg += t.jegyek[i];
    }
    return  static_cast<double>(osszeg) / t.jegyekSzama;
}


void meretez(Tantargy& t, unsigned ujMeret){
    unsigned* ujTomb = new unsigned[ujMeret];
    unsigned masolando = (ujMeret < t.jegyekSzama) ? ujMeret : t.jegyekSzama;
    for (unsigned i = 0; i < masolando; ++i) {
        ujTomb[i] = t.jegyek[i];
    }
    for (unsigned i = masolando; i < ujMeret; ++i) {
        ujTomb[i] = 5;
    }
    delete[] t.jegyek;
    t.jegyek = ujTomb;
    t.jegyekSzama = ujMeret;

}

void meretez(Tantargy& t, unsigned ujMeret, unsigned a,unsigned b){
    unsigned* ujTomb = new unsigned[ujMeret];
    unsigned masolando = (ujMeret < t.jegyekSzama) ? ujMeret : t.jegyekSzama;
    for (unsigned i = 0; i < masolando; ++i) {
        ujTomb[i] = t.jegyek[i];
    }
    for (unsigned i = masolando; i < ujMeret; ++i) {
        ujTomb[i] = (i % 2 == 0) ? a : b;
    }
    delete[] t.jegyek;
    t.jegyek = ujTomb;
    t.jegyekSzama = ujMeret;
}


} //namespace egyetem


int main(){
    using namespace egyetem;

    const unsigned DB = 3;

    Tantargy tantargyak[DB];
    for (unsigned i = 0; i < DB; ++i){
        cout << "\n--- " << (i + 1) << ". tantargy ---\n";
        beolvas(tantargyak[i]);
    }

    for (unsigned i = 0; i < DB; ++i) {
        unsigned ujMeret;
        std::cout << "\nAdd meg az uj meretet a(z) " << tantargyak[i].kod << " tantargyhoz: ";
        std::cin >> ujMeret;

        unsigned a, b;
        std::cout << "Add meg a ket valtakozo erteket: ";
        std::cin >> a >> b;
        meretez(tantargyak[i], ujMeret, a, b);
    }



    cout << "\n---Beolvasott---\n";
    double maxAtlag = -1;
    unsigned bestIndex =0;

    for (unsigned i = 0; i < DB; ++i){
        kiir(tantargyak[i]);
        double aktAtlag = atlag(tantargyak[i]);
        cout << "Atlag:" << aktAtlag << '\n';
        if (aktAtlag > maxAtlag) {
            maxAtlag = aktAtlag;
            bestIndex = i;
        }

    }


    std::cout << "\n=== Legjobb atlagu tantargy ===\n";
    kiir(tantargyak[bestIndex]);
    std::cout << "Atlag: " << atlag(tantargyak[bestIndex]) << "\n";

    for (unsigned i = 0; i < DB; ++i) {
        felszabadit(tantargyak[i]);
    }

    return 0;


}



