#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// using namespace std;

#include "verseny.h"

std::vector<Probalkozas> pv1(3);

void kiirProbalkozasVektor (const std::vector<Probalkozas>& pv)
{
    for (size_t i=0;i<pv.size();i++)
    {
        std::cout << pv[i].getNev() << " ";
        std::cout << pv[i].getTavolsag() << " ";
        std::cout << pv[i].getErvenyes() << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "main() eleje!" << std::endl << std::endl;


    {
        // ide keruljon a vector<Problakozas>-os feladat megoldasa:
        kiirProbalkozasVektor(pv1);
        pv1[1].setTavolsag(1);
        pv1[1].setErvenyes(1);
        pv1[1].setNev("nev1");
        kiirProbalkozasVektor(pv1);
        for (int i=0; i <pv1.size(); i++){
            double t;
            bool e;
            std::string n;
            std::cout << i+1 << " ervenyes? \n";
            std::cin >> e;
            std::cout << i+1 << " tavolsag? \n";
            std::cin >> t;
            std::cout << i+1 << " nev? \n";
            std::cin >> n;

            pv1[i].setErvenyes(e);
            pv1[i].setTavolsag(t);
            pv1[i].setNev(n);
        }

        pv1.resize(5);
        kiirProbalkozasVektor(pv1);
    }
    // ismeretlen 0 0
    // ismeretlen 0 0
    // ismeretlen 0 0
    //
    // Sandor 29.9 1
    // Jozsef 31.8 0
    // Benedek 32.7 0
    // ismeretlen 0 0
    // ismeretlen 0 0

//    // konstruktor teszt (egyelore nincs output)
   Verseny v("verseny1.txt");
   const Verseny& v_cref = v;

   // kiir() 1. verzio teszt
   v_cref.kiir();
   std::cout << std::endl;
//    // Verseny1
//    // Anita 35.91 1
//    // Bea 40.17 1
//    // Csilla 39.93 1
//    // Diana 36.98 1
//    // Emma 37.11 1
//    // Emma 39.22 0
//    // Diana 37.12 1
//    // Anita 38.88 0
//    // Anita 35.92 1
//    // Csilla 38.5 0

   // kiir() 2. verzio teszt (lasd a keletkezett fajl tartalmat!)
   {
       std::ofstream masolat("verseny1-masolat1.txt");
       v_cref.kiir(masolat);
   }

   // kiir() 3. verzio teszt (lasd a keletkezett fajl tartalmat!)
   v_cref.kiir("verseny1-masolat2.txt");

   // uj() teszt
   v.uj("Diana",40.31,0);
   v.uj("Diana",40.29,1);
   v.uj("Sanyi",1.129,0);
   v.uj("Zolee",11.129,1);
   v.kiir();
   std::cout << std::endl;
   // Verseny1
   // Anita 35.91 1
   // Bea 40.17 1
   // Csilla 39.93 1
   // Diana 36.98 1
   // Emma 37.11 1
   // Emma 39.22 0
   // Diana 37.12 1
   // Anita 38.88 0
   // Anita 35.92 1
   // Csilla 38.5 0
   // Diana 40.31 0
   // Diana 40.29 1

   // ervenyesDobasok() teszt
   {
       std::cout << "Ervenyes dobasok listaja:" << std::endl;
       // itt kerdezd le es ird ki az ervenyes dobasokat:
       // (...)
       std::vector<double> erDob = v.ervenyesDobasok();
       for (double d : erDob){
           std::cout  <<  d << " ";
       }
       std::cout << std::endl;
   }
   // Ervenyes dobasok listaja:
   // 35.91 40.17 39.93 36.98 37.11 37.12 35.92 40.29

   // nevSzerint() teszt
   std::vector<Probalkozas> prob;
   prob.push_back(Probalkozas("Torlendo1",9999.99,0));
   prob.push_back(Probalkozas("Torlendo2",9999.99,0));
   prob.push_back(Probalkozas("Torlendo3",9999.99,0));
   v_cref.nevSzerint("Anita",prob);
   std::cout << "csak Anita dobasok listaja:" << std::endl;
   for (size_t i=0;i<prob.size();i++)
   {
       std::cout << prob[i].getNev() << " ";
       std::cout << prob[i].getTavolsag() << " ";
       std::cout << prob[i].getErvenyes() << std::endl;
   }
   std::cout << std::endl;
   // Anita 35.91 1
   // Anita 38.88 0
   // Anita 35.92 1

   std::vector<Probalkozas> prob1;
   prob.push_back(Probalkozas("bs",9999.99,0));
   prob.push_back(Probalkozas("bs2",9999.99,0));
   prob.push_back(Probalkozas("bd3",9999.99,0));
   prob.push_back(Probalkozas("bs",9999.99,0));
   prob.push_back(Probalkozas("bs2",9999.99,0));
   prob.push_back(Probalkozas("bd3",9999.99,0));
   kiirProbalkozasVektor(prob1);
   v_cref.nevSzerint("Zolee",prob1);
   for (size_t i=0;i<prob1.size();i++)
   {
       std::cout << prob1[i].getNev() << " ";
       std::cout << prob1[i].getTavolsag() << " ";
       std::cout << prob1[i].getErvenyes() << std::endl;
   }
   std::cout << std::endl;
    std::cout << "main() vege!" << std::endl;
    return 0;
}
